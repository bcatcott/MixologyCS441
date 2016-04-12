#ifndef INGREDIENTDATABASE_H
#define INGREDIENTDATABASE_H

#include <QMainWindow>
#include <vector>
#include "ingredient.h"

namespace Ui {
	class IngredientDatabase;
}

class IngredientDatabase : public QMainWindow
{
	Q_OBJECT

public:
	static IngredientDatabase Instance(QWidget *parent = 0); //Must be called to create IngredientDatabase
    ~IngredientDatabase();
	void populateDB(string filename);
	
private:
	static bool _instance; //Singleton Variable
	explicit IngredientDatabase(QWidget *parent = 0); //Private because of Singleton
    Ui::IngredientDatabase *ui;
	vector<Ingredient> ingredientList;
};

#endif // INGREDIENTDATABASE_H
