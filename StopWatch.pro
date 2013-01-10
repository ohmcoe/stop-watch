#-------------------------------------------------
#
# Project created by QtCreator 2013-01-07T13:54:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StopWatch
TEMPLATE = app

CONFIG += static
static{
    CONFIG += static
    QTPLUGIN += qico
    DEFINES += STATIC
    message("Static build.")
}

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

OTHER_FILES +=

RESOURCES += \
    resources.qrc
