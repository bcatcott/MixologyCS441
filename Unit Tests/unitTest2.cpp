#include "Cocktail.h"
#include "CocktailDB.h"
#include "Cabinet.h"
#include "Ingredient.h"
#include "IngredientDatabase.h"
#include <iostream>
#include <string>

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
	CDB->processFile("cocktailDatabase.txt");

	int command;
	string input;

	cout << "CS 441 Mixology Project - Unit Test 2" << endl;

	while(1)
	{
		cout << "<<Cabinet>>" << endl;
		Cab->displayCab();
		cout << endl;
		cout << "1 - Add Ingredient to Cabinet" << endl;
		cout << "2 - Remove Ingredient from Cabinet" << endl;
		cout << "3 - View Possible Ingredients" << endl;
		cout << "4 - Clear Cabinet" << endl;
		cout << "5 - Display Cocktail Database" << endl;
		cout << "6 - Find Cocktail" << endl;
		cout << "7 - I'm Feeling Lucky" << endl;
		cout << "0 - Exit" << endl;
		cin >> command;
		if(command == 1)
		{
			cout << "Enter Ingredient to Add" << endl;
			cin.ignore();
			getline(cin, input);
			Ingredient newIng(input);
			newIng.FormatIng();
			Cab->addIng(newIng, *IngDB);
		}
		else if(command == 2)
		{
			cout << "Enter Ingredient to Remove" << endl;
			cin.ignore();
			getline(cin, input);
			Ingredient ingToDelete(input);
			ingToDelete.FormatIng();
			Cab->removeIng(ingToDelete);
		}
		else if(command == 3)
		{
			cout << "<<Possible Ingredients>>" << endl;
			IngDB->displayDB();
			cout << endl;
		}
		else if(command == 4)
		{
			Cab->clearIngs();
			cout << "Cabinet Cleared" << endl;
		}
		else if(command == 5)
		{
			CDB->display();
		}
		else if(command == 6)
		{
			cout << "Enter Cocktail to Find" << endl;
			cin.ignore();
			getline(cin, input);
			Cocktail newCocktail = CDB->findCocktail(input);
			if(newCocktail.getCocktailName() == "nothing")
				cout << "Could not find cocktail" << endl;
			else
				newCocktail.printCocktailRecipe();
		}
		else if(command == 7)
			CDB->imFeelingLucky();
		else if(command == 0)
			break;
		else if(cin.fail())
		{
			cout << "Not a valid input" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else
			cout << "Not a valid input" << endl;
	}
	cout << "Program Terminated" << endl;

	return 0;
}
