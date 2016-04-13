#pragma once

#include <string>
#include <vector>
#include "Ingredient.h"

class IngredientDatabase
{
private:
	static IngredientDatabase* _instance; //Singleton Variable

protected:
	vector<Ingredient> ingredientDBList; //so cabinet can use
	IngredientDatabase(); //Protected because of singleton

public:
	static IngredientDatabase* Instance(); //Must be called to create instance
    ~IngredientDatabase();
	void populateDB(string filename);
	void displayDB();
};
