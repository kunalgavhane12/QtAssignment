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

void Transfer::on_pushButton_Cancel_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Title","Do you Want to cancel?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        close();
    }
}


void Transfer::on_pushButton_TransferAmount_clicked()
{
    QString FromAccountNo = ui->label_FormAccountNo->text();
    QString ToAccountNO = ui->label_ToAccountNo->text();
    QString Amount = ui->label_Transfer->text();

    Login conn;

//    conn.connectionOpen();

    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    if(qry->exec("select * from BankAccountDetails where AccountNumber = '"+FromAccountNo+"'"))
    {
        if(qry->next())
        {
            double sBalance = qry->value("Balance").toDouble();
            qDebug() << "sBal: "<<sBalance;

            if(sBalance >= Amount.toDouble())
            {
                sBalance -= Amount.toDouble();

                qry->prepare("update BankAccountDetails SET Balance = '"+QString::number(sBalance)+"' where AccountNumber = '"+FromAccountNo+"'");
                qry->exec();

                if(qry->exec("select * from BankAccountDetails where AccountNumber = '"+ToAccountNO+"'"))
                {
                    if(qry->next())
                    {
                        double rBalance = qry->value("Balance").toDouble();
                        qDebug() << "sBal: "<<sBalance;

                        rBalance += Amount.toDouble();

                        qry->prepare("update BankAccountDetails SET Balace = '"+QString::number(rBalance)+"' where AccountNumber = '"+ToAccountNO+"'");
                        qry->exec();
                    }

                }
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

}

