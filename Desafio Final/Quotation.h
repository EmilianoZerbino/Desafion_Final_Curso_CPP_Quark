#pragma once

#include <ctime>
#include <string>
#include "Clothing.h"

using namespace std;

class Quotation
{
public:

	Quotation();
	Quotation(int id, string salesmanCode, Clothing* clothing, int quantity);
	int getId();
	string getSalesmanCode();
	string getDateAndTime();
	Clothing* getClothing();
	int getQuantity();
	float getFinalPurchase();

private:
	
	int id;
	string salesmanCode;
	string dateAndTime;
	Clothing* clothing;
	int quantity;
	float unitPrice;
	float finalPurchase;

	string calculateDateAndTime();
};