#ifndef DEMANDETCPPULL_H
#define DEMANDETCPPULL_H

#include <QTcpSocket>
#include <client.h>
#include <QList>

class DemandeTcpPull:public QTcpSocket
{
    Q_OBJECT

public:
    DemandeTcpPull( QTcpSocket *sock, QList<QByteArray> &video);


 signals:
    void requeteComplete();

protected:
    QTcpSocket *sockControle;
    QTcpSocket sockDonnees;
    QByteArray requeteClient;
    QList<QByteArray> &images;

    void connecteSockDonnee();
    void envoieImage();
    void finConnection();
    void demandeClient(QByteArray message);


protected slots:
    void requeteRecu();
    void traiterRequete();
};

#endif // DEMANDETCPPULL_H
