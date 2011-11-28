#include "client.h"

Client::Client(): QTcpSocket()
{

}

void Client::demandeClient(QByteArray message)
{
    requeteClient.append(message);
}
