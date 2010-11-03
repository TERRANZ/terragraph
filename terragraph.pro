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
    terralib/window.cpp \
    terralib/windowimpl.cpp \
    terralib/point.cpp \
    terralib/character.cpp \
    terralib/arrow.cpp \
    terralib/rect.cpp \
    terralib/box.cpp \
    terralib/circle.cpp
HEADERS += src/mainwindow.h \
    terralib/window.h \
    terralib/windowimpl.h \
    terralib/point.h \
    terralib/character.h \
    terralib/arrow.h \
    terralib/rect.h \
    terralib/box.h \
    terralib/circle.h \
    terralib/glyph.h
FORMS += src/mainwindow.ui
