#ifndef SERVEURTCPPULL_H
#define SERVEURTCPPULL_H

#include <QTcpServer>
#include <QList>

class ServeurTcpPull: public QTcpServer
{
    Q_OBJECT

public:
    ServeurTcpPull();

protected:

protected slots:
    void connexionAuServeur();

protected:
    QList<QByteArray> mesImages;
    void chargerVideo();

};

#endif // SERVEURTCPPULL_H
