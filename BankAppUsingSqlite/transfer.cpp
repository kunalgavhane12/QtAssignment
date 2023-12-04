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
    reply = QMessageBox::question(this,"Title","Do you Want to Transfer?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No)
    {
        close();
    }

    QString FromAccountNo = ui->lineEdit_FromAccountNo->text();
    QString ToAccountNo = ui->lineEdit_ToAccountNo->text();
    QString Amount = ui->lineEdit_Transfer->text();
    Login conn;

    conn.connectionOpen();

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
            }
            else
            {
                qDebug() << "insufficient Balance";
            }
        }
    }
    else
    {
        qDebug() << "Error executing qry: " << qry->lastError().text();
    }
    conn.connectionClose();
}

