#include "order.h"
#include <QDebug>

Order::Order(){
    qDebug()<<"Order create";
}

void Order::set_order(Car rental_car,int *rental_date, int *expire_date){
    this->rental_car = &rental_car;

    this->rental_date[0] = rental_date[0];
    this->rental_date[1] = rental_date[1];
    this->rental_date[2] = rental_date[2];

    this->expire_date[0] = expire_date[0]; // year
    this->expire_date[1] = expire_date[1]; // month
    this->expire_date[2] = expire_date[2]; // date
}


