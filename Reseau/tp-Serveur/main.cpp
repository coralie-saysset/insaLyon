#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtNetwork>
#include <serveur.h>
#include <client.h>
#include <serveurtcppull.h>
#include <demandetcppull.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Serveur serveurVideo;
    ServeurTcpPull Serfichou;

    w.show();

    return a.exec();
}
