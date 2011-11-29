#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpSocket>

class Client: public QObject
{
Q_OBJECT
public:

    Client( QTcpSocket *sock, const QByteArray& cata);
    ~Client();

signals:
    void requeteComplete();

private:
    QByteArray requeteClient;
    QTcpSocket * sockControle;
    const QByteArray& catalogue;
    void envoieCatalogue();

protected slots:
    void demandeClient(QByteArray message);
    void requeteRecu();
    void traiterRequete();

};

#endif // CLIENT_H
