#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1100, 700);   //fix screen size
    this->setWindowTitle("主畫面");
    upload_car_infor_w = new Test1(this);
    upload_car_infor_w->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete upload_car_infor_w;
}

void MainWindow::on_pushButton_clicked()
{
    upload_car_infor_w->show();
}
