#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include "car.h"
#include "report.h"

namespace Order_space {
    class Order;
}
class Order{
public:
    explicit Order();
    QString order_id;
    QString user_id;
    QString car_id;
    Car *rental_car;
    Report *order_report;
    int rental_date[3];
    int expire_date[3];
    void set_order(Car rental_car,int *rental_date, int *expire_date);
private:

};

#endif // ORDER_H
