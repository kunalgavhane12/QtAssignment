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

    connect(Player, &QMediaPlayer::durationChanged, this, &VideoPlayer::durationChanged);
    connect(Player, &QMediaPlayer::positionChanged, this, &VideoPlayer::positionChanged);

    ui->horizontalSlider_Duration->setRange(0, Player->duration() / 1000);
}

VideoPlayer::~VideoPlayer()
{
    delete ui;
}

void VideoPlayer::durationChanged(qint64 duration)
{
    mDuration = duration / 1000;
    ui->horizontalSlider_Duration->setMaximum(mDuration);
}

void VideoPlayer::positionChanged(qint64 duration)
{
    if(!ui->horizontalSlider_Duration->isSliderDown())
    {
        ui->horizontalSlider_Duration->setValue(duration / 1000);
    }
    updateDuration(duration / 1000);
}


void VideoPlayer::updateDuration(qint64 Duration)
{
    if(Duration || mDuration)
    {
        QTime CurremtTime((Duration / 3600) % 60,(Duration / 60) % 60,  Duration % 60, (Duration * 1000) % 1000);
        QTime TotalTime((mDuration / 3600) % 60,(mDuration / 60) % 60, mDuration % 60, (mDuration * 1000) % 1000);

        QString Format = "";
        if(mDuration > 3600)
        {
            Format = "hh:mm:ss";
        }
        else
        {
            Format = "mm:ss";
        }

        ui->label_Current_Time->setText(CurremtTime.toString(Format));
        ui->label_Total_Time->setText(TotalTime.toString(Format));
    }
}


void VideoPlayer::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Select Video  File"),"",tr("MP4 Files(*.mkv, *.avi, *.mpg, *.mp4)"));

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
    if(is_Pause == true)
    {
       is_Pause = false;
       Player->play();
       ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    }
    else
    {
        is_Pause = true;
        Player->pause();
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}


void VideoPlayer::on_pushButton_Stop_clicked()
{
    Player->stop();
    Player->setPosition(0);
}


void VideoPlayer::on_pushButton_Volume_clicked()
{
    if(is_Muted == false)
    {
       is_Muted = true;
       ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
       Player->setMuted(true);
    }
    else
    {
        is_Muted = false;
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

