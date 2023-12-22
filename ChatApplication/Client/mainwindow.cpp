#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ClientManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionConnect_triggered()
{
    _client = new ClientManager();
    connect(_client, &ClientManager::connected, [this](){ui->centralwidget->setEnabled(true);});

    connect(_client, &ClientManager::disconnected, [this](){ui->centralwidget->setEnabled(false);});

    connect(_client, &ClientManager::dataReceived, this, &MainWindow::dataReceived);
    _client->connectToServer();
}


void MainWindow::on_btnSend_clicked()
{
    auto message = ui->lineEditMessage->text().trimmed();
    _client->sendMessage(message);

    ui->listMessage->addItem(message);
    ui->lineEditMessage->setText("");
    ui->lineEditMessage->setFocus();
}

void MainWindow::dataReceived(QByteArray data)
{
    ui->listMessage->addItem(data);
}

