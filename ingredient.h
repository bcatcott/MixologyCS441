#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

using namespace std;

class ingredient
{
private:
	string name;
	int quantity;

public:
	ingredient(string inputName);
	ingredient(string inputName, int inputQuantity);
	~ingredient();
	bool operator==(const ingredient &obj);
	string getName();
	int getQuantity();
	void updateQuantity(int amt);
};

#endif
