#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->textEdit->installEventFilter(this);
    ui->plainTextEdit->installEventFilter(this);
    ui->label->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *obj, QEvent *event) // 事件过滤器
{

    if(obj == ui->textEdit)
    {              // 如果是lineEdit部件上的事件
        if(event->type() == QEvent::KeyPress)
        {

            if(windowState() != Qt::WindowMaximized)      // 如果现在不是全屏
                setWindowState(Qt::WindowMaximized);      // 将窗口设置为全屏
             //setWindowState(Qt::WindowMaximized);   // 窗口最大化
             ui->label_2->setText("键盘按下，窗口最大化");
        }

    }
   if(obj == ui->plainTextEdit){              // 如果是lineEdit部件上的事件
        if(event->type() == QEvent::KeyPress)
        {
            //if(windowState() == Qt::WindowMaximized)      // 如果现在不是全屏
                setWindowState(Qt::WindowNoState);        // 否则恢复以前的大小
             //this->resize(500,500);
             //setWindowState(Qt::WindowMinimized);
             ui->label_2->setText("键盘按下,恢复大小");
        }
    }


//返回父类，其他的都错
    return QWidget::eventFilter(obj, event);
}



void Widget::mousePressEvent(QMouseEvent *event) // 鼠标按下事件
{
    if(event->button() == Qt::LeftButton)
    {             // 如果是鼠标左键按下
        if(windowState() != Qt::WindowFullScreen)      // 如果现在不是全屏
        {
            setWindowState(Qt::WindowFullScreen);      // 将窗口设置为全屏
            ui->label_2->setText("鼠标左键按下，窗口最大化");
        }

        //else setWindowState(Qt::WindowNoState);        // 否则恢复以前的大小
    }
    else if(event->button() == Qt::RightButton)
    {             // 如果是鼠标左键按下
        if(windowState() == Qt::WindowFullScreen)      // 如果现在不是全屏
        {
            setWindowState(Qt::WindowNoState);        // 否则恢复以前的大小
            ui->label_2->setText("鼠标右键按下，恢复大小");
        }

    }
}

void Widget::keyPressEvent(QKeyEvent *event)       // 键盘按下事件
{
    if(event->modifiers() == Qt::ControlModifier){ // 是否按下Ctrl键
        if(event->key() == Qt::Key_M)              // 是否按下M键
        {
            this->focusNextPrevChild(true);               //进行焦点切换，切换至下一个部件
            ui->label->setText("切换至下一个部件");
        }

        else if(event->key() == Qt::Key_N)              // 是否按下N键
        {
            this->focusNextPrevChild(false);               //进行焦点切换，切换至上一个部件
             ui->label->setText("切换至上一个部件");
        }

    }
    else QWidget::keyPressEvent(event);
}
