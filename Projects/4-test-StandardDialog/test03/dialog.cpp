#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QColorDialog>
#include <QFontDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QPalette pal=ui->plainTextEdit->palette();  //获取文本框的palette
    QColor iniColor=pal.color(QPalette::Text);   //现有的文字的颜色
    QColor color=QColorDialog::getColor(iniColor,this,"选择颜色");
    if(color.isValid())//如果颜色是可用的
    {
        pal.setColor(QPalette::Text,color);//设置QPalette对象
        ui->plainTextEdit->setPalette(pal);//设置文本框颜色
    }
}

void Dialog::on_pushButton_2_clicked()
{
        QFont iniFont=ui->plainTextEdit->font();//获取文本框字体
        bool ok=false;
        QFont font=QFontDialog::getFont(&ok,iniFont);
        if(ok)
        ui->plainTextEdit->setFont(font);
}
