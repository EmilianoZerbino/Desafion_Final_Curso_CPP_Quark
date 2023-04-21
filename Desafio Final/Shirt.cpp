#include "Shirt.h"
#include <iostream>


Shirt::Shirt(float unitPrice, bool isPremium, bool isShortSleeve, bool isMaoCollar)
    :Clothing(getName(isPremium, isShortSleeve, isMaoCollar),unitPrice, isPremium)
{
    this->isShortSleeve = isShortSleeve;
    this->isMaoCollar = isMaoCollar;
}

float Shirt::getUnitFinalPrice()
{
    float unitFinalPrice=unitPrice;
    if (isShortSleeve) {
        unitFinalPrice = unitFinalPrice * 0.9;
    }
    if (isMaoCollar) {
        unitFinalPrice = unitFinalPrice * 1.03;
    }
    if (isPremium) {
        unitFinalPrice = unitFinalPrice * 1.3;
    }
    return unitFinalPrice;
}

string Shirt::getName(bool isPremium, bool isShortSleeve, bool isMaoCollar) {
    string name = "Camisa";
    if (isShortSleeve) {
        name = name + " manga Corta";
    }
    else {
        name = name + " manga Larga";
    }
    if (isMaoCollar) {
        name = name + " Cuello MAO";
    }
    else {
        name = name + " Cuello Normal";
    }
    if (isPremium) {
        name = name + " Premium";
    }
    else {
        name = name + " Standard";
    }

    return name;
}

