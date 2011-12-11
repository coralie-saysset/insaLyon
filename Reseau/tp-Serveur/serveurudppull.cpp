#include "serveurudppull.h"
#include <QFile>


ServeurUdpPull::ServeurUdpPull(): QTcpServer()
{
    sockecoute = new QUdpSocket;
    chargerVideo();
    sockecoute->bind(QHostAddress::Any, 11114, QUdpSocket::ShareAddress);
    //sock lié au port de 11114 ecoutant depuis toutes les adresses
    // et plusieurs a la fois
    connect(sockecoute, SIGNAL(readyRead()), this, SLOT(requeteRecu()));

    waitForNewConnection();

    //attend une connection
}

void ServeurUdpPull::requeteRecu()
{
    qDebug()<<"requete recue";
    QByteArray requete;
    QHostAddress address;
    quint16 maxSize =sockecoute->pendingDatagramSize();
    requete.resize(maxSize);
    sockecoute->readDatagram(requete.data(),maxSize,&address);
    qDebug()<<requete;

    traiterRequete(requete,address);

}

void ServeurUdpPull::traiterRequete(QByteArray requete, QHostAddress hostAddress)
{
    if (requete.count("\r\n")>3)
    {
        struct ClientUdp nouveauClient;
        nouveauClient.addresse=hostAddress;
        nouveauClient.port = requete.split('\n')[1].trimmed().
                             split(' ')[1].trimmed().toInt();
        nouveauClient.tailleFragment = requete.split('\n')[2].trimmed().
                             split(' ')[1].trimmed().toInt();// Kev dit -64, WTF?
        nouveauClient.numImage=1;
        clientsConnectes.append(nouveauClient);
/*
        qDebug()<<clientsConnectes[0].addresse;
        qDebug()<<clientsConnectes[0].port;
        qDebug()<<clientsConnectes[0].tailleFragment;
*/
    }
    else if (requete.count("\r\n")==2)
    {
        if (requete.startsWith("END"))
        {
        //detruire le client proprement (s'il existe!!)
        }
        else
        {
            envoieImage(hostAddress);
        }
    }
}

void ServeurUdpPull::envoieImage(QHostAddress addresseClient)
{
    //identification du client
    int numClient=-1;
    for(int i=0; i<=clientsConnectes.size()-1; i++)
    {
        if (clientsConnectes[i].addresse==addresseClient)
        {
            numClient=i;
        }
    }
    if (numClient==-1)
    {
        return;
    }

    //s'il existe
    ClientUdp client =clientsConnectes[numClient];
    int posFragment=0;
    QByteArray imageEnCours= mesImages[client.numImage];
    bool enCours=true;

    while (enCours)
    {
        QByteArray message;

        //position de l'image
        QByteArray nombre(QByteArray::number(client.numImage));
        message.append(nombre);

        message.append("\r\n");

        //taille de l'image
        nombre=QByteArray::number(mesImages[client.numImage].size());
        message.append(nombre);

        message.append("\r\n");

        //position du fragment
        nombre=(QByteArray::number(posFragment));
        message.append(nombre);

        message.append("\r\n");

        if(imageEnCours.size()>client.tailleFragment)
            //paquet standard
        {
            //Taille du Fragment demandé
            nombre=(QByteArray::number(client.tailleFragment));
            message.append(nombre);

            message.append("\r\n");

            //Image a envoyer
            message.prepend(imageEnCours,client.tailleFragment);

            //Image restante
            imageEnCours=imageEnCours.remove(1,client.tailleFragment);

            //qDebug()<<message.size();
            sockecoute->writeDatagram(message,client.addresse, client.port);

            posFragment+=(client.tailleFragment);
        }
        else if(imageEnCours.size()<=client.tailleFragment)
        {
            //dernier fragment de taille différente?
            nombre=(QByteArray::number(imageEnCours.size()));
            message.append(nombre);

            message.append("\r\n");

            //Il ne reste qu'un morceau à envoyer
            message.append(imageEnCours);

            sockecoute->writeDatagram(message,client.addresse, client.port);
            posFragment=0;
            clientsConnectes[numClient].numImage+=1;
            enCours=false;


        }

//Que faire quand tout a Ã©tÃ© envoyÃ©?
//Pour l'instant boucler
        if (clientsConnectes[numClient].numImage==mesImages.count())
        {
            clientsConnectes[numClient].numImage=1;
        }
    }
}


void ServeurUdpPull::chargerVideo()
{
    QFile flux("/home/cocoon/Bureau/tp-Serveur/flux6.txt");
    if (!flux.open(QIODevice::ReadOnly) ) return;
    QString buffer;

    while( !buffer.startsWith("IPS") )
        { buffer = flux.readLine(); }

    while( !flux.atEnd() )
    {
        QFile image( flux.readLine().trimmed() );
        image.open(QIODevice::ReadOnly);
        mesImages.push_back( image.readAll() );

    }

}

