#include "ingredientdatabase.h"
#include "cabinet.h"
#include <string>
#include <iostream>

using namespace std;

int main() {

	IngredientDatabase ingredientDB1;
	cabinet cabinet1;
	char command;
	string input;

	ingredientDB1.populateDB("Ingredient.txt");

	cout << "CS 441 Mixology Project - Unit Test 1" << endl << endl;

	cout << "List of Possible Ingredients: " << endl;

	ingredientDB1.displayIngDB();

	cout << endl << endl << "Ingredients in Cabinet:" << endl;

	cabinet1.displayCab();

	cout << endl << endl << "Would you like to add an ingredient? (Y/N) ";

	cin >> command;

	if ((command == 'y') || (command == 'Y')) {
		cout << endl << "Please enter an ingredient: ";
		cin >> input;
	}
}