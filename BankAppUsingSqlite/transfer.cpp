#include "transfer.h"
#include "ui_transfer.h"

Transfer::Transfer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transfer)
{
    ui->setupUi(this);
}

Transfer::~Transfer()
{
    delete ui;
}


void Transfer::on_pushButton_TransferAmount_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Quick Transfer","Do you Want to Transfer?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No)
    {
        close();
    }

    QString FromAccountNo = ui->lineEdit_FromAccountNo->text();
    QString ToAccountNo = ui->lineEdit_ToAccountNo->text();
    QString Amount = ui->lineEdit_Transfer->text();

    Login conn;

    conn.connectionOpen();

    if(!(conn.isValidDeposit(FromAccountNo) && conn.isValidDeposit(ToAccountNo) && conn.isValidDeposit(Amount)))
    {
        QMessageBox::information(this, "Login", "Please enter only digits");
        ui->lineEdit_ToAccountNo->clear();
        ui->lineEdit_FromAccountNo->clear();
        ui->lineEdit_Transfer->clear();
        return;
    }

    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    if(qry->exec("select * from BankAccountDetails where AccountNumber = '"+FromAccountNo+"'"))
    {
        if(qry->next())
        {
            double sBalance = qry->value("Balance").toDouble();

            if(sBalance >= Amount.toDouble())
            {
                sBalance -= Amount.toDouble();

                qry->prepare("update BankAccountDetails SET Balance = '"+QString::number(sBalance)+"' where AccountNumber = '"+FromAccountNo+"'");
                qry->exec();

                if(qry->exec("select * from BankAccountDetails where AccountNumber = '"+ToAccountNo+"'"))
                {
                    if(qry->next())
                    {
                        double rBalance = qry->value("Balance").toDouble();

                        rBalance += Amount.toDouble();

                        qry->prepare("update BankAccountDetails SET Balance = '"+QString::number(rBalance)+"' where AccountNumber = '"+ToAccountNo+"'");
                        qry->exec();
                    }
                }
                ui->label_Status->setText("Transfer success");
                QMessageBox::information(this,"Quick Transfer","Transfer Sucess");
                close();
            }
            else
            {
                QMessageBox::information(this,"Quick Transfer","Insufficient Balance");
                qDebug() << "Insufficient Balance";
                ui->label_Status->setText("Insufficient Balance");

            }
        }
    }
    else
    {
        qDebug() << "Error executing qry: " << qry->lastError().text();
    }

    ui->lineEdit_FromAccountNo->clear();
    ui->lineEdit_ToAccountNo->clear();
    ui->lineEdit_Transfer->clear();
    ui->label_Status->clear();

    conn.connectionClose();
}

