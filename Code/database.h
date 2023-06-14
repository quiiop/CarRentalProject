#ifndef DATABASE_H
#define DATABASE_H
#include<QSqlDatabase>
#include <QApplication>
#include <QLabel>
#include <QString>
#include <QSqlQuery>

class Database
{
public:
    bool dbdConnection();
    int addCar(QString Brand,QString Model,QString kilometers,QString MaxSeat,QString RentalPrice,QString filePath);//新增車輛
    bool signUp(QString Account,QString Password,QString Name,QString Phone,QString Address);//註冊帳號
    bool checkAccount(QString Account);//檢查是否有重複
};


#endif // DATABASE_H
