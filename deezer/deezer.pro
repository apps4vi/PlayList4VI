#-------------------------------------------------
#
# Project created by QtCreator 2015-01-06T11:10:28
#
#-------------------------------------------------

QT       += network sql testlib

QT       -= gui

TARGET = deezerlib

TEMPLATE = lib

CONFIG += staticlib

SOURCES += deezer.cpp

HEADERS += deezer.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
