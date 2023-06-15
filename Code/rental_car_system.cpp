#include "rental_car_system.h"
#include <QDebug>
#include "database.h"
#include <QPixmap>
#include "mainwindow.h"
#include <iostream>
#include <string>

Rental_Car::Rental_Car(Ui::MainWindow *ui){
    mainwindow_ui = ui;
}

Car* Rental_Car::show_Rental_page(int rental_page_index)
{
    Database db;
    QStringList brandList= db.getCarBrandInfo();
    int width = mainwindow_ui->picture1->height();
    int height = mainwindow_ui->picture1->height();
    std::string path = "C:/Users/CSS_Tim/Desktop/OOAD/CarRentalProject/image/";
    std::string temp[] = {"car.jpg", "car2.jpg", "car3.jpg", "car4.jpg", "car5.jpg", "car6.jpg"};
    std::string brand[] = {"TOYOTA","HONDA","NISSAN","NISSAN","NISSAN","NISSAN"};
    std::string model[] = {"Wish","CR-V","TIIDA","SENTRA","ALTIMA","X-TRAIL"};
    std::string kilomenter[] = {"5000","4820","5513","3654","5420","4251"};
    std::string maxSeat[] = {"7","5","5","5","5","5"};
    std::string rentalPrice[] = {"5000","4800","5500","3500","5500","4200"};
    std::string img1_path = path + temp[rental_page_index];
    std::string img2_path = path + temp[rental_page_index+1];
    QString brandStr1 = QString::fromStdString(brand[rental_page_index]);
    QString kilomenterStr1 = QString::fromStdString(kilomenter[rental_page_index]);
    QString maxSeatStr1 = QString::fromStdString(maxSeat[rental_page_index]);
    QString modelStr1 = QString::fromStdString(model[rental_page_index]);
    QString rentalPricelStr1 = QString::fromStdString(rentalPrice[rental_page_index]);
    QString brandStr2 = QString::fromStdString(brand[rental_page_index+1]);
    QString kilomenterStr2 = QString::fromStdString(kilomenter[rental_page_index+1]);
    QString maxSeatStr2 = QString::fromStdString(maxSeat[rental_page_index+1]);
    QString modelStr2 = QString::fromStdString(model[rental_page_index+1]);
    QString rentalPricelStr2 = QString::fromStdString(rentalPrice[rental_page_index+1]);
    QString img1_qpath = QString::fromStdString(img1_path);
    QString img2_qpath = QString::fromStdString(img2_path);
    qDebug()<<"brandStr1";
    qDebug()<<brandStr1;
    mainwindow_ui->label_7->setText(modelStr1);
    mainwindow_ui->label_8->setText(rentalPricelStr1);
    mainwindow_ui->label_9->setText(modelStr2);
    mainwindow_ui->label_10->setText(rentalPricelStr2);
    Car *car_array = new Car[2];
    int carid1 = rental_page_index+1;
    int carid2 = rental_page_index+2;
    car_array[0].car_id = QString::number(carid1);
    car_array[0].BrandInput = brandStr1;
    car_array[0].KmInput = kilomenterStr1;
    car_array[0].ModelLine = modelStr1;
    car_array[0].RentalPriceLine = rentalPricelStr1;
    car_array[0].MaxSeatLine = maxSeatStr1;
    car_array[0].filePath = img1_qpath;
    car_array[1].car_id = QString::number(carid2);
    car_array[1].BrandInput = brandStr2;
    car_array[1].KmInput = kilomenterStr2;
    car_array[1].ModelLine = modelStr2;
    car_array[1].RentalPriceLine = rentalPricelStr2;
    car_array[1].MaxSeatLine = maxSeatStr2;
    car_array[1].filePath = img2_qpath;

    QPixmap image(img1_qpath);
    image = image.scaled(width, height);
    mainwindow_ui->picture1->setPixmap(image);
    mainwindow_ui->picture1->show();

    QPixmap image2(img2_qpath);
    image2 = image2.scaled(width, height);
    mainwindow_ui->picture2->setPixmap(image2);
    mainwindow_ui->picture2->show();

    return car_array;
}

void Rental_Car::show_Product_page(QString img_qpath)
{
    int width = mainwindow_ui->product_picture->width();
    int height = mainwindow_ui->product_picture->height();

    QPixmap image(img_qpath);
    image = image.scaled(width, height);
    mainwindow_ui->product_picture->setPixmap(image);
    mainwindow_ui->product_picture->show();
}
