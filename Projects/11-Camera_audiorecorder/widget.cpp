#include "widget.h"
#include "ui_widget.h"
#include <QAudioRecorder>
#include <QDebug>
#include <QFileDialog>

#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //音频录制模块
    audioRecorder = new QAudioRecorder;

    QStringList inputs = audioRecorder->audioInputs();
    ui->comboBox->addItems(inputs);

    connect(audioRecorder, &QAudioRecorder::durationChanged, this,
            &Widget::updateProgress);

    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/pcm");
    audioSettings.setQuality(QMultimedia::HighQuality);
    audioRecorder->setAudioSettings(audioSettings);

    //相机拍照模块
    //设置摄像头
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if(cameras.count() > 0) {
        foreach (const QCameraInfo &cameraInfo, cameras) {
            qDebug() << cameraInfo.description();
        }
        //cameras.at(0)，使用第一个摄像头
        camera = new QCamera(cameras.at(0));
    }

    viewfinder = new QCameraViewfinder(this);
    camera->setViewfinder(viewfinder);
    viewfinder->resize(600, 350);

    imageCapture = new QCameraImageCapture(camera);

    camera->start();
}

Widget::~Widget()
{
    delete ui;
}

//音频录制槽函数（关联方式 ui+代码）
// 选择按钮
void Widget::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName();
    ui->lineEdit->setText(fileName);
}

// 开始按钮
void Widget::on_pushButton_3_clicked()
{
    audioRecorder->setAudioInput(ui->comboBox->currentText());
    audioRecorder->setOutputLocation(QUrl::fromLocalFile(ui->lineEdit->text()));
    audioRecorder->record();
}

// 停止按钮
void Widget::on_pushButton_4_clicked()
{
    audioRecorder->stop();
}

void Widget::updateProgress(qint64 duration)
{
    if (audioRecorder->error() != QMediaRecorder::NoError || duration < 1000)
        return;
    //duration指毫秒
    setWindowTitle(tr("Recorded %1 sec").arg(duration / 1000));
}


//相机照相槽函数
// 拍照按钮
void Widget::on_pushButton_clicked()
{
    camera->setCaptureMode(QCamera::CaptureStillImage);
    QString fileName = QFileDialog::getSaveFileName();
    camera->searchAndLock();
    // 必须使用绝对路径，capture()函数用于捕获以及保存
    imageCapture->capture(fileName);
    camera->unlock();
}
