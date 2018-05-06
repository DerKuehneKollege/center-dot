#-------------------------------------------------
#
# Project created by QtCreator 2015-11-07T18:06:11
#
#-------------------------------------------------

VERSION = 1.0.2
QMAKE_TARGET_COMPANY = "Atomkraftzwerg"
QMAKE_TARGET_PRODUCT = "CenterDot"
QMAKE_TARGET_DESCRIPTION = "Shows a centered crosshair as a layer above your game."
QMAKE_TARGET_COPYRIGHT = "(c) 2016 Atomkraftzwerg"

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CenterDot
TEMPLATE = app
RC_FILE = src/centerdot.rc

SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/winkeyboardhook.cpp \
    src/settingsdialog.cpp

HEADERS  += src/mainwindow.h \
    src/winkeyboardhook.h \
    src/settingsdialog.h \
    src/settingsdata.h

FORMS    += \
    src/settings.ui

RESOURCES += src/resources.qrc

DISTFILES += \
    src/centerdot.rc

DEFINES += \
  APP_VERSION=\"\\\"$$VERSION\\\"\" \
  APP_COMPANY=\"\\\"$$QMAKE_TARGET_COMPANY\\\"\" \
  APP_PRODUCT=\"\\\"$$QMAKE_TARGET_PRODUCT\\\"\" \
  APP_DESCRIPTION=\"\\\"$$QMAKE_TARGET_DESCRIPTION\\\"\" \
  APP_COPYRIGHT=\"\\\"$$QMAKE_TARGET_COPYRIGHT\\\"\"
