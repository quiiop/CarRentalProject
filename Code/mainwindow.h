#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "test1.h"
#include "ui_mainwindow.h"
#include <string>
#include "car.h"
#include "order.h"
#include "person.h"
#include "report.h"

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
    void show_repair_report();
    void calculate_repair_report_pg();
    void clear_repair_report_pg();
    void show_repair_report_detail(Order *order);
    void clear_repair_report_detail_pg();
    bool check_Date_label_format(QString year, QString month, QString date);

    Test1 *upload_car_infor_w;
    QString Account;
    QString Password;
    Rental_Car *rental_page;
    int rental_page_index;
    Car *car_array;
    Car *all_car_array;
    Car rental_car;
    Order *rental_order;
    Person *customer;
    Person *sigin_customer;
    int repair_report_pg;
    int repair_report_index;
    int repair_report_remain_item;
    Order *order_array; // use test
    Order *process_order;
    QLabel *front_label[6];
    QPushButton *front_button[6];
    bool check_report_1;
    bool check_report_2;
    bool check_report_3;

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

    void on_SigIn_Button_clicked();

    void on_DecideSigin_Button_clicked();


    void on_SigIN_Account_lineEdit_textEdited(const QString &arg1);

    void on_SignIN_Password_lineEdit_2_textEdited(const QString &arg1);

    void on_SignIN_Name_lineEdit_3_textEdited(const QString &arg1);

    void on_SignIN_phone_lineEdit_4_textEdited(const QString &arg1);

    void on_SigIN_address_lineEdit_5_textEdited(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_customer_report_button_clicked();

    void on_company_Rapair_Report_Button_clicked();

    void on_repaire_report_last_pg_button_clicked();

    void on_repaire_report_next_pg_button_clicked();

    void on_repaire_report_button_1_clicked();

    void on_repaire_report_button_2_clicked();

    void on_repaire_report_button_3_clicked();

    void on_repaire_report_button_4_clicked();

    void on_repaire_report_button_5_clicked();

    void on_repaire_report_button_6_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_comboBox_4_currentIndexChanged(const QString &arg1);

    void on_Return_Report_Button_clicked();

protected:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
