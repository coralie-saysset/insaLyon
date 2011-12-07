#include <QDebug>
#include "demandetcppull.h"
#include <QHostAddress>


DemandeTcpPull::DemandeTcpPull( QTcpSocket *sock,
                                QList<QByteArray> &video):
        sockControle(sock), images(video)

{
    numImageEnvoie=0;
    sockDonnees = new QTcpSocket(this);
    connect(sockControle, SIGNAL(readyRead()),
           this, SLOT(requeteRecu()));
    connect(this, SIGNAL(requeteComplete()),
            this, SLOT(traiterRequete()));
}

DemandeTcpPull::~DemandeTcpPull()
{
//pas encore bien operationnel tout ça
    sockControle->deleteLater();
    sockDonnees->deleteLater();
}

void DemandeTcpPull::requeteRecu()
{
        requeteClient.append(sockControle->readAll());

        if ( requeteClient.endsWith("\r\n\r\n") )
        {

            emit requeteComplete();
        }
}


void DemandeTcpPull::traiterRequete()
{
    qDebug()<<"requete ";
    qDebug()<< requeteClient;
    if (requeteClient.count("\r\n")==3)
      {
        connecteSockDonnee();
        }
    else if (requeteClient.count("\r\n")==2)
    {
        if (requeteClient.startsWith("END"))
        {
           this->~DemandeTcpPull();
        }
        else
        {
            envoieImage();
        }
    }
    requeteClient.clear();
}
void DemandeTcpPull::connecteSockDonnee()
{
    quint16 clientPort = requeteClient.split('\n')[1].trimmed().
                         split(' ')[1].trimmed().toInt();
    //on recupere le port du client envoyé dans la requete
    //on connecte le socket de donnee
    sockDonnees->connectToHost((sockControle->localAddress()),clientPort);
    // verifier la connection: qDebug()<<sockDonnees->isOpen();

}


void DemandeTcpPull::envoieImage()
{
        QByteArray message;
        QByteArray nombre(QByteArray::number(numImageEnvoie));
        message.append(nombre);
	//position de l'image
        message.append("\r\n");
        nombre= QByteArray::number(images[numImageEnvoie].size());
        message.append(nombre);
	//taille de l'image
        message.append("\r\n");
        message.append(images[numImageEnvoie]);
	//envoie du message
        sockDonnees->write(message);
        numImageEnvoie+=1;

//Que faire quand tout a été envoyé?
//Pour l'instant boucler
        if (numImageEnvoie==images.count())
        {
            numImageEnvoie=0;
        }


}


