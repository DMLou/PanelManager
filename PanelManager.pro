#-------------------------------------------------
#
# Project created by QtCreator 2015-05-01T19:33:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PanelManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    external/sqlite/sqlite3.c \
    DbWrapper.cpp

HEADERS  += mainwindow.h \
    external/sqlite/sqlite3.h \
    DbWrapper.h

FORMS    += \
    mainwindow.ui
