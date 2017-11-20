#-------------------------------------------------
#
# Project created by QtCreator 2013-01-07T13:54:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StopWatch
TEMPLATE = app

SOURCES += main.cpp\
    widget.cpp \
    stopwatch.cpp

HEADERS += widget.h \
    stopwatch.h \
    version.h

FORMS   += \
    widget.ui

RC_FILE = StopWatch.rc

OTHER_FILES += \
    StopWatch.rc

RESOURCES += \
    resources.qrc

CONFIG += static staticlib
