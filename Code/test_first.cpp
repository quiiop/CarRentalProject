#include <QtTest>
#include <QCoreApplication>
#include "mainwindow.h"
#include "database.h"
#include <QDebug>

class Function_Test{
public:
    Function_Test(){

    }
    bool check_Date_label_format(QString year, QString month, QString date){
        QRegularExpression regex("[^0-9]");
        if(year=="" || month=="" || date==""){
            return false;
        }else if(year.at(0)=='0' || year.contains(regex) || month.at(0)=='0' || month.contains(regex) || month.toInt() >12 || date.at(0)=='0' || date.contains(regex) || date.toInt() > 31) {
            return false;
        }else{
            return true;
        }
    }
};

class MyTest : public QObject
{
    Q_OBJECT

private slots:

    void testExample()
    {
        QString year = "2000";
        QString month = "3";
        QString date = "7";
        Function_Test *ft = new Function_Test();

        bool result = ft->check_Date_label_format(year, month, date);
        int r = 0;
        if(result){
            r = 1;
        }else{
            r = 0;
        }
        QCOMPARE(r, 1);
    }
    void testExample1()
    {
        QString year = "2000";
        QString month = "23";
        QString date = "7";
        Function_Test *ft = new Function_Test();

        bool result = ft->check_Date_label_format(year, month, date);
        int r = 0;
        if(result){
            r = 1;
        }else{
            r = 0;
        }
        QCOMPARE(r, 0);
    }
    void testExample2()
    {
        QString account = "test";
        Database db;
        bool result = db.checkAccount(account);
        int r=-1;
        if(result){
            r = 1;
        }else{
            r = 0;
        }
        QCOMPARE(r, 0);
    }
    void testExample3()
    {
        QString account = "dsfsdifisu";
        Database db;
        bool result = db.checkAccount(account);
        int r=-1;
        if(result){
            r = 1;
        }else{
            r = 0;
        }
        QCOMPARE(r, 1);
    }
    void testExample4()
    {
        Database db;
        QString account = "test";
        QString password = "test";

        bool result = db.checkPassword(account,password);//檢查密碼
        int r=-1;
        if(result){
            r = 1;
        }else{
            r = 0;
        }
        QCOMPARE(r, 1);
    }
    void testExample5()
    {
        Database db;
        QString account = "test";
        QString password = "testpassword";

        bool result = db.checkPassword(account,password);//檢查密碼
        int r=-1;
        if(result){
            r = 1;
        }else{
            r = 0;
        }
        QCOMPARE(r, 0);
    }
    void testExample6()
    {
        Database db;
        QString account = "test";
        QString password = "test";

        int result = db.getAccountType(account);
        int r = -1;
        if(result==1){
            r = 1;
        }else{
            r = 0;
        }
        QCOMPARE(r, 0);
    }
    void testExample7()
    {
        Database db;
        QString account = "company";

        int result = db.getAccountType(account);
        int r = -1;
        if(result==1){
            r = 1;
        }else{
            r = 0;
        }
        QCOMPARE(r, 1);
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    Database db;
    db.dbdConnection();
    MyTest test;
    QTest::qExec(&test);

    return 0;
}

#include "test_first.moc"
