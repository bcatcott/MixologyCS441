#include "ingredientdatabase.h"
#include "cabinet.h"
#include <string>
#include <iostream>

using namespace std;

int main() {

	IngredientDatabase *ingDB;
	ingDB = IngredientDatabase::Instance();
	Cabinet *cabinet1;
	cabinet1 = Cabinet::Instance();
	int command;
	string input;
	char again = 'y';

	ingDB->populateDB("Ingredient.txt");

	cout << "CS 441 Mixology Project - Unit Test 1" << endl << endl;

	cout << "List of Possible Ingredients: " << endl;
	ingDB->displayDB();

	cout << endl << "Ingredients in Cabinet:" << endl;
	cabinet1->displayCab();

	while ((again == 'y') || (again == 'Y'))
	{
		cout << "COMMANDS" << endl;
		cout << "1 - Add Ingredient to Cabinet" << endl;
		cout << "2 - Remove Ingredient from Cabinet" << endl;
		cout << endl << "Please choose an option: ";
		cin >> command;

		if (command == 1)
		{
			cout << endl << "Please enter an ingredient to add: ";
			cin >> input;
			Ingredient newIng(input);
			newIng.FormatIng();
			cabinet1->addIng(newIng, *ingDB);
		}
		else if (command == 2)
		{
			cout << endl << "Please enter an ingredient to remove: ";
			cin >> input;
			Ingredient deleteIng(input);
			deleteIng.FormatIng();
			cabinet1->removeIng(deleteIng);
		}

		cout << endl << "Ingredients in Cabinet:" << endl;
		cabinet1->displayCab();

		cout << "Would you like to perform another action? (Y/N) ";
		cin >> again;
		cout << endl;
	}
}