#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "test1.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Test1 *upload_car_infor_w;
    QString Account;
    QString Password;

private slots:
    void on_Account_lineEdit_textEdited(const QString &arg1);

    void on_Password_lineEdit_textEdited(const QString &arg1);

    void on_Login_Button_clicked();

    void on_Upload_Car_Button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
