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
	if(name == obj.name)
		return true;
	else
		return false;
}

string Ingredient::GetName() const
{
	return name;
}

void Ingredient::SetName(string inputName)
{
	name = inputName;
}

int Ingredient::GetQuantity()const
{
	return quantity;
}

void Ingredient::SetQuantity(int inputQuantity)
{
	quantity = inputQuantity;
}

void Ingredient::UpdateQuantity(int amt)
{
	quantity += amt;
}

void Ingredient::DisplayIngredient() 
{
	string tempName = name;
	for (int i = 0; i < (tempName.size()); i++)
	{
		if (tempName[i] == '_')
			tempName[i] = ' ';
	}
	cout << tempName;
}

void Ingredient::DisplayQuantity()
{
	cout << quantity;
}

void Ingredient::FormatIng() {
	for (int i = 0; i < (name.size() - 1); i++)
	{
	if (name[i] == ' ')
		name[i] = '_';
	else
		name[i] = tolower(name[i]);
	}
}
