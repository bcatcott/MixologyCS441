#include <string>
#include <vector>
#include <iostream>
#include "Cocktail.h"

using namespace std;

Cocktail::Cocktail()
{
    string cocktailName ="";
    ingNeeded = 0;
}

Cocktail::Cocktail(string inputCocktail)
{
	cocktailName = inputCocktail;
	ingNeeded = 0;
}
  
Cocktail::Cocktail(string inName, vector <Ingredient> inRecipe, float inRating)
{
	cocktailName = inName;
	recipe = inRecipe;
	rating = inRating;
	ingNeeded = 0;
}

Cocktail::~Cocktail()
{
}

string Cocktail::GetCocktailName() const
{
	return cocktailName;
}
  
void Cocktail::PrintCocktailName()
{
	cout << cocktailName << endl;
}
  
void Cocktail::PrintCocktailRecipe()
{
	cout << cocktailName << ":" << endl;
	for (int i = 0; i < recipe.size(); i++ )
  	{
		cout << recipe[i].GetName() << " " << recipe[i].GetQuantity() << endl;
  	}
}
  
  
void Cocktail::AddIngCocktail(Ingredient ing)
{
	bool updateFlag = false; //whether or not to update qty or add new ing
	for(int i = 0; i < recipe.size(); i++)
	{
		if(recipe[i].GetName() == ing.GetName()) //if the vector already has ing, just update qty
		{
			recipe[i].UpdateQuantity(ing.GetQuantity());
			updateFlag = true;
			break;
		}
	}
	if(updateFlag == false)
		recipe.push_back(ing);
}

Cocktail Cocktail::ScaleRecipe(int scale)
{
	Cocktail temp = *this;

	for (int i = 0; i < recipe.size() ; i++)
	{
		temp.recipe[i].SetQuantity(temp.recipe[i].GetQuantity() * scale); //Goes through each ingredient and multiplies it
	}
	return temp;
}

void Cocktail::AddCocktail ()
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
	cin >> inputRating;
	rating = inputRating;
	
	cin >> inputComment;
	comment.push_back(inputComment);
	
}

void Cocktail::SetIngNeeded(int needed) 
{
	ingNeeded = needed;
}

int Cocktail::VisitIngredient(Ingredient ing)
{
	for (int i = 0; i < (recipe.size() - 1); i++)
	{
		if (recipe[i] == ing)
			return 1;
	}
	return 0;
}

int Cocktail::GetNumOfIngredients() const
{
	return recipe.size();
}

//if this has a larger number of ingredients needed than cocktail compare, returns true
bool Cocktail::VisitIngNeeded(Cocktail compare)
{
	if (ingNeeded > compare.GetIngNeeded())
		return true;
	return false;
}

int Cocktail::GetIngNeeded() const
{
	return ingNeeded;
}


vector <Ingredient> Cocktail::GetRecipe()
{
	return recipe;
}

float Cocktail::GetRating() const
{
	return rating;
}
