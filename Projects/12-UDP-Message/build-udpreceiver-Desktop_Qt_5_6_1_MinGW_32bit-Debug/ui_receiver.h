/********************************************************************************
** Form generated from reading UI file 'receiver.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVER_H
#define UI_RECEIVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Receiver
{
public:
    QLabel *label;

    void setupUi(QDialog *Receiver)
    {
        if (Receiver->objectName().isEmpty())
            Receiver->setObjectName(QStringLiteral("Receiver"));
        Receiver->resize(400, 300);
        label = new QLabel(Receiver);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 130, 191, 41));

        retranslateUi(Receiver);

        QMetaObject::connectSlotsByName(Receiver);
    } // setupUi

    void retranslateUi(QDialog *Receiver)
    {
        Receiver->setWindowTitle(QApplication::translate("Receiver", "Receiver", 0));
        label->setText(QApplication::translate("Receiver", "\347\255\211\345\276\205\346\216\245\346\224\266\346\225\260\346\215\256\357\274\201", 0));
    } // retranslateUi

};

namespace Ui {
    class Receiver: public Ui_Receiver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVER_H
