#include <string>
#include <vector>
#include <iostream>
#include "Cabinet.h"

using namespace std;

Cabinet::Cabinet()
{
}

Cabinet::~Cabinet()
{
    _instance = 0; //Resets singleton code
}

void Cabinet::addIng(Ingredient ing)
{
	bool pushFlag = false; //checks if an ingredient was pushed onto ingredientList
	for(size_t j = 0; j < ingredientDBList.size(); j++)
	{
		if(ing == ingredientDBList[j]) //compares ingredient trying to add with all ingredients in database
		{
			string tempName = ing.getName();
			for (int i = 0; i < tempName.size(); i++)
			{
				if (tempName[i] == ' ')
					tempName[i] = '_';
				else
					tempName[i] = tolower(tempName[i]);
			}
			ing.setName(tempName);
			ingredientList.push_back(ing);
			pushFlag = true;
			break;
		}
	}
	if(pushFlag = false)
		cout << "Ingredient not found in database" << endl;
}

void Cabinet::visitIngredients(Ingredient ing)
{

}

void Cabinet::removeIng(Ingredient ing)
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

void Cabinet::clearIngs()
{
	ingredientList.clear();
}

void Cabinet::displayCab()
{
	for (size_t i = 0; i < ingredientList.size(); i++)
	{
		ingredientList[i].displayIngredient();
		cout << endl;
	}		
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
