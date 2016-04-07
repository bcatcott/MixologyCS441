#include <string>
#include <vector>
#include "ingredient.h"

using namespace std;

class cabinet
{
private:
	vector<ingredient> ingredientList;

public:
	cabinet();
	~cabinet();
	void addIng(ingredient ing);
	void visitIngredients(ingredient ing);
	void removeIng(ingredient ing);
	void clearIngs();
	void displayCab();

};
