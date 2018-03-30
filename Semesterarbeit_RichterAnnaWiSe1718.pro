TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    attlib.cpp \
    tokenlib.cpp \
    txtlib.cpp

HEADERS += \
    att.h \
    token.h \
    txt.h

DISTFILES += \
    mediacenter.xml \
    pricelist.txt
data.path = $$OUT_PWD/

data.files += $$PWD/*.dat

data.files += $$PWD/*.xml

data.files += $$PWD/*.dtd

data.files += $$PWD/*.txt

INSTALLS += data
