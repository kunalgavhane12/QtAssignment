#include "VideoPlayer.h"
#include "ui_videoplayer.h"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoPlayer)
{
    ui->setupUi(this);

    Player = new QMediaPlayer();

    ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_Stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_Seek_Backward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_Seek_Forward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

    ui->horizontalSlider_Volume->setMinimum(0);
    ui->horizontalSlider_Volume->setMaximum(100);
    ui->horizontalSlider_Volume->setValue(30);

    Player->setVolume(ui->horizontalSlider_Volume->value());
}

VideoPlayer::~VideoPlayer()
{
    delete ui;
}


void VideoPlayer::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Select Video  File"),"",tr("MP4 Files(*.avi, *.mpg, *.mp4)"));

    Video = new QVideoWidget();

    Video->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);

    Video->setParent(ui->groupBox_Video);

    Player->setVideoOutput(Video);

    Player->setMedia(QUrl(fileName));

    Video->setVisible(true);

    Video->show();

    Player->play();
}


void VideoPlayer::on_horizontalSlider_Duration_valueChanged(int value)
{
    Player->setPosition(value * 1000);
}

void VideoPlayer::on_pushButton_Play_Pause_clicked()
{
    if(Is_Pause == true)
    {
       Is_Pause = false;
       Player->play();
       ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    }
    else
    {
        Is_Pause = true;
        Player->pause();
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}


void VideoPlayer::on_pushButton_Stop_clicked()
{
    Player->stop();
}


void VideoPlayer::on_pushButton_Volume_clicked()
{
    if(Is_Muted == false)
    {
       Is_Muted = true;
       ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
       Player->setMuted(true);
    }
    else
    {
        Is_Muted = false;
        ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        Player->setMuted(false);
    }
}


void VideoPlayer::on_horizontalSlider_Volume_valueChanged(int value)
{
    Player->setVolume(value);
}


void VideoPlayer::on_pushButton_Seek_Backward_clicked()
{
    ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value() - 20);
    Player->setPosition(ui->horizontalSlider_Duration->value() * 1000);
}


void VideoPlayer::on_pushButton_Seek_Forward_clicked()
{
    ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value() + 20);
    Player->setPosition(ui->horizontalSlider_Duration->value() * 1000);
}

