#include "serveurtcppull.h"
#include "demandetcppull.h"
#include <QFile>


ServeurTcpPull::ServeurTcpPull(): QTcpServer()
{

         qDebug()<<"hey!";
    chargerVideo();
         qDebug()<<"you";
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

}
void ServeurTcpPull::chargerVideo()
{
    QFile flux("flux5.txt");
    if (!flux.open(QIODevice::ReadOnly) ) return;

    QByteArray adresseImage;
    QString buffer;

    while( !buffer.startsWith("IPS") )
        { buffer = flux.readLine(); }

    while( !flux.atEnd() ) {
        QFile image( flux.readLine().trimmed() );
        image.open(QIODevice::ReadOnly);
        mesImages.push_back( image.readAll() );
    }

}
