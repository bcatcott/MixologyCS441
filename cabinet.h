#include <string>
#include <vector>
#include "ingredient.h"

using namespace std;

class cabinet
{
private:
	vector<Ingredient> ingredientList;

public:
	cabinet();
	~cabinet();
	void addIng(Ingredient ing);
	void visitIngredients(Ingredient ing);
	void removeIng(Ingredient ing);
	void clearIngs();
	void displayCab();

};
