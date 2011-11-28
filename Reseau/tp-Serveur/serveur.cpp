#include "serveur.h"
#include <QTcpSocket>
#include <QString>
#include <QFile>
#include <QDebug>
#include <client.h>

Serveur::Serveur():
    QTcpServer()
{
        tailleMessage=0;
    //charge le dossier catalogue
    recupCatalogue();
    connect(this, SIGNAL(newConnection()),
            this, SLOT(connexionAuServeur()) );

    listen( QHostAddress::Any, 8081 );
    waitForNewConnection();
    //attend une connection

}

//ajoute un client à la liste et attend une requete
void Serveur::connexionAuServeur()
{
       QTcpSocket* sock = nextPendingConnection();
//        Client *monClient = qobject_cast<Client*> (nextPendingConnection());

        connect(sock, SIGNAL(readyRead()),
                this, SLOT(requeteRecu()));

        qDebug() << "Nouvelle connection entrante !";
}

void Serveur::requeteRecu()
{
    qDebug() << "On vient de recevoir un message !";
//identification du client
     QTcpSocket *monClient = qobject_cast<QTcpSocket *>(sender());
// Bordel infame
// probleme d'heritage entre QtcpSocket et client. A voir.
     connect(this, SIGNAL(RequeteComplete(QByteArray)), monClient, SLOT (DemandeClient(QByteArray)));
    static QByteArray RequeteHTTP;
    QByteArray morceauMessage;

    if (monClient->canReadLine())
    {
        morceauMessage=monClient->readLine();
        if (morceauMessage== "\r\n")
        {
            qDebug()<< QString(RequeteHTTP);

            emit RequeteComplete(RequeteHTTP);
        }
        else
        {
            RequeteHTTP=RequeteHTTP.append(morceauMessage);
        }
    }

}


void Serveur::getCatalogue() {
//a voir...


}
//titre explicite.
//idee:Passer adresse du fichier en parametre?
void Serveur::recupCatalogue()
{
    QString nomFichier("C:\\tp-serveur\\cata.txt");
    QFile fichier(nomFichier);
    if (fichier.open( QIODevice::ReadWrite))
    {
        catalogue = fichier.readAll();
        fichier.close();
    }

}
