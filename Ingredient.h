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
	string getName() const;
	void setName(string inputName);
	void setQuantity(int inputQuantity);
	int getQuantity() const;
	void updateQuantity(int amt);
	void displayIngredient();
	void displayQuantity();
	void FormatIng();
};

