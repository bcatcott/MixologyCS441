#include <vector>
#include <string>
#include "ingredient.h"

using namespace std;

class recipe
{
private:
	vector<ingredient> recipeVec;
public:
	recipe();
	void printRecipe();
	void addIngredient(ingredient ing);
};
