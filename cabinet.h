#include <string>
#include <vector>
#include "ingredient.h"

using namespace std;

class cabinet {
private:
	vector<ingredient> ingredientList;

public:
	cabinet();
	~cabinet();
	void addIng(string ing);
	void visitIngredients(ingredient ing);
	void removeIng(string ing);
	void clearIngs();
	void displayCab();

};