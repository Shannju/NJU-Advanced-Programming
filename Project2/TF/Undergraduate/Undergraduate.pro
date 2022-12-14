QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bar.cpp \
    card.cpp \
    main.cpp \
    mainwindow.cpp \
    object.cpp \
    random.cpp \
    scene.cpp \
    square.cpp \
    unit.cpp

HEADERS += \
    bar.h \
    card.h \
    mainwindow.h \
    object.h \
    random.h \
    scene.h \
    square.h \
    unit.h

FORMS += \
    bar.ui \
    card.ui \
    mainwindow.ui \
    scene.ui \
    unit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc

