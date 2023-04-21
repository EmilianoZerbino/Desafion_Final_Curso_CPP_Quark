#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <iomanip>

#include "Store.h"
#include "View.h"
#include "Salesman.h"


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

View::View() {
}

void View::loadStore(Store& store)
{
    nameStore = store.getName();
    adressStore = store.getAdress();
}

void View::loadSalesman(Salesman salesman)
{
    this->salesman = salesman;
}

void  View::loadSalesmanMenu(string& codeEntered, string& passwordEntered, bool incorrect)
{
    setConsole();
    header("                   COTIZADOR EXPRESS - LOGIN", false, "                                  Ingrese salir para finalizar.");
    setCursorPosition(0, 5);
    cout << " Bienvenido al Sistema de Cotizacion Express de " + nameStore + ": \n";
    if (incorrect) 
    {
        setErrorLetter();
        cout << " Usuario o Password incorrecto, vuelva a intentarlo.\n\n";
        setNormalLetter();
    }
    else {
        cout << "\n\n";
    }
    cout << " Ingrese Codigo de Vendedor: ";
    cin >> codeEntered;
    if (codeEntered != "salir") {
        
        cout << "\n Ingrese su Password: ";
        cin >> passwordEntered;
    }
}

string View::loadMainMenu()
{
    header("               COTIZADOR EXPRESS - MENU PRINCIPAL",true, "                                          Ingrese 3 para salir.");
    setCursorPosition(0, 7);
    cout << "                SELECCIONE UNA OPCION DEL MENU          \n\n";
    cout << " 1) Historial de Cotizaciones\n";
    cout << " 2) Realizar Cotizacion\n";
    cout << " 3) Salir\n\n";
    cout << "         Su opcion: ";
    setCursorPosition(20, 13);
    cin >> option;
    checkIncorrectOption(20, 13);
    return option;
}

void View::loadQuotatiosHistory(list<Quotation> quotations)
{
    header("          COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES", false, "");
    setCursorPosition(0, 27);
    cout << "                                                                ";
    setCursorPosition(0, 5);
    COORD size;
    size.X = 64;
    size.Y = 200;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), size);
    
            if (quotations.size() > 0) {

                auto it = quotations.begin();
                Quotation quotation = *it;

                for (auto quotation = quotations.begin(); quotation != quotations.end(); ++quotation) {
                    cout << " Numero de Identificacion : " + to_string(quotation->getId()) + "\n";
                    cout << " Fecha Y Hora de Cotizacion : " + quotation->getDateAndTime() + "\n";
                    cout << " Codigo del Vendedor : " + quotation->getSalesmanCode() + "\n";
                    cout << " Prenda Cotizada : "+ quotation->getClothing()->getType()+"\n";
                    cout << " Precio Unitario : $" << fixed << setprecision(2) << quotation->getClothing()->getUnitPrice() << endl;
                    cout << " Cantidad de Unidades cotizadas : " + to_string(quotation->getQuantity()) + "\n";
                    cout << " Precio Final : $" << fixed << setprecision(2) << quotation->getFinalPurchase() << endl;
                    cout << "\n\n";
                }
            }
            string s;
            cout << "Ingrese 3 para volver al Menu Principal: ";
            while (s != "3") {
            cin >> s;             
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
            GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo);
            COORD cursorPosition;
            cursorPosition.X = screenBufferInfo.dwCursorPosition.X;
            cursorPosition.Y = screenBufferInfo.dwCursorPosition.Y - 1;
            SetConsoleCursorPosition(hConsole, cursorPosition);
            cout << "Ingrese 3 para volver al Menu Principal:                        \n";
            setErrorLetter();
            cout << "Valor Incorrecto.";
            setNormalLetter();
            cursorPosition.X = screenBufferInfo.dwCursorPosition.X + 41;
            cursorPosition.Y = screenBufferInfo.dwCursorPosition.Y - 1;
            SetConsoleCursorPosition(hConsole, cursorPosition);
            }
            setConsole();
}

int View::loadQuoteMenu()
{
    header("                 COTIZADOR EXPRESS - COTIZAR         ", true, "                                          Ingrese 3 para salir.");
    setCursorPosition(0, 7);
    cout << " PASO 1: Seleccione la prenda a Cotizar:\n\n";
    cout << " 1) Camisa\n";
    cout << " 2) Pantalon\n\n";
    cout << "         Su opcion:                                          ";
    option = "0";
    clothing = 0;
    setCursorPosition(20, 12);
    cin >> option;
    checkIncorrectOption(20, 12);
    if (option == "1")
    {
        loadQuoteShirt1Menu();
    }
    else if (option == "2")
    {
        clothing = clothing + 4;
        loadQuoteTrouserMenu();
    }
    if (option == "3") {
        clothing = -1;
    }
    return clothing;
}

