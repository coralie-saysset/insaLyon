#include "client.h"
#include <QFile>

Client::Client( QTcpSocket *sock, const QByteArray& cata):
        sockControle(sock), catalogue(cata)

 {

      connect(sockControle, SIGNAL(readyRead()),this, SLOT(requeteRecu()));
      connect(this, SIGNAL(requeteComplete()),
              this, SLOT (traiterRequete()));
  }// vide

Client::~Client()
{
    qDebug()<< QString(sockControle->readAll());
}


void Client::demandeClient(QByteArray message)
{
    requeteClient.append(message);
}

void Client::requeteRecu()

{
        requeteClient.append(sockControle->readAll());
            qDebug()<< requeteClient.toHex();
        if ( requeteClient.endsWith("\r\n\r\n") )
        {
            qDebug()<< requeteClient;
            emit requeteComplete();
        }

}

void Client::traiterRequete()
{
    envoieCatalogue();
    requeteClient.clear();
}


void Client::envoieCatalogue()
{
    QFile fichier("catalogue.txt");

    if (fichier.open( QIODevice::ReadWrite))
    {
        sockControle->write( catalogue );

    }

}
