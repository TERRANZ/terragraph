# -------------------------------------------------
# Project created by QtCreator 2010-11-03T10:39:45
# -------------------------------------------------
QT += network \
    sql \
    svg \
    xml \
    xmlpatterns
TARGET = terragraph
TEMPLATE = app
SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    terralib/character.cpp \
    terralib/arrow.cpp \
    terralib/box.cpp \
    terralib/circle.cpp \
    terralib/command.cpp \
    terralib/visitor.cpp \
    terralib/vertex.cpp \
    terralib/windowqt.cpp \
    terralib/processdiagram.cpp \
    terralib/channeldiagram.cpp \
    terralib/complex.cpp \
    terralib/arc.cpp
HEADERS += src/mainwindow.h \
    terralib/point.h \
    terralib/character.h \
    terralib/arrow.h \
    terralib/rect.h \
    terralib/box.h \
    terralib/circle.h \
    terralib/command.h \
    terralib/visitor.h \
    terralib/vertex.h \
    terralib/geometry.h \
    terralib/window.h \
    terralib/windowqt.h \
    terralib/processdiagram.h \
    terralib/channeldiagram.h \
    terralib/complex.h \
    terralib/arc.h \
    terralib/glyph.h
FORMS += src/mainwindow.ui
