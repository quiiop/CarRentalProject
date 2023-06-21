#ifndef DATABASE_H
#define DATABASE_H
#include<QSqlDatabase>
#include <QApplication>
#include <QLabel>
#include <QString>
#include <QSqlQuery>
#include <string>

class Database
{
public:
    bool dbdConnection();
    int addCar(QString Brand,QString Model,QString kilometers,QString MaxSeat,QString RentalPrice,QString CarStatus,QString filePath);//新增車輛
    bool signUp(QString Account,QString Password,QString Name,QString Phone,QString Address);//註冊帳號
    bool checkAccount(QString Account);//檢查是否有重複
    bool checkPassword(QString Account,QString Password);//檢查密碼
    int getAccountType(QString Account);//取得帳號Type
    int getCarIdByModelAndKilometers(QString Model,QString kilometers);
    void insertPartsStatus(int ID);
    QString getRentalCarInfo();
    QStringList getCarBrandInfo();
    QString getCustomerID(QString Account);
    bool getCustomerRentalCar(QString customertID);
    void updateRentalCar(QString customertID);
    void escheatRentalCar(QString customertID);
    QString addOrder(QString customertID,QString carID,QString rentalDate,QString expireDate);
    QString getOrderID(QString customertID);
    QString getOrderCarID(QString orderID);
    QString getOrderrentalDate(QString orderID);
    QString getOrderexpireDate(QString orderID);
    void finishOrder(QString orderID,QString evaluation);

};


#endif // DATABASE_H
