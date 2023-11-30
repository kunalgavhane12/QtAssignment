#include "profilepage.h"
#include "ui_profilepage.h"

#include <QDebug>

int profilePage::count = 0;

profilePage::profilePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profilePage)
{
    ui->setupUi(this);
}

profilePage::~profilePage()
{
    delete ui;
}

void profilePage::accountDetails()
{
    ui->lineEdit->setText("Name : Kunal Gavhane");
    ui->lineEdit_2->setText("Account Number: " + QString::number(accountNumber));

//    qDebug() << "Name: " << name;
//    qDebug() << "Account Number: " << accountNumber;

}

void profilePage::deposit(float amount)
{
    balance += amount;
    ui->lineEdit->setText("Balance : ");
    ui->lineEdit_2->setText(QString::number(balance));

}

void profilePage::balanceEnquiry()
{
    ui->lineEdit->setText("Name : Kunal Gavhane");
    ui->lineEdit_2->setText("Account Balance : " + QString::number(balance));

    //qDebug() << "Balance: " << balance;
}

void profilePage::on_pushButton_account_clicked()
{
    accountDetails();
}

bool profilePage::balanceTransfer(float amt)
{
    if(balance < amt)
    {
        return false;
    }
    else
    {
        balance -= amt;
        return true;
    }

}


void profilePage::on_pushButton_Transfer_clicked()
{
    ui->lineEdit->setText("Enter Transfer Amount:");
    ui->lineEdit_2->clear();

//    QPushButton *btn = (QPushButton*) sender();
//    QString number = btn->text();

    float amount = 0.0;//take from user input

    if(balanceTransfer(amount))
    {
        ui->lineEdit->setText("Transfer Successful");
     //   qDebug() << "Transfer Successful";
    }
    else
    {
        ui->lineEdit->setText("Insufficient Balance, Transaction Failed");
       // qDebug() << "Insufficient Balance, Transaction Failed";
    }
}


void profilePage::on_pushButton_Balance_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    balanceEnquiry();
}


void profilePage::on_pushButton_Logout_clicked()
{
    exit(0);
}


void profilePage::on_pushButton_Deposit_clicked()
{
    deposit(1000);
}

