#include "Ingredientdatabase.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

IngredientDatabase::IngredientDatabase()
{
}

void IngredientDatabase::PopulateDB(string filename)
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

bool IngredientDatabase::CompareDB(Ingredient ing)
{
	for(size_t i = 0; i < ingredientDBList.size() - 1; i++)
	{
		if(ing == ingredientDBList[i])
			return true;
	}
	return false;
}

void IngredientDatabase::DisplayDB()
{
    if (ingredientDBList.size() == 0)
    {
        cout << "Empty Ingredients Database\n";
    }
	for (size_t i = 0; i < ingredientDBList.size(); i++)
	{
		ingredientDBList[i].DisplayIngredient();
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

int IngredientDatabase::GetSize()
{
    return ingredientDBList.size();
}

vector<Ingredient> IngredientDatabase::SearchDB(string searchIngName)
{
	vector<Ingredient> searchedList;

	if (searchIngName.length() != 0)
	{
		for (int i = 0; i < searchIngName.length(); i++)
		{
			if (searchIngName[i] == ' ')
				searchIngName[i] = '_';
			else
				searchIngName[i] = tolower(searchIngName[i]);
		}

		for (int i = 0; i < ingredientDBList.size(); i++)
		{
			bool possibleIng = true;
			if (searchIngName.length() <= ingredientDBList[i].GetName().length())
			{
				int x = 0;
				while (x < searchIngName.length())
				{
					if (searchIngName[x] == ingredientDBList[i].GetName()[x])
						x++;
					else
						x = 1 + searchIngName.length();
				}
				if (x == searchIngName.length())
				{
					Ingredient searchIngObj(searchIngName);
					searchedList.push_back(searchIngObj);
				}

			}
		}
	}
}
