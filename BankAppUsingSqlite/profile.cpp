#include "profile.h"
#include "ui_profile.h"

Profile::Profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);
}

Profile::~Profile()
{
    delete ui;
}



void Profile::on_pushButton_AccountDetails_clicked()
{
    Login conn;
    QSqlQueryModel *model = new QSqlQueryModel();

    conn.connectionOpen();

    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select accountnumber,name,email,balance from BankAccountDetails");
    qry->exec();

    model->setQuery(*qry);

    ui->tableView->setModel(model);

    conn.connectionClose();
    qDebug() << (model->rowCount());

}


void Profile::on_pushButton_Transfer_clicked()
{

}


void Profile::on_pushButton_Balance_clicked()
{
    Login conn;
    QSqlQueryModel *model = new QSqlQueryModel();

    conn.connectionOpen();

    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select Name,Balance from BankAccountDetails");
    qry->exec();

    model->setQuery(*qry);

    ui->tableView->setModel(model);

    conn.connectionClose();
    qDebug() << (model->rowCount());

}


void Profile::on_pushButton_Logout_clicked()
{
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this,"Logout","Do You Want to Logout?", QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        exit(0);
    }

}

