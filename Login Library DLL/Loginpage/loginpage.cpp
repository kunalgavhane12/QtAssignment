#include "loginpage.h"
#include "ui_loginpage.h"
#include "loginlib.h"
#include <QMessageBox>

LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
{

    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}


void LoginPage::on_pushButton_login_clicked()
{
    LoginLib check;

    QString username, password;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(!check.isValidEmail(username))
    {
        QMessageBox::information(this, "login", "Invalid username");
        return;
    }

    if(!check.isValidPassword(password))
    {
        QMessageBox::information(this, "login", "Invalid password");
        return;
    }

    if(authenticate(username,password))
    {
        QMessageBox::information(this,"login", "Login Success");
    }
    else
    {
          QMessageBox::information(this,"login", "Login Failed");
    }


}

bool LoginPage::authenticate(const QString& username, const QString& password)
{

    QFile file_DB;
    file_DB.setFileName("D:/Qt Assignment/BankApp/user_credential.txt");

    if(!file_DB.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Login", "File not open");
        return false;
    }

    QTextStream in(&file_DB);

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList parts = line.split(" ");

        if(parts.size() == 2 && parts[0] == username && parts[1] == password)
        {
            file_DB.close();
            return true;
        }
    }

    file_DB.close();
    return false;

}

