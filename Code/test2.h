#ifndef TEST2_H
#define TEST2_H

#include <QMainWindow>
#include <QString>
#include <person.h>

namespace Ui {
class Test2;
}

class Test2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Test2(QWidget *parent = nullptr);
    QString Login_Account;
    QString Login_Password;
    ~Test2();

private slots:
    void on_Login_Button_clicked();

    void on_Login_Account_textEdited(const QString &arg1);

    void on_Login_Password_textEdited(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::Test2 *ui;
    Person person;
};

#endif
