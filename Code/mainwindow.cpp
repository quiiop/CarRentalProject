#include "mainwindow.h"
#include "rental_car_system.h"
#include "database.h"
#include <QPixmap>
#include <QDebug>
#include <QString>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("主畫面");
    this->setFixedSize(1217, 747);

    upload_car_infor_w = new Test1(this);
    upload_car_infor_w->hide();

    rental_page = new Rental_Car(ui);
    rental_page_index = 0;
    repair_report_pg = 0;
    repair_report_index = 0;
    repair_report_remain_item = 0;
    check_report_1 = false;
    check_report_2 = false;
    check_report_3 = false;

    // Login
    ui->stackedWidget->setCurrentIndex(0); // Login Page
    int width = ui->Login_cover->width();
    int height = ui->Login_cover->height();
    QPixmap image("D:/QtProject/CarRentalProject/image/cover.jpg");
    image = image.scaled(width, height);
    ui->Login_cover->setPixmap(image);
    ui->Login_cover->show();
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
        ui->stackedWidget->setCurrentIndex(7);
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
    ui->stackedWidget->setCurrentIndex(5);
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
    rental_order->rental_car = &rental_car;

    rental_order->rental_date[0] = ui->Rental_Date_Year->text().toInt();
    rental_order->rental_date[1] = ui->Rental_Date_Month->text().toInt();
    rental_order->rental_date[2] = ui->Rental_Date_Date->text().toInt();

    rental_order->expire_date[0] = ui->Expire_Date_Year->text().toInt();
    rental_order->expire_date[1] = ui->Expire_Date_Month->text().toInt();
    rental_order->expire_date[2] = ui->Expire_Date_Date->text().toInt();

    qDebug()<<"img : "<<rental_order->rental_car->filePath;
    qDebug()<<"Rental year= "<<rental_order->rental_date[0]<<" month= "<<rental_order->rental_date[1]<<" Date= "<<rental_order->rental_date[2];
    qDebug()<<"Expire year= "<<rental_order->expire_date[0]<<" month= "<<rental_order->expire_date[1]<<" Date= "<<rental_order->expire_date[2];
    /*save order*/
    rental_order->car_id = rental_car.car_id;
    rental_order->user_id = customer->user_id;
    rental_order->order_id = "";
    /*
    這裡要儲存客戶的order
    rental_order->car_id
    rental_order->user_id
    rental_order->order_id (DataBase自動產生)
    */
    
    /*save customer*/
    customer->is_rental_car = true;
    /*
    這裡要存customer的資料
    customer->is_rental_car
    */
    ui->stackedWidget->setCurrentIndex(5);
    int width = ui->order_product_picture->width();
    int height = ui->product_picture->height();

    QPixmap image(rental_order->rental_car->filePath);
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
    /*
    這裡要存customer的資料
    customer->is_rental_car
    */
    rental_page_index = 0;
    car_array = rental_page->show_Rental_page(rental_page_index);
    /* create report */
    rental_order->order_report = new Report();
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_SigIn_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    sigin_customer = new Person();
}

void MainWindow::on_SigIN_Account_lineEdit_textEdited(const QString &arg1)
{
    sigin_customer->Account = arg1;
}


void MainWindow::on_SignIN_Password_lineEdit_2_textEdited(const QString &arg1)
{
    sigin_customer->Password = arg1;
}

void MainWindow::on_SignIN_Name_lineEdit_3_textEdited(const QString &arg1)
{
    sigin_customer->Name = arg1;
}

void MainWindow::on_SignIN_phone_lineEdit_4_textEdited(const QString &arg1)
{
    sigin_customer->phone = arg1;
}

void MainWindow::on_SigIN_address_lineEdit_5_textEdited(const QString &arg1)
{
    sigin_customer->address = arg1;
}

void MainWindow::on_DecideSigin_Button_clicked()
{
    Database db;
    // save object sign_customer
    /*
    存sign_customer
    sigin_customer->Name
    sigin_customer->phone
    sigin_customer->Account
    sigin_customer->Password
    sigin_customer->address
    sigin_customer->user_id (DataBase自動產生)
    sigin_customer->is_rental_car (預設為false)
    */
    if(db.checkAccount("test")){
        db.signUp("test","test","test","1234567890","test");
        qDebug()<<"Success";
        ui->stackedWidget->setCurrentIndex(0);
    }else{
        qDebug()<<"Fail Account重複!!";
        ui->error_message->setText("重複的Account! 請重新輸入!");
    }

}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    //qDebug()<<"test "<<arg1;
    rental_order->order_report->Evaluation = arg1;
}

