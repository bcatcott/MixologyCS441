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

void cabinet::addIng(ingredient ing)
{
	bool updateFlag = false; //whether or not to update qty or add new ing
	for(size_t i = 0; i < ingredientList.size(); i++)
	{
		if(ingredientList[i].getName() == ing.getName()) //if the vector already has ing, just update qty
		{
			ingredientList[i].updateQuantity(ing.getQuantity());
			updateFlag = true;
			break;
		}
	}
	if(updateFlag == false)
		ingredientList.push_back(ing);
}

void cabinet::visitIngredients(ingredient ing)
{
	
}

void cabinet::removeIng(ingredient ing)
{
	for(vector<ingredient>::iterator iter = ingredientList.begin(); iter != ingredientList.end(); ++iter) //iterates through ingredientList to find matching ingredient to erase
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
	for(size_t i = 0; i < ingredientList.size(); i++)
		cout << ingredientList[i].getName() << " " << ingredientList[i].getQuantity() << endl;
}
