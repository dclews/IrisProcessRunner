#-------------------------------------------------
#
# Project created by QtCreator 2014-03-02T03:51:34
#
#-------------------------------------------------

include(/usr/local/share/iris/iris_plugin.pri)

TARGET = $$qtLibraryTarget(xclueless.iris.ProcessRunner)

LIBS += -lIris

QT       -= gui

CONFIG +=  c++11 plugin
SOURCES +=  ProcessRunner.cpp \
            ProcessRunnerPlugin.cpp \
            ProcessRunnerFactory.cpp

HEADERS += ProcessRunner.hpp \
           ProcessRunnerPlugin.hpp \
           ProcessRunnerFactory.hpp
