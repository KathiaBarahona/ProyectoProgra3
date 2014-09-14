#-------------------------------------------------
#
# Project created by QtCreator 2014-09-06T16:55:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EstadisticaCarro
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    carro.cpp \
    factura.cpp \
    gasfactura.cpp

HEADERS  += mainwindow.h \
    carro.h \
    factura.h \
    gasfactura.h

FORMS    += mainwindow.ui \
    gasfactura.ui
