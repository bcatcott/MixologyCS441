#include <string>
#include <vector>
#include <iostream>
#include "cabinet.h"

using namespace std;

cabinet::cabinet()
{
}

cabinet::~cabinet()
{
}

void cabinet::addIng(Ingredient ing)
{
	string tempName = ing.getName();
	for (int i = 0; i < (tempName.size() - 1); i++)
	{
		if (tempName[i] == ' ')
			tempName[i] = '_';
		else
			tempName[i] = tolower(tempName[i]);
	}



	ingredientList.push_back(ing);
}

void cabinet::visitIngredients(Ingredient ing)
{
	
}

void cabinet::removeIng(Ingredient ing)
{
	for(vector<Ingredient>::iterator iter = ingredientList.begin(); iter != ingredientList.end(); ++iter) //iterates through ingredientList to find matching ingredient to erase
	{
		if(*iter == ing)
		{
			ingredientList.erase(iter);
			break;
		}
	}
}

void cabinet::clearIngs()
{
	ingredientList.clear();
}

void cabinet::displayCab()
{
	if (ingredientList.size() > 0)
	for (size_t i = 0; i < (ingredientList.size() - 1); i++)
	{
		ingredientList[i].displayIngredient();
		cout << endl;
	}
	else
		cout << "No Ingredients" << endl;
}
