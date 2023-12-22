#include "clientchatwidget.h"
#include "ui_clientchatwidget.h"

ClientChatWidget::ClientChatWidget(QTcpSocket *client, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientChatWidget),
    _client(client)
{
    ui->setupUi(this);
    connect(_client, &QTcpSocket::readyRead,this, &ClientChatWidget::dataReceived);
    connect(_client, &QTcpSocket::disconnected,this, &ClientChatWidget::clientDisconnected);
}

ClientChatWidget::~ClientChatWidget()
{
    delete ui;
}

void ClientChatWidget::dataReceived()
{
    auto data = _client->readAll();
    ui->listMessage->addItem(data);
}

void ClientChatWidget::clientDisconnected()
{
    ui->WidgetSendMessage->setEnabled(false);
}

void ClientChatWidget::on_btnSend_clicked()
{
    _client->write(ui->lineEditMessage->text().trimmed().toUtf8());
    ui->lineEditMessage->setText("");
}