void MainWindow::on_customer_report_button_clicked()
{
    /* save report */
    /*
     存report資料
     rental_order->order_report->Evaluation;
     */
    ui->stackedWidget->setCurrentIndex(2);
}

/* company page */

void MainWindow::on_company_Rapair_Report_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    calculate_repair_report_pg();
    show_repair_report();
}

void MainWindow::calculate_repair_report_pg(){
    /*test order*/
    int total_order = 13;
    order_array = new Order[total_order];
    /*
    這裡要改成從DataBase調出資料，存到order_array
    */
    
    QString BrandInput = "Toyota";
    for(int i=0; i<total_order; i++){
        order_array[i].car_id = "Test_car"+QString::number(i);
        order_array[i].user_id = "Test_user"+QString::number(i);
        order_array[i].order_id = "Test_oder"+QString::number(i);
        order_array[i].rental_date[0] = i;
        order_array[i].rental_date[1] = 10+i;
        order_array[i].rental_date[2] = 20+i;
        order_array[i].expire_date[0] = i;
        order_array[i].expire_date[1] = 100+i;
        order_array[i].expire_date[2] = 200+i;
        order_array[i].order_report = new Report();
        order_array[i].order_report->car_id = order_array[i].car_id;
        order_array[i].order_report->user_id = order_array[i].user_id;
        order_array[i].order_report->order_id = order_array[i].order_id;
        order_array[i].rental_car = new Car();
        order_array[i].rental_car->ModelLine = "Model "+QString::number(i);
    }


    if(total_order%6==0){
        repair_report_pg = total_order / 6;
        repair_report_remain_item = 0;
    }else{
        if(total_order/6==0){
            repair_report_pg = 1;
        }else{
            repair_report_pg = (total_order / 6)+1;
        }
        repair_report_remain_item = total_order%6;
    }
    qDebug()<<"repair_report_pg = "<<repair_report_pg;
    qDebug()<<"remain_item = "<<repair_report_remain_item;
}

void MainWindow::show_repair_report(){
    /*show content on frontEnd*/
    front_label[0] = ui->repaire_report_label_1;
    front_button[0] = ui->repaire_report_button_1;

    front_label[1] = ui->repaire_report_label_2;
    front_button[1] = ui->repaire_report_button_2;

    front_label[2] = ui->repaire_report_label_3;
    front_button[2] = ui->repaire_report_button_3;

    front_label[3] = ui->repaire_report_label_4;
    front_button[3] = ui->repaire_report_button_4;

    front_label[4] = ui->repaire_report_label_5;
    front_button[4] = ui->repaire_report_button_5;

    front_label[5] = ui->repaire_report_label_6;
    front_button[5] = ui->repaire_report_button_6;

    if(repair_report_index==repair_report_pg-1 && repair_report_remain_item != 0){
        int temp_index = 0;
        qDebug()<<"290 repair_report_index = "<<repair_report_index;
        for(int j=repair_report_index*6; j<(repair_report_index*6+repair_report_remain_item); j++){
            qDebug()<<"j = "<<j;
            front_label[temp_index]->setText( order_array[j].rental_car->ModelLine );
            front_button[temp_index]->setVisible(true);
            temp_index = temp_index+1;
        }
        for(int j=repair_report_remain_item; j<6; j++){
            front_label[j]->setText( "尚無資料" );
            front_button[j]->setVisible(false);
        }
    }else{
        qDebug()<<"299 repair_report_index = "<<repair_report_index;
        front_label[0]->setText( order_array[repair_report_index*6].rental_car->ModelLine );
        front_button[0]->setVisible(true);

        front_label[1]->setText( order_array[repair_report_index*6+1].rental_car->ModelLine );
        front_button[1]->setVisible(true);

        front_label[2]->setText( order_array[repair_report_index*6+2].rental_car->ModelLine );
        front_button[2]->setVisible(true);

        front_label[3]->setText( order_array[repair_report_index*6+3].rental_car->ModelLine );
        front_button[3]->setVisible(true);

        front_label[4]->setText( order_array[repair_report_index*6+4].rental_car->ModelLine );
        front_button[4]->setVisible(true);

        front_label[5]->setText( order_array[repair_report_index*6+5].rental_car->ModelLine );
        front_button[5]->setVisible(true);
    }
}

void MainWindow::clear_repair_report_pg(){
    front_label[0]->setText(" ");
    front_button[0]->setVisible(false);

    front_label[1]->setText(" ");
    front_button[1]->setVisible(false);

    front_label[2]->setText(" ");
    front_button[2]->setVisible(false);

    front_label[3]->setText(" ");
    front_button[3]->setVisible(false);

    front_label[4]->setText(" ");
    front_button[4]->setVisible(false);

    front_label[5]->setText(" ");
    front_button[5]->setVisible(false);
}

