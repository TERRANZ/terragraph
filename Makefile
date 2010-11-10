#############################################################################
# Makefile for building: terragraph
# Generated by qmake (2.01a) (Qt 4.6.3) on: ?? ????. 10 13:41:02 2010
# Project:  terragraph.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile terragraph.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_SVG_LIB -DQT_SQL_LIB -DQT_XMLPATTERNS_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/qt4/QtXmlPatterns -I/usr/include/qt4/QtSql -I/usr/include/qt4/QtSvg -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtSvg -lQtSql -lQtXmlPatterns -lQtXml -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/main.cpp \
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
		terralib/arc.cpp moc_mainwindow.cpp
OBJECTS       = main.o \
		mainwindow.o \
		character.o \
		arrow.o \
		box.o \
		circle.o \
		command.o \
		visitor.o \
		vertex.o \
		windowqt.o \
		processdiagram.o \
		channeldiagram.o \
		complex.o \
		arc.o \
		moc_mainwindow.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		terragraph.pro
QMAKE_TARGET  = terragraph
DESTDIR       = 
TARGET        = terragraph

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: terragraph.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtSvg.prl \
		/usr/lib/libQtSql.prl \
		/usr/lib/libQtXmlPatterns.prl \
		/usr/lib/libQtXml.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtNetwork.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile terragraph.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtSvg.prl:
/usr/lib/libQtSql.prl:
/usr/lib/libQtXmlPatterns.prl:
/usr/lib/libQtXml.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtNetwork.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile terragraph.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/terragraph1.0.0 || $(MKDIR) .tmp/terragraph1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/terragraph1.0.0/ && $(COPY_FILE) --parents src/mainwindow.h terralib/point.h terralib/character.h terralib/arrow.h terralib/rect.h terralib/box.h terralib/circle.h terralib/command.h terralib/visitor.h terralib/compositor.h terralib/vertex.h terralib/geometry.h terralib/window.h terralib/windowqt.h terralib/processdiagram.h terralib/channeldiagram.h terralib/complex.h terralib/arc.h .tmp/terragraph1.0.0/ && $(COPY_FILE) --parents src/main.cpp src/mainwindow.cpp terralib/character.cpp terralib/arrow.cpp terralib/box.cpp terralib/circle.cpp terralib/command.cpp terralib/visitor.cpp terralib/vertex.cpp terralib/windowqt.cpp terralib/processdiagram.cpp terralib/channeldiagram.cpp terralib/complex.cpp terralib/arc.cpp .tmp/terragraph1.0.0/ && $(COPY_FILE) --parents src/mainwindow.ui .tmp/terragraph1.0.0/ && (cd `dirname .tmp/terragraph1.0.0` && $(TAR) terragraph1.0.0.tar terragraph1.0.0 && $(COMPRESS) terragraph1.0.0.tar) && $(MOVE) `dirname .tmp/terragraph1.0.0`/terragraph1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/terragraph1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp
moc_mainwindow.cpp: terralib/windowqt.h \
		terralib/window.h \
		terralib/point.h \
		terralib/complex.h \
		terralib/compositor.h \
		terralib/rect.h \
		terralib/geometry.h \
		terralib/processdiagram.h \
		terralib/vertex.h \
		src/mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/mainwindow.h -o moc_mainwindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: src/mainwindow.ui
	/usr/bin/uic-qt4 src/mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: src/main.cpp src/mainwindow.h \
		terralib/windowqt.h \
		terralib/window.h \
		terralib/point.h \
		terralib/complex.h \
		terralib/compositor.h \
		terralib/rect.h \
		terralib/geometry.h \
		terralib/processdiagram.h \
		terralib/vertex.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o src/main.cpp

mainwindow.o: src/mainwindow.cpp src/mainwindow.h \
		terralib/windowqt.h \
		terralib/window.h \
		terralib/point.h \
		terralib/complex.h \
		terralib/compositor.h \
		terralib/rect.h \
		terralib/geometry.h \
		terralib/processdiagram.h \
		terralib/vertex.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o src/mainwindow.cpp

character.o: terralib/character.cpp terralib/character.h \
		terralib/compositor.h \
		terralib/window.h \
		terralib/point.h \
		terralib/rect.h \
		terralib/geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o character.o terralib/character.cpp

arrow.o: terralib/arrow.cpp terralib/arrow.h \
		terralib/compositor.h \
		terralib/window.h \
		terralib/point.h \
		terralib/rect.h \
		terralib/geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o arrow.o terralib/arrow.cpp

box.o: terralib/box.cpp terralib/box.h \
		terralib/compositor.h \
		terralib/window.h \
		terralib/point.h \
		terralib/rect.h \
		terralib/geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o box.o terralib/box.cpp

circle.o: terralib/circle.cpp terralib/circle.h \
		terralib/compositor.h \
		terralib/window.h \
		terralib/point.h \
		terralib/rect.h \
		terralib/geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o circle.o terralib/circle.cpp

command.o: terralib/command.cpp terralib/command.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o command.o terralib/command.cpp

visitor.o: terralib/visitor.cpp terralib/visitor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o visitor.o terralib/visitor.cpp

vertex.o: terralib/vertex.cpp terralib/vertex.h \
		terralib/complex.h \
		terralib/compositor.h \
		terralib/window.h \
		terralib/point.h \
		terralib/rect.h \
		terralib/geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o vertex.o terralib/vertex.cpp

windowqt.o: terralib/windowqt.cpp terralib/windowqt.h \
		terralib/window.h \
		terralib/point.h \
		terralib/complex.h \
		terralib/compositor.h \
		terralib/rect.h \
		terralib/geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o windowqt.o terralib/windowqt.cpp

processdiagram.o: terralib/processdiagram.cpp terralib/processdiagram.h \
		terralib/compositor.h \
		terralib/window.h \
		terralib/point.h \
		terralib/rect.h \
		terralib/geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o processdiagram.o terralib/processdiagram.cpp

channeldiagram.o: terralib/channeldiagram.cpp terralib/channeldiagram.h \
		terralib/compositor.h \
		terralib/window.h \
		terralib/point.h \
		terralib/rect.h \
		terralib/geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o channeldiagram.o terralib/channeldiagram.cpp

complex.o: terralib/complex.cpp terralib/complex.h \
		terralib/compositor.h \
		terralib/window.h \
		terralib/point.h \
		terralib/rect.h \
		terralib/geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o complex.o terralib/complex.cpp

arc.o: terralib/arc.cpp terralib/arc.h \
		terralib/complex.h \
		terralib/compositor.h \
		terralib/window.h \
		terralib/point.h \
		terralib/rect.h \
		terralib/geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o arc.o terralib/arc.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

