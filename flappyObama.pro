#-------------------------------------------------
#
# Project created by QtCreator 2015-04-25T14:51:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = flappyObama
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    obama.cpp \
    map.cpp

HEADERS  += mainwindow.h \
    obama.h \
    map.h

FORMS    += mainwindow.ui

LIBS += -L"/home/semitro/libs/SFML-2.2/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += "/home/semitro/libs/SFML-2.2/include"
DEPENDPATH += "/home/semitro/libs/SFML-2.2/include"
