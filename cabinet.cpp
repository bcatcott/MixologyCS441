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
	for (int i = 0; i < tempName.size(); i++)
	{
		if (tempName[i] == ' ')
			tempName[i] = '_';
		else
			tempName[i] = tolower(tempName[i]);
	}
	ingredientList.push_back(tempName);
}

void cabinet::visitIngredients(Ingredient ing)
{
	_instance = 0; //Resets singleton code
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
	for (size_t i = 0; i < ingredientList.size(); i++)
	{
		ingredientList[i].displayIngredient();
		cout << endl;
	}		
}

bool cabinet::_instance = 0; //Singleton Code


cabinet cabinet::Instance() //Singleton Code
{
	if (_instance == 0)
	{
		_instance = 1;
		return cabinet();
	}
	else
	{
		cout << "Error: can only have one instance of Singleton" << endl;
		exit(0);
	}
}

