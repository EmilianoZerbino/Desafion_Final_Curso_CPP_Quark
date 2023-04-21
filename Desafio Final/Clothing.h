#pragma once
#include <string>

using namespace std;

class Clothing
{
public:

	Clothing(string type, float unitPrice, bool isPremium);
	virtual float getUnitFinalPrice() = 0;
	string getType();
	float getUnitPrice();

protected:

	bool isPremium;
	float unitPrice;

private:

	string type;
	
};

