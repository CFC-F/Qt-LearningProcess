#-------------------------------------------------
#
# Project created by QtCreator 2016-05-25T23:13:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myrichtext
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mysyntaxhighlighter.cpp

HEADERS  += mainwindow.h \
    mysyntaxhighlighter.h

FORMS    += mainwindow.ui

QT += printsupport
