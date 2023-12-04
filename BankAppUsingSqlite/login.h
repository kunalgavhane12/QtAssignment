#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>
#include "profile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase mydb;

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



public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_Login_clicked();

    bool isValidEmail(const QString &);

    bool isValidPassword(const QString &);

    bool authenticate(const QString&, const QString&);

    void on_pushButton_CreateAccount_clicked();

    void loadAccountNumberFromDatabasae();

    void saveAccountNumberToDatabasae();

    void allClear();


private:
    Ui::Login *ui;
    QFile file;
    static int Count;
};
#endif // LOGIN_H
