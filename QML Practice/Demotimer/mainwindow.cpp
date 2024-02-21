#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
//#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);

    connect(m_timer,SIGNAL(timeout()),this,SLOT(myFunction()));
    m_timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myFunction()
{
    QDate date = QDate::currentDate();
    QString date_text = date.toString("dd/MM/yyyy");

    QTime time =QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");

    if(time.second()%2 == 0)
    {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    ui->label->setText(date_text);
    ui->label_2->setText(time_text);

}

