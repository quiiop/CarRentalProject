#include "car.h"
#include <QDebug>


Car::Car(){
    qDebug() << "Car create";
}

QString Car::get_BrandInput(){
    return this->BrandInput;

}

void Car::set_car(QString BrandInput, QString KmInput, QString ModelLine, QString CarStatus, QString MaxSeatLine, QString RentalPriceLine, QString filePath){
    this->BrandInput = BrandInput;
    this->KmInput = KmInput;
    this->ModelLine = ModelLine;
    this->CarStatus = CarStatus;
    this->MaxSeatLine = MaxSeatLine;
    this->RentalPriceLine = RentalPriceLine;
    this->filePath = filePath;
}
