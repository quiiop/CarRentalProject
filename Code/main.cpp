#include "mainwindow.h"
#include "test1.h"
#include "test2.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Database db;
    MainWindow window;
    window.show();
    db.dbdConnection();

    //Test2 t2;
    //t2.show();

    return a.exec();
}
