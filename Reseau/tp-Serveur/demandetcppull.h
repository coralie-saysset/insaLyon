#ifndef DEMANDETCPPULL_H
#define DEMANDETCPPULL_H

#include <QTcpSocket>
#include <QList>

class DemandeTcpPull:public QObject
{
    Q_OBJECT

public:
    DemandeTcpPull( QTcpSocket *sock, QList<QByteArray> &video);
    ~DemandeTcpPull();// destructeur à revoir.

 signals:
    void requeteComplete();

protected:
    QTcpSocket *sockControle;
    QTcpSocket *sockDonnees;
    QByteArray requeteClient;
    QList<QByteArray> &images;
    int numImageEnvoie;

    void connecteSockDonnee();
    void envoieImage();
    void demandeClient(QByteArray message);


protected slots:
    void requeteRecu();
    void traiterRequete();

};

#endif // DEMANDETCPPULL_H
