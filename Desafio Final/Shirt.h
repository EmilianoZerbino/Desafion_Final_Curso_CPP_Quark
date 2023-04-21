#pragma once

#include "Clothing.h"

class Shirt : public Clothing
{
public:

    Shirt(float unitPrice, bool isPremium, bool isShortSleeve, bool isMaoCollar);
    float getUnitFinalPrice() override;

private:

    bool isShortSleeve;
    bool isMaoCollar;

    string getName(bool isPremium, bool isShortSleeve, bool isMaoCollar);

};

