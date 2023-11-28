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
    qDebug() << "Name: " << name;
    qDebug() << "Account Number: " << accountNumber;

}

void profilePage::balanceEnquiry()
{
    qDebug() << "Balance: " << balance;
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
    float amount = 10.0;//take from user input

    if(balanceTransfer(amount))
    {
        qDebug() << "Transfer Successfully";
    }
    else
    {
        qDebug() << "Insufficient Balance, Transaction Failed";
    }
}


void profilePage::on_pushButton_Balance_clicked()
{
    balanceEnquiry();
}


void profilePage::on_pushButton_Logout_clicked()
{
    exit(0);
}

