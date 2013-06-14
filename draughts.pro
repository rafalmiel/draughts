#-------------------------------------------------
#
# Project created by QtCreator 2013-06-02T13:39:47
#
#-------------------------------------------------

QT       += core gui svg

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = draughts
TEMPLATE = app

INCLUDEPATH += src


SOURCES += src/main.cpp\
        src/ui/MainWindow.cpp \
    src/model/Board.cpp \
    src/model/Rules.cpp \
    src/model/Move.cpp \
    src/model/Piece.cpp \
    src/model/Field.cpp \
    src/model/games/draughts/DraughtsBoard.cpp \
    src/model/games/draughts/DraughtsChecker.cpp \
    src/model/games/draughts/DraughtsField.cpp \
    src/model/games/draughts/DraughtsMove.cpp \
    src/model/games/draughts/DraughtsRules.cpp \
    src/model/games/draughts/brazilian/DraughtsBrazilianBoard.cpp \
    src/model/Game.cpp \
    src/model/games/draughts/DraughtsGame.cpp \
    src/model/games/draughts/brazilian/DraughtsBrazilianRules.cpp \
    src/model/games/draughts/brazilian/DraughtsBrazilianGame.cpp \
    src/ui/draughts/DraughtsBoardWidget.cpp \
    src/model/games/draughts/brazilian/DraughtsBrazilianField.cpp \
    src/model/games/draughts/brazilian/DraughtsBrazilianMove.cpp \
    src/model/games/draughts/brazilian/DraughtsBrazilianChecker.cpp \
    src/model/GameManager.cpp \
    src/ui/draughts/DraughtsBoardScene.cpp \
    src/ui/draughts/DraughtsBoardView.cpp

HEADERS  += src/ui/MainWindow.h \
    src/model/Board.h \
    src/model/Rules.h \
    src/model/Move.h \
    src/model/Piece.h \
    src/model/Field.h \
    src/model/games/draughts/DraughtsBoard.h \
    src/model/games/draughts/DraughtsChecker.h \
    src/model/games/draughts/DraughtsField.h \
    src/model/games/draughts/DraughtsMove.h \
    src/model/games/draughts/DraughtsRules.h \
    src/model/games/draughts/brazilian/DraughtsBrazilianBoard.h \
    src/model/Game.h \
    src/model/games/draughts/DraughtsGame.h \
    src/model/games/draughts/brazilian/DraughtsBrazilianRules.h \
    src/model/games/draughts/brazilian/DraughtsBrazilianGame.h \
    src/ui/draughts/DraughtsBoardWidget.h \
    src/model/games/draughts/DraughtsTypes.h \
    src/model/games/draughts/brazilian/DraughtsBrazilianField.h \
    src/model/games/draughts/brazilian/DraughtsBrazilianMove.h \
    src/model/games/draughts/Draughts.h \
    src/model/games/draughts/brazilian/DraughtsBrazilian.h \
    src/model/games/draughts/brazilian/DraughtsBrazilianChecker.h \
    src/model/Types.h \
    src/model/GameManager.h \
    src/ui/draughts/DraughtsBoardScene.h \
    src/ui/draughts/DraughtsBoardTypes.h \
    src/ui/draughts/DraughtsBoardView.h

FORMS    += src/ui/MainWindow.ui \
    src/ui/draughts/DraughtsBoardWidget.ui

RESOURCES += \
    images.qrc
