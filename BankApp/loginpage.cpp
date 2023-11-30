#include "loginpage.h"
#include "ui_loginpage.h"

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


void LoginPage::on_pushButton_Login_clicked()
{
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(!isValidEmail(username))
    {
        QMessageBox::information(this, "Login", "Invalid UserName");
        return;
    }

    if(!isValidPassword(password))
    {
        QMessageBox::warning(this, "Login", "Password must have at least one digit,"
         " one lowercase, one uppercase, one special character and be at least 8 character long");
        return;
    }

    if(authenticate(username,password))
    {
        QMessageBox::information(this, "Login", "Login Success");
        hide();

        profilepage = new profilePage(this);
        profilepage->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Invalid username or password");
    }

}

bool LoginPage::isValidEmail(const QString& email)
{
    int index = email.indexOf('@');
    if(index == -1)
        return false;

    if(email.leftRef(index).isEmpty())
        return false;

    QString domainPart = email.mid(index + 1);
    QStringList domainParts = domainPart.split('.');

    if(domainPart.left(5).compare("gmail", Qt::CaseInsensitive) != 0
            && domainPart.left(5).compare("yahoo", Qt::CaseInsensitive) != 0
            && domainPart.left(10).compare("rediffmail", Qt::CaseInsensitive) !=0)
        return false;

    if (domainParts.size() < 2 || domainPart.right(4).compare(".com", Qt::CaseInsensitive) != 0
            && domainPart.right(3).compare(".in", Qt::CaseInsensitive) != 0)
        return false;

    return true;
}

bool LoginPage::isValidPassword(const QString& password)
{
    bool digit = false;
    bool lowercase = false;
    bool uppercase = false;
    bool specialchar = false;

    for(const QChar &ch: password)
    {
        if(ch.isDigit())
            digit = true;
        else if(ch.isLower())
            lowercase = true;
        else if(ch.isUpper())
            uppercase = true;
        else if(ch.isPunct() || ch.isSymbol())
            specialchar = true;
    }

    return (digit && lowercase && uppercase && specialchar && password.length() >=8);
}


bool LoginPage::authenticate(const QString& username, const QString& password)
{

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


void LoginPage::on_pushButton_Reset_clicked()
{
    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();
}


void LoginPage::on_pushButton_CreateAccount_clicked()
{

    file_DB.setFileName("D:/Qt Assignment/BankApp/user_credential.txt");

    if(!file_DB.open(QFile::WriteOnly | QFile::Append))
    {
        QMessageBox::information(this, "Form", "File not open");
        return;
    }

    QTextStream out(&file_DB);
    QString text = "\n" + ui->lineEdit_Email->text() + " " + ui->lineEdit_cspassword->text();
    out << text;

    file_DB.flush();
    file_DB.close();

    QMessageBox::information(this, "Form", "Account Created");

}

