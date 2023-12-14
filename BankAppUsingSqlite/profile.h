#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>
#include "login.h"
#include <QStandardItemModel>

namespace Ui {
class Profile;
}

class Profile : public QDialog
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent = nullptr);
    ~Profile();

private slots:

    void on_pushButton_AccountDetails_clicked();

    void on_pushButton_Transfer_clicked();

    void on_pushButton_Balance_clicked();

    void on_pushButton_Logout_clicked();

    void displayAccountDetailsInTable();

    void displayAccountBalanceInTable();


private:
    Ui::Profile *ui;

};

#endif // PROFILE_H
