#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T11:38:08
#
#-------------------------------------------------

QT       += core gui
QT       += core sql

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hisCompRepoUI
TEMPLATE = app
CONFIG   += c++11


SOURCES += main.cpp\
        DataFetch/datafetch.cpp\
        Models/computers.cpp\
        Models/computerswithpeople.cpp\
        Models/people.cpp\
        Models/peoplewithcomputers.cpp\
        Processor/logic.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h\
        Utilities/constants.h\
        DataFetch/datafetch.h\
        Models/computers.h\
        Models/computerswithpeople.h\
        Models/people.h\
        Models/peoplewithcomputers.h\
        Processor/logic.h

FORMS    += mainwindow.ui
