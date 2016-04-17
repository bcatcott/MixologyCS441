#include <string>
#include <vector>
#include <iostream>
#include "Cocktail.h"

using namespace std;

Cocktail::Cocktail()
{
    string cocktailName ="";
}

 Cocktail::Cocktail(string inputCocktail)
{
	cocktailName = inputCocktail;
}
  
Cocktail::~Cocktail()
{
}
  
void Cocktail::printCocktailName()
{
	cout << cocktailName << endl;
}
  
void Cocktail::printCocktailRecipe()
{
	cout << cocktailName << ":" << endl;
	for (int i = 0; i < recipe.size(); i++ )
  	{
		cout << recipe[i].getName() << " " << recipe[i].getQuantity() << endl;
  	}
}
  
  
void Cocktail::addIngCocktail(Ingredient ing)
{
	bool updateFlag = false; //whether or not to update qty or add new ing
	for(int i = 0; i < recipe.size(); i++)
	{
		if(recipe[i].getName() == ing.getName()) //if the vector already has ing, just update qty
		{
			recipe[i].updateQuantity(ing.getQuantity());
			updateFlag = true;
			break;
		}
	}
	if(updateFlag == false)
		recipe.push_back(ing);
}

void Cocktail::scaleRecipe(int scale)
{
	for (int i = 0; i < recipe.size() ; i++)
	{
		recipe[i].setQuantity(recipe.getQuantity() * scale); //Goes through each ingredient and multiplies it
	}
	
}

void Cocktail::addCocktail ()
{
	string inputName; 
	int ingNumber;
	float inputRating; 
	string inputComment;
	
	cin >> inputName;
	cocktailName = inputName;
	
	//Insert number of ingredients in recipe. Add ingredients until number of ingredients reached
	//cin >> ingNumber;
	//for (int i = 0; i < ingNumber; i++)
	//{
		
	//}
	cin >> inputRating
	rating = inputRating;
	
	cin >> inputComment
	comment.push_back(inputComment);
	
}
