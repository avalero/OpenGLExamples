TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    figure.cpp \
    triangle.cpp \
    square.cpp \
    circle.cpp

LIBS += -lglut -lGLU -lGL

HEADERS += \
    figure.h \
    triangle.h \
    square.h \
    circle.h
