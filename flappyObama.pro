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
    bestscore.cpp \
    pause.cpp \
    button.cpp \
    game.cpp

HEADERS  += mainwindow.h \
    obama.h \
    map.h \
    food.h \
    menu.h \
    bestscore.h \
    pause.h \
    button.h \
    game.h \
    gameMode.h

FORMS    += mainwindow.ui
LIBS += -L"/home/semitro/libs/SFML-2.2/lib"
LIBS += -L"lib" #Инсталлятор должен будет скопировать файлы библиотеки в /usr/lib !
                     #Ещё надо будет создать файл с очками и записать туда значение 0
CONFIG(release, debug|release): LIBS +=  -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
INCLUDEPATH += "/home/semitro/libs/SFML-2.2/include"
DEPENDPATH += "/home/semitro/libs/SFML-2.2/include"
INCLUDEPATH += "include"
DEPENDPATH += "include"

RESOURCES += \
    res.qrc
