
//
//  CocktailDB.hpp
//  MixCS351
//
//  Created by So Cal on 4/5/16.
//  Copyright © 2016 So Cal. All rights reserved.
//

#pragma once

#include <vector>
#include "Ingredient.h"
#include "Cocktail.h"
#include "Cabinet.h"

using namespace std;

class CocktailDB
{
private:
    vector <Cocktail> dataBase;
	static CocktailDB* _instance; //Singleton Variable

protected:
	CocktailDB(); //Protected because of singleton
    
public:
	static CocktailDB* Instance(); //Must be called to create instance
	~CocktailDB();
    void ProcessFile (const string fileName);
    void Display();
    void ExportDatabase ();
    void ImFeelingLucky();
    std::vector<Cocktail> FindCocktail(string input);
	vector<Cocktail> SearchByIngredient(Cabinet cab);
	vector<Cocktail> SortByIngNeeded(vector <Cocktail> CTDB);
    
};
