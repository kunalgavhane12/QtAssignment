#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMetaEnum>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setDeviceController();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_InIPAddress_textChanged(const QString &arg1)
{
    QString state = "0";
    if(arg1 == "...")
    {
        state = "";
    }
    else
    {
        QHostAddress address(arg1);

        if(QAbstractSocket::IPv4Protocol == address.protocol())
        {
            state = "1";

        }
    }

    ui->InIPAddress->setProperty("state", state);
    style()->polish(ui->InIPAddress);
}


void MainWindow::on_btnConnect_clicked()
{
    if(_controller.isConnected())
    {
        _controller.disconnect();
    }
    else
    {
        auto ip = ui->InIPAddress->text();
        auto port = ui->spinBox->value();

        _controller.connectToDevice(ip, port);
    }
}

void MainWindow::device_connected()
{
    ui->listConsole->addItem("Connected To Device");
    ui->btnConnect->setText("Disconnect");
    ui->grpSendData->setEnabled(true);

}

void MainWindow::device_disconnected()
{
    ui->listConsole->addItem("Disconnected To Device");
    ui->btnConnect->setText("Connect");
    ui->grpSendData->setEnabled(false);
}

void MainWindow::device_stateChanged(QAbstractSocket::SocketState state)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    ui->listConsole->addItem(metaEnum.valueToKey(state));
}

void MainWindow::device_errorOccurred(QAbstractSocket::SocketError error)
{

    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    ui->listConsole->addItem(metaEnum.valueToKey(error));

}

void MainWindow::device_dataReady(QByteArray data)
{
    ui->listConsole->addItem(QString(data));

}

void MainWindow::setDeviceController()
{
    connect(&_controller, &DeviceController::connected, this, &MainWindow::device_connected);
    connect(&_controller, &DeviceController::disconnected, this, &MainWindow::device_disconnected);
    connect(&_controller, &DeviceController::stateChanged, this, &MainWindow::device_stateChanged);
//    connect(&_controller, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error(QAbstractSocket::SocketError)));
    connect(&_controller, &DeviceController::dataReady, this, &MainWindow::device_dataReady);

}


void MainWindow::on_btnSend_clicked()
{
    auto message = ui->lineEdit_Message->text().trimmed();
    _controller.send(message);
}

