#include "profile.h"
#include "ui_profile.h"

Profile::Profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);
    displayAccountDetailsInTable();

}

Profile::~Profile()
{
    delete ui;
}

void Profile::on_pushButton_AccountDetails_clicked()
{
    displayAccountDetailsInTable();
}

void Profile::on_pushButton_Transfer_clicked()
{

    Transfer transferpage(this);
    transferpage.setModal(true);
    transferpage.exec();

//    this->hide();
//    Transfer *transfer;
//    transfer = new Transfer(this);
//    transfer->show();
}

void Profile::on_pushButton_Balance_clicked()
{
    displayAccountBalanceInTable();

}


void Profile::on_pushButton_Logout_clicked()
{
    Login conn;
    QMessageBox::StandardButton reply;

    if(conn.USE_DB)
    {
        reply = QMessageBox::question(this,"Logout","Do You Want to Logout?", QMessageBox::Yes| QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
           conn.connectionClose();
           close();
        }
    }

    if(conn.USE_FILE)
    {
        reply = QMessageBox::question(this,"Logout","Do You Want to Logout?", QMessageBox::Yes| QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            conn.fileClose();
            exit(0);
        }
    }

}

void Profile::displayAccountDetailsInTable()
{
    Login conn;

    if(conn.USE_DB)
    {
        QSqlQueryModel *model = new QSqlQueryModel();

//        conn.connectionOpen();

        QSqlQuery* qry = new QSqlQuery(conn.mydb);

        qry->prepare("select accountnumber,name,email,balance from BankAccountDetails");
        qry->exec();

        model->setQuery(*qry);

        ui->tableView->setModel(model);

//        conn.connectionClose();
        qDebug() << (model->rowCount());
    }

    if (conn.USE_FILE)
    {
        QFile file("D:/qt practice program/QtPractice/Sql application/BankAppUsingSqlite/accountdetails.txt");

        if (file.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&file);

            QStringList headers = {"Account Number", "Name", "Email", "Balance"};
            QStandardItemModel *model = new QStandardItemModel(0, headers.length(), this);
            model->setHorizontalHeaderLabels(headers);

            while (!in.atEnd())
            {
                QString line = in.readLine();
//                qDebug() << "Read line:" << line;
                QStringList fields = line.split(',');
                fields = fields.mid(0, 4);

                QList<QStandardItem *> items;
                for (const QString &field : fields)
                {
                    items.append(new QStandardItem(field));
                }
                model->appendRow(items);
            }

            file.close();

            ui->tableView->setModel(model);
        }
    }

}

void Profile::displayAccountBalanceInTable()
{
    Login conn;

    // file_DB data display using displayAccountBalanceInTable
    if(conn.USE_DB)
    {
        QSqlQueryModel *model = new QSqlQueryModel();

//        conn.connectionOpen();

        QSqlQuery* qry = new QSqlQuery(conn.mydb);

        qry->prepare("select Name,Balance from BankAccountDetails");
        qry->exec();

        model->setQuery(*qry);

        ui->tableView->setModel(model);

//        conn.connectionClose();
    }

    // file data display using displayAccountBalanceInTable
    if (conn.USE_FILE)
    {
        QFile file("D:/qt practice program/QtPractice/Sql application/BankAppUsingSqlite/accountdetails.txt");

        if (file.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&file);

            QStringList headers = {"Name", "Balance"};
            QStandardItemModel *model = new QStandardItemModel(0, headers.length(), this);
            model->setHorizontalHeaderLabels(headers);

            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList fields = line.split(',');

                QString accountNumber = fields[1];
                QString email = fields[3];

                QList<QStandardItem *> items;
                items.append(new QStandardItem(accountNumber));
                items.append(new QStandardItem(email));
                model->appendRow(items);
            }

            file.close();

            ui->tableView->setModel(model);
        }
    }

}

