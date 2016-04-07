#include <string>
#include "Ingredient.h"

using namespace std;

Ingredient::Ingredient(const string &inputName)
{
	name = inputName;
	quantity = 1;
}

Ingredient::Ingredient(string inputName, int inputQuantity)
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

string Ingredient::getName()
{
	return name;
}

int Ingredient::getQuantity()const
{
	return quantity;
}

void Ingredient::updateQuantity(int amt)
{
	quantity += amt;
}
