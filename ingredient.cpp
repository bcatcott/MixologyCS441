#include <vector>
#include <string>
#include "ingredient.h"

using namespace std;

ingredient::ingredient(string inputName) {
	name = inputName;
}

bool ingredient::operator==(const ingredient& rhs) {
	if (name == rhs.name)
		return true;
	else
		return false;
		
}