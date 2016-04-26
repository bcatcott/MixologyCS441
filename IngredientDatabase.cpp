#include "Ingredientdatabase.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

IngredientDatabase::IngredientDatabase()
{
}

void IngredientDatabase::populateDB(string filename)
{
    string line;
    ifstream myfile;
    myfile.open (filename);

    if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
			ingredientDBList.push_back(Ingredient(line));
        }
        myfile.close();
      }

      else cout << "Unable to open file\n";
    myfile.close();
}

bool IngredientDatabase::compareDB(Ingredient ing)
{
	for(size_t i = 0; i < ingredientDBList.size() - 1; i++)
	{
		if(ing == ingredientDBList[i])
			return true;
	}
	return false;
}

void IngredientDatabase::displayDB()
{
	for (size_t i = 0; i < ingredientDBList.size(); i++)
	{
		ingredientDBList[i].displayIngredient();
		cout << endl;
	}
}

IngredientDatabase::~IngredientDatabase()
{
	_instance = 0; //resets Singleton code
}


IngredientDatabase* IngredientDatabase::_instance = 0; //Singleton Code


IngredientDatabase* IngredientDatabase::Instance() //Singleton code
{
	if (_instance == 0)
	{
		_instance = new IngredientDatabase;
		return _instance;
	}
	else
	{
		cout << "Error: can only have one instance of IngredientDatabase" << endl;
		exit(0);
	}
}
