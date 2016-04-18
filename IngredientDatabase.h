#pragma once

#include <string>
#include <vector>
#include "Ingredient.h"

class IngredientDatabase
{
private:
	static IngredientDatabase* _instance; //Singleton Variable
	vector<Ingredient> ingredientDBList;

protected:
	IngredientDatabase(); //Protected because of singleton

public:
	static IngredientDatabase* Instance(); //Must be called to create instance
    ~IngredientDatabase();
	void populateDB(string filename);
	bool compareDB(Ingredient ing); //returns true if ing is in vector
	void displayDB();
};
