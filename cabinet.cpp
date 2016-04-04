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

void cabinet::addIng(string ing)
{
	ingredient i(ing);
	ingredientList.push_back(i);
}

void cabinet::visitIngredients(ingredient ing)
{
	
}

void cabinet::removeIng(string ing)
{
	ingredient i(ing);
	for(std::vector<ingredient>::iterator iter = ingredientList.begin(); iter != ingredientList.end(); ++iter) //only works if we restrict cabinet st there are no duplicate Ings
	{
		if(*iter == i)
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
	std::copy(ingredientList.begin(), ingredientList.end(),
        std::ostream_iterator<int>(std::cout, " "));
}