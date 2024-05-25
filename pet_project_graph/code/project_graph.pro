QT += core gui
QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graphical_Graph_Editor
TEMPLATE = app


SOURCES += main.cpp\
    CGraph.cpp \
    CreateGraphWindow.cpp \
    Edge.cpp \
    GraphWidget.cpp \
    LinkedList.cpp \
    MainWindow.cpp \
    NodeVisual.cpp

HEADERS  += \
    CGraph.h \
    CreateGraphWindow.h \
    Edge.h \
    GraphWidget.h \
    LinkedList.h \
    MainWindow.h \
    NodeVisual.h \
    NodeVisual.h

FORMS    += \
    CreateGraphWindow.ui \
    MainWindow.ui

RESOURCES += \
    icons.qrc
