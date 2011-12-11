#ifndef SERVEURUDPPULL_H
#define SERVEURUDPPULL_H

#include <QTcpServer>
#include <QList>
#include <QUdpSocket>

struct ClientUdp
{
    QHostAddress addresse;
    quint16 tailleFragment;
    quint16 port;
    int numImage;
};


class ServeurUdpPull: public QTcpServer
{
    Q_OBJECT

public:
    ServeurUdpPull();

protected slots:
   // void connexionAuServeur();
    void requeteRecu();


protected:
    QUdpSocket *sockecoute;
    QList<QByteArray> mesImages;
    void chargerVideo();
    QList<struct ClientUdp> clientsConnectes;
    void traiterRequete (QByteArray requete, QHostAddress hostAddress);
    void envoieImage (QHostAddress addresseClient);
};

#endif // SERVEURUDPPULL_H
