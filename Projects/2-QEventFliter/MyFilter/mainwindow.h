#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMatrix>
#include <QTextFrame>
#include <QLineEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool eventFilter(QObject *obj, QEvent *event);
private slots:
    void on_pushButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QImage Img;
    bool x;
};

#endif // MAINWINDOW_H
