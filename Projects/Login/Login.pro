#-------------------------------------------------
#
# Project created by QtCreator 2020-05-05T21:18:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Login
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    logindialog.cpp \
    registerdialog.cpp

HEADERS  += dialog.h \
    logindialog.h \
    registerdialog.h

FORMS    += dialog.ui \
    logindialog.ui \
    registerdialog.ui
