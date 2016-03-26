#include "ingredientdatabase.h"
#include "ui_ingredientdatabase.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

IngredientDatabase::IngredientDatabase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IngredientDatabase)
{
    ui->setupUi(this);

    //Create linked-list called IngredientDB
    //Call populateDB() to read file and populate databse
}

IngredientDatabase::populateDB(string filename)
{
    string line;
    ifstream myfile;
    myfile.open (filename);

    if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
          cout << line << '\n';
        }
        myfile.close();
      }

      else cout << "Unable to open file";
    myfile.close();
}

IngredientDatabase::~IngredientDatabase()
{
    delete ui;
}
