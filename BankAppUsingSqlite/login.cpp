#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    if(!connectionOpen())
    {
        ui->label_Status->setText("Failed to open database");
    }
    else
    {
        ui->label_Status->setText("Connected...");
    }
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_Login_clicked()
{
    QString username, password;
    username = ui->lineEdit_Username->text();
    password = ui->lineEdit_Password->text();

    if(!connectionOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    connectionOpen();//this function open your connection only one time

    QSqlQuery qry;

    if(!isValidEmail(username))
    {
        QMessageBox::information(this, "Login", "Invalid Username");
        return;
    }

    if(!isValidPassword(password))
    {
        QMessageBox::warning(this, "Login", "Password must have at least one digit,"
             " one lowercase, one uppercase, one special character and be at least 8 character long");
        return;
    }

    //finding
    qry.prepare("select * from AccountDetails where Username ='"+username+"' and Password='"+password+"'");

    if(qry.exec())
    {
        int count=0;

        while(qry.next())
        {
            count++;
        }
        if(count == 1)
        {
            ui->label_Status->setText("username and password is correct");

            connectionClose();//this function close your database connection after login success.

            this->hide();
            Profile profilepage;
            profilepage.setModal(true);
            profilepage.exec();
        }
        if(count > 1)
            ui->label_Status->setText("Duplicate username and password");
        if(count < 1)
            ui->label_Status->setText("username and password is not correct");
    }

}

bool Login::isValidEmail(const QString& username)
{
    int index = username.indexOf('@');
    if(index == -1)
        return false;

    if(username.leftRef(index).isEmpty())
        return false;

    QString domainPart = username.mid(index+1);
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

bool Login::isValidPassword(const QString& password)
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


void Login::on_pushButton_CreateAccount_clicked()
{
    QString name, surname, email, deposit_amount, username, password;

    name = ui->lineEdit_name->text();
    surname = ui->label_Surname->text();
    email = ui->lineEdit_Email->text();
    deposit_amount = ui->lineEdit_deposit->text();
    username = ui->lineEdit_Email->text();
    password = ui->lineEdit_fpassword->text();

    QSqlQuery qry;

   qry.prepare("insert into AccountDetails (Name, Surname, Email, Deposit, Username,Password)"
               " values ('"+name+"', '"+surname+"','"+email+"','"+deposit_amount+"','"+username+"','"+password+"')");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Submit"),tr("Account Created"));
        connectionClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }

}

