#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>

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


private:
    Ui::LoginPage *ui;
};
#endif // LOGINPAGE_H
