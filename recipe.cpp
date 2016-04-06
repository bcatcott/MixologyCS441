#include "recipe.h"
#include <iostream>
#include <string>

using namespace std;

recipe::recipe()
{
}

void recipe::printRecipe()
{
	for(int i = 0; i < recipeVec.size(); i++)
		cout << recipeVec[i].getName() << " " << recipeVec[i].getQuantity() << endl;
}

void recipe::addIngredient(ingredient ing)
{
	bool updateFlag = false; //whether or not to update qty or add new ing
	for(int i = 0; i < recipeVec.size(); i++)
	{
		if(recipeVec[i].getName() == ing.getName()) //if the vector already has ing, just update qty
		{
			recipeVec[i].updateQuantity(ing.getQuantity());
			updateFlag = true;
			break;
		}
	}
	if(updateFlag == false)
		recipeVec.push_back(ing);
}
