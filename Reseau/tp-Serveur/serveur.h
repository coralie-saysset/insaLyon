#ifndef SERVEUR_H
#define SERVEUR_H

#include <QTcpServer>
#include <QString>
#include "client.h"

class Serveur : public QTcpServer
{
    Q_OBJECT

public:
    Serveur();




protected:
    QList<Client *> clientsConnectes;
    QByteArray catalogue;
    QString fichierPath;
    void chargerCatalogue();



protected slots:
    void connexionAuServeur();



};

#endif // SERVEUR_H
