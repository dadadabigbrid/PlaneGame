#include "mainwindow.h"
#include <QApplication>
#include"welcome.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    WELCOME w;
    w.show();

    return a.exec();
}
