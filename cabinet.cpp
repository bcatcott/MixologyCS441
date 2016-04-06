#include <iostream>
#include <string>
#include <vector>
#include "cabinet.h"

using namespace std;

void cabinet::addIng(string ingredient) {
	if (searchDatabase(ingredient)  == true)
	{
		ingredientList.push_back(ingredient);
	}
}

void cabinet::visitIngredients(ingredient i) {

}

void cabinet::removeIng(string ingredient) {

}

void cabinet::clearIngs() {
	ingredientList.clear();
}

bool cabinet::searchDatabase(string ingredient)
{
	int size = ingredientList.size();
	
	for (int i=0; i < size; i++)
	{
		if (ingredientList[i] == ingrediant) //this won't work, it's checking if an ingredient is equal to a string
		{
			return false;
		}
	}
	
	return true;
}
