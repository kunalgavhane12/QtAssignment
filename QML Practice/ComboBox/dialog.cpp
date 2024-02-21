#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
    load();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_comboBox_currentIndexChanged(int index)
{
    ui->label_2->setText(QString::number(index) + " = "+ui->comboBox->currentText());
}


void Dialog::on_pushButton_clicked()
{
    QSettings settings("MyCompany", "MyApp");
    settings.setValue("settings", ui->comboBox->currentIndex());

    QMessageBox::information(this, "Saved", "Selection saved, Please close and reopen application");

}

void Dialog::init()
{
    ui->comboBox->clear();
    for(int i = 0; i < 10; i++)
        ui->comboBox->addItem("Item Number: " + QString::number(i));

}

void Dialog::load()
{
    QSettings settings("MyCompany", "MyApp");

    QVariant value = settings.value("Settings",0);

    bool ok;
    int index = value.toInt(&ok);

    if(!ok)
    {
        QMessageBox::critical(this,"Loading error", "Error loading selection!");
        return;
    }

    if(index < ui->comboBox->count())
    {
        ui->comboBox->setCurrentIndex(index);
    }
    else
    {
        ui->comboBox->setCurrentIndex(0);
    }

}

