#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QMediaPlaylist>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //视频播放器

    // 设置标签的对齐方式为居中对齐、自动填充背景为暗色
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setBackgroundRole(QPalette::Dark);
    ui->label->setAutoFillBackground(true);
    movie = new QMovie(this);
    movie->setFileName("../Test10-movie_player/movie.gif");
    // 设置缓存模式
    movie->setCacheMode(QMovie::CacheAll);
    // 设置动画大小为标签的大小
    QSize size = ui->label->size();
    movie->setScaledSize(size);
    ui->label->setMovie(movie);
    // 设置水平滑块的最大最小值，当动画播放时自动更改滑块的值
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(movie->frameCount());
    connect(movie, &QMovie::frameChanged,
            ui->horizontalSlider, &QSlider::setValue);

    //音乐播放器
    //变量名 ， 类
    player = new QMediaPlayer(this);
    //player->setMedia(QUrl::fromLocalFile("D:/QTproject/SrcProjects/13/13-5/myplayer/music3.mp3"));

    connect(player, &QMediaPlayer::positionChanged,
            this, &MainWindow::updatePosition);

    connect(player, &QMediaPlayer::stateChanged, this, &MainWindow::stateChanged);
    connect(player, &QMediaPlayer::mediaStatusChanged,
            this, &MainWindow::mediaStatusChanged);
    connect(player, static_cast<void(QMediaPlayer::*)(QMediaPlayer::Error)>
            (&QMediaPlayer::error), this, &MainWindow::showError);

//    connect(player, &QMediaPlayer::metaDataAvailableChanged,
//            this, &MainWindow::metaDataAvailableChanged);
    playlist = new QMediaPlaylist;
    //playlist->addMedia(QUrl::fromLocalFile("D:/QTproject/SrcProjects/13/13-5/myplayer/music.mp3"));
    //路径可以使用绝对或者相对路径
    //playlist->addMedia(QUrl::fromLocalFile("../myplayer/music2.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("D:/QTproject/SrcProjects/13/13-5/myplayer/music2.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("D:/QTproject/SrcProjects/13/13-5/myplayer/music3.mp3"));
    playlist->setCurrentIndex(0);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);

    connect(player, &QMediaPlayer::metaDataAvailableChanged,
            this, &MainWindow::metaDataAvailableChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//视频播放器槽函数（关联方式为ui+代码）
void MainWindow::on_horizontalSlider_valueChanged(int value)
{// 播放进度
    movie->jumpToFrame(value);
}

void MainWindow::on_pushButton_clicked()
{// 开始按钮
    movie->start();
}

void MainWindow::on_pushButton_2_toggled(bool checked)
{// 暂停按钮
    movie->setPaused(checked);
}

void MainWindow::on_pushButton_3_clicked()
{// 停止按钮
    movie->stop();
}

void MainWindow::on_pushButton_4_clicked()
{// 截屏按钮
    int id = movie->currentFrameNumber();
    QPixmap pix = movie->currentPixmap();
    pix.save(QString("../Test10-movie_player/%1.png").arg(id));
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{// 播放速度
    movie->setSpeed(arg1);
}

//音乐播放器槽函数（关联方式为ui+代码）

void MainWindow::on_pushButton_6_clicked()
{ // 播放
    player->play();
}

void MainWindow::on_pushButton_7_clicked()
{ // 暂停
    player->pause();
}

void MainWindow::on_pushButton_5_clicked()
{ // 停止
    player->stop();
}


void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{ // 设置播放进度
    player->setPosition(position * 1000);
}

//音乐播放器槽函数（关联方式，纯代码型）
void MainWindow::updatePosition(qint64 position)
{ // 更新滑块显示
    ui->horizontalSlider_2->setMaximum(player->duration() / 1000);
    ui->horizontalSlider_2->setValue(position / 1000);
}

void MainWindow::mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    switch (status) {
    case QMediaPlayer::UnknownMediaStatus:
        ui->label_5->setText(tr("媒体未知状况！"));
        break;
    case QMediaPlayer::NoMedia:
        ui->label_5->setText(tr("没有媒体文件！"));
        break;
    case QMediaPlayer::BufferingMedia:
        ui->label_5->setText(tr("正在缓冲媒体文件！"));
        break;
    case QMediaPlayer::BufferedMedia:
        ui->label_5->setText(tr("媒体文件缓冲完成！"));
        break;
    case QMediaPlayer::LoadingMedia:
        ui->label_5->setText(tr("正在加载媒体！"));
        break;
    case QMediaPlayer::StalledMedia:
        ui->label_5->setText(tr("播放停滞！"));
        break;
    case QMediaPlayer::EndOfMedia:
        ui->label_5->setText(tr("播放结束！"));
        break;
    case QMediaPlayer::LoadedMedia:
        ui->label_5->setText(tr("媒体加载完成！"));
        break;
    case QMediaPlayer::InvalidMedia:
        ui->label_5->setText(tr("不可用的媒体文件！"));
        break;
    default: break;
    }
}

void MainWindow::stateChanged(QMediaPlayer::State state)
{
    switch (state) {
    case QMediaPlayer::StoppedState:
        ui->label_4->setText(tr("停止状态！"));
        break;
    case QMediaPlayer::PlayingState:
        ui->label_4->setText(tr("播放状态！"));
        break;
    case QMediaPlayer::PausedState:
        ui->label_4->setText(tr("暂停状态！"));
        break;
    default: break;
    }
}

void MainWindow::showError(QMediaPlayer::Error error)
{
    switch (error) {
    case QMediaPlayer::NoError:
        ui->label_3->setText(tr("没有错误！"));
        break;
    case QMediaPlayer::ResourceError:
        ui->label_3->setText(tr("媒体资源无法被解析！"));
        break;
    case QMediaPlayer::FormatError:
        ui->label_3->setText(tr("不支持该媒体格式！"));
        break;
    case QMediaPlayer::NetworkError:
        ui->label_3->setText(tr("发生了一个网络错误！"));
        break;
    case QMediaPlayer::AccessDeniedError:
        ui->label_3->setText(tr("没有播放权限！"));
        break;
    case QMediaPlayer::ServiceMissingError:
        ui->label_3->setText(tr("没有发现有效的播放服务！"));
        break;
    default: break;
    }
}

// 获取元数据
void MainWindow::metaDataAvailableChanged(bool available)
{
    if(available) {
        QString title = player->metaData("Title").toString();
        QString author = player->metaData("Author").toString();
        setWindowTitle(title + "-" + author);
    }
}
