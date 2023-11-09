#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void numPressed();

    void on_AllClear_clicked();

    void on_Modules_clicked();

    void on_Clear_clicked();

    void on_Delete_clicked();

    void on_LeftBracket_clicked();

    void on_RightBracket_clicked();

    void on_Power_clicked();

    void on_Point_clicked();

    void on_Equals_clicked();

    double performOperation();

    int isdigit(char ch);

    int getPriority(char);

    double arthimaticOperation(double a, double b, char op);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
