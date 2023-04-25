QT       += core gui widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtLanguage
TEMPLATE = app

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filemanager.cpp \
    form.cpp \
    keyboard.cpp \
    main.cpp \
    mainwindow.cpp \
    searchclass.cpp

HEADERS += \
    filemanager.h \
    form.h \
    keyboard.h \
    mainwindow.h \
    searchclass.h

FORMS += \
    form.ui \
    keyboard.ui \
    mainwindow.ui

TRANSLATIONS = QtLanguage_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
