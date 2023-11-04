#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>

double result = 0.0 ,num1 = 0.0, num2 = 0.0;
bool add = false;
bool sub = false;
bool mul = false;
bool Div = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("");

    for (int i = 0; i < 10; i++)
    {
        QString btnName = "pushButton" + QString::number(i);
        QPushButton *numberButton = findChild<QPushButton*>(btnName);
        connect(numberButton, SIGNAL(clicked()), this, SLOT(numPressed()));

    }

    connect(ui->Addition, SIGNAL(clicked()), this, SLOT(numPressed()));
    connect(ui->Divide, SIGNAL(clicked()), this, SLOT(numPressed()));
    connect(ui->Multiply, SIGNAL(clicked()), this, SLOT(numPressed()));
    connect(ui->Subt, SIGNAL(clicked()), this, SLOT(numPressed()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numPressed()
{
    QPushButton *btn = (QPushButton*)sender();
    QString value = btn->text();
    QString displayVal = ui->lineEdit->text();
    QString newVal = displayVal + value;
    ui->lineEdit->setText(newVal);

    if(0 == QString::compare(value, "÷", Qt::CaseInsensitive))
    {
        Div= true;
     }
    if(0 == QString::compare(value, "×", Qt::CaseInsensitive))
    {
        mul = true;
    }
    if(0 == QString::compare(value, "+", Qt::CaseInsensitive))
    {
        add =true;
    }
    if(0 == QString::compare(value, "−", Qt::CaseInsensitive))
    {
        sub =true;
    }

}

void MainWindow::on_AllClear_clicked()
{
    ui->lineEdit->setText("");
    num1 = 0.0;
    num2 = 0.0;
    result = 0.0;
    add = false;
    sub = false;
    mul = false;
    Div = false;
}

void MainWindow::on_Clear_clicked()
{
    ui->lineEdit->setText("");
}

void MainWindow::on_Modules_clicked()
{
    QString displayVal = ui->lineEdit->text();
    result = displayVal.toDouble();
    result /= 100;
    ui->lineEdit->setText(QString::number(result));
}

void MainWindow::on_Delete_clicked()
{
    QString str = ui->lineEdit->text();
    ui->lineEdit->setText("");
    for(int i=0; i<str.length()-1; i++)
    {
        ui->lineEdit->setText(ui->lineEdit->text()+str[i]);
    }
}

void MainWindow::on_LeftBracket_clicked()
{
    QString displayVal = ui->lineEdit->text();
    ui->lineEdit->setText(displayVal+"(");
}

void MainWindow::on_RightBracket_clicked()
{
    QString displayVal = ui->lineEdit->text();
    ui->lineEdit->setText(displayVal+")");
}

void MainWindow::on_Power_clicked()
{
    QString displayVal = ui->lineEdit->text();
    result = displayVal.toDouble();
    result*=result;
    ui->lineEdit->setText(QString::number(result));
}

void MainWindow::on_Point_clicked()
{
    QPushButton *btn = (QPushButton*)sender();
    QString value = btn->text();
    QString displayVal = ui->lineEdit->text();
    QString newVal = displayVal + value;
    ui->lineEdit->setText(newVal);
}

void MainWindow::on_Equals_clicked()
{
    double ans=0.0;
    QString displayVal = ui->lineEdit->text();
    ui->lineEdit->setText("");
    QRegularExpression numberRegex("([+-]?\\d*\\.?\\d+)");
    QRegularExpressionMatchIterator numberMatches = numberRegex.globalMatch(displayVal);

    if(numberMatches.hasNext())
    {
        num1 = numberMatches.next().captured(1).toDouble();
    }
    if(numberMatches.hasNext())
    {
        num2 = numberMatches.next().captured(1).toDouble();
    }
    ui->lineEdit->setText(QString::number(num1)+" "+QString::number(num2));

    if(add)
    {
        ans = num1 + num2;
        add = false;
    }
    if(mul)
    {
        ans = num1 * num2;
        mul = false;
    }
    if(sub)
    {
        ans = num1 - num2;
        sub = false;
    }
    if(Div)
    {
        if(num2 == 0.0)
        {
            ui->lineEdit->setText("Error: Division by zero");
            return;
        }
        else
            ans = num1 / num2;

        Div = false;
      }

//    ui->lineEdit->setText(displayVal + "=" + QString::number(ans));
    ui->lineEdit->setText(QString::number(ans));

}
