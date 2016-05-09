#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Cabinet *Cab;
    Cab = Cabinet::Instance(); //instance of cabinet
    IngredientDatabase *IngDB;
    IngDB = IngredientDatabase::Instance(); //instance of ingredient database
    CocktailDB *CDB;
    CDB = CocktailDB::Instance(); //instance of cocktail database

    IngDB->PopulateDB("ingredientDatabase.txt");

    //debug
    qInfo("size = %d", IngDB->GetSize());

    CDB->ProcessFile("cocktailDatabase.txt");

    return a.exec();
}
