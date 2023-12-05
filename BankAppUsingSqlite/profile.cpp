#include "profile.h"
#include "ui_profile.h"
#include "transfer.h"

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
    //open new windows ask account no amount create amount user input account no and debit amount current user

    Transfer *transfer;
    transfer = new Transfer(this);
    transfer->show();
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
    Login conn;
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this,"Logout","Do You Want to Logout?", QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        conn.connectionClose();
        exit(0);
    }

}

