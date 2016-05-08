#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T09:47:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mixology
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../Cabinet.cpp \
    ../Cocktail.cpp \
    ../CocktailDB.cpp \
    ../Ingredient.cpp \
    ../IngredientDatabase.cpp



HEADERS  += mainwindow.h \
    ../Cabinet.h \
    ../Cocktail.h \
    ../CocktailDB.h \
    ../Ingredient.h \
    ../IngredientDatabase.h

FORMS    += mainwindow.ui

DISTFILES += \
    ../cocktailDatabase.txt \
    ../ingredientDatabase.txt
