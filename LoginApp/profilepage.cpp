#include "profilepage.h"
#include "ui_profilepage.h"
#include <QMessageBox>

ProfilePage::ProfilePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfilePage)
{
    ui->setupUi(this);


    LoginApp conn;
    if(!conn.connectionOpen())
    {
        ui->label_Profilepage_Status->setText("Failed to open the database");
    }
    else
    {
        ui->label_Profilepage_Status->setText("Connected..");
    }
}

ProfilePage::~ProfilePage()
{
    delete ui;
}

void ProfilePage::on_pushButton_save_clicked()
{
    LoginApp conn;

    QString name, surname,emailid, password;
    name = ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
    emailid = ui->lineEdit_email->text();
    password = ui->lineEdit_password->text();

    if(!conn.connectionOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    conn.connectionOpen();//this function open your connection only one time

    QSqlQuery qry;

    //insert
    qry.prepare("insert into user_pass (Username,Password) values ('"+emailid+"', '"+password+"')");

    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Save"),tr("Saved"));

        conn.connectionClose();//close the connection with databse when query exxute successfuly
    }
    else
    {
        QMessageBox::critical(this, tr("Error"),qry.lastError().text());
    }

}


void ProfilePage::on_pushButton_update_clicked()
{
    LoginApp conn;

    QString name, surname,emailid, password;
    name = ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
    emailid = ui->lineEdit_email->text();
    password = ui->lineEdit_password->text();

    if(!conn.connectionOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    conn.connectionOpen();//this function open your connection only one time

    QSqlQuery qry;

//update
    qry.prepare("update user_pass set Username='"+emailid+"',Password='"+password+"' where Username='"+emailid+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Edit"),tr("Updated"));

        conn.connectionClose();//close the connection with databse when query exxute successfuly
    }
    else
    {
        QMessageBox::critical(this, tr("Error"),qry.lastError().text());
    }

}


void ProfilePage::on_pushButton_delete_clicked()
{
    LoginApp conn;

    QString name, surname,emailid, password;
    name = ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
    emailid = ui->lineEdit_email->text();
    password = ui->lineEdit_password->text();

    if(!conn.connectionOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    conn.connectionOpen();//this function open your connection only one time

    QSqlQuery qry;

//Delete
    qry.prepare("Delete from user_pass where username='"+emailid+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Delete"),tr("Deleted"));

        conn.connectionClose();//close the connection with databse when query exxute successfuly
    }
    else
    {
        QMessageBox::critical(this, tr("Error"),qry.lastError().text());
    }

}

