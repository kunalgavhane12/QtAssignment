#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStack>

double result = 0.0;
QString expression = "0";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("0");

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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QString key = event->text();

    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        on_Equals_clicked();
        expression = ui->lineEdit->text();
    }

    if(event->key() == Qt::Key_Delete)
    {
        on_AllClear_clicked();
        expression = "";
        ui->lineEdit->clear();
    }
    else if(event->key() == Qt::Key_Backspace)
    {
        QString s = ui->lineEdit->text();
        expression = "";
        for(int i=0; i<s.length()-1; i++)
        {
            expression +=s[i];
            ui->lineEdit->setText(ui->lineEdit->text()+s[i]);
        }
    }
    else if(event->type() == QEvent::KeyPress)
    {
        expression +=  key;

    }

    ui->lineEdit->setText(expression);
}

/*bool MainWindow::event(QEvent *event)
{
    //keyborad event
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *k_ev = static_cast<QKeyEvent *>(event);
        if(k_ev->key() == 'A')
        {
            qDebug() << "Key: " << (char) k_ev->key() << "----handled by event";
            return true;
        }
    }
    //mouse event
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *m_ev = static_cast<QMouseEvent *>(event);
        if(m_ev->button() == Qt::LeftButton)
        {
            qDebug() << "in event(), left click.";
            return true;
        }
        else if(m_ev->button() == Qt::RightButton)
        {
            qDebug() << "in event(), right click.";
            return true;
        }
        else
        {
            return QWidget::event(event);
        }
    }
    return QWidget::event(event);
}*/

void MainWindow::on_AllClear_clicked()
{
    ui->lineEdit->clear();
    ui->History->clear();
    expression = "";
}


void MainWindow::on_Clear_clicked()
{
    ui->lineEdit->clear();
    expression = "";
}

void MainWindow::on_Modules_clicked()
{
    QString displayVal = ui->lineEdit->text();
    double result = displayVal.toDouble();
    result /= 100;
    ui->History->setText(displayVal + " = " +QString::number(result));
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
    ui->History->setText(displayVal + " ^ = " +QString::number(result));
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


int MainWindow::getPriority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

double MainWindow::arthimaticOperation(double a, double b, char op)
{
    if (op == '+')
      return a + b;
    else if (op == '-')
      return a - b;
    else if (op == '*')
      return a * b;
    else if (op == '/')
      if(b != 0.0)
      return a / b;

    return 0.0;
}

double MainWindow::performOperation()
{
    QString s = ui->lineEdit->text();
    QStack<double> numbers;
    QStack<char> operators;

    QString currentNumber = "";
    for (int i = 0; i < s.length(); i++)
    {
            if(s[i]>='0' && s[i]<='9')
            {
                while((i< s.length() && (s[i]>='0' && s[i]<='9')) || s[i] == '.')
                {
                    currentNumber += s[i];
                    i++;
                }
                numbers.push(currentNumber.toDouble());
                currentNumber ="";
                i--;

            }
            else if (s[i] == '(')
            {
                operators.push(s[i].toLatin1());
            }
            else if (s[i] == ')')
            {
                while (!operators.empty() && operators.top() != '(')
                {
                    double b = numbers.top();
                    numbers.pop();
                    double a = numbers.top();
                    numbers.pop();
                    char op = operators.top();
                    operators.pop();
                    double ans = arthimaticOperation(a,b,op);
                    numbers.push(ans);
                }
                operators.pop();
                if(operators.empty())
                {
                    double b = numbers.top();
                    numbers.pop();
                    double a = numbers.top();
                    numbers.pop();
                    numbers.push(a*b);
                }
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                while (!operators.empty() && getPriority(operators.top()) >= getPriority(s[i].toLatin1()))
                {
                    double b = numbers.top();
                    numbers.pop();
                    double a = numbers.top();
                    numbers.pop();
                    char op = operators.top();
                    operators.pop();
                    double ans = arthimaticOperation(a,b,op);
                    numbers.push(ans);
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
            double ans = arthimaticOperation(a,b,op);
            numbers.push(ans);
        }
        return numbers.top();
}

void MainWindow::on_Equals_clicked()
{
    QString displayVal = ui->lineEdit->text();
    result = performOperation();

    ui->History->setText(displayVal + " = " + QString::number(result));
    ui->lineEdit->setText(QString::number(result));
}
