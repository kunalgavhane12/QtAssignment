#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "loginlib.h"
#include <QtSql>
#include <QMessageBox>
#include <QLineEdit>
#include <QKeyEvent>
#include <QEvent>
#include "profile.h"
#include "sqlite3.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT
public:

    bool USE_DB = false;
    bool USE_FILE = true;
    QSqlDatabase mydb;
    QFile file;

    void connectionClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connectionOpen()
    {

        mydb = QSqlDatabase::addDatabase("QSQLITE");

        mydb.setDatabaseName("D:/qt practice program/QtPractice/Sql application/BankAppUsingSqlite/user_credential.db");

        if(!mydb.open())
        {
            qDebug() << "Failed to open the database";
            return false;
        }
        else
        {
            qDebug() << "Connected...";
            loadAccountNumberFromDatabasae();
            return true;
        }
    }

    void fileClose()
    {
        file.flush();
        file.close();
    }

    bool fileOpen()
    {
        file.setFileName("D:/qt practice program/QtPractice/Sql application/BankAppUsingSqlite/accountdetails.txt");

        if(!file.open(QFile::Append | QFile::Text))
        {
            QMessageBox::information(this, "Login", "File not open");
            return false;
        }
        else
        {
            qDebug() << "Connected...";
//            loadAccountNumberFromDatabasae();
            return true;
        }
    }

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_Login_clicked();

    bool authenticate(const QString&, const QString&);

    void on_pushButton_CreateAccount_clicked();

    void loadAccountNumberFromDatabasae();

    void saveAccountNumberToDatabasae();

    bool saveAccountToFile(int accountNumber, const QString &, const QString &, const QString &, const QString &, const QString &);


    void allClear();

    void keyPressEvent(QKeyEvent *event)override;


private:
    Ui::Login *ui;
    static int Count;
    QString username, password;


};
#endif // LOGIN_H
