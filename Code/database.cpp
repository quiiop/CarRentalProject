#include "database.h"
#include <QDebug>
bool Database::dbdConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("140.124.183.46");
    db.setPort(3306);
    db.setDatabaseName("carrentalsystem");
    db.setUserName("ooad");
    db.setPassword("Csslab438");
    if (!db.open()) {
        return false;
    }
    db.close();
    return true;
}
int Database::addCar(QString Brand,QString Model,QString kilometers,QString MaxSeat,QString RentalPrice,QString filePath){
    int err = 1;
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("INSERT INTO car VALUES (0,:brand,:model,:kilometers,:MaxSeat,:RentalPrice,:filePath);");
    q.bindValue(":brand", Brand);
    q.bindValue(":model", Model);
    q.bindValue(":kilometers", kilometers);
    q.bindValue(":MaxSeat", MaxSeat);
    q.bindValue(":RentalPrice", RentalPrice);
    q.bindValue(":filePath", filePath);

    if(!q.exec()){
        err=0;
    }
    db.close();
    return err;

}
bool Database::signUp(QString Account,QString Password,QString Name,QString Phone,QString Address){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    bool st=true;
    QString Type="Customer";
    QSqlQuery q(db);
    q.prepare("INSERT INTO user VALUES (0,:account,:password,type,:name,:phone,:address);");
    q.bindValue(":account", Account);
    q.bindValue(":password", Password);
    q.bindValue(":type", Type);
    q.bindValue(":name", Name);
    q.bindValue(":phone", Phone);
    q.bindValue(":address", Address);
    if(!q.exec()){
        st=false;
        qDebug()<<"失敗";
    }
    db.close();
    return st;
}
bool Database::checkAccount(QString Account){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("SELECT id FROM carrentalsystem.user where account=:account;");
    q.bindValue(":account", Account);
    qDebug()<<q.value(0);
    if(q.value(0)==NULL){
        return true;
    }else {
        return false;
    }
}
