#-------------------------------------------------
#
# Project created by QtCreator 2015-09-24T19:55:44
#
#-------------------------------------------------

QT       += core gui
INCLUDEPATH += \
                /usr/include/opencv4
                /usr/include
LIBS += -L/usr/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = etahta
TEMPLATE = app


SOURCES += main.cpp\
    depo.cpp \
    dotsignal.cpp \
    gridlines.cpp \
    mainwindow.cpp \
    popupmenu.cpp \
    scene.cpp \
    toolKalem.cpp \
    tooltahta.cpp \
    verectangle.cpp

HEADERS  += \
    depo.h \
    diagramitem.h \
    dotsignal.h \
    filecrud.h \
    gridlines.h \
    mainwindow.h \
    popupmenu.h \
    scene.h \
    toolKalem.h \
    tooltahta.h \
    verectangle.h

FORMS    +=

RESOURCES += \
    icon.qrc
