#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("主畫面");
    this->setFixedSize(1217, 747);
    ui->stackedWidget->setCurrentIndex(0); // Login Page

    upload_car_infor_w = new Test1(this);
    upload_car_infor_w->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete upload_car_infor_w;
}

void MainWindow::on_Account_lineEdit_textEdited(const QString &arg1)
{
    Account = arg1;
}

void MainWindow::on_Password_lineEdit_textEdited(const QString &arg1)
{
    Password = arg1;
}

void MainWindow::on_Login_Button_clicked()
{
    if(Account=="customer" && Password=="password"){
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if(Account=="company" && Password=="password"){
        ui->stackedWidget->setCurrentIndex(3);
    }else{
         ui->Login_Message->setText("登入失敗 !!");
    }
}

void MainWindow::on_Upload_Car_Button_clicked()
{
    upload_car_infor_w->show();
}
