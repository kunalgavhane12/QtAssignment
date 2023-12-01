#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>

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
    void on_pushButton_Details_clicked();

    void on_pushButton_Transfer_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_Logout_clicked();

private:
    Ui::Profile *ui;
};

#endif // PROFILE_H
