#ifndef TRANSFER_H
#define TRANSFER_H

#include <QDialog>
#include "login.h"

namespace Ui {
class Transfer;
}


class Profile;

class Transfer : public QDialog
{
    Q_OBJECT

public:
//    explicit Transfer(QWidget *parent = nullptr);
    explicit Transfer(Profile* profileInstance, QWidget *parent = nullptr);
    ~Transfer();


private slots:
    void on_pushButton_TransferAmount_clicked();

    bool isAccountExists(const QString &Number);

    void updatedDetails();

private:
    Ui::Transfer *ui;
    Profile *profile;

};

#endif // TRANSFER_H
