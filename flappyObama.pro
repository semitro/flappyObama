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
    map.cpp \
    food.cpp \
    menu.cpp \
    bestscore.cpp

HEADERS  += mainwindow.h \
    obama.h \
    map.h \
    food.h \
    menu.h \
    bestscore.h

FORMS    += mainwindow.ui

LIBS += -L"lib/SFML" #Инсталлятор должен будет скопировать файлы библиотеки в /usr/lib !
                     #Ещё надо будет создать файл с очками и записать туда значение 0
CONFIG(release, debug|release): LIBS +=  -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += "include"
DEPENDPATH += "include"

RESOURCES += \
    res.qrc
