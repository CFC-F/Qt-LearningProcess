#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QTextFrame>
//#include <QMatrix>
//#include <QLineEdit>
//#include <QVariant>
//#include <QEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //进行各项定义
    Img = ui->label->pixmap()->toImage();
    x = true;
     //安装事件过滤器函数
    ui->lineEdit->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//通过使用事件过滤器，控制图片的放大与缩小
bool MainWindow::eventFilter(QObject *obj, QEvent *event) // 事件过滤器
{
    if(obj == ui->lineEdit){              // 如果是lineEdit部件上的事件
        if(event->type() == QEvent::KeyPress)
        {
            if(x)
            {
                QMatrix matrix;
                matrix.scale(1.6,1.6);
                QImage tmpImg = Img.transformed(matrix);
                ui->label->setPixmap(QPixmap::fromImage(tmpImg));
                x=!x;
            }
            else
            {
                ui->label->setPixmap(QPixmap::fromImage(Img));
                x=!x;
            }
            return true;  //返回true 表示已处理
        }
        else
            return false;  //返回false，表示其他事件继续处理
    }
    return QWidget::eventFilter(obj, event);
}

//使用按钮，进行图片的放缩
void MainWindow::on_pushButton_clicked(bool checked)
{
    if(checked)
    {
        QMatrix matrix;
        matrix.scale(1.6,1.6);
        QImage tmpImg = Img.transformed(matrix);
        ui->label->setPixmap(QPixmap::fromImage(tmpImg));
    }
    else
    {
        ui->label->setPixmap(QPixmap::fromImage(Img));
    }
}
