#ifndef RENTAL_CAR_SYSTEM_H
#define RENTAL_CAR_SYSTEM_H
#include <QString>
#include <string>
#include "car.h"

namespace Ui {
    class MainWindow;
}

namespace Rental_Car_space {
    class Rental_Car;
}

class Rental_Car{
public:
    explicit Rental_Car(Ui::MainWindow *ui);
    Car* show_Rental_page(int rental_page_index);
    void show_Product_page(QString img_qpath);
    Ui::MainWindow *mainwindow_ui;
private:
};

#endif // RENTAL_CAR_SYSTEM_H
