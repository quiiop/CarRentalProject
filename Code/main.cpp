#include "mainwindow.h"
#include "test1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    Test1 w;
    w.show();

    return a.exec();
}
