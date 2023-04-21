#pragma once

#include "Clothing.h"

class Trouser : public Clothing
{
public:

    Trouser(float unitPrice, bool isPremium, bool isSkinny);
    float getUnitFinalPrice() override;
    

private:

    bool isSkinny;
    string getName(bool isPremium, bool isSkinny);

};

