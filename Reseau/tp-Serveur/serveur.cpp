#include "serveur.h"
#include <QTcpSocket>
#include <QString>
#include <QDebug>
#include <QFile>
#include <client.h>

Serveur::Serveur():
    QTcpServer(), fichierPath("startup.txt")
{

    chargerCatalogue();
    connect(this, SIGNAL(newConnection()),
            this, SLOT(connexionAuServeur()) );

    listen( QHostAddress::Any, 8081 );
    waitForNewConnection();
    //attend une connection

}

//ajoute un client Ã  la liste et attend une requete
void Serveur::connexionAuServeur()
{
       QTcpSocket* sock = nextPendingConnection();
       Client *client = new Client(sock, catalogue);
       clientsConnectes << client;

    //    qDebug() << "Nouvelle connection entrante !";
}

void Serveur::chargerCatalogue()
{
    QFile fichier("startup.txt");

    if ( !fichier.open( QIODevice::ReadWrite))
    {
        return;
    }

     catalogue = fichier.readLine().trimmed();
     catalogue += "\r\n";
     catalogue += fichier.readLine().trimmed();
     catalogue += "\r\n";


     QString ficPath;
     while( fichier.canReadLine() ){
           ficPath = fichier.readLine().trimmed();
           QFile flux( ficPath );


           if( !flux.open( QIODevice::ReadOnly ) )
           { continue;}

           catalogue += "Object ID=";
           catalogue += flux.readLine().split(' ')[1].trimmed();
           catalogue += " name=";
           catalogue += flux.readLine().split(' ')[1].trimmed();
           catalogue += " type=";
           catalogue += flux.readLine().split(' ')[1].trimmed();
           catalogue += " address=";
           catalogue += flux.readLine().split(' ')[1].trimmed();
           catalogue += " port=";
           catalogue += flux.readLine().split(' ')[1].trimmed();
           catalogue += " protocol=";
           catalogue += flux.readLine().split(' ')[1].trimmed();
           catalogue += " ips=";
           catalogue += flux.readLine().split(' ')[1].trimmed();
           catalogue += "\r\n";

     }
     catalogue += "\r\n";

     int size = catalogue.size();

     catalogue.insert( 0, "\r\n\r\n" );
     catalogue.insert( 0, QString::number( size) );
     catalogue.insert( 0, "Content-Length: " );
     catalogue.insert( 0, "Content-Type: text/txt\r\n" );
     catalogue.insert( 0, "HTTP/1.1 200 OK\r\n" );



}
