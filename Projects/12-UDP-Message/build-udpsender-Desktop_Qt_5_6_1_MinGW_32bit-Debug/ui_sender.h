/********************************************************************************
** Form generated from reading UI file 'sender.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDER_H
#define UI_SENDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Sender
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Sender)
    {
        if (Sender->objectName().isEmpty())
            Sender->setObjectName(QStringLiteral("Sender"));
        Sender->resize(400, 300);
        pushButton = new QPushButton(Sender);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 120, 75, 23));
        lineEdit = new QLineEdit(Sender);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 90, 113, 21));

        retranslateUi(Sender);

        QMetaObject::connectSlotsByName(Sender);
    } // setupUi

    void retranslateUi(QDialog *Sender)
    {
        Sender->setWindowTitle(QApplication::translate("Sender", "Sender", 0));
        pushButton->setText(QApplication::translate("Sender", "\350\277\233\350\241\214\345\271\277\346\222\255", 0));
    } // retranslateUi

};

namespace Ui {
    class Sender: public Ui_Sender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDER_H