void View::loadQuoteShirt1Menu()
{
    if (option != "3") {
        setCursorPosition(0, 7);
        cout << " PASO 2.a: La camisa a cotizar , Es de manga corta?\n\n";
        cout << " 1) Si    \n";
        cout << " 2) No      \n\n";
        cout << "         Su opcion:                                           ";
        setCursorPosition(20, 12);
        cin >> option;
        checkIncorrectOption(20, 12);
        if (option == "2")
        {
            clothing = clothing + 2;
        }
        loadQuoteShirt2Menu();
    }
}

void View::loadQuoteShirt2Menu()
{
    if (option != "3") {
        setCursorPosition(0, 7);
        cout << " PASO 2.b: La camisa a cotizar, Es cuello Mao?     \n\n";
        cout << " 1) Si\n";
        cout << " 2) No\n\n";
        cout << "         Su opcion:                                           ";
        setCursorPosition(20, 12);
        cin >> option;
        checkIncorrectOption(20, 12);
        if (option == "2")
        {
            clothing = clothing++;
        }
        loadQualityMenu();
    }
}

void View::loadQuoteTrouserMenu()
{
    if (option != "3") {
        setCursorPosition(0, 7);
        cout << " PASO 2: El pantalon a cotizar, Es chupin?\n\n";
        cout << " 1) Si      \n";
        cout << " 2) No      \n\n";
        cout << "         Su opcion:                                           ";
        setCursorPosition(20, 12);
        cin >> option;
        checkIncorrectOption(20, 12);
        if (option == "2")
        {
            clothing = clothing++;
        }
        loadQualityMenu();
    }
}

void View::loadQualityMenu()
{
    if (option != "3") {
        setCursorPosition(0, 7);
        cout << " PASO 3: Seleccione la calidad de la prenda:   \n\n";
        cout << " 1) Standard\n";
        cout << " 2) Premium\n\n";
        cout << "         Su opcion:                                           ";
        setCursorPosition(20, 12);
        cin >> option;
        checkIncorrectOption(20, 12);
        if (option == "2")
        {
            clothing = clothing + 6;
        }
    }
}

float View::loadPriceMenu()
{
    header("                 COTIZADOR EXPRESS - COTIZAR         ", true, "                      Ingrese M para volver al menu principal. ");
    setCursorPosition(0, 7);
    cout << " PASO 4: Ingrese el precio unitario de la prenda a cotizar:   \n\n";
    cout << "         Precio:             \n";
    cout << "            \n\n";
    cout << "                                                              ";
    string ingreso;
    bool check = true;
    float precio;
    setCursorPosition(17, 9);
    while (check) {
        cin >> ingreso;
        if (ingreso != "M") {
                try {
                    precio = stof(ingreso);
                    check = false;
                }
                catch (invalid_argument const& e) {
                    setCursorPosition(17, 9);
                    setErrorLetter();
                    cout << "                                        ";
                    cout << "\n         Valor incorrecto, vuelva a intentarlo.                ";
                    setNormalLetter();
                    setCursorPosition(17, 9);
                }
        }
        else 
        {
            precio = -1;
            check = false;
        }
    }
    return precio;
}

int View::loadQuantityMenu(int stock)
{
    header("                 COTIZADOR EXPRESS - COTIZAR         ", true, "                      Ingrese M para volver al menu principal. ");
    setCursorPosition(0, 7);
    cout << "                                                           \n";
    cout << " INFORMACION:\n";
    cout << " EXISTEN " << stock << " UNIDADES EN STOCK DE LA PRENDA SELECCIONADA\n\n";
    cout << " PASO 5: Ingrese la cantidad de unidades a cotizar:   \n\n";
    cout << "         Cantidad:\n";
    cout << "           \n\n";
    cout << "                               ";
    setCursorPosition(19, 13);
    string ingreso;
    bool check = true;
    int quantity;
    setCursorPosition(19, 13);
    while (check) {
        cin >> ingreso;
        if (ingreso != "M") {
            try {
                size_t pos = 0;
                quantity = stoi(ingreso, &pos);
                if (pos == ingreso.length())
                {
                    check = false;
                    if (quantity > stock) {
                        setCursorPosition(19, 13);
                        setErrorLetter();
                        cout << "                                        ";
                        cout << "\n         El Valor ingresado excede el stock de esta prenda.";
                        setNormalLetter();
                        setCursorPosition(19, 13);
                        check = true;
                    }
                }
                else {
                    throw invalid_argument("Es un Float");
                }
            }
            catch (invalid_argument const& e) {
                setCursorPosition(19, 13);
                setErrorLetter();
                cout << "                                        ";
                cout << "\n         Valor incorrecto, vuelva a intentarlo.                    ";
                setNormalLetter();
                setCursorPosition(19, 13);
            }
        }
        else
        {
            quantity = -1;
            check = false;
        }
    }
    return quantity;
}

