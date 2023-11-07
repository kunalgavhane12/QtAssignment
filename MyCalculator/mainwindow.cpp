#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStack>

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

}

void MainWindow::on_AllClear_clicked()
{
    ui->lineEdit->clear();
    ui->History->clear();
}


void MainWindow::on_Clear_clicked()
{
    ui->lineEdit->clear();
}

void MainWindow::on_Modules_clicked()
{
    QString displayVal = ui->lineEdit->text();
    double result = displayVal.toDouble();
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
    double result = displayVal.toDouble();
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


double MainWindow::performOperation()
{
    QString s = ui->lineEdit->text();
    QStack<double> numbers;
    QStack<char> operators;

    QString currentNumber ="";

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            while(i < s.length() && (s[i]>='0' && s[i]<='9'))
            {
                currentNumber += s[i];
                i++;
            }
            numbers.push(currentNumber.toDouble());
            currentNumber.clear();
        }

        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            while (!operators.empty())
            {
                    double b = numbers.top();
                    numbers.pop();
                    double a = numbers.top();
                    numbers.pop();
                    char op = operators.top();
                    operators.pop();
                    if (op == '+')
                    {
                        numbers.push(a + b);
                    }
                    else if (op == '-')
                    {
                        numbers.push(a - b);
                    }
                    else if (op == '*')
                    {
                        numbers.push(a * b);
                    }
                    else if (op == '/')
                    {
                        numbers.push(a / b);
                    }
            }
                operators.push(s[i].toLatin1());
        }
    }
        while (!operators.empty())
        {
            double b = numbers.top();
            numbers.pop();
            double a = numbers.top();
            numbers.pop();
            char op = operators.top();
            operators.pop();
            if (op == '+')
            {
                numbers.push(a + b);
            }
            else if (op == '-')
            {
                numbers.push(a - b);
            }
            else if (op == '*')
            {
                numbers.push(a * b);
            }
            else if (op == '/')
            {
                numbers.push(a / b);
            }
        }

    return numbers.top();
}

void MainWindow::on_Equals_clicked()
{
    QString displayVal = ui->lineEdit->text();
    double result = performOperation();
    ui->History->setText(displayVal);
    ui->lineEdit->setText(QString::number(result));
}