void MainWindow::on_repaire_report_last_pg_button_clicked()
{
    if(repair_report_index >0){
        repair_report_index = repair_report_index -1;
        clear_repair_report_pg();
        show_repair_report();
    }
}

void MainWindow::on_repaire_report_next_pg_button_clicked()
{
    if(repair_report_index < repair_report_pg-1){
        repair_report_index = repair_report_index +1;
        clear_repair_report_pg();
        show_repair_report();
    }
}

void MainWindow::show_repair_report_detail(Order *order){
    process_order = order;
    ui->repair_report_detail_user_id->setText("User_id = "+order->user_id);
    ui->repair_report_detail_car_id->setText("Car_id = "+order->car_id);
    ui->repair_report_detail_order_id->setText("Order_id = "+order->order_id);
    ui->repair_report_detail_ExpireDate->setText("Expire_Date = "+QString::number(order->expire_date[0])+"-"+QString::number(order->expire_date[1])+"-"+QString::number(order->expire_date[2]));
    ui->repair_report_detail_RentalDate->setText("Rental_Date = "+QString::number(order->rental_date[0])+"-"+QString::number(order->rental_date[1])+"-"+QString::number(order->rental_date[2]));
}

void MainWindow::on_repaire_report_button_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    show_repair_report_detail(&order_array[0]);
}

void MainWindow::on_repaire_report_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    show_repair_report_detail(&order_array[1]);
}

void MainWindow::on_repaire_report_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    show_repair_report_detail(&order_array[2]);
}

void MainWindow::on_repaire_report_button_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    show_repair_report_detail(&order_array[3]);
}

void MainWindow::on_repaire_report_button_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    show_repair_report_detail(&order_array[4]);
}

void MainWindow::on_repaire_report_button_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    show_repair_report_detail(&order_array[5]);
}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    if(arg1=="選擇" || arg1==""){
        ui->battery_err_msg_label->setText("error 請選擇 !");
        check_report_1 = false;
    }else if (arg1=="良好") {
        process_order->order_report->battery = true;
        ui->battery_err_msg_label->setText(" ");
        check_report_1 = true;
    }else {
        process_order->order_report->battery = false;
        ui->battery_err_msg_label->setText(" ");
        check_report_1 = true;
    }
}

void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    if(arg1=="選擇" || arg1==""){
        ui->engine_err_msg_label->setText("error 請選擇 !");
        check_report_2 = false;
    }else if (arg1=="良好") {
        process_order->order_report->engine = true;
        ui->engine_err_msg_label->setText(" ");
        check_report_2 = true;
        qDebug()<<"model "<<process_order->car_id<<" engine status true";
    }else {
        process_order->order_report->engine = false;
        ui->engine_err_msg_label->setText(" ");
        check_report_2 = true;
        qDebug()<<"model "<<process_order->car_id<<" engine status false";
    }
}

void MainWindow::on_comboBox_4_currentIndexChanged(const QString &arg1)
{
    if(arg1=="選擇" || arg1==""){
        ui->tire_err_msg_label->setText("error 請選擇 !");
        check_report_3 = false;
    }else if (arg1=="良好") {
        process_order->order_report->tire = true;
        check_report_3 = true;
        ui->tire_err_msg_label->setText(" ");
    }else {
        process_order->order_report->tire = false;
        check_report_3 = true;
        ui->tire_err_msg_label->setText(" ");
    }
}

void MainWindow::clear_repair_report_detail_pg()
{
    ui->Return_Report_err_msg_label->setText(" ");
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->comboBox_4->setCurrentIndex(0);
    ui->battery_err_msg_label->setText(" ");
    ui->engine_err_msg_label->setText(" ");
    ui->tire_err_msg_label->setText(" ");
    check_report_1 = false;
    check_report_2 = false;
    check_report_3 = false;
    repair_report_index = 0;
}

void MainWindow::on_Return_Report_Button_clicked()
{
    if(!check_report_1 || !check_report_2 || !check_report_3){
        ui->Return_Report_err_msg_label->setText("尚有資料未選擇 !");
    }else{
        /*
        這裡要把repaire report寫入dataBase
        process_order->order_report->battery
        process_order->order_report->engine
        process_order->order_report->tire
        */
        clear_repair_report_detail_pg();
        ui->stackedWidget->setCurrentIndex(8);
        clear_repair_report_pg();
        show_repair_report();
    }
}
