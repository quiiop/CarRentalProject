#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "test1.h"
#include "ui_mainwindow.h"
#include <string>
#include "car.h"
#include "order.h"
#include "person.h"

class Rental_Car;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Test1 *upload_car_infor_w;
    QString Account;
    QString Password;
    Rental_Car *rental_page;
    int rental_page_index;
    Car *car_array;
    Car rental_car;
    Order *rental_order;
    Person *customer;

private slots:
    void on_Account_lineEdit_textEdited(const QString &arg1);

    void on_Password_lineEdit_textEdited(const QString &arg1);

    void on_Login_Button_clicked();

    void on_Upload_Car_Button_clicked();

    void on_picture1_Button_clicked();

    void on_NextPageButton_clicked();

    void on_PreviousPageButton_clicked();

    void on_Return_RentalCar_Button_clicked();

    void on_picture2_Button_clicked();

    void on_Order_Button_clicked();

    void on_Return_Button_clicked();

    void on_decide_order_Button_clicked();

    void on_Return_Car_Button_clicked();

protected:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
