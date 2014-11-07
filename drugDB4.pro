#-------------------------------------------------
#
# Project created by QtCreator 2014-04-30T16:07:40
#
#-------------------------------------------------

QT       += core gui
DESTDIR = $$PWD
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = drugDB4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    SideEffect.cpp \
    Pharmaciemanager.cpp \
    Pharmacie.cpp \
    Medicin.cpp \
    result.cpp \
    modifier.cpp \
    dialog_phname.cpp

HEADERS  += mainwindow.h \
    SideEffect.h \
    Pharmaciemanager.h \
    Pharmacie.h \
    Medicin.h \
    result.h \
    modifier.h \
    dialog_phname.h

FORMS    += mainwindow.ui \
    result.ui \
    modifier.ui \
    dialog_phname.ui
