#include <string>
#include <vector>
#include <iostream>
#include "Cabinet.h"

using namespace std;

Cabinet::Cabinet()
{
}

Cabinet* Cabinet::_instance = 0; //Singleton Code


Cabinet* Cabinet::Instance() //Singleton Code
{
	if (_instance == 0)
	{
		_instance = new Cabinet();
		return _instance;
	}
	else
	{
		cout << "Error: can only have one instance of Cabinet" << endl;
		exit(0);
	}
}

Cabinet::~Cabinet()
{
    _instance = 0; //Resets singleton code
}

void Cabinet::AddIng(Ingredient ing, IngredientDatabase ingDB)
{
	if(ingDB.CompareDB(ing)) //checks to see if ing is in database, then allowed to add to cabinet
	{
		string tempName = ing.GetName();
		for (int i = 0; i < tempName.size(); i++)
		{
			if (tempName[i] == ' ')
				tempName[i] = '_';
			else
				tempName[i] = tolower(tempName[i]);
		}
		ing.SetName(tempName);
		ingredientList.push_back(ing);
	}
	else
		cout << "Ingredient not found in database" << endl;
}

void Cabinet::RemoveIng(Ingredient ing)
{
	int removed = 0;
	for(vector<Ingredient>::iterator iter = ingredientList.begin(); iter != ingredientList.end(); ++iter) //iterates through ingredientList to find matching ingredient to erase
	{
		if(*iter == ing)
		{
			ingredientList.erase(iter);
			removed = 1;
			break;
		}
	}
	if (removed == 0)
		cout << "Ingredient not found in cabinet" << endl;
}

void Cabinet::ClearIngs()
{
	ingredientList.clear();
}

void Cabinet::DisplayCab()
{
	if (ingredientList.size() == 0)
		cout << "Empty" << endl;
	else 
	{
		for (size_t i = 0; i < ingredientList.size(); i++)
		{
			ingredientList[i].DisplayIngredient();
			cout << endl;
		}
	}
	cout << endl;
}

vector<Ingredient> Cabinet::GetCabIngList() 
{
	return ingredientList;
}
