#pragma once
#include <string>
#include <vector>
#include "Ingredient.h"

using namespace std;

class Cocktail
{
private:
	string cocktailName;
	vector <Ingredient> recipe;
	float rating;
	vector <string> comment;
	int ingNeeded;

public:
	Cocktail();
	Cocktail(string inputName);
	Cocktail(string inName, vector <Ingredient> inRecipe, float inRating);
	~Cocktail();

	string GetCocktailName() const;
	int GetNumOfIngredients() const;
	int GetIngNeeded() const;
	float GetRating() const;

	void PrintCocktailName();
	void PrintCocktailRecipe();
	void AddIngCocktail(Ingredient ing);
	Cocktail ScaleRecipe(int scale);
	void AddCocktail();
	void SetIngNeeded(int needed);
	int VisitIngredient(Ingredient ing);
	bool VisitIngNeeded(Cocktail compare);
	vector<Ingredient> GetRecipe();

};
