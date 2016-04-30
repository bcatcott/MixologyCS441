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
	string GetCocktailName() const;
	void PrintCocktailName();
	void PrintCocktailRecipe();
	void AddIngCocktail(Ingredient ing);
	void ScaleRecipe(int scale);
	void AddCocktail();
	void SetIngNeeded(int needed);
	int VisitIngredient(Ingredient ing);
	int GetNumOfIngredients() const;
	bool VisitIngNeeded(Cocktail compare);
	int GetIngNeeded() const;
};
