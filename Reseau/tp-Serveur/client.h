#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpSocket>

class Client :public QTcpSocket
{
public:
    Client();

protected:
    QByteArray requeteClient;

protected slots:
    void demandeClient(QByteArray message);

};

#endif // CLIENT_H
