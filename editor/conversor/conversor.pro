#-------------------------------------------------
#
# Project created by QtCreator 2011-11-20T10:58:05
#
#-------------------------------------------------

CONFIG -= qt
CONFIG   += console
CONFIG   -= app_bundle

QT       -= core
QT       -= gui

TARGET = conversor

CONFIG += win32
INCLUDEPATH += ..
INCLUDEPATH += ../..

win32 {
        LIBS =  -lmingw32 -lSDLmain -lSDL -mwindows

        INCLUDES = -I/usr/include/SDL \
        -I/usr/include \
        -I. \
        -I./include \
        -L/usr/lib \
        -I.. \
        -I../..

        QMAKE_CCFLAGS += -DWIN32 -DPC
        QMAKE_CXXFLAGS += -DWIN32 -DPC
}

TEMPLATE = app


SOURCES += main.cpp \
    ../../file/file_io.cpp

HEADERS += \
    ../../file/format.h \
    ../../file/file_io.h \
    ../../file/v_2_0_0.h \
    ../../file/v_1.h \
    ../../file/v_2_0_1.h \
    ../../file/v_2_0_2.h \
    ../../file/v_2_0_3.h \
    ../../file/v_2_0_4.h \
    ../../file/v_2_1.h \
    ../../file/v_2_1_1.h


