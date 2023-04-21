#include "Store.h"
#include "Salesman.h"
#include "Stock.h"

using namespace std;

Store::Store(string name, string adress, list<Salesman>& salesmans, Stock& stock) : salesmans(salesmans), stock(stock)
{
	this->name = name;
	this->adress = adress;
}

string Store::getName()
{
	return name;
}

string Store::getAdress()
{
	return adress;
}

list<Salesman>& Store::getSalesmans()
{
	return salesmans;
}

Stock Store::getStock()
{
	return stock;
}

list<Quotation> Store::getQuotatiosHistory()
{
	return QuotationsHistory;
}

void Store::pushQuotation(Quotation quotation)
{
	QuotationsHistory.push_back(quotation);
}

int Store::getNextIdQuo()
{
	nextIdQuo++;
	return nextIdQuo;
}
