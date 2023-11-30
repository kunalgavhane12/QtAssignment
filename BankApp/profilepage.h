#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QDialog>

namespace Ui {
class profilePage;
}

class profilePage : public QDialog
{
    Q_OBJECT

public:
    explicit profilePage(QWidget *parent = nullptr);
    ~profilePage();

private slots:
    void on_pushButton_account_clicked();

    void on_pushButton_Transfer_clicked();

    void on_pushButton_Balance_clicked();

    void on_pushButton_Logout_clicked();

    void accountDetails();
    void deposit(float);
    bool balanceTransfer(float);
    void balanceEnquiry();


    void on_pushButton_Deposit_clicked();

private:
    Ui::profilePage *ui;

    QString name;
    int accountNumber;
    float balance;
    static int count;

};

#endif // PROFILEPAGE_H
