#ifndef TRANSFER_H
#define TRANSFER_H

#include <QDialog>
#include "login.h"
#include "profile.h"

namespace Ui {
class Transfer;
}

class Transfer : public QDialog
{
    Q_OBJECT

public:
    explicit Transfer(QWidget *parent = nullptr);
    ~Transfer();

private slots:

    void on_pushButton_TransferAmount_clicked();

private:
    Ui::Transfer *ui;

};

#endif // TRANSFER_H
