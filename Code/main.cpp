#include "mainwindow.h"
#include "test1.h"
#include "test2.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow window;
    window.show();
    dbdConnection();
    //AddCar("TOYOTA","WISH",15400,7,3000,"C/asdasdasd");

    //Test2 t2;
    //t2.show();

    return a.exec();
}
