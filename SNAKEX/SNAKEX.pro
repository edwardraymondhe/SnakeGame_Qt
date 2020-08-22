#-------------------------------------------------
#
# Project created by QtCreator 2019-09-13T00:15:51
#
#-------------------------------------------------

QT       += core gui    \
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SNAKEX
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        brick.cpp \
        button.cpp \
        fastfood.cpp \
        food.cpp \
        main.cpp \
        mainwindow.cpp \
        normalfood.cpp \
        obj.cpp \
        rules.cpp \
        slowfood.cpp \
        snake.cpp \
        wall.cpp

HEADERS += \
        brick.h \
        button.h \
        constants.h \
        fastfood.h \
        food.h \
        mainwindow.h \
        normalfood.h \
        obj.h \
        rules.h \
        slowfood.h \
        snake.h \
        wall.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
