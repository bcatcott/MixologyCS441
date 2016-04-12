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
using namespace std;


class CocktailDB
{
public:
    vector <Cocktail> dataBase;
    
public:
    
    void processFile (string fileName);
    void display();

      
    
};


