#include "login.h"
#include "ui_login.h"

int Login::Count = 0;

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

    if(username.isEmpty() && password.isEmpty())
    {
        QMessageBox::information(this, "Login", "Please fill in all fields");
        return;

    }

    if(!check.isValidEmail(username))
    {
        QMessageBox::information(this, "Login", "Invalid Username");
        allClear();
        return;
    }

    if(!check.isValidPassword(password))
    {
        QMessageBox::warning(this, "Login", "Password must have at least one digit,"
             " one lowercase, one uppercase, one special character and has to be at least of 8 characters");
        ui->lineEdit_Password->clear();
        return;
    }

    password = encrypt(password);

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

                this->hide();
                Profile profilepage;
                profilepage.setModal(true);
                profilepage.exec();
            }
            if(count < 1)
            {
                ui->label_Status->setText("username and password is not correct");
                QMessageBox::warning(this, "Login", "Invalid username or password");
                allClear();
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
            allClear();
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
        QStringList parts = line.split(",");

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
    LoginLib check;

    name = ui->lineEdit_name->text();
    email = ui->lineEdit_Email->text();
    deposit = ui->lineEdit_deposit->text();
    username = ui->lineEdit_fusername->text();
    password = ui->lineEdit_fpassword->text();

    if (name.isEmpty() || email.isEmpty() || deposit.isEmpty() || username.isEmpty() || password.isEmpty())
    {
           QMessageBox::warning(this, "Account Opening", "Please fill in all fields");
           return;
    }

    if(!isValidName(name))
    {
        QMessageBox::information(this, "Account Opening", "Please enter valid name, only alphabets");
        ui->lineEdit_name->clear();
        return;
    }

    if(!isValidDeposit(deposit))
    {
        QMessageBox::information(this, "Account Opening", "Please enter only digits.");
        ui->lineEdit_deposit->clear();
        return;
    }
    if(!check.isValidEmail(email))
    {
        QMessageBox::information(this, "Account Opening", "Invalid email");
        ui->lineEdit_Username->clear();
        return;
    }

    if(!check.isValidEmail(username))
    {
        QMessageBox::information(this, "Account Opening", "Invalid Username");
        ui->lineEdit_Username->clear();
        return;
    }

    if(!check.isValidPassword(password))
    {
        QMessageBox::warning(this, "Login", "Password must have at least one digit,"
             " one lowercase, one uppercase, one special character and has to be at least of 8 characters");
        ui->lineEdit_Password->clear();
        return;
    }

    //insert encrypted password
      password = encrypt(password);

    if(USE_DB)
    {
    //finding details in database file
      QSqlQuery qry;

      qry.prepare("SELECT name,email FROM BankAccountDetails WHERE Name = '"+name+"' AND Email = '"+email+"'");

      if (qry.exec())
      {
          int count = 0;

          while (qry.next())
          {
              count++;
//              qDebug() << "Finding...";
          }

//          qDebug() << "Finding..." << count;

          if (count >= 1)
          {
              ui->label_Status->setText("Account already exists");
              QMessageBox::information(this, "Account Opening", "Account already exists");
              allClear();
              return;
          }

          if (count < 1)
          {
              Count++;
              saveAccountToDatabase(Count, name, email, deposit, username, password);
          }
      }
      else
      {
          qDebug() << "Error loading databases: " << qry.lastError().text();
      }
    }


    if(USE_FILE)
    {
        int count = 0;

        file.setFileName("D:/qt practice program/QtPractice/Sql application/BankAppUsingSqlite/accountdetails.txt");

        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::information(this, "Account opening", "File not open");
            return;
        }

       QTextStream in(&file);

        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList data = line.split(',');

            if (data.size() >= 6 && data[1] == name && data[2] == email)
            {
               count++;
               qDebug() << "find :" <<count;
            }
        }
        qDebug() << "find :" <<count;
        if(count < 1)
        {
            loadAccountNumberFromFile();
//            qDebug() <<"before count: "<<Count;
            Count++;
            saveAccountToFile(Count, name, email, deposit, username, password);
            saveAccountNumberToFile();
//            qDebug() <<"After count: "<<Count;
        }
        else
        {
            ui->label_Status->setText("Account already exists");
            QMessageBox::information(this, "Account Opening", "Account already exists");
            allClear();
            return;
        }

    }

    QMessageBox::information(this, "Account Opening", "Account Created");
    allClear();

}

void Login::loadAccountNumberFromDatabase()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM Count_Table LIMIT 1"))
    {
        if (query.next())
        {
            Count = query.value(0).toInt();
        }

    }
    else
    {
        qDebug() << "Error loading 'Count' from the databases: " << query.lastError().text();
    }

}


void Login::saveAccountNumberToDatabase()
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

void Login::saveAccountToDatabase(int accountNumber, const QString &name, const QString &email, const QString &deposit, const QString &username, const QString &password)
{
    QSqlQuery qry;

    qry.prepare("insert into BankAccountDetails (AccountNumber, Name, Email, Balance, Username,Password)"
               " values ('"+QString::number(accountNumber)+"','"+name+"', '"+email+"', '"+deposit.toDouble()+"', '"+username+"', '"+password+"')");

    if (!qry.exec())
    {
        qDebug() << "Error inserting account into database: " << qry.lastError().text();
    }

    saveAccountNumberToDatabase();
}

void Login::saveAccountToFile(int accountNumber, const QString &name, const QString &email, const QString &deposit, const QString &username, const QString &password)
{
    fileOpen();

    QTextStream out(&file);

    out << accountNumber << "," << name << "," << email << "," << deposit.toDouble() << "," << username << "," << password << endl;

    fileClose();
}

void Login::saveAccountNumberToFile()
{
    QFile countFile("D:/qt practice program/QtPractice/Sql application/BankAppUsingSqlite/count.txt");

    if (!countFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "File not open";
        return;
    }

    QTextStream out(&countFile);
    out << Count;
    countFile.close();
}

void Login::loadAccountNumberFromFile()
{
    QFile countFile("D:/qt practice program/QtPractice/Sql application/BankAppUsingSqlite/count.txt");
    if (!countFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "File not open";
        return;
    }

    QTextStream in(&countFile);
    QString line = in.readLine();
    Count = line.toInt();
    countFile.close();
}

bool Login::isValidName(const QString &name)
{
    for(QChar ch: name)
    {
        if(!(ch.isLetter() || ch == ' '))
            return false;
    }
    return true;
}

bool Login::isValidDeposit(const QString &deposit)
{
    for(QChar ch: deposit)
    {
        if(!(ch.isDigit() || ch == '.'))
            return false;
    }
    return true;
}

QString Login::encrypt(const QString& data)
{
    QByteArray hash = QCryptographicHash::hash(data.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

void Login::allClear()
{
    ui->lineEdit_name->clear();
    ui->lineEdit_Email->clear();
    ui->lineEdit_deposit->clear();
    ui->lineEdit_fusername->clear();
    ui->lineEdit_fpassword->clear();
    ui->lineEdit_Username->clear();
    ui->lineEdit_Password->clear();
}
