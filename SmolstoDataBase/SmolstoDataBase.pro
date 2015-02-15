#-------------------------------------------------
#
# Project created by QtCreator 2015-01-30T16:07:45
#
#-------------------------------------------------

QT       += core gui

TARGET = SmolstoDataBase
TEMPLATE = app

include(qtsingleapplication/src/qtsingleapplication.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    finder.cpp \
    client.cpp \
    loadsavebase.cpp \
    dialogsearchquery.cpp \
    dialogconfirmation.cpp

HEADERS  += mainwindow.h \
    finder.h \
    client.h \
    loadsavebase.h \
    dialogsearchquery.h \
    dialogconfirmation.h

FORMS    += mainwindow.ui \
    dialogsearchquery.ui \
    dialogconfirmation.ui

RESOURCES += \
    Resources.qrc
    RC_FILE = icon.rc

OTHER_FILES += \
    icon.rc \
    SmolstoDataBase.pro
