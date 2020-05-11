#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QGraphicsOpacityEffect>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //scale 缩放
    QPropertyAnimation *pScaleAnimation1 = new QPropertyAnimation(ui->scaleButton, "geometry");
    pScaleAnimation1->setDuration(1000);
    pScaleAnimation1->setStartValue(QRect(260, 360, 0, 0));
    pScaleAnimation1->setEndValue(QRect(360, 160, 140, 140));
    pScaleAnimation1->setEasingCurve(QEasingCurve::InOutQuad);

    QPropertyAnimation *pScaleAnimation2 = new QPropertyAnimation(ui->scaleButton, "geometry");
    pScaleAnimation2->setDuration(1000);
    pScaleAnimation2->setStartValue(QRect(360, 160, 140, 140));
    pScaleAnimation2->setEndValue(QRect(260, 360, 0, 0));
    pScaleAnimation2->setEasingCurve(QEasingCurve::InOutQuad);

    QSequentialAnimationGroup *pScaleGroup = new QSequentialAnimationGroup(this);
    pScaleGroup->addAnimation(pScaleAnimation1);
    pScaleGroup->addAnimation(pScaleAnimation2);

    //pos 位移
    QPropertyAnimation *pPosAnimation1 = new QPropertyAnimation(ui->posButton, "pos");
    pPosAnimation1->setDuration(1000);
    pPosAnimation1->setStartValue(QPoint(600, 120));
    pPosAnimation1->setEndValue(QPoint(600, 360));
    pPosAnimation1->setEasingCurve(QEasingCurve::InOutQuad);

    QSequentialAnimationGroup *pPosGroup = new QSequentialAnimationGroup(this);
    pPosGroup->addPause(500);
    pPosGroup->addAnimation(pPosAnimation1);

    // 串行显示
    QLabel *label1 = new QLabel(this);
    label1->setText("串行显示");
    label1->setGeometry(30, 70, 100, 30);
    QPropertyAnimation *animation1 = new QPropertyAnimation(label1, "geometry");
    animation1->setDuration(2000);
    animation1->setStartValue(QRect(30, 70, 100, 30));
    animation1->setEndValue(QRect(250, 260, 120, 30));
    animation1->setEasingCurve(QEasingCurve::OutBounce);

    QLabel *label2 = new QLabel(this);
    label2->setText("Hello QT!");
    label2->setGeometry(30, 100, 100, 30);
    QPropertyAnimation *animation2 = new QPropertyAnimation(label2, "geometry");
    //QPropertyAnimation *animation2 = new QPropertyAnimation(&button, "geometry");
    animation2->setDuration(1000);
    animation2->setStartValue(QRect(30,100, 100, 30));
    animation2->setEndValue(QRect(250, 360, 120, 60));

// 串行动画组
//    QSequentialAnimationGroup group;
//    group.addAnimation(animation1);
//    group.addAnimation(animation2);
//    QSequentialAnimationGroup *group = new QSequentialAnimationGroup(this);
//    group->addAnimation(animation1);
//    group->addAnimation(animation2);

    //动画组 串行
    QSequentialAnimationGroup *pOpacityGroup = new QSequentialAnimationGroup(this);
    pOpacityGroup->addPause(1000);
    pOpacityGroup->addAnimation(animation1);
    pOpacityGroup->addAnimation(animation2);

    //动画组 并行
    m_group = new QParallelAnimationGroup(this);
    m_group->addAnimation(pScaleGroup);
    m_group->addAnimation(pPosGroup);
    m_group->addAnimation(animation1);
    m_group->addAnimation(animation2);
    //m_group->addAnimation(pOpacityGroup);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    m_group->setDirection(QAbstractAnimation::Forward);
    m_group->setLoopCount(1);
    m_group->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    m_group->setDirection(QAbstractAnimation::Backward);
    m_group->setLoopCount(1);
    m_group->start();
}
