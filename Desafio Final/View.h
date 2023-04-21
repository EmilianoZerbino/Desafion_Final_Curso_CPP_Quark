#pragma once
#include <string>
#include <vector>
#include <list>

#include "Store.h"
#include "Salesman.h"
#include "Quotation.h"

using namespace std;

class View
{
public:

    View();
    void loadSalesmanMenu(string& codeEntered, string& passwordEntered, bool incorrect);
    string loadMainMenu();
    void loadQuotatiosHistory(list<Quotation> quotations);
    int  loadQuoteMenu();
    void loadQuotationResult(Quotation quotation);
    float loadPriceMenu();
    int loadQuantityMenu(int stock);

    void loadStore(Store& store);
    void loadSalesman(Salesman salesman);  
    
    void endScreen();

private:

    string nameStore;
    string adressStore;
    Salesman salesman;
    string option;
    int clothing=0;

    string clothingDescription[12] = {"Camisa - Corta - Mao - Standard","Camisa - Corta - Normal - Standard",
                              "Camisa - Larga - Mao - Standard","Camisa - Larga - Normal - Standard",
                              "Pantalon - Chupin - Standard"   , "Pantalon - Normal - Standard"     ,
                              "Camisa - Corta - Mao - Premium" ,"Camisa - Corta - Normal - Premium" ,
                              "Camisa - Larga - Mao - Premium" ,"Camisa - Larga - Normal - Premium" ,
                              "Pantalon - Chupin - Premium"    , "Pantalon - Normal - Premium"      ,
                             };

    void loadQuoteShirt1Menu();
    void loadQuoteShirt2Menu();
    void loadQuoteTrouserMenu();
    void loadQualityMenu();
    void header(string pagina, bool salesman, string leyenda);
    void cleanConsole();
    void checkIncorrectOption(int posX, int posY);
    void setConsole();
    void setErrorLetter();
    void setNormalLetter();
    void setCursorPosition(short x, short y);

};
