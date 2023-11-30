#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QDialog>
#include "loginapp.h"

namespace Ui {
class ProfilePage;
}

class ProfilePage : public QDialog
{
    Q_OBJECT

public:
    explicit ProfilePage(QWidget *parent = nullptr);
    ~ProfilePage();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::ProfilePage *ui;
};

#endif // PROFILEPAGE_H
