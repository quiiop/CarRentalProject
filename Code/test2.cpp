#include "test2.h"
#include "ui_test2.h"
#include <QDebug>

Test2::Test2(QWidget *parent) : QMainWindow(parent)
{
    ui = new Ui::Test2;
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    this->setWindowTitle("登入");
}

void Test2::on_Login_Account_textEdited(const QString &arg1)
{
    Login_Account = arg1;
    qDebug() << "Login_Account：" << Login_Account;
}

void Test2::on_Login_Password_textEdited(const QString &arg1)
{
    Login_Password = arg1;
    qDebug() << "Login_Passord：" << Login_Password;
}


void Test2::on_Login_Button_clicked()
{
    if(Login_Account == "admin" && Login_Password == "password"){
        ui->stackedWidget->setCurrentIndex(1);
    }else{
        ui->stackedWidget->setCurrentIndex(2);
    }

}


Test2::~Test2()
{
    delete ui;
}















