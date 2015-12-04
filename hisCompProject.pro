#-------------------------------------------------
#
# Project created by QtCreator 2015-11-27T10:39:02
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = hisCompProject
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    Processor/list.cpp \
    Models/people.cpp \
    DataFetch/datafetch.cpp \
    UI/display.cpp

HEADERS += \
    Processor/list.h \
    Models/people.h \
    Utilities/constants.h \
    DataFetch/datafetch.h \
    UI/display.h

FORMS +=

OTHER_FILES += \
    database.csv
