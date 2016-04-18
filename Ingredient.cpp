#include <string>
#include <iostream>
#include "Ingredient.h"

using namespace std;

Ingredient::Ingredient(const string &inputName)
{
	name = inputName;
	quantity = 1;
}

Ingredient::Ingredient(const string &inputName, int inputQuantity)
{
	name = inputName;
	quantity = inputQuantity;
}

Ingredient::~Ingredient()
{
}

bool Ingredient::operator==(const Ingredient &obj)
{
	string tempName = obj.name;
	/*for (int i = 0; i < (tempName.size() - 1); i++)
	{
		if (tempName[i] == ' ')
			tempName[i] = '_';
		else
			tempName[i] = tolower(tempName[i]);
	}*/
	//why is all of this in here? this operator is only meant to compare names of ingredients
	//i left it in here, but it does not work with unit test 2

	if(name == tempName)
		return true;
	else
		return false;
}

string Ingredient::getName() const
{
	return name;
}

void Ingredient::setName(string inputName)
{
	name = inputName;
}

int Ingredient::getQuantity()const
{
	return quantity;
}

void Ingredient::setQuantity(int inputQuantity)
{
	quantity = inputQuantity;
}

void Ingredient::updateQuantity(int amt)
{
	quantity += amt;
}

void Ingredient::displayIngredient() 
{
	string tempName = name;
	for (int i = 0; i < (tempName.size()); i++)
	{
		if (tempName[i] == '_')
			tempName[i] = ' ';
	}
	cout << tempName;
}

void Ingredient::displayQuantity()
{
	cout << quantity;
}

