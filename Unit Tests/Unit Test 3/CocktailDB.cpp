//
//  CocktailDB.cpp
//  MixCS351
//
//  Created by So Cal on 4/5/16.
//  Copyright © 2016 So Cal. All rights reserved.
//

#include <fstream>
#include <string>
#include <iostream>
#include "Cocktail.h"
#include "CocktailDB.h"
#include "cabinet.h"
using namespace std;

CocktailDB::CocktailDB()
{
}

CocktailDB::~CocktailDB()
{
	_instance = 0; //Resets singleton code
}

void CocktailDB::ExportDatabase()
{
    ofstream fout;
    fout.open ("cocktailDatabase.txt");

    for (int i =0; i<dataBase.size();i++)
    {
        Cocktail ck;
        ck = dataBase[i];
        fout<<ck.GetCocktailName()<<endl;
        for (int j =0;j<ck.GetRecipe().size();j++)
        {
            string name = ck.GetRecipe()[j].GetName();
            int quantity = ck.GetRecipe()[j].GetQuantity();
            fout << name << "  ";
            fout << quantity << endl;
        }

        fout << ck.GetRating();
        fout<<endl;
    }
    fout.close();
}

void CocktailDB::Display()
{
    for (int i =0; i<dataBase.size();i++)
    {
        cout<<"CockTail "<<i+1<<endl;
        dataBase[i].PrintCocktailRecipe();
        cout<< endl;
    }
}



void CocktailDB::ProcessFile(const string fileName)
{
    
    ifstream fin;
    fin.open(fileName);
    string nameOfCocktail; string ingName;
    int quantity = 0;
    int numOfIng = 0;
    float rating =0;
	vector <Ingredient> recipe;


    while (fin >> nameOfCocktail)
    {
    fin >> numOfIng;

		for (int i =0;i<numOfIng;i++)
		{
			fin >> ingName;
		    fin >> quantity;
			Ingredient newIngredient(ingName, quantity);
			
			recipe.push_back(newIngredient);
		}
    fin >> rating;
	Cocktail ck(nameOfCocktail, recipe, rating);
    dataBase.push_back(ck);
    }

    fin.close();
    
}

CocktailDB* CocktailDB::_instance = 0; //Singleton Code


CocktailDB* CocktailDB::Instance() //Singleton Code
{
	if (_instance == 0)
	{
		_instance = new CocktailDB();
		return _instance;
	}
	else
	{
		cout << "Error: can only have one instance of CocktailDB" << endl;
		exit(0);
	}
}

vector<Cocktail> CocktailDB::FindCocktail(string input)
{
    vector<Cocktail> results;
    vector<Cocktail>::iterator it;
	string cocktail;

	for(it = dataBase.begin(); it != dataBase.end(); ++it)
	{
		for(int i = 0; i < input.length(); i++)
		{
		    cocktail = (*it).GetCocktailName();
            if(input[i] != cocktail[i])
            {
                break;
            }
		}
        results.push_back(*it);
	}
	
	if( results.size() == 0 )
	{
		Cocktail temp("nothing");
		results.push_back(temp);
	}
	
	return results;
}

void CocktailDB::ImFeelingLucky()
{
	int random = rand() % dataBase.size();
	dataBase[random].PrintCocktailRecipe();
	cout << endl;
}

vector<Cocktail> CocktailDB::SearchByIngredient(Cabinet cab) {

	vector<Ingredient> cabIngList;
	cabIngList = cab.GetCabIngList();
	vector<Cocktail> tempCTDB = dataBase;

	for (int x = 0; x < (tempCTDB.size() - 1); x++)
	{
		int total = tempCTDB[x].GetNumOfIngredients();
		for (int i = 0; i < (cabIngList.size() - 1); i++)
		{
			total -= tempCTDB[x].VisitIngredient(cabIngList[i]);

		}
		tempCTDB[x].SetIngNeeded(total);
    }

	return SortByIngNeeded(tempCTDB);
}

vector<Cocktail> CocktailDB::SortByIngNeeded(vector <Cocktail> tempCTDB)
{
	vector<Cocktail> sortedCocktailDB;

	while (tempCTDB.size() != 0)
	{
		Cocktail newCocktail = tempCTDB[0];
		int count = 0;

		for (int x = 1; x < (tempCTDB.size() - 1); x++)
		{
			if (newCocktail.VisitIngNeeded(tempCTDB[x]))
			{
				newCocktail = tempCTDB[x];
				count = x;
			}
		}

		sortedCocktailDB.push_back(newCocktail);
		tempCTDB.erase(tempCTDB.begin() + count);
	}

	return sortedCocktailDB;
}
