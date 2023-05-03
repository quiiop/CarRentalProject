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
    // db.saveData(car.get_BrandInput(), car.KmInput)
}

int Test1::regex_label(QString str){
    int r = 0;
    int len = str.length();
    for(int i=0; i<len; i++){
        if(i==0 && str[i]=='0'){
            qDebug()<<"err 92";
            return r;
        }
        if(str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'){
            qDebug()<<"err 96";
            continue;
        }else{
            return r;
        }
    }
    r = 1;
    return r;
}

int Test1::check_label(){
    int err =0;
    // BrandInput 檢查
    if(BrandInput == ""){
        ui->BrandError->setText("不可以空白");
        err++;
    }else{
        ui->BrandError->setText("");
    }

    // KInput 檢查
    if(KmInput == ""){
        ui->KmError->setText("不可以空白");
        err++;
    }else if (regex_label(KmInput)==0) {
        ui->KmError->setText("有錯誤");
        err++;
    }else{
        ui->KmError->setText("");
    }

    // MaxSeatLine 檢查
    if(MaxSeatLine == ""){
        ui->MaxSeatsError->setText("不可以空白");
        err++;
    }else if(regex_label(MaxSeatLine)==0){
        ui->MaxSeatsError->setText("有錯誤");
        err++;
    }else{
        ui->MaxSeatsError->setText("");
    }

    // ModelLine 檢查
    if(ModelLine == ""){
        ui->ModelError->setText("不可以空白");
        err++;
    }else{
        ui->ModelError->setText("");
    }

    // RentalPriceLine 檢查
    if(RentalPriceLine == ""){
        ui->PriceError->setText("不可以空白");
        err++;
    }else if(regex_label(RentalPriceLine) == 0){
        ui->PriceError->setText("有錯誤");
        err++;
    }else{
        ui->PriceError->setText("");
    }

    // CarStatus 檢查
    if(CarStatus == ""){
        ui->StatusError->setText("不可以空白");
        err++;
    }else{
        ui->StatusError->setText("");
    }

    // filePath 檢查
    if(filePath == ""){
        ui->ImageError->setText("不可以空白");
        err++;
    }else{
        ui->ImageError->setText("");
    }

    if (err>0){
        return 0;
    }else{
        return 1;
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
    // qDebug()<<__cplusplus;
    int  r1 = check_label();
    qDebug()<<"Brand Line "<<BrandInput;
    qDebug()<<"Km Line "<<KmInput;
    qDebug()<<"MaxSeatLine Line "<<MaxSeatLine;
    qDebug()<<"ModelLine Line "<<ModelLine;
    qDebug()<<"Car Status "<<CarStatus;
    qDebug()<<"RentalPriceLine Line "<<RentalPriceLine;
    QLabel *message = ui->message;
    int r2 = save_file(filePath);
    qDebug()<<"r1 = "<<r1<<" r2 = "<<r2;
    // int r3 = Add(car.get_BrandInput(), car.KmInput, car.MaxSeatLine, car.ModelLine, car.CarStatus, car.RentalPriceLine);
    if (r1==1 && r2==1){ // add && r3==1
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

