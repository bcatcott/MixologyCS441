#include <string>
#include <vector>
#include "ingredient.h"

using namespace std;

class cabinet
{
private:
	vector<Ingredient> ingredientList;
	cabinet(); //Private because of singleton
	static bool _instance; //Singleton Variable


public:
	static cabinet Instance(); //Must be called to create cabinet
	~cabinet();
	void addIng(Ingredient ing);
	void visitIngredients(Ingredient ing);
	void removeIng(Ingredient ing);
	void clearIngs();
	void displayCab();

};
