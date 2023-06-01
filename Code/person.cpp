#include "person.h"
#include <QDebug>


Person::Person(){
    qDebug() << "Person !!";
    Account = "0.0";
    Password = "0.0";
    is_rental_car = false;
}
