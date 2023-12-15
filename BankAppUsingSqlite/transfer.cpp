#include "transfer.h"
#include "ui_transfer.h"
#include "profile.h"
#include "ui_profile.h"

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

        if(conn.USE_DB)
        {
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

            conn.connectionClose();
        }

        if(conn.USE_FILE)
        {
            if(!isAccountExists(FromAccountNo))
            {
                QMessageBox::information(this, "Quick Transfer", "Invalid Account Number");
                return;
            }

            if(!isAccountExists(ToAccountNo))
            {
                QMessageBox::information(this, "Quick Transfer", "Invalid Account Number");
                return;
            }

            QFile file("D:/qt practice program/QtPractice/Sql application/BankAppUsingSqlite/accountdetails.txt");

            if (!file.open(QFile::ReadOnly | QFile::Text))
            {
                QMessageBox::information(this, "Quick Transfer", "File not open");
                return;
            }

            QFile tempFile("D:/qt practice program/QtPractice/Sql application/BankAppUsingSqlite/temp.txt");

            if (tempFile.open(QFile::ReadWrite | QFile:: Text))
            {
                QTextStream out(&tempFile);

                QTextStream in(&file);

                while (!in.atEnd())
                {
                    QString line = in.readLine();
                    QStringList data = line.split(',');

                    if (data.size() >= 6 && data[0] == FromAccountNo)
                    {
                        if (data[3].toDouble() < Amount.toDouble())
                        {
                            QMessageBox::information(this, "Quick Transfer", "Insufficient Balance");
                            ui->label_Status->setText("Insufficient Balance");
                            file.close();
                            tempFile.remove();
                            return;
                        }
                        else
                        {
                            double sBalance = data[3].toDouble();
                            sBalance -= Amount.toDouble();
                            data[3] = QString::number(sBalance);
                            qDebug() << "Balance deducted";
                        }
                    }

                    if (data.size() >= 6 && data[0] == ToAccountNo)
                    {
                        double rBalance = data[3].toDouble();
                        rBalance += Amount.toDouble();
                        data[3] = QString::number(rBalance);
                        qDebug() << "Balance received";

                        ui->label_Status->setText("Transfer success");
                        QMessageBox::information(this, "Quick Transfer", "Transfer Success");
                    }

                    out << data.join(',') << '\n';
                }

                tempFile.close();
                file.close();
                updatedDetails();

                tempFile.remove();
            }
            close();
        }
}

bool Transfer::isAccountExists(const QString &accountNumber)
{
    QFile file("D:/qt practice program/QtPractice/Sql application/BankAppUsingSqlite/accountdetails.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Quick Transfer", "File not open");
        return false;
    }

    QTextStream out(&file);
    while(!out.atEnd())
    {
        QString line = out.readLine();
        QStringList data = line.split(',');

        if(data.size() >= 6 && data[0] == accountNumber)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void Transfer::updatedDetails()
{
    QFile tempFile("D:/qt practice program/QtPractice/Sql application/BankAppUsingSqlite/temp.txt");


    if (!tempFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Quick Transfer", "File not open");
        return;
    }

    QFile file("D:/qt practice program/QtPractice/Sql application/BankAppUsingSqlite/accountdetails.txt");

    if (file.open(QFile::WriteOnly | QFile:: Text))
    {
        QTextStream out(&file);

        QTextStream in(&tempFile);

        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList data = line.split(',');

            if (data.size() >= 6)
            {
                out << data.join(',');
            }
            out << '\n';
        }

        tempFile.close();
        file.close();
    }
}




