#include "Clothing.h"

Clothing::Clothing(string type, float unitPrice, bool isPremium)
{
	this->type = type;
	this->unitPrice = unitPrice;
	this->isPremium = isPremium;
}

string Clothing::getType()
{
	return type;
}

float Clothing::getUnitPrice()
{
	return unitPrice;
}

