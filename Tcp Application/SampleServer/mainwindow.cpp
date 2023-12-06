#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _server = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_startServer_clicked()
{
    if(_server == nullptr)
    {
        auto port = ui->spinServer_port->value();
        _server = new MyTCPServer(port);

        connect(_server, &MyTCPServer::newClientConnected, this, &MainWindow::newClient_Connected);
        connect(_server, &MyTCPServer::dataReceived, this, &MainWindow::clientDataReceived);
        connect(_server, &MyTCPServer::clientDisconnect, this, &MainWindow::clientDisconnected);

    }

    auto state = (_server->isStarted()) ? "1": "0";

    ui->label_ConnectionStatus->setProperty("state", state);
    style()->polish(ui->label_ConnectionStatus);

}

void MainWindow::newClient_Connected()
{
    ui->listConsole->addItem("New Client connected");
}


void MainWindow::on_btnSendToAll_clicked()
{
    auto message = ui->lineEdit_Message->text().trimmed();
    _server->sendToAll(message);
}

void MainWindow::clientDisconnected()
{
    ui->listConsole->addItem("Client Disconnected");
}

void MainWindow::clientDataReceived(QString message)
{
    ui->listConsole->addItem(message);

}

