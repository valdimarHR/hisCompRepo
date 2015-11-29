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
    list.cpp \
    people.cpp

HEADERS += \
    list.h \
    people.h

FORMS +=

OTHER_FILES += \
    database.csv
