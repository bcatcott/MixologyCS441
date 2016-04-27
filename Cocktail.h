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
	float rating;
	vector <string> comment;
	int ingNeeded = 0;

public:
	Cocktail();
	Cocktail(string inputName);
	~Cocktail();
  void printCocktailName();
  void printCocktailRecipe();
  void addIngCocktail(Ingredient ing);
  void scaleRecipe(int scale);
  void addCocktail();
  void SetIngNeeded(int needed);
  int VisitIngredient(Ingredient ing);
  int GetNumOfIngredients() const;
  bool VisitIngNeeded(Cocktail compare);
  int GetIngNeeded() const;
};
