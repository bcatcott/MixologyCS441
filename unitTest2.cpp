#include "Cocktail.h"
#include "CocktailDB.h"
#include "Cabinet.h"
#include "Ingredient.h"
#include "IngredientDatabase.h"
#include <iostream>

using namespace std;

int main()
{
	Cabinet *Cab;
	Cab = Cabinet::Instance(); //instance of cabinet

	IngredientDatabase *IngDB;
	IngDB = IngredientDatabase::Instance(); //instance of ingredient database

	CocktailDB *CDB;
	CDB = CocktailDB::Instance(); //instance of cocktail database

	IngDB->populateDB("ingredientDatabase.txt");
	cout << "<<<INGREDIENT DATABASE>>>" << endl;
	IngDB->displayDB();
	cout << endl;

	CDB->processFile("cocktailDatabase.txt");
	cout << "<<<COCKTAIL DATABASE>>>" << endl;
	CDB->display();

	Ingredient i0("something");
	Ingredient i1("RUM");
	cout << "Adding RUM" << endl;
	Cab->addIng(i1, *IngDB);
	Ingredient i2("WINE");
	cout << "Adding WINE" << endl;
	Cab->addIng(i2, *IngDB);
	Ingredient i3("7_UP");
	cout << "Adding 7 UP" << endl;
	Cab->addIng(i3, *IngDB);
	cout << "<<<CONTENTS OF CABINET>>>" << endl;
	Cab->displayCab();
	cout << "Removing RUM" << endl;
	Cab->removeIng(i1); //bug here, when you want to remove "RUM" its name was converted to "rum" so it can't be found in the cabinet and is not removed
	cout << "Removing something not in cabinet" << endl;
	Cab->removeIng(i0);
	cout << "<<<CONTENTS OF CABINET>>>" << endl;
	Cab->displayCab();
	cout << "Clearing Cabinet" << endl;
	Cab->clearIngs();
	cout << "<<<CONTENTS OF CABINET>>>" << endl;
	Cab->displayCab();

	return 0;
}
