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

void IngredientDatabase::populateDB(string filename)
{
    string line;
    ifstream myfile;
    myfile.open (filename);

    if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
			ingredientList.push_back(Ingredient(line));
        }
        myfile.close();
      }

      else cout << "Unable to open file";
    myfile.close();
}

IngredientDatabase::~IngredientDatabase()
{
	_instance = 0;
	delete ui;
}


bool IngredientDatabase::_instance = 0; //Singleton Code


IngredientDatabase IngredientDatabase::Instance(QWidget *parent = 0) //Singleton code (I do not know if it is nessisary to have the QWidget *parent = 0 here or just at the declaration for the constructor)
{
	if (_instance == 0)
	{
		_instance = 1;
		return IngredientDatabase(QWidget *parent = 0);
	}
	else
	{
		cout << "Error: can only have one instance of ingredientdatabase" << endl;
		exit(0);
	}
}

