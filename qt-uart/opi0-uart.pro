QT += core serialport
QT -= gui

TARGET = opi0-uart
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    opiuart.cpp

HEADERS += \
    opiuart.h

