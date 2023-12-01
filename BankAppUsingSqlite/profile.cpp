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

void Profile::on_pushButton_Details_clicked()
{

}


void Profile::on_pushButton_Transfer_clicked()
{

}


void Profile::on_pushButton_3_clicked()
{

}


void Profile::on_pushButton_Logout_clicked()
{

}

