#-------------------------------------------------
#
# Project created by QtCreator 2015-08-25T15:12:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = TimeTester
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    algorithms.cpp \
    data.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    algorithms.h \
    data.h

FORMS    += mainwindow.ui
