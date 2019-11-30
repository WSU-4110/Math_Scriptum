QT += testlib
QT += gui

CONFIG += qt warn_on depend_includepath testcase

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_sultanadilunittest.cpp
HEADERS += \
    ../Math_Scriptum/mainwindow.h
