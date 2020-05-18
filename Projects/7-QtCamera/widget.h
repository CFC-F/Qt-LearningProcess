#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
class QMediaPlaylist;
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QMediaRecorder;
class QAudioRecorder;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QCamera *camera;
    QMediaRecorder *recorder;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;
    QAudioRecorder *audioRecorder;

private slots:
    void updatePosition(qint64 position);
    void stateChanged(QMediaPlayer::State state);
    void mediaStatusChanged(QMediaPlayer::MediaStatus status);
    void metaDataAvailableChanged(bool available);
    void showError(QMediaPlayer::Error error);
    void on_pushButton_Play_clicked();
    void on_pushButton_Pause_clicked();
    void on_pushButton_Stop_clicked();
    void on_horizontalSlider_sliderMoved(int position);
    void on_pushButton_Capture_clicked();
    void on_pushButton_Open_Camera_clicked();
    void on_pushButton_Close_Camera_clicked();
//    void updateProgress(qint64 duration);
//    void on_pushButton_Start_Recorder_clicked();
//    void on_pushButton_Stop_Recorder_clicked();
//    void on_pushButton_clicked();
};

#endif // WIDGET_H
