#include <string>
#include "ingredient.h"

using namespace std;

ingredient::ingredient(string inputName)
{
	name = inputName;
	quantity = 1;
}

ingredient::ingredient(string inputName, int inputQuantity)
{
	name = inputName;
	quantity = inputQuantity;
}

ingredient::~ingredient()
{
}

bool ingredient::operator==(const ingredient &obj)
{
	if(name == obj.name)
		return true;
	else
		return false;
}

string ingredient::getName()
{
	return name;
}

int ingredient::getQuantity()
{
	return quantity;
}

void ingredient::updateQuantity(int amt)
{
	quantity += amt;
}
