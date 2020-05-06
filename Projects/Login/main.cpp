#include "dialog.h"
#include <QApplication>
#include "registerdialog.h"
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog dialog_login;
    RegisterDialog dialog_reg;
    Dialog w;
    //w.show();

    if(dialog_login.exec() == QDialog::Accepted){
        switch (dialog_login.flag) {
            case 1:
                w.show();
                break;
            case 2:
                dialog_reg.show();
                break;
            default:
                break;
        }
    }

    return a.exec();
}

