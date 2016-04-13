#include <string>
#include <vector>
#include "Ingredient.h"
#include "IngredientDatabase.h"

using namespace std;

class Cabinet: public IngredientDatabase
{
private:
	vector<Ingredient> ingredientList;
	static Cabinet* _instance; //Singleton Variable

protected:
	Cabinet(); //Protected because of singleton

public:
	static Cabinet* Instance(); //Must be called to create instance
	~Cabinet();
	void addIng(Ingredient ing);
	void visitIngredients(Ingredient ing);
	void removeIng(Ingredient ing);
	void clearIngs();
	void displayCab();
};
