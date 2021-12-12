QT -= gui
QT += core
QT += network
QT += sql

CONFIG += c++11
CONFIG -= app_bundle
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        listdatacontroller.cpp \
        main.cpp \
        mysqldao.cpp \
        user.cpp

OTHER_FILES += etc/webapp.ini

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(../QtWebApp/QtWebApp/httpserver/httpserver.pri)

HEADERS += \
    listdatacontroller.h \
    mysqldao.h \
    user.h
