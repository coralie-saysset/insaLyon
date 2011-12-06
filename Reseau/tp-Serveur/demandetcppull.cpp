#include <QDebug>
#include "demandetcppull.h"
#include <QHostAddress>

DemandeTcpPull::DemandeTcpPull( QTcpSocket *sock,
                                QList<QByteArray> &video):
        sockControle(sock), images(video)

{

    connect(sockControle, SIGNAL(readyRead()),
           this, SLOT(requeteRecu()));
    connect(this, SIGNAL(requeteComplete()),
            this, SLOT(traiterRequete()));
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
      qDebug()<< requeteClient;
    if (requeteClient.count("\r\n")==3)
      {
        connecteSockDonnee();
        }
    else if (requeteClient.count("\r\n")==2)
    {
        if (requeteClient.startsWith("END"))
        {

            finConnection();
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
    qDebug() << clientPort;
    sockDonnees.connectToHost((sockControle->localAddress()),clientPort);
}

void DemandeTcpPull::envoieImage()
{
    //if (requeteClient=="GET -1\r\n\r\n")
     //   {
        QByteArray message;
        QString test;
        test="1\r\n";
        test.append(images[0].size());
        test.append("\r\n");
        message.append(test);
        message.append(images[0]);
        sockDonnees.write(message);
        qDebug()<<"test";

      //  }
}
void DemandeTcpPull::finConnection()
{

}
