#-------------------------------------------------
#
# Project created by QtCreator 2019-12-04T20:51:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TabloAviareysov
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

win32 {
        RC_FILE += file.rc
        OTHER_FILES += file.rc
}

SOURCES += \
        addrace.cpp \
        adduser.cpp \
        controlraces.cpp \
        controlusers.cpp \
        infouser.cpp \
        menuadmin.cpp \
        menucashier.cpp \
        plane.cpp \
        signin.cpp \
        signup.cpp \
        user.cpp \
        main.cpp \
        mainwidget.cpp \
        workwidget.cpp

HEADERS += \
        addrace.h \
        adduser.h \
        config.h \
        controlraces.h \
        controlusers.h \
        infouser.h \
        menuadmin.h \
        menucashier.h \
        plane.h \
        signin.h \
        signup.h \
        user.h \
        mainwidget.h \
        workwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    dialog_addrace.ui \
    dialog_adduser.ui \
    dialog_controlraces.ui \
    dialog_controlusers.ui \
    dialog_infouser.ui \
    dialog_menuadmin.ui \
    dialog_menucashier.ui \
    window_authorization.ui \
    window_registration.ui \
    window_workwidget.ui
