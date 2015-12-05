#-------------------------------------------------
#
# Project created by QtCreator 2015-11-27T10:39:02
#
#-------------------------------------------------

QT       += core
QT       += core sql

QT       -= gui

TARGET = hisCompProject
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    Models/people.cpp \
    DataFetch/datafetch.cpp \
    UI/ui.cpp \
    Processor/logic.cpp \
    Models/computers.cpp \
    Models/computerswithpeople.cpp \
    Models/peoplewithcomputers.cpp

HEADERS += \
    Models/people.h \
    Utilities/constants.h \
    DataFetch/datafetch.h \
    UI/ui.h \
    Processor/logic.h \
    Models/computers.h \
    Models/computerswithpeople.h \
    Models/peoplewithcomputers.h

FORMS +=

OTHER_FILES += \
    database.csv
