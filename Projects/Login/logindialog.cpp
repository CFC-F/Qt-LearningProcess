#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    flag = 0;
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{
    flag = 1;
    if(ui->lineEdit->text()==tr("阳光")&&
            ui->lineEdit_2->text()==tr("123456")){
        accept();
    }
    else{
        QMessageBox::warning(this,tr("Warning"),
                            tr("user name or password error!"),
                            QMessageBox::Yes);

        //清空内容并定位光标
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit->setFocus();
    }
}

void LoginDialog::on_pushButton_2_clicked()
{
    flag = 2;
    accept();
}
