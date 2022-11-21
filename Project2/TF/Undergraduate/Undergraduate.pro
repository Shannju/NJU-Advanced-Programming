QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card.cpp \
    main.cpp \
    mainwindow.cpp \
    object.cpp \
    scene.cpp \
    top.cpp \
    unit.cpp

HEADERS += \
    card.h \
    mainwindow.h \
    object.h \
    scene.h \
    top.h \
    unit.h

FORMS += \
    card.ui \
    mainwindow.ui \
    scene.ui \
    top.ui \
    unit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc

QMAKE_CXXFLAGS_RELEASE += -g

QMAKE_CFLAGS_RELEASE += -g

QMAKE_LFLAGS_RELEASE = -mthreads -Wl
