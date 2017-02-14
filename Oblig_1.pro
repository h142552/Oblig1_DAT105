TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    person.cpp \
    util_heltall.cpp \
    heltall_bilde.cpp \
    matrise_skriver.cpp \
    ansatt.cpp \
    ansattdata.cpp

HEADERS += \
    person.h \
    util_heltall.h \
    heltall_bilde.h \
    matrise_skriver.h \
    ansatt.h \
    ansattdata.h
