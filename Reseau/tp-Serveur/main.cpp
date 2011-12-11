#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtNetwork>
#include "serveur.h"
#include "serveurtcppull.h"
#include "serveurudppull.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Serveur serveurVideo;
    ServeurTcpPull Serfichou;
    ServeurUdpPull SerMoiABoire;

    w.show();

    return a.exec();
}
