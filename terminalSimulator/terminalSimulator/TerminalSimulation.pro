QT       += core widgets
TARGET = TerminalSimulation
TEMPLATE = app 
SOURCES += main.cpp mainwindow.cpp processC.cpp
HEADERS += mainwindow.h processC.h
LIBS += -lboost_thread -lpthread 
