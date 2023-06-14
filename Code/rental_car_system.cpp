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
    int width = mainwindow_ui->picture1->height();
    int height = mainwindow_ui->picture1->height();

    std::string path = "D:/QtProject/CarRentalProject/image/";
    std::string temp[] = {"car.png", "car2.jpg", "car3.jpg", "car4.jpg", "car5.jpg", "car6.jpg"};
    std::string img1_path = path + temp[rental_page_index];
    std::string img2_path = path + temp[rental_page_index+1];
    QString img1_qpath = QString::fromStdString(img1_path);
    QString img2_qpath = QString::fromStdString(img2_path);



    Car *car_array = new Car[2];
//    car_array[0].KmInput
    car_array[0].filePath = img1_qpath;
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
