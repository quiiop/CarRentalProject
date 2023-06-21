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
    db.close();
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
    db.close();
}
QStringList Database::getCarBrandInfo(){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    QStringList brand;
    q.prepare("SELECT brand,model,kilomenter,maxSeat,rentalPrice FROM carrentalsystem.car where rentalStatus=0 order by id;");
    if(q.exec()){
        while(q.next()){
            brand << q.value("brand").toString();
        }
    }
    db.close();
    return brand;

}
QString Database::getCustomerID(QString Account){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("SELECT id FROM carrentalsystem.user where account=:account;");
    q.bindValue(":account", Account);
    if(q.exec()){
        while(q.next()){
            return q.value("id").toString();
        }
    }
    db.close();
}
bool Database::getCustomerRentalCar(QString customertID){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("SELECT rentalCar FROM carrentalsystem.user where id=:ID;");
    q.bindValue(":ID", customertID);
    if(q.exec()){
        while(q.next()){
            if("1"==q.value("rentalCar").toString()){
                return true;
            }else{
                return false;
            }

        }
    }
    db.close();
}
void Database::updateRentalCar(QString customertID){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    qDebug()<<customertID.toInt();
    q.prepare("UPDATE carrentalsystem.user SET rentalCar=1 where id=:ID;");
    q.bindValue(":ID", customertID.toInt());
    q.exec();
    db.close();
}
void Database::escheatRentalCar(QString customertID){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("UPDATE carrentalsystem.user SET rentalCar=0 where id=:ID;");
    q.bindValue(":ID", customertID.toInt());
    q.exec();
    db.close();
}
QString Database::addOrder(QString customertID,QString carID,QString rentalDate,QString expireDate){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("INSERT INTO executionorder VALUES (0,:customertID,:carID,:rentalDate,:expireDate);");
    q.bindValue(":customertID", customertID);
    q.bindValue(":carID", carID);
    q.bindValue(":rentalDate", rentalDate);
    q.bindValue(":expireDate", expireDate);
    q.exec();
    q.prepare("SELECT orderID FROM carrentalsystem.executionorder where customerID=:customertID AND carID=:carID;");
    q.bindValue(":customertID", customertID);
    q.bindValue(":carID", carID);
    if(q.exec()){
        while(q.next()){
            return q.value("orderID").toString();
        }
    }
    db.close();
}
QString Database::getOrderID(QString customertID){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("SELECT orderID FROM carrentalsystem.executionorder where customerID=:ID;");
    q.bindValue(":ID", customertID);
    if(q.exec()){
        while(q.next()){
            return q.value("orderID").toString();
        }
    }
    db.close();
}
QString Database::getOrderCarID(QString orderID){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("SELECT carID FROM carrentalsystem.executionorder where orderID=:ID;");
    q.bindValue(":ID", orderID);
    if(q.exec()){
        while(q.next()){
            return q.value("carID").toString();
        }
    }
    db.close();
}
QString Database::getOrderrentalDate(QString orderID){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("SELECT rentalDate FROM carrentalsystem.executionorder where orderID=:ID;");
    q.bindValue(":ID", orderID);
    if(q.exec()){
        while(q.next()){
            return q.value("rentalDate").toString();
        }
    }
    db.close();
}
QString Database::getOrderexpireDate(QString orderID){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    q.prepare("SELECT expireDate FROM carrentalsystem.executionorder where orderID=:ID;");
    q.bindValue(":ID", orderID);
    if(q.exec()){
        while(q.next()){
            return q.value("expireDate").toString();
        }
    }
    db.close();
}
void Database::finishOrder(QString orderID,QString evaluation){
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery q(db);
    QString customerID;
    QString carID;
    QString rentalDate;
    QString expireDate;
    q.prepare("SELECT * FROM carrentalsystem.executionorder where orderID=:ID;");
    q.bindValue(":ID", orderID);
    if(q.exec()){
        while(q.next()){
             customerID = q.value("customerID").toString();
             carID = q.value("carID").toString();
             rentalDate = q.value("rentalDate").toString();
             expireDate = q.value("expireDate").toString();
        }
    }
    q.prepare("INSERT INTO finishorder VALUES (:ID,:customerID,:carID,:rentalDate,:expireDate,0,:evaluation);");
    q.bindValue(":ID", orderID);
    q.bindValue(":customerID", customerID);
    q.bindValue(":carID", carID);
    q.bindValue(":rentalDate", rentalDate);
    q.bindValue(":expireDate", expireDate);
    q.bindValue(":evaluation", evaluation);
    q.exec();
    q.prepare("DELETE FROM carrentalsystem.executionorder WHERE orderID = :ID;");
    q.bindValue(":ID", orderID);
    q.exec();
    db.close();
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
