#include "database.h"

bool dbdConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("140.124.183.46");
    db.setPort(3306);
    db.setDatabaseName("Mysql");
    db.setUserName("ooad");
    db.setPassword("Csslab438");
    if (!db.open()) {
        return false;
    }
    db.close();
    return true;
}
int AdddCar(QString Brand,QString Model,QString kilometers,QString MaxSeat,QString RentalPrice,QString filePath){
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
