#include "Store.h"
#include "View.h"
#include "Salesman.h"
#include "Presenter.h"
#include "Stock.h"

#include <windows.h>

#include <list>

using namespace std;


int main()
{
    list<Salesman> salesmans;
    Salesman salesman1("Juan Manuel", "Carrizo", "1001", "password01");
    Salesman salesman2("Luis", "Pedrozo", "1002", "password02");
    salesmans.push_back(salesman1);
    salesmans.push_back(salesman2);

    Stock stock(100, 150, 75, 175, 750, 250, 100, 150, 75, 175, 750, 250);

    Store store("Todo Ropa", "Av. San Martin 123", salesmans, stock);
    View view;

    Presenter presentador(store, view);
    presentador.execute();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 0);
    return 0;
}