#include "database.h"
#include <QDebug>
#include <QT>
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
int Database::addCar(QString Brand,QString Model,QString kilometers,QString MaxSeat,QString RentalPrice,QString CarStatus,QString filePath){
    int err = 1;
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("INSERT INTO car VALUES (0,:brand,:model,:kilometers,:MaxSeat,:RentalPrice,:carStatus,:filePath,0,3,3,3);");
    q.bindValue(":brand", Brand);
    q.bindValue(":model", Model);
    q.bindValue(":kilometers", kilometers);
    q.bindValue(":MaxSeat", MaxSeat);
    q.bindValue(":RentalPrice", RentalPrice);
    if(CarStatus=="良好"){
        q.bindValue(":carStatus",3);
    }else if(CarStatus=="尚可"){
        q.bindValue(":carStatus",2);
    }else{
        q.bindValue(":carStatus",1);
    }
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
    QSqlQuery q(db);
    q.prepare("INSERT INTO user VALUES (0,:account,:password,0,:name,:phone,:address,0);");
    q.bindValue(":account", Account);
    q.bindValue(":password", Password);
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
    int r=0;
    if(q.exec()){
        while(q.next()){
            r++;
        }
    }
    if(r==0){
        return true;
    }else{
        return false;
    }
}
bool Database::checkPassword(QString Account,QString Password){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("SELECT password FROM carrentalsystem.user where account=:account;");
    q.bindValue(":account", Account);
    int r=0;
    if(q.exec()){
        while(q.next()){
            if(Password==q.value("password").toString()){
                return true;
            }else{
                return false;
            }
            r++;
        }
    }
    if(r==0){
        return false;
    }
}
int Database::getAccountType(QString Account){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("SELECT type FROM carrentalsystem.user where account=:account;");
    q.bindValue(":account", Account);
    if(q.exec()){
        while(q.next()){
            return q.value("type").toInt();
        }
    }
}
QVector<QString> Database::getRentalCarInfo(){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("SELECT * FROM carrentalsystem.car where rentalStatus=0;");
    if(q.exec()){
        while(q.next()){
            q.value("type").toInt();
        }
    }
}
//int Database::accountId(){

//}
//bool Database::submitOrder(QString Account,QString Password,QString Name,QString Phone,QString Address){
//    QSqlDatabase db = QSqlDatabase::database();
//    db.open();
//    bool st=true;
//    QSqlQuery q(db);
//    q.prepare("INSERT INTO user VALUES (0,:account,:password,0,:name,:phone,:address,0);");
//    q.bindValue(":account", Account);
//    q.bindValue(":password", Password);
//    q.bindValue(":name", Name);
//    q.bindValue(":phone", Phone);
//    q.bindValue(":address", Address);
//    if(!q.exec()){
//        st=false;
//        qDebug()<<"失敗";
//    }
//    db.close();
//    return st;
//}
