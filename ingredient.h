#pragma once

#include <string>

using namespace std;

class Ingredient
{
private:
	string name;
	int quantity;

public:
	Ingredient(const string &inputName);
	Ingredient(string inputName, int inputQuantity);
	~Ingredient();
	bool operator==(const Ingredient &obj);
	string getName();
	int getQuantity() const;
	void updateQuantity(int amt);
};

