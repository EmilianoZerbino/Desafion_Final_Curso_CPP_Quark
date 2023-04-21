#include "Trouser.h"
#include <iostream>


Trouser::Trouser(float unitPrice, bool isPremium, bool isSkinny)
    :Clothing(getName(isPremium, isSkinny),unitPrice, isPremium)
{
    this->isSkinny = isSkinny;
}

float Trouser::getUnitFinalPrice()
{
    float unitFinalPrice=unitPrice;
    if (isSkinny) {
        unitFinalPrice = unitFinalPrice * 0.88;
    }
    if (isPremium) {
        unitFinalPrice = unitFinalPrice * 1.3;
    }
    return unitFinalPrice;
}

string Trouser::getName(bool isPremium, bool isSkinny) {
    string name = "Pantalon";
    if (isSkinny) {
        name = name + " Chupin";
    }
    else {
        name = name + " Normal";
    }
    if (isPremium) {
        name = name + " Premium";
    }
    else {
        name = name + " Standard";
    }

    return name;
}


