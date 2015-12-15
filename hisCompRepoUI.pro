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
        mainwindow.cpp \
    UI/edit.cpp \
    UI/editcomputers.cpp \
    UI/clickscientist.cpp \
    UI/clickcomputer.cpp \
    UI/secretsanta.cpp \
    UI/readme.cpp

HEADERS  += mainwindow.h\
        Utilities/constants.h\
        DataFetch/datafetch.h\
        Models/computers.h\
        Models/computerswithpeople.h\
        Models/people.h\
        Models/peoplewithcomputers.h\
        Processor/logic.h \
    UI/edit.h \
    UI/editcomputers.h \
    UI/clickscientist.h \
    UI/clickcomputer.h \
    UI/secretsanta.h \
    UI/readme.h

FORMS    += mainwindow.ui \
    UI/edit.ui \
    UI/editcomputers.ui \
    UI/clickscientist.ui \
    UI/clickcomputer.ui \
    UI/secretsanta.ui \
    UI/readme.ui

RESOURCES += \
    images.qrc \
    files.qrc
