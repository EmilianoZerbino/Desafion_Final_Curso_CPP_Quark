#pragma once

using namespace std;

class Stock
{
public:

	Stock(int camisaCortaMaoStandard, int camisaCortaNormalStandard, int camisaLargaMaoStandard,
		  int camisaLargaNormalStandard, int pantalonChupinStandard, int pantalonNormalStandard,
		  int camisaCortaMaoPremium, int camisaCortaNormalPremium, int camisaLargaMaoPremium,
		  int camisaLargaNormalPremium, int pantalonChupinPremium, int pantalonNormalPremium);

	int getClothingStock(int clothingType);


private:

	int quantities[12];

};
