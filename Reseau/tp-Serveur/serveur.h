#ifndef SERVEUR_H
#define SERVEUR_H

#include <QTcpServer>
#include <QString>

class Serveur : public QTcpServer
{
    Q_OBJECT

public:
    Serveur();

signals:
    void RequeteComplete(QByteArray);


protected:
    QList<QTcpSocket *> clientsConnectes;
    QByteArray catalogue;
    quint16 tailleMessage;
    void recupCatalogue();


protected slots:
    void connexionAuServeur();
    void requeteRecu();
    void getCatalogue();


};

#endif // SERVEUR_H
