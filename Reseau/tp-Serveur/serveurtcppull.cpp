#include "serveurtcppull.h"
#include "demandetcppull.h"
#include <QFile>


ServeurTcpPull::ServeurTcpPull(): QTcpServer()
{

    chargerVideo();
    connect(this, SIGNAL(newConnection()),
            this, SLOT(connexionAuServeur()) );

    listen( QHostAddress::Any, 11113 );
    waitForNewConnection();
    //attend une connection
}

void ServeurTcpPull::connexionAuServeur()
{

    QTcpSocket* sock = nextPendingConnection();
    DemandeTcpPull *client = new DemandeTcpPull(sock, mesImages);
    clientsConnectes<< client;
    connect(client, SIGNAL(deconnection(DemandeTcpPull*)), this, SLOT(deconnexionClient(DemandeTcpPull*)));
}
void ServeurTcpPull::chargerVideo()
{
    QFile flux("/home/cocoon/Bureau/tp-Serveur/flux5.txt");
    if (!flux.open(QIODevice::ReadOnly) ) return;

    QByteArray adresseImage;
    QString buffer;

    while( !buffer.startsWith("IPS") )
        { buffer = flux.readLine(); }

    while( !flux.atEnd() ) {
        QFile image( flux.readLine().trimmed() );
        image.open(QIODevice::ReadOnly);
        mesImages.push_back( image.readAll() );
 //       qDebug()<<mesImages.last().size();
    }

}

void ServeurTcpPull::deconnexionClient(DemandeTcpPull* ceClient)
{

    clientsConnectes.removeOne(ceClient);
    ceClient->~DemandeTcpPull();
}

