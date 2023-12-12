#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginPage; }
QT_END_NAMESPACE

class LoginPage : public QMainWindow
{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_Reset_clicked();

    void on_pushButton_CreateAccount_clicked();

    bool isValidEmail(const QString &);

    bool isValidPassword(const QString &);

    bool authenticate(const QString &, const QString &);


private:
    Ui::LoginPage *ui;
    QString username;
    QString password;
    QFile file_DB;

};
#endif // LOGINPAGE_H
