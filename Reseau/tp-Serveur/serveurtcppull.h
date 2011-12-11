#ifndef SERVEURTCPPULL_H
#define SERVEURTCPPULL_H

#include <QTcpServer>
#include <QList>
#include "demandetcppull.h"

class ServeurTcpPull: public QTcpServer
{
    Q_OBJECT

public:
    ServeurTcpPull();

protected slots:
    void connexionAuServeur();
    void deconnexionClient(DemandeTcpPull* ceClient);

protected:
    QList<QByteArray> mesImages;
    void chargerVideo();
    QList<DemandeTcpPull *> clientsConnectes;

};

#endif // SERVEURTCPPULL_H

