#include "mainwindow.h"
#include "test1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;
    window.show();
    dbdConnection();
    //AddCar("TOYOTA","WISH",15400,7,3000,"C/asdasdasd");
    return a.exec();
}
