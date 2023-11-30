#include "loginapp.h"
#include "ui_loginapp.h"

LoginApp::LoginApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginApp)
{
    ui->setupUi(this);

//    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");

//    mydb = QSqlDatabase::addDatabase("QSQLITE");

//    mydb.setDatabaseName("D:/qt practice program/QtPractice/Sql application/LoginApp/user_credentials.db");

//    if(!mydb.open())
    if(!connectionOpen())
    {
        ui->label_status->setText("Failed to open the database");
    }
    else
    {
        ui->label_status->setText("Connected..");
    }


}

LoginApp::~LoginApp()
{
    delete ui;
}


void LoginApp::on_Login_clicked()
{
    QString username, password;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

 //   if(!mydb.isOpen())
    if(!connectionOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    connectionOpen();//this function open your connection only one time

    QSqlQuery qry;

    //finding
    qry.prepare("select * from USER_PASS where Username ='"+username+"' and Password='"+password+"'");

    if(qry.exec())
    {
        int count=0;

        while(qry.next())
        {
            count++;
        }

        if(count == 1)
        {
            ui->label_status->setText("username and password is correct");

            connectionClose();//this function close your database connection after login success.

            this->hide();
            ProfilePage profilepage;
            profilepage.setModal(true);
            profilepage.exec();

        }
        if(count > 1)
            ui->label_status->setText("Duplicate username and password");
        if(count < 1)
            ui->label_status->setText("username and password is not correct");
    }


}

