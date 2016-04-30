#pragma once

#include <string>
#include <iostream>

using namespace std;

class Ingredient
{
private:
	string name;
	int quantity;

public:
	Ingredient(const string &inputName);
	Ingredient(const string &inputName, int inputQuantity);
	~Ingredient();
	bool operator==(const Ingredient &obj);
	string GetName() const;
	void SetName(string inputName);
	void SetQuantity(int inputQuantity);
	int GetQuantity() const;
	void UpdateQuantity(int amt);
	void DisplayIngredient();
	void DisplayQuantity();
	void FormatIng();
};

