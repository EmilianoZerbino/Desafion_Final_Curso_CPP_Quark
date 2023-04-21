#pragma once
#include<string>
#include "Quotation.h"
#include<list>

using namespace std;

class Salesman
{
public:

	Salesman();
	Salesman(string name, string lastName, string code, string password);
	Quotation quote(int quotationCode, Clothing* clothing, int quantity);
	string getName();
	string getLastName();
	string getPassword();
	string getCode();

private:

	string name;
	string lastName;
	string code;
	string password;
};