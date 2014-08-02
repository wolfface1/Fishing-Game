#############################################################################
# Makefile for building: FishingGame
# Generated by qmake (2.01a) (Qt 4.8.6) on: Sat Jul 26 21:51:48 2014
# Project:  FishingGame.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile FishingGame.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -march=x86-64 -mtune=generic -O2 -pipe -fstack-protector-strong --param=ssp-buffer-size=4 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -march=x86-64 -mtune=generic -O2 -pipe -fstack-protector-strong --param=ssp-buffer-size=4 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt/mkspecs/linux-g++ -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -I. -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1,--sort-common,--as-needed,-z,relro -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
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

SOURCES       = GameLog.cpp \
		main.cpp \
		MainWindow.cpp \
		seaTable.cpp \
		seaWidget.cpp \
		build/CMakeFiles/3.0.0/CompilerIdC/CMakeCCompilerId.c \
		build/CMakeFiles/3.0.0/CompilerIdCXX/CMakeCXXCompilerId.cpp moc_GameLog.cpp \
		moc_MainWindow.cpp \
		moc_seaWidget.cpp \
		qrc_seaWidgetImages.cpp
OBJECTS       = GameLog.o \
		main.o \
		MainWindow.o \
		seaTable.o \
		seaWidget.o \
		CMakeCCompilerId.o \
		CMakeCXXCompilerId.o \
		moc_GameLog.o \
		moc_MainWindow.o \
		moc_seaWidget.o \
		qrc_seaWidgetImages.o
DIST          = /usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/common/gcc-base.conf \
		/usr/share/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt/mkspecs/common/g++-base.conf \
		/usr/share/qt/mkspecs/common/g++-unix.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/release.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/shared.prf \
		/usr/share/qt/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		FishingGame.pro
QMAKE_TARGET  = FishingGame
DESTDIR       = 
TARGET        = FishingGame

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

$(TARGET): ui_MainWindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: FishingGame.pro  /usr/share/qt/mkspecs/linux-g++/qmake.conf /usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/common/gcc-base.conf \
		/usr/share/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt/mkspecs/common/g++-base.conf \
		/usr/share/qt/mkspecs/common/g++-unix.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/release.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/shared.prf \
		/usr/share/qt/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -o Makefile FishingGame.pro
/usr/share/qt/mkspecs/common/unix.conf:
/usr/share/qt/mkspecs/common/linux.conf:
/usr/share/qt/mkspecs/common/gcc-base.conf:
/usr/share/qt/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt/mkspecs/common/g++-base.conf:
/usr/share/qt/mkspecs/common/g++-unix.conf:
/usr/share/qt/mkspecs/qconfig.pri:
/usr/share/qt/mkspecs/modules/qt_phonon.pri:
/usr/share/qt/mkspecs/modules/qt_webkit.pri:
/usr/share/qt/mkspecs/features/qt_functions.prf:
/usr/share/qt/mkspecs/features/qt_config.prf:
/usr/share/qt/mkspecs/features/exclusive_builds.prf:
/usr/share/qt/mkspecs/features/default_pre.prf:
/usr/share/qt/mkspecs/features/release.prf:
/usr/share/qt/mkspecs/features/default_post.prf:
/usr/share/qt/mkspecs/features/shared.prf:
/usr/share/qt/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt/mkspecs/features/warn_on.prf:
/usr/share/qt/mkspecs/features/qt.prf:
/usr/share/qt/mkspecs/features/unix/thread.prf:
/usr/share/qt/mkspecs/features/moc.prf:
/usr/share/qt/mkspecs/features/resources.prf:
/usr/share/qt/mkspecs/features/uic.prf:
/usr/share/qt/mkspecs/features/yacc.prf:
/usr/share/qt/mkspecs/features/lex.prf:
/usr/share/qt/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile FishingGame.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/FishingGame1.0.0 || $(MKDIR) .tmp/FishingGame1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/FishingGame1.0.0/ && $(COPY_FILE) --parents GameLog.h LogItem.h MainWindow.h seaTable.h seaWidget.h .tmp/FishingGame1.0.0/ && $(COPY_FILE) --parents seaWidgetImages.qrc .tmp/FishingGame1.0.0/ && $(COPY_FILE) --parents GameLog.cpp main.cpp MainWindow.cpp seaTable.cpp seaWidget.cpp build/CMakeFiles/3.0.0/CompilerIdC/CMakeCCompilerId.c build/CMakeFiles/3.0.0/CompilerIdCXX/CMakeCXXCompilerId.cpp .tmp/FishingGame1.0.0/ && $(COPY_FILE) --parents MainWindow.ui .tmp/FishingGame1.0.0/ && (cd `dirname .tmp/FishingGame1.0.0` && $(TAR) FishingGame1.0.0.tar FishingGame1.0.0 && $(COMPRESS) FishingGame1.0.0.tar) && $(MOVE) `dirname .tmp/FishingGame1.0.0`/FishingGame1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/FishingGame1.0.0


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

