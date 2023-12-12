#include "profile.h"
#include "ui_profile.h"
#include "transfer.h"
#include <QStandardItemModel>

Profile::Profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);
}

Profile::~Profile()
{
    delete ui;
}



void Profile::on_pushButton_AccountDetails_clicked()
{
    Login conn;

    if(conn.USE_DB)
    {
        QSqlQueryModel *model = new QSqlQueryModel();

        conn.connectionOpen();

        QSqlQuery* qry = new QSqlQuery(conn.mydb);

        qry->prepare("select accountnumber,name,email,balance from BankAccountDetails");
        qry->exec();

        model->setQuery(*qry);

        ui->tableView->setModel(model);

        conn.connectionClose();
        qDebug() << (model->rowCount());
    }

    if (conn.USE_FILE)
    {
        QStandardItemModel* model = new QStandardItemModel;

        conn.fileOpen();
        QTextStream in(&conn.file);

        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList fields = line.split(" ");
            QList<QStandardItem *> items;

            for (const QString &field : fields)
            {
                items.append(new QStandardItem(field));
            }
            model->appendRow(items);
        }

        ui->tableView->setModel(model);

        ui->tableView->show();

        conn.fileClose();
    }
}


void Profile::on_pushButton_Transfer_clicked()
{
    Transfer *transfer;
    transfer = new Transfer(this);
    transfer->show();
}


void Profile::on_pushButton_Balance_clicked()
{
    Login conn;

    if(conn.USE_DB)
    {
        QSqlQueryModel *model = new QSqlQueryModel();

        conn.connectionOpen();

        QSqlQuery* qry = new QSqlQuery(conn.mydb);

        qry->prepare("select Name,Balance from BankAccountDetails");
        qry->exec();

        model->setQuery(*qry);

        ui->tableView->setModel(model);

        conn.connectionClose();
        qDebug() << (model->rowCount());
    }

    if(conn.USE_FILE)
    {
        QFile *model = new QFile();

        conn.fileOpen();

        conn.connectionClose();

    }

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
            exit(0);
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

