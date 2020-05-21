#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


//键盘按下事件
void Widget::keyPressEvent(QKeyEvent *event)       // 键盘按下事件
{
    qDebug() << tr("键盘按下事件");
    //ui->label->setText(ui->label->text().append("键盘按下事件"));
    ui->label_3->setText("键盘按下事件");

    //复合键值-ctrl+M,最大化，恢复大小
    if(event->modifiers() == Qt::ControlModifier)     // 是否按下Ctrl键
    {
        if(event->key() == Qt::Key_M)                // 是否按下M键
        {
            if(windowState() != Qt::WindowMaximized)
            {
                qDebug() << tr("键盘键值-Ctrl+M");
                ui->label->setText("Ctrl+M-最大化");
                setWindowState(Qt::WindowMaximized);   // 窗口最大化
            }

            else setWindowState(Qt::WindowNoState);    // 否则恢复以前的大小
        }

    }
    else QWidget::keyPressEvent(event);


//    //ctrl+M,最大化
//    if(event->modifiers() == Qt::ControlModifier){ // 是否按下Ctrl键
//        if(event->key() == Qt::Key_M)              // 是否按下M键
//        {
//            qDebug() << tr("键盘键值-Ctrl+M");
//            ui->label->setText(ui->label->text().append("键盘键值-Ctrl+M"));
//            setWindowState(Qt::WindowMaximized);   // 窗口最大化
//        }

//    }
//    else QWidget::keyPressEvent(event);

    //单键键值
    switch (event->key())
        {
            //ESC键s
            case Qt::Key_Escape:
                qDebug() << tr("键盘键值-ESC");
                //ui->label->setText(ui->label->text().append("键盘键值-ESC"));
                ui->label->setText("ESC");
            break;
            //回车键
            case Qt::Key_Return:
                qDebug() <<"Enter";
                //ui->label->setText(ui->label->text().append("Enter"));
                ui->label->setText("Enter");
            break;
            //退格键
            case Qt::Key_Backspace:
                qDebug() <<"Back";
                //ui->label->setText(ui->label->text().append("Back"));
                ui->label->setText("Back");
            break;
            //空格键
            case Qt::Key_Space:
                qDebug() <<"Space";
                //ui->label->setText(ui->label->text().append("Space"));
                ui->label->setText("Space");
            break;
            //F1键
            case Qt::Key_F1:
                qDebug() <<"F1";
                //ui->label->setText(ui->label->text().append("F1"));
                ui->label->setText("F1");
            break;
        }
}

// 按键释放事件
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << tr("键盘释放事件");
    //ui->label->setText(ui->label->text().append("键盘释放事件"));
    ui->label_3->setText("键盘释放事件");
    if(event->key() == Qt::Key_Up)
        {
            qDebug() << "release: "<< "up";
        }

    //ctrl+N,全屏放缩（全屏与最大化不同）
    if(event->modifiers() == Qt::ControlModifier){ // 是否按下Ctrl键
        if(event->key() == Qt::Key_N)              // 是否按下N键
        {
             //setWindowState(Qt::WindowMinimized);        // 窗口最大化
            if(windowState() != Qt::WindowFullScreen)      // 如果现在不是全屏
                setWindowState(Qt::WindowFullScreen);      // 将窗口设置为全屏
            else setWindowState(Qt::WindowNoState);        // 否则恢复以前的大小
        }

    }
    else QWidget::keyPressEvent(event);
}
