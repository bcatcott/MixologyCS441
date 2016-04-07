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
const int MAX=20;


void CocktailDB::addCocktail(string newCocktailIngredients)
{
    string newWords [MAX];
    int counter=0;
    string tempString;
    
    for (int i =0;i<newCocktailIngredients.length();i++)//appending string 'sentence' into a string array of 'words
    {
        if (newCocktailIngredients[i]==' ')
        {
            counter++;
            tempString = newWords[counter];
        }
        else
            newWords[counter]+=newCocktailIngredients[i];
        
    }
    Cocktail ck;
    ck.cocktailName = newWords [0];
    cout<<ck.cocktailName<<endl;

    
    
}

void CocktailDB::processFile(string fileName)
{
    
    ifstream fin;
    fin.open(fileName);
    string tempCocktail;

    if (fin)
    {
    
    while (getline(fin,tempCocktail))
        addCocktail(tempCocktail);
           
    }
    else
        cout<<"error, bad file."<<endl;
    fin.close();
    
}




/*
void CocktailDB::importDB(string fileName)
{
    ifstream fin;
    fin.open(fileName);
    string name;
    string mixer; //place holder for both alc and non alc ingredients
    int quantity;
    char cmd;
    
    while (fin>>cmd)
    {
        if (cmd == 'N')
        {
            Cocktail newCk;
            fin>>name;
            newCk.ckName = name;
            fin>>cmd;
            if (cmd == 'M')
            {
                fin>>mixer;
                newCk.vMixer.push_back(mixer);
                //cout<< ck.vMixer[0]<<endl;    //ECHO
                fin>>cmd;
            }
            else if (cmd == 'Q')
            {
                fin>>quantity;
                cout<<quantity; //ECHO
                newCk.vQuantity.push_back(quantity);
                //cout<<ck.vQuantity[0];
                fin>>cmd;
            }
            dataBase.push_back(newCk);
        }
    }
    
}
*/


