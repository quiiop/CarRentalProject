#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include "order.h"

namespace Person_space {
    class Person;
}
class Person{
public:
    explicit Person();
    QString Account;
    QString Password;
    QString Name;
    QString phone;
    QString address;
    QString user_id;
    bool is_rental_car;
    Order *customer_order;

private:

};

#endif // PERSON_H
