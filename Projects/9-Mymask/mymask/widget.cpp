#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QMouseEvent>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置透明度
    //setWindowOpacity(0.6);

        //QPixmap pixmap(":/image/yafeilinux.png");
//    QPixmap pixmap(":/image/test1.png");
//    ui->label_2->setPixmap(pixmap);
//    ui->label_2->setMask(pixmap.mask());
    QPixmap pix;
    // 加载图片
    //pix.load(":/image/yafeilinux.png");
    pix.load(":/image/test12.png");
    //pix.load(":/image/test123.png");

    //背景透明，没设置这个的话会有毛边
    setAttribute(Qt::WA_TranslucentBackground);

    // 设置窗口大小为图片大小
    resize(pix.size());
    // 为窗口设置遮罩
    setMask(pix.mask());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    // 从窗口左上角开始绘制图片
    //painter.drawPixmap(10, 0, QPixmap(":/image/yafeilinux.png"));
    painter.drawPixmap(0, 0, QPixmap(":/image/test12.png"));
    //painter.drawPixmap(0,0, QPixmap(":/image/test123.png"));
    //QPainter painter(this);
   // painter.fillRect(rect(), QColor(255,255,255,100));
}

//void Widget::mousePressEvent(QMouseEvent *)
//{   // 关闭窗口
//    close();
//}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        dragPosition = event->globalPos() - frameGeometry().topLeft();
    }else if(event->button() == Qt::RightButton){
        close();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton){
        move(event->globalPos() - dragPosition);
    }
}

