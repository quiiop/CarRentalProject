#ifndef TEST1_H
#define TEST1_H

#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include "car.h"

namespace Ui {
class Test1;
}

class Test1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Test1(QWidget *parent = nullptr);
    ~Test1();
    void emitSignal_test(int);
    void slot_test(QLabel *label);
    int save_file(QString file_path);
    void Rental_car_info();
    void check_car_info();
    int check_label();
    int regex_label(QString str);

    Car car;

    QLineEdit *BrandLine;
    QString BrandInput;

    QLineEdit *KmLine;
    QString KmInput;

    QString MaxSeatLine;
    QString ModelLine;
    QString RentalPriceLine;
    QString CarStatus;

    QPushButton *SubmitButton;

    QString filePath;

signals:

private slots:

    void on_SubmitButton_clicked();

    void on_BrandLine_textEdited(const QString &arg1);

    void on_KmLine_textEdited(const QString &arg1);

    void on_submitPicture_clicked();

    void on_MaxSeatLine_textEdited(const QString &arg1);

    void on_ModelLine_textEdited(const QString &arg1);

    void on_RentalPriceLine_textEdited(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::Test1 *ui;
};

#endif // TEST1_H
