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

	IngDB->PopulateDB("ingredientDatabase.txt");
	CDB->ProcessFile("cocktailDatabase.txt");

	int command;
	string input;

	cout << "CS 441 Mixology Project - Unit Test 3" << endl;

	while(1)
	{
		cout << "<<Cabinet>>" << endl;
		Cab->DisplayCab();
		cout << endl;
		cout << "1 - Add Ingredient to Cabinet" << endl;
		cout << "2 - Remove Ingredient from Cabinet" << endl;
		cout << "3 - Cocktail Search based on Cabinet" << endl;
		cout << "4 - View Possible Ingredients" << endl;
		cout << "5 - Clear Cabinet" << endl;
		cout << "6 - Display Cocktail Database" << endl;
		cout << "7 - Find Cocktail" << endl;
		cout << "8 - I'm Feeling Lucky" << endl;
		cout << "0 - Exit" << endl;
		cin >> command;
		if(command == 1)
		{
			cout << "Enter Ingredient to Add" << endl;
			cin.ignore();
			getline(cin, input);
			Ingredient newIng(input);
			newIng.FormatIng();
			Cab->AddIng(newIng, *IngDB);
		}
		else if(command == 2)
		{
			cout << "Enter Ingredient to Remove" << endl;
			cin.ignore();
			getline(cin, input);
			Ingredient ingToDelete(input);
			ingToDelete.FormatIng();
			Cab->RemoveIng(ingToDelete);
		}
		else if(command == 3)
		{
			vector<Cocktail> result = CDB->SearchByIngredient(*Cab);
			for(size_t i = 0; i < result.size(); i++)
				cout << "Cocktail: " << result[i].GetCocktailName() << " Ingredients needed: " << result[i].GetIngNeeded() << endl;
		}
		else if(command == 4)
		{
			cout << "<<Possible Ingredients>>" << endl;
			IngDB->DisplayDB();
			cout << endl;
		}
		else if(command == 5)
		{
			Cab->ClearIngs();
			cout << "Cabinet Cleared" << endl;
		}
		else if(command == 6)
		{
			CDB->Display();
		}
		else if(command == 7)
		{
			cout << "Enter Cocktail to Find" << endl;
			cin.ignore();
			getline(cin, input);
			vector<Cocktail> newCocktails = CDB->FindCocktail(input);
			vector<Cocktail>::iterator it;
			for(it = newCocktails.begin(); it != newCocktails.end(); it++)
			{
				if((*it).GetCocktailName() == "nothing")
					cout << "Could not find any cocktails" << endl;
				else
					(*it).PrintCocktailRecipe();
			}
		}
		else if(command == 8)
			CDB->ImFeelingLucky();
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
