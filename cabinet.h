#include <iostream>
#include <string>
#include <vector>
#include "ingredient.h"


using namespace std;

class cabinet {
private:
	vector<ingredient> ingredientList;

public:
	void addIng(string ingredient);
	void visitIngredients(ingredient i);
	void removeIng(string ingredient);
	void clearIngs();

};