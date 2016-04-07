#include <string>
#include <vector>
#include "ingredient.h"

using namespace std;

class Cocktail
{
  private:
  
    string cocktailName;
    vector <ingredient> recipe;
    
  
  public:
    
    Cocktail();
    ~Cocktail();
    void printCocktailName();
    void printCocktailRecipe();
    void printRecipe();

};
