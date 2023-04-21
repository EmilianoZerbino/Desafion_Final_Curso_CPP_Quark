#pragma once
#include <list>
#include<string>
#include "Salesman.h"
#include "Stock.h"

using namespace std;

class Store
{
public:

    Store(string name, string adress, list<Salesman>& salesmans, Stock& stock);
    string getName();
    string getAdress();
    list<Salesman>& getSalesmans();
    Stock getStock();
    list<Quotation> getQuotatiosHistory();
    void pushQuotation(Quotation quotation);
    int getNextIdQuo();

private:

    string name;
    string adress;
    list<Salesman>& salesmans;
    Stock& stock;
    list<Quotation> QuotationsHistory;
    int nextIdQuo = 0;

};

