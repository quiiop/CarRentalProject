#include "test1.h"
#include "ui_test1.h"
#include <QDebug>
#include <QString>
#include <QFileDialog>


Test1::Test1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Test1)
{
    ui->setupUi(this);
    this->setFixedSize(1100, 700);   //fix screen size
    this->setWindowTitle("上傳車輛資訊");
}

void Test1::on_BrandLine_textEdited(const QString &arg1)
{
    BrandInput = arg1;
}

void Test1::on_KmLine_textEdited(const QString &arg1)
{
    KmInput = arg1;
}

void Test1::on_MaxSeatLine_textEdited(const QString &arg1)
{
    MaxSeatLine = arg1;
}

void Test1::on_ModelLine_textEdited(const QString &arg1)
{
    ModelLine = arg1;
}

void Test1::on_RentalPriceLine_textEdited(const QString &arg1)
{
    RentalPriceLine = arg1;
}

void Test1::on_comboBox_currentIndexChanged(const QString &arg1)
{
    CarStatus = arg1;
}

void Test1::on_submitPicture_clicked()
{
       QFileDialog fileDialog;
       fileDialog.setWindowTitle("開啟檔案");
       fileDialog.setDirectory("C:\\");
       fileDialog.setNameFilter("圖片 (*.png *.jpg *.bmp)");
       fileDialog.setFileMode(QFileDialog::ExistingFile);
       filePath = fileDialog.getOpenFileName();
       qDebug() << "所選擇的檔案為：" << filePath;

       QLabel *pictureLabel = ui->pictureLabel;
       pictureLabel->setText(filePath);
}

int Test1::save_file(QString filePath){
    int r = 0;
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly)) {
            QString newFilePath = "D:/Qt project/Test1/image/"+file.fileName().split('/').last();
            QFile newFile(newFilePath);
            if (newFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Unbuffered)) {
                QDataStream out(&newFile);
                out.setByteOrder(QDataStream::LittleEndian);
                out.writeRawData(file.readAll().constData(), file.size());
                newFile.close();
                qDebug() << "儲存檔案成功：" << newFilePath;
            }
            file.close();
        }
        r = 1;
    }
    return r;
}

void Test1::Rental_car_info(){
    car.set_car(BrandInput, KmInput, ModelLine, CarStatus, MaxSeatLine, RentalPriceLine, filePath);
    // check_car_info();
}

void Test1::check_label(){
    if(BrandInput == ""){
        ui->BrandError->setText("不可以空白");
    }else{
        ui->BrandError->setText("");
    }

    if(KmInput == ""){
        ui->KmError->setText("不可以空白");
    }else{
        ui->KmError->setText("");
    }

    if(MaxSeatLine == ""){
        ui->MaxSeatsError->setText("不可以空白");
    }else{
        ui->MaxSeatsError->setText("");
    }

    if(ModelLine == ""){
        ui->ModelError->setText("不可以空白");
    }else{
        ui->ModelError->setText("");
    }

    if(RentalPriceLine == ""){
        ui->PriceError->setText("不可以空白");
    }else{
        ui->PriceError->setText("");
    }

    if(CarStatus == ""){
        ui->StatusError->setText("不可以空白");
    }else{
        ui->StatusError->setText("");
    }

    if(filePath == ""){
        ui->ImageError->setText("不可以空白");
    }else{
        ui->ImageError->setText("");
    }
};


void Test1::check_car_info(){
    qDebug()<<"Car Check !!";
    qDebug()<<"Brand Line "<<car.get_BrandInput();
    qDebug()<<"Km Line "<<car.KmInput;
    qDebug()<<"MaxSeatLine Line "<<car.MaxSeatLine;
    qDebug()<<"ModelLine Line "<<car.ModelLine;
    qDebug()<<"Car Status "<<car.CarStatus;
    qDebug()<<"RentalPriceLine Line "<<car.RentalPriceLine;
}



void Test1::on_SubmitButton_clicked()
{
    check_label();
    qDebug()<<"Brand Line "<<BrandInput;
    qDebug()<<"Km Line "<<KmInput;
    qDebug()<<"MaxSeatLine Line "<<MaxSeatLine;
    qDebug()<<"ModelLine Line "<<ModelLine;
    qDebug()<<"Car Status "<<CarStatus;
    qDebug()<<"RentalPriceLine Line "<<RentalPriceLine;
    QLabel *message = ui->message;

    int r = save_file(filePath);
    if (r==1){
       Rental_car_info();
       message->setText("上傳成功");
    }else{
        message->setText("上傳失敗");
    }

}

Test1::~Test1()
{
    delete ui;
}

