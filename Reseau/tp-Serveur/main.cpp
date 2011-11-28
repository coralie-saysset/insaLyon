#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtNetwork>
#include <serveur.h>
#include <client.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Serveur serveurVideo;
    w.show();

    return a.exec();
}
