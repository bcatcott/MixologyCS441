#pragma once

#include <string>

using namespace std;

class ingredient
{
private:
	string name;
	int quantity;

public:
	ingredient(const string &inputName);
	ingredient(string inputName, int inputQuantity);
	~ingredient();
	bool operator==(const ingredient &obj);
	string getName();
	int getQuantity() const;
	void updateQuantity(int amt);
};

