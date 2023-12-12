#include "login.h"
#include "ui_login.h"

int Login::Count = 0;

//bool USE_DB = false;
//bool USE_FILE = true;

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

    if(USE_FILE)
    {
        if(!fileOpen())
        {
            ui->label_Status->setText("Failed to open database");
        }
        else
        {
            ui->label_Status->setText("Connected USE_FILE...");
        }

    }


}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_Login_clicked()
{
    LoginLib check;

    username = ui->lineEdit_Username->text();
    password = ui->lineEdit_Password->text();

    if(!connectionOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    connectionOpen();//this function open your connection only one time


    if(!check.isValidEmail(username))
    {
        QMessageBox::information(this, "Login", "Invalid Username");
        return;
    }

    if(!check.isValidPassword(password))
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


bool Login::authenticate(const QString& username, const QString& password)
{
    file.setFileName("D:/qt practice program/QtPractice/Sql application/BankAppUsingSqlite/accountdetails.txt");

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

        if (parts.size() >= 6 && parts[4] == username && parts[5] == password)
        {
            fileClose();
            return true;
        }
    }

    fileClose();
    return false;

}


void Login::on_pushButton_CreateAccount_clicked()
{

    QString name, email, deposit_amount;

    name = ui->lineEdit_name->text();
    email = ui->lineEdit_Email->text();
    deposit_amount = ui->lineEdit_deposit->text();
    username = ui->lineEdit_fusername->text();
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

        }
        else
        {
            QMessageBox::critical(this,tr("error"),qry.lastError().text());
        }
    }

    if (USE_FILE)
    {
        if (saveAccountToFile(Count, name, email, deposit_amount, username, password))
        {
            QMessageBox::information(this, "Submit", "Account Created");
        }
        else
        {
            QMessageBox::critical(this, tr("Error"), "Failed to create account in file");
        }
    }

    allClear();

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

bool Login::saveAccountToFile(int accountNumber, const QString &name, const QString &email, const QString &balance, const QString &username, const QString &password)
{

    QTextStream out(&file);
    out << accountNumber << " " << name << " " << email << " " << balance << " " << username << " " << password << endl;

    return true;
}


void Login::saveAccountNumberToDatabasae()
{
    QSqlQuery qry;

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

void Login::allClear()
{
    ui->lineEdit_name->clear();
    ui->lineEdit_Email->clear();
    ui->lineEdit_deposit->clear();
    ui->lineEdit_fusername->clear();
    ui->lineEdit_fpassword->clear();
}

void Login::keyPressEvent(QKeyEvent *event)
{
    QString key = event->text();

    if (event->type() == QEvent::KeyPress)
    {
        if ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || (key >= '0' && key <= '9'))
        {
            return;
        }
        else
        {
            event->ignore();
        }
    }

}

