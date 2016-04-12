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
using namespace std;

void CocktailDB::exportDatabase()
{
    ofstream fout;
    fout.open ("cocktailDatabase.txt");
    for (int i =0; i<dataBase.size();i++)
    {
        Cocktail ck;
        ck = dataBase[i];
        fout<<ck.cocktailName<<endl;
        for (int j =0;j<ck.recipe.size();j++)
        {
            string name = ck.recipe[j].getName();
            int quantity = ck.recipe[j].getQuantity();
            fout << name << "  ";
            fout << quantity << endl;
        }
        fout<<endl;
    }
    fout.close();
}
void CocktailDB::display()
{
    for (int i =0; i<dataBase.size();i++)
    {
        cout<<"CockTail "<<i+1<<endl;
        dataBase[i].printCocktailRecipe();
        cout<< endl;
    }
}



void CocktailDB::processFile(const string fileName)
{
    
    ifstream fin;
    fin.open(fileName);
    string nameOfCocktail; string ingName;
    int quantity = 0;
    int numOfIng = 0;

    while (fin >> nameOfCocktail)
    {
    Cocktail ck(nameOfCocktail);
    fin >> numOfIng;
    for (int i =0;i<numOfIng;i++)
    {
        fin >> ingName;
        fin >> quantity;
        Ingredient newIngredient(ingName, quantity);
        ck.addIngCocktail(newIngredient);
    }
        dataBase.push_back(ck);
    }

    fin.close();
    
}