void View::loadQuotationResult(Quotation quotation)
{
    header("                 COTIZADOR EXPRESS - COTIZACION", false, "                      Ingrese 3 para volver al menu principal. ");
    string s;
    while (s != "3") {
        setCursorPosition(0, 5);
        cout << " Numero de Identificacion : " + to_string(quotation.getId()) + "\n";
        cout << " Fecha Y Hora de Cotizacion : " + quotation.getDateAndTime() + "\n";
        cout << " Codigo del Vendedor : " + salesman.getCode() + "\n";
        cout << " Prenda Cotizada : "+ quotation.getClothing()->getType()+"\n";
        cout << " Precio Unitario : $" << fixed << setprecision(2) << quotation.getClothing()->getUnitPrice() << endl;
        cout << " Cantidad de Unidades cotizadas : " + to_string(quotation.getQuantity()) + "\n";
        cout << " Precio Final : $" << fixed << setprecision(2) << quotation.getFinalPurchase() << endl;
        setCursorPosition(1, 28);
        cout << "                   ";
        setCursorPosition(1, 28);
        cin >> s;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
        GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo);
        COORD cursorPosition;
        cursorPosition.X = screenBufferInfo.dwCursorPosition.X;
        cursorPosition.Y = screenBufferInfo.dwCursorPosition.Y - 1;
        SetConsoleCursorPosition(hConsole, cursorPosition);
        cout << "                      \n";
        setErrorLetter();
        cout << "Valor Incorrecto.";
        setNormalLetter();
        cursorPosition.X = screenBufferInfo.dwCursorPosition.X ;
        cursorPosition.Y = screenBufferInfo.dwCursorPosition.Y - 1;
        SetConsoleCursorPosition(hConsole, cursorPosition);
    }
}

void View::header(string pagina, bool checkSalesman, string leyenda)
{
    cleanConsole();
    cout << pagina + "\n";
    cout << "----------------------------------------------------------------\n";
    cout << " " + nameStore + " | " + adressStore + "\n";
    cout << "----------------------------------------------------------------\n";
    if (checkSalesman) {
        cout << " Vendedor: " + salesman.getName() + " " + salesman.getLastName() + " | " + salesman.getCode() + "\n";
        cout << "----------------------------------------------------------------\n\n";
    }
    else 
    {
        cout << "\n\n\n";
    }
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "----------------------------------------------------------------\n";
    cout << leyenda;
}

void View::endScreen()
{
    cleanConsole();
    cout << "\n\n\n\n\n\n\n\n\n----------------------------------------------------------------\n";
    cout << "              GRACIAS POR UTILIZAR EL SISTEMA\n";
    cout << "----------------------------------------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "----------------------------------------------------------------\n";
    cout << "                                 Presione una tecla para salir.";
    setCursorPosition(0, 15);
}

void View::cleanConsole()
{
    system("cls");
}

void View::setConsole()
{
    system("mode con: lines=30 cols=64");
    setNormalLetter();
}

void View::setErrorLetter()
{
    SetConsoleTextAttribute(hConsole, 4);
}

void View::setNormalLetter()
{
    SetConsoleTextAttribute(hConsole, 15);
}

void View::setCursorPosition(short x, short y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(hConsole, pos);
}

void View::checkIncorrectOption(int posX, int posY) {
    while (option != "1" && option != "2" && option != "3") {
        setCursorPosition(posX, posY);
        setErrorLetter(),
            cout << "   Opcion Incorrecta, Vuelva a intentarlo.";
        setNormalLetter();
        setCursorPosition(posX, posY);
        cin >> option;
    }
}
