#include "login.h"
#include "ui_login.h"

int Login::Count = 0;

bool USE_DB = true;
bool USE_FILE = false;

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    if(USE_DB)
    {
        if(!connectionOpen())
        {
            ui->label_Status->setText("Failed to open database");
        }
        else
        {
            ui->label_Status->setText("Connected USE_DB...");
        }

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

//    if(!connectionOpen())
//    {
//        qDebug() << "Failed to open the database";
//        return;
//    }

//    connectionOpen();//this function open your connection only one time


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


    if(USE_DB)
    {
        //finding
        QSqlQuery qry;

        qry.prepare("select Username,Password from BankAccountDetails where Username ='"+username+"' and Password='"+password+"'");

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
                QMessageBox::information(this, "Login", "Login Sucess");

                connectionClose();//this function close your database connection after login success.

                this->hide();
                Profile profilepage;
                profilepage.setModal(true);
                profilepage.exec();
            }
            if(count < 1)
            {
                ui->label_Status->setText("username and password is not correct");

                QMessageBox::warning(this, "Login", "Invalid username or password");
            }
        }
    }

    if(USE_FILE)
    {
        if(authenticate(username,password))
        {
            QMessageBox::information(this, "Login", "Login Success");
            hide();

            Profile *profilePage;
            profilePage = new Profile(this);
            profilePage->show();
        }
        else
        {
            QMessageBox::warning(this, "Login", "Invalid username or password");
        }

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

    if(domainPart.left(5).compare("gmail", Qt::CaseInsensitive) != 0 && domainPart.left(5).compare("yahoo", Qt::CaseInsensitive) != 0 && domainPart.left(10).compare("rediffmail", Qt::CaseInsensitive) !=0)
            return false;

    if (domainParts.size() < 2 || domainPart.right(4).compare(".com", Qt::CaseInsensitive) != 0 && domainPart.right(3).compare(".in", Qt::CaseInsensitive) != 0)
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

bool Login::authenticate(const QString& username, const QString& password)
{
    file.setFileName("D:/Qt Assignment/BankApp/user_credential.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Login", "File not open");
        return false;
    }

    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList parts = line.split(" ");

        if(parts.size() == 2 && parts[0] == username && parts[1] == password)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;

}



void Login::on_pushButton_CreateAccount_clicked()
{

    QString name, email, deposit_amount, username, password;

    name = ui->lineEdit_name->text();

    email = ui->lineEdit_Email->text();
    deposit_amount = ui->lineEdit_deposit->text();
    username = ui->lineEdit_Email->text();
    password = ui->lineEdit_fpassword->text();

    if(USE_DB)
    {
//        qDebug()<<"AccountNumber: " <<Count;
        Count++;

        QSqlQuery qry;

        qry.prepare("insert into BankAccountDetails (AccountNumber, Name, Email, Balance, Username,Password)"
                   " values ('"+QString::number(Count)+"','"+name+"', '"+email+"', '"+deposit_amount+"', '"+username+"', '"+password+"')");

        if(qry.exec())
        {
            QMessageBox::information(this,"Submit","Account Created");

            saveAccountNumberToDatabasae();
    //        connectionClose();
        }
        else
        {
            QMessageBox::critical(this,tr("error"),qry.lastError().text());
        }
    }

}

void Login::loadAccountNumberFromDatabasae()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM Count_Table LIMIT 1"))
    {
        if (query.next())
        {
            Count = query.value(0).toInt();
        }
        else
        {
            qDebug() << "Warning: Count_table is empty.";
        }
    }
    else
    {
        qDebug() << "Error loading 'Count' from the databases: " << query.lastError().text();
    }

}

void Login::saveAccountNumberToDatabasae()
{
    QSqlQuery qry;

//    qDebug()<<"Save count: "<<Count;

    qry.prepare("update Count_Table set Count='"+QString::number(Count)+"' where Count=Count");

    if (qry.exec())
    {
        qDebug() << "Count Updated in the database.";
    }
    else
    {
        qDebug() << "Error updating 'Count' in the database: " << qry.lastError().text();
    }
}

