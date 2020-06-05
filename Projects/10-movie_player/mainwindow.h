#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
class QMovie;
class QMediaPlaylist;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //视频播放器槽函数（关联方式 ui+代码）
    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_toggled(bool checked);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_spinBox_valueChanged(int arg1);
    //音乐播放器槽函数（关联方式 ui+代码）
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_horizontalSlider_2_sliderMoved(int position);

//变量
private:
    Ui::MainWindow *ui;
    QMovie *movie;

    QMediaPlayer *player;
    QMediaPlaylist *playlist;

//音乐播放器槽函数（关联方式1，纯代码）
private slots:
    void updatePosition(qint64 position);

    void stateChanged(QMediaPlayer::State state);
    void mediaStatusChanged(QMediaPlayer::MediaStatus status);
    void showError(QMediaPlayer::Error error);

    void metaDataAvailableChanged(bool available);
};

#endif // MAINWINDOW_H


