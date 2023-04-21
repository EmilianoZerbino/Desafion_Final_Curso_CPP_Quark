#include "Quotation.h"
#include "Clothing.h"
#include <string>
#include <ctime>

using namespace std;

Quotation::Quotation() {}

Quotation::Quotation(int id, string salesmanCode, Clothing* clothing, int quantity) {
	this->id = id;
	this->salesmanCode = salesmanCode;
	this->dateAndTime = calculateDateAndTime();
	this->clothing = clothing;
	this->quantity = quantity;
}

int Quotation::getId()
{
	return id;
}

string Quotation::getSalesmanCode()
{
	return salesmanCode;
}

string Quotation::getDateAndTime()
{
	return dateAndTime;
}

Clothing* Quotation::getClothing()
{
	return clothing;
}

int Quotation::getQuantity()
{
	return quantity;
}

float Quotation::getFinalPurchase()
{
	return quantity*clothing->getUnitFinalPrice();
}

string Quotation::calculateDateAndTime()
{
    time_t tiempo = time(nullptr);
    tm fechaHora;
    localtime_s(&fechaHora, &tiempo);
	string hora;
	string minutos;
	if (fechaHora.tm_hour < 10) {
		hora = "0" + to_string(fechaHora.tm_hour);
	}
	else {
		hora = to_string(fechaHora.tm_hour);
	}
	if (fechaHora.tm_min < 10) {
		minutos = "0" + to_string(fechaHora.tm_min);
	}
	else {
		minutos = to_string(fechaHora.tm_min);
	}
    string resultado = (to_string(fechaHora.tm_mday) + "/" + to_string(fechaHora.tm_mon+1) + "/" + to_string(fechaHora.tm_year+1900) + "  " + hora + ":" + minutos);
    return resultado;
}
