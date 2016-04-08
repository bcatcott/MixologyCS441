#include <string>
#include <vector>
#include <iostream>
#include "Cocktail.h"

using namespace std;

  Cocktail::Cocktail(string inputCocktail, Ingrediant cocktailRecipe)
  {
    cocktailName = inputcocktail;
    recipe = cocktailRecipe;
  }
  
  Cocktail::~Cocktail()
  {
  }
  
  string Cocktail::printCocktailName()
  {
    return cocktailName;
  }
  
  void printCocktailRecipe()
  {
  }
  
  void printRecipe()
  {
  }
  
  void addIngCocktail(ingredient ing)
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
