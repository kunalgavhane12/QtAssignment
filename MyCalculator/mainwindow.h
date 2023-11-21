#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


namespace  {

 constexpr char ADDITION = '+';

}

namespace  {

 constexpr char MULTIPLY = '*';

}

namespace  {

 constexpr char SUBSTRACT = '-';

}

namespace  {

 constexpr char DIVISION = '/';

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void numPressed();

    void keyPressEvent(QKeyEvent *event) override;

   // bool event(QEvent *event) override;

    void on_AllClear_clicked();

    void on_Modules_clicked();

    void on_Clear_clicked();

    void on_LeftBracket_clicked();

    void on_RightBracket_clicked();

    void on_Power_clicked();

    void on_Dot_clicked();

    void on_Equals_clicked();

    double performOperation();

    int getPriority(char);

    double arthimaticOperation(double a, double b, char op);

    void on_Delete_clicked();

    bool isvaildExpression(const QString expression);

    bool isOperator(const QChar &);
    bool lastCharOperator(const QString &);

private:
    Ui::MainWindow *ui;
    double result = 0.0;
    QString expression = "0";
    static int dot;

};
#endif // MAINWINDOW_H
