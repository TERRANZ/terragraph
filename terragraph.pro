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
    src/logger.cpp \
    terralib/character.cpp \
    terralib/arrow.cpp \
    terralib/box.cpp \
    terralib/circle.cpp \
    terralib/command.cpp \
    terralib/visitor.cpp \
    terralib/windowqt.cpp \
    terralib/processdiagram.cpp \
    terralib/channeldiagram.cpp \
    terralib/arc.cpp \
    terralib/settings.cpp \
    terralib/graphicmanager.cpp \
    terralib/vertex.cpp
HEADERS += src/mainwindow.h \
    src/logger.h \
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
    terralib/glyph.h \
    terralib/settings.h \
    terralib/graphicmanager.h
FORMS += src/mainwindow.ui
