TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    figure.cpp \
    ball.cpp

LIBS += -lglut -lGLU -lGL

HEADERS += \
    figure.h \
    ball.h
