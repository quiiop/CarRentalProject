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
    this->setWindowTitle("Sign up");
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

void Test1::on_SubmitButton_clicked()
{
    qDebug()<<"Brand Line "<<BrandInput;
    qDebug()<<"Km Line "<<KmInput;
    qDebug()<<"MaxSeatLine Line "<<MaxSeatLine;
    qDebug()<<"ModelLine Line "<<ModelLine;
    qDebug()<<"Car Status "<<CarStatus;
    qDebug()<<"RentalPriceLine Line "<<RentalPriceLine;
    QLabel *message = ui->message;

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
    }

    message->setText("上傳成功");
}

Test1::~Test1()
{
    delete ui;
}

/*
void Test1::slot_test(QLabel *label){
    static bool key = true;
    if (key){
        label->setText("welcome");
    }else{
        label->setText("歡迎");
    }
    key = !key;
}

void Test1::on_pushButton_clicked()
{
    QLabel *TestLabel;
    TestLabel = ui->
    slot_test(TestLabel);
}

void Test1::on_lineEdit_returnPressed()
{
    QString input = lineEdit->text();
    qDebug()<<"line edit "<<input;
    lineEdit->clear();
}
*/
