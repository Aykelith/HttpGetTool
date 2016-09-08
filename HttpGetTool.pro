#-------------------------------------------------
#
# Project created by QtCreator 2016-09-08T09:47:46
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HttpGetTool
TEMPLATE = app
INCLUDEPATH += src

SOURCES += src/main.cpp \
        src/MainWindow.cpp \
    src/JSONHighlighter.cpp

HEADERS  += src/MainWindow.hpp \
    src/JSONHighlighter.hpp
