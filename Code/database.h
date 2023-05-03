#ifndef DATABASE_H
#define DATABASE_H
#include<QSqlDatabase>
#include <QApplication>
#include <QLabel>
#include <QString>
#include <QSqlQuery>

bool dbdConnection();
int AdddCar(QString Brand,QString Model,QString kilometers,QString MaxSeat,QString RentalPrice,QString filePath);

#endif // DATABASE_H
