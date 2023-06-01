#include "mainwindow.h"
#include "rental_car_system.h"
#include "database.h"
#include <QPixmap>
#include <QDebug>
#include <QString>

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

    rental_page = new Rental_Car(ui);
    rental_page_index = 0;

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
        customer = new Person();
        if(customer->is_rental_car){
            ui->stackedWidget->setCurrentIndex(5);
        }else{
            ui->stackedWidget->setCurrentIndex(2);
            car_array = rental_page->show_Rental_page(rental_page_index);
        }

    }
    else if(Account=="company" && Password=="password"){
        ui->stackedWidget->setCurrentIndex(6);
    }else{
         ui->Login_Message->setText("登入失敗 !!");
    }
}

void MainWindow::on_Upload_Car_Button_clicked()
{
    upload_car_infor_w->show();
}

void MainWindow::on_picture1_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    rental_car = car_array[0];
    QString img_qpath = rental_car.filePath;
    rental_page->show_Product_page(img_qpath);
}

void MainWindow::on_picture2_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    rental_car = car_array[1];
    QString img_qpath = rental_car.filePath;
    rental_page->show_Product_page(img_qpath);
}

void MainWindow::on_NextPageButton_clicked()
{
    if(rental_page_index == 4){

    }else{
        rental_page_index = rental_page_index +2;
        car_array = rental_page->show_Rental_page(rental_page_index);
    }
}

void MainWindow::on_PreviousPageButton_clicked()
{
    if(rental_page_index == 0){

    }else{
        rental_page_index = rental_page_index -2;
        car_array = rental_page->show_Rental_page(rental_page_index);
    }
}

void MainWindow::on_Return_RentalCar_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Order_Button_clicked()
{
    rental_order = new Order();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Return_Button_clicked()
{
    ui->Rental_Date_Year->setText("");
    ui->Rental_Date_Month->setText("");
    ui->Rental_Date_Date->setText("");
    ui->Expire_Date_Year->setText("");
    ui->Expire_Date_Month->setText("");
    ui->Expire_Date_Date->setText("");
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_decide_order_Button_clicked()
{
    rental_order->rental_car = rental_car;

    rental_order->rental_date[0] = ui->Rental_Date_Year->text().toInt();
    rental_order->rental_date[1] = ui->Rental_Date_Month->text().toInt();
    rental_order->rental_date[2] = ui->Rental_Date_Date->text().toInt();

    rental_order->expire_date[0] = ui->Expire_Date_Year->text().toInt();
    rental_order->expire_date[1] = ui->Expire_Date_Month->text().toInt();
    rental_order->expire_date[2] = ui->Expire_Date_Date->text().toInt();
    qDebug()<<"img : "<<rental_order->rental_car.filePath;
    qDebug()<<"Rental year= "<<rental_order->rental_date[0]<<" month= "<<rental_order->rental_date[1]<<" Date= "<<rental_order->rental_date[2];
    qDebug()<<"Expire year= "<<rental_order->expire_date[0]<<" month= "<<rental_order->expire_date[1]<<" Date= "<<rental_order->expire_date[2];

    customer->is_rental_car = true;
    ui->stackedWidget->setCurrentIndex(5);
    int width = ui->order_product_picture->width();
    int height = ui->product_picture->height();

    QPixmap image(rental_order->rental_car.filePath);
    image = image.scaled(width, height);
    ui->order_product_picture->setPixmap(image);
    ui->order_product_picture->show();

    QString rental_date = QString::number(rental_order->rental_date[0])+"-"+QString::number(rental_order->rental_date[1])+"-"+QString::number(rental_order->rental_date[2]);
    ui->label_25->setText(rental_date);
    QString expire_date = QString::number(rental_order->expire_date[0])+"-"+QString::number(rental_order->expire_date[1])+"-"+QString::number(rental_order->expire_date[2]);
    ui->label_27->setText(expire_date);
}

void MainWindow::on_Return_Car_Button_clicked()
{
    customer->is_rental_car = false;
    rental_page_index = 0;
    car_array = rental_page->show_Rental_page(rental_page_index);
    ui->stackedWidget->setCurrentIndex(2);
}
