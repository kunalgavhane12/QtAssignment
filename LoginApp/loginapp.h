#ifndef LOGINAPP_H
#define LOGINAPP_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "profilepage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginApp; }
QT_END_NAMESPACE

class LoginApp : public QMainWindow
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
        mydb.setDatabaseName("D:/qt practice program/QtPractice/Sql application/LoginApp/user_credentials.db");

        if(!mydb.open())
        {
            qDebug() << "Failed to open the database";
            return false;
        }
        else
        {
            qDebug() << "Connected..";
            return true;
        }
    }

public:
    LoginApp(QWidget *parent = nullptr);
    ~LoginApp();

private slots:
    void on_Login_clicked();

private:
    Ui::LoginApp *ui;
//    QSqlDatabase mydb;
};
#endif // LOGINAPP_H
