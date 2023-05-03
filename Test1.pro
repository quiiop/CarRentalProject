#-------------------------------------------------
#
# Project created by QtCreator 2023-04-30T11:48:40
#
#-------------------------------------------------
QT       += core gui
QT       += sql
QT       += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test1
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

INCLUDEPATH = $$PWD\Code \

SOURCES += \
        Code\main.cpp \
        Code\mainwindow.cpp \
    Code/test2.cpp \
    Code/car.cpp \
    Code/test1.cpp \
    Code/database.cpp

HEADERS += \
        Code\mainwindow.h \
    Code/test2.h \
    Code/car.h \
    Code/test1.h \
    Code/database.h

FORMS += \
        Code\mainwindow.ui \
    Code/test2.ui \
    Code/test1.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