compiler_moc_header_make_all: moc_GameLog.cpp moc_MainWindow.cpp moc_seaWidget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_GameLog.cpp moc_MainWindow.cpp moc_seaWidget.cpp
moc_GameLog.cpp: LogItem.h \
		seaWidget.h \
		seaTable.h \
		GameLog.h
	/usr/bin/moc $(DEFINES) $(INCPATH) GameLog.h -o moc_GameLog.cpp

moc_MainWindow.cpp: ui_MainWindow.h \
		seaWidget.h \
		seaTable.h \
		GameLog.h \
		LogItem.h \
		MainWindow.h
	/usr/bin/moc $(DEFINES) $(INCPATH) MainWindow.h -o moc_MainWindow.cpp

moc_seaWidget.cpp: seaTable.h \
		seaWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) seaWidget.h -o moc_seaWidget.cpp

compiler_rcc_make_all: qrc_seaWidgetImages.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_seaWidgetImages.cpp
qrc_seaWidgetImages.cpp: seaWidgetImages.qrc
	/usr/bin/rcc -name seaWidgetImages seaWidgetImages.qrc -o qrc_seaWidgetImages.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_MainWindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_MainWindow.h
ui_MainWindow.h: MainWindow.ui \
		seaWidget.h \
		seaTable.h
	/usr/bin/uic MainWindow.ui -o ui_MainWindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

GameLog.o: GameLog.cpp GameLog.h \
		LogItem.h \
		seaWidget.h \
		seaTable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GameLog.o GameLog.cpp

main.o: main.cpp MainWindow.h \
		ui_MainWindow.h \
		seaWidget.h \
		seaTable.h \
		GameLog.h \
		LogItem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

MainWindow.o: MainWindow.cpp MainWindow.h \
		ui_MainWindow.h \
		seaWidget.h \
		seaTable.h \
		GameLog.h \
		LogItem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MainWindow.o MainWindow.cpp

seaTable.o: seaTable.cpp seaTable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o seaTable.o seaTable.cpp

seaWidget.o: seaWidget.cpp seaWidget.h \
		seaTable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o seaWidget.o seaWidget.cpp

CMakeCCompilerId.o: build/CMakeFiles/3.0.0/CompilerIdC/CMakeCCompilerId.c 
	$(CC) -c $(CFLAGS) $(INCPATH) -o CMakeCCompilerId.o build/CMakeFiles/3.0.0/CompilerIdC/CMakeCCompilerId.c

CMakeCXXCompilerId.o: build/CMakeFiles/3.0.0/CompilerIdCXX/CMakeCXXCompilerId.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CMakeCXXCompilerId.o build/CMakeFiles/3.0.0/CompilerIdCXX/CMakeCXXCompilerId.cpp

moc_GameLog.o: moc_GameLog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_GameLog.o moc_GameLog.cpp

moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MainWindow.o moc_MainWindow.cpp

moc_seaWidget.o: moc_seaWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_seaWidget.o moc_seaWidget.cpp

qrc_seaWidgetImages.o: qrc_seaWidgetImages.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_seaWidgetImages.o qrc_seaWidgetImages.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
