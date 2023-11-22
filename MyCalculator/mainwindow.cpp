#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStack>

int MainWindow::dot = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int index = 0; index < 10; index++)
    {
        QString btnName = "pushButton" + QString::number(index);
        QPushButton *numberButton = findChild<QPushButton*>(btnName);
        connect(numberButton, SIGNAL(clicked()), this, SLOT(numPressed()));

    }

    connect(ui->Addition, SIGNAL(clicked()), this, SLOT(operatorPressed()));
    connect(ui->Divide, SIGNAL(clicked()), this, SLOT(operatorPressed()));
    connect(ui->Multiply, SIGNAL(clicked()), this, SLOT(operatorPressed()));
    connect(ui->Subt, SIGNAL(clicked()), this, SLOT(operatorPressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numPressed()
{
    QString oldExpression = ui->lineEdit->text();
    QPushButton *btn = (QPushButton*)sender();
    QString value = btn->text();

    if (oldExpression != value)
    {
        QString newValue = oldExpression + value;
        ui->lineEdit->setText(newValue);
    }
    else if ((value == ADDITION || value == SUBSTRACT || value == MULTIPLY || value == DIVISION) && dot == 1)
    {
        dot = 0;
        ui->lineEdit->setText(oldExpression + value);
    }
    else
    {
        ui->lineEdit->setText(value);
    }
}

void MainWindow::operatorPressed()
{
    QString expression = ui->lineEdit->text();
    QPushButton *btn = (QPushButton*)sender();
    QString value = btn->text();

    if (value == ADDITION || value == SUBSTRACT || value == MULTIPLY || value == DIVISION)
    {
        dot = 0;
        if (lastCharOperator(expression) && validOperators.contains(value))
        {
            expression = expression.left(expression.length() - 1) + value;
        }
        else
        {
            expression += value;
        }
        ui->lineEdit->setText(expression);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QString oldExp = expression;
    QString key = event->text();

    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        on_Equals_clicked();
        expression = ui->lineEdit->text();
    }

    if (event->key() == Qt::Key_Delete)
    {
        on_AllClear_clicked();
        expression = "";
        ui->lineEdit->clear();
    }
    else if (event->key() == Qt::Key_Backspace)
    {
        QString oldexpression = ui->lineEdit->text();
        expression = "";
        for (int i = 0; i < oldexpression.length() - 1; i++)
        {
            expression += oldexpression[i];
            ui->lineEdit->setText(ui->lineEdit->text() + oldexpression[i]);
        }
    }
    else if (event->type() == QEvent::KeyPress)
    {
        if ((key >= '0' && key <= '9') || key == '.' || key == '(' || key ==')')
        {
            if (lastCharOperator(expression) &&  key == '.')
            {
                expression = expression.left(expression.length() - 1) + key;
            }
            else
            {
                if (!ui->lineEdit->text().contains('.') && key == ".")
                {
                    expression += key;
                    dot = 1;
                }
                else if (key != ".")
                {
                    expression += key;
                }
            }
        }
        else if (validOperators.contains(key))
        {
            dot = 0;
            if (lastCharOperator(expression) && validOperators.contains(key))
            {
                expression = expression.left(expression.length() - 1) + key;
            }
            else
            {
                expression += key;
            }
        }
    }

    // handle Special character alphabet
    if (oldExp != expression)
        ui->lineEdit->setText(expression);
}

bool MainWindow::isOperator(const QChar &ch)
{
    return validOperators.contains(ch);
}

bool MainWindow::lastCharOperator(const QString &exp)
{
    if(!exp.isEmpty())
    {
        QChar lastChar = exp.at(exp.length()-1);
        return isOperator(lastChar);
    }
    return false;
}


void MainWindow::on_AllClear_clicked()
{
    ui->lineEdit->clear();
    ui->History->clear();
    expression = "";
    result = 0.0;
    dot = 0;
}

void MainWindow::on_Clear_clicked()
{
    ui->lineEdit->clear();
    expression = "";
    result = 0.0;
    dot = 0;
}

void MainWindow::on_Modules_clicked()
{
    QString displayVal = ui->lineEdit->text();
    double result = displayVal.toDouble();
    result /= 100;
    ui->History->setText(displayVal + " = " +QString::number(result));
    ui->lineEdit->setText(QString::number(result));
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
    ui->History->setText("sqr("+displayVal + ")= " +QString::number(result));
    ui->lineEdit->setText(QString::number(result));
}

void MainWindow::on_Dot_clicked()
{
    QString oldExpression = ui->lineEdit->text();

    if(dot == 0)
    {
        dot = 1;
        ui->lineEdit->setText(oldExpression + ".");

    }
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


int MainWindow::getPriority(char op)
{
    if (op == ADDITION || op == SUBSTRACT)
        return 1;
    else if (op == MULTIPLY || op == DIVISION)
        return 2;
    return 0;
}

double MainWindow::arthimaticOperation(double a, double b, char op)
{
    if (op == ADDITION)
      return a + b;
    else if (op == SUBSTRACT)
      return a - b;
    else if (op == MULTIPLY)
      return a * b;
    else if (op == DIVISION)
    {
      if(b != 0.0)
      {
          return a / b;
      }
      else
      {
        ui->lineEdit->setText("Cannot divide by zero");
        exit(1);
      }
    }
    return 0.0;
}

double MainWindow::performOperation()
{
    QString curExpression = ui->lineEdit->text();
    QStack<double> numbers;
    QStack<char> operators;

    QString currentNumber = "";
    for (int curIndex = 0; curIndex < curExpression.length(); curIndex++)
    {
            if(curExpression[curIndex]>='0' && curExpression[curIndex]<='9')
            {
                while((curIndex< curExpression.length() &&
                       (curExpression[curIndex]>='0' && curExpression[curIndex]<='9'))
                      || curExpression[curIndex] == '.')
                {
                    currentNumber += curExpression[curIndex];
                    curIndex++;
                }
                numbers.push(currentNumber.toDouble());
                currentNumber ="";
                curIndex--;

            }
            else if (curExpression[curIndex] == '(')
            {
                operators.push(curExpression[curIndex].toLatin1());
            }
            else if (curExpression[curIndex] == ')')
            {
                while (!operators.empty() && operators.top() != '(')
                {
                    double b = numbers.pop();
                    double a = numbers.pop();
                    char op = operators.pop();
                    double ans = arthimaticOperation(a,b,op);
                    numbers.push(ans);
                }
                operators.pop();
                if(operators.empty())
                {
                    double b = numbers.pop();
                    double a = numbers.pop();
                    numbers.push(a*b);
                }
            }
            else if (curExpression[curIndex] == ADDITION || curExpression[curIndex] == SUBSTRACT || curExpression[curIndex] == MULTIPLY || curExpression[curIndex] == DIVISION)
            {
                while (!operators.empty() && getPriority(operators.top()) >= getPriority(curExpression[curIndex].toLatin1()))
                {
                    double b = numbers.pop();
                    double a = numbers.pop();
                    char op = operators.pop();
                    double ans = arthimaticOperation(a,b,op);
                    numbers.push(ans);
                }
                operators.push(curExpression[curIndex].toLatin1());
            }
        }

        while (!operators.empty())
        {
            double b = numbers.pop();
            double a = numbers.pop();
            char op = operators.pop();
            double ans = arthimaticOperation(a,b,op);
            numbers.push(ans);
        }
        return numbers.top();
}

bool MainWindow::isValidExpression(const QString expression)
{
    QStack<char> stack;
    for(int index=0; index < expression.length(); index++)
    {
        if((expression[index] >= '0' && expression[index] <= '9') || expression[index] == '.'
                || expression[index] == ADDITION || expression[index] == SUBSTRACT ||
                expression[index] == MULTIPLY || expression[index] == DIVISION
                || expression[index] == '(' || expression[index] == ')')
        {
            if(expression[index] == '(')
            {
                stack.push(expression[index].toLatin1());
            }
            else if(expression[index] == ')')
            {
                if(stack.isEmpty() || stack.pop() != '(')
                    return false;
            }
        }
        else
        {
            return false;
        }
    }
    return stack.isEmpty();

}

void MainWindow::on_Equals_clicked()
{
    QString expression = ui->lineEdit->text();

    if (!isValidExpression(expression))
    {
        ui->lineEdit->setText("Error");
        return;
    }

    result = performOperation();
    ui->History->setText(expression + "=" + QString::number(result));
    ui->lineEdit->setText(QString::number(result));

}

/*
void MainWindow::on_Equals_clicked()
{
    QString displayVal = ui->lineEdit->text();

    if (!isValidExpression(displayVal))
    {
        ui->lineEdit->setText("Error");
        return;
    }

    if (isOperator(displayVal[0]))
    {
        double secondOperand = displayVal.mid(1).toDouble();

        if (displayVal[0] == ADDITION)
        {
            result = 0 + secondOperand;
        }
        else if (displayVal[0] == SUBSTRACT)
        {
            result = 0 - secondOperand;
        }
        else if (displayVal[0] == MULTIPLY)
        {
            result = 0 * secondOperand;
        }
        else if (displayVal[0] == DIVISION)
        {
            if (secondOperand != 0)
            {
                result = 0 / secondOperand;
            }
            else
            {
                ui->lineEdit->setText("Cannot divide by zero");
                return;
            }
        }

        ui->History->setText("0" + displayVal[0] + QString::number(secondOperand) + "=" + QString::number(result));
        ui->lineEdit->setText(QString::number(result));
    }
    else if (isOperator(displayVal[1]))
    {
        double firstOperand = displayVal.mid(0).toDouble();

        if (displayVal[1] == ADDITION)
        {
            result = firstOperand + firstOperand;
        }
        else if (displayVal[1] == SUBSTRACT)
        {
            result = firstOperand - firstOperand;
        }
        else if (displayVal[1] == MULTIPLY)
        {
            result = firstOperand * firstOperand;
        }
        else if (displayVal[1] == DIVISION)
        {
            if (firstOperand != 0)
            {
                result = firstOperand / firstOperand;
            }
            else
            {
                ui->lineEdit->setText("Result is undefined");
                return;
            }
        }

        ui->History->setText(QString::number(firstOperand) + displayVal[1] + QString::number(firstOperand) + "=" + QString::number(result));
        ui->lineEdit->setText(QString::number(result));
    }
    else
    {
        result = performOperation();
        ui->History->setText(displayVal + "=" + QString::number(result));
        ui->lineEdit->setText(QString::number(result));
    }
}
*/
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
