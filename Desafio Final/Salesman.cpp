#include "Salesman.h"
#include "Clothing.h"
#include<string>

using namespace std;

Salesman::Salesman()
{

}

Salesman::Salesman(string name, string lastName, string code, string password) 
{
	this->name = name;
	this->lastName = lastName;
	this->code = code;
	this->password = password;
}

Quotation Salesman::quote(int quotationCode, Clothing* clothing, int quantity)
{
	return Quotation(quotationCode, code, clothing, quantity);
}

string Salesman::getName()
{
	return name;
}

string Salesman::getLastName()
{
	return lastName;
}

string Salesman::getPassword()
{
	return password;
}

string Salesman::getCode()
{
	return code;
}

