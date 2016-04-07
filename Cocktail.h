#include <string>
#include <vector>
#include "Ingredient.h"

using namespace std;

class Cocktail
{
  private:
  
    string cocktailName;
    vector <Ingredient> recipe;
    
  
  public:
    
    Cocktail();
    ~Cocktail();
    void printCocktailName();
    void printCocktailRecipe();
    void printRecipe();

};
