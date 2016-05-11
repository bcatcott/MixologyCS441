#pragma once
#include <string>
#include <vector>
#include "Ingredient.h"
#include "IngredientDatabase.h"

using namespace std;

class Cabinet
{
private:
	vector<Ingredient> ingredientList;
	static Cabinet* _instance; //Singleton Variable

protected:
	Cabinet(); //Protected because of singleton

public:
	static Cabinet* Instance(); //Must be called to create instance
	~Cabinet();
	void AddIng(Ingredient ing, IngredientDatabase ingDB); //must pass ingredient and database ingredient is from
	void RemoveIng(Ingredient ing);
	void ClearIngs();
	void DisplayCab();
	vector<Ingredient> GetCabIngList();
};
