#pragma once
#include <string>
#include <vector>
#include "Ingredient.h"

using namespace std;

class Cocktail
{
  public:
  
    string cocktailName;
    vector <Ingredient> recipe;
    
  
  public:
    
    Cocktail();
    ~Cocktail();
    void printCocktailName();
    void printCocktailRecipe();
    void printRecipe();
    void addIngCocktail();

};
