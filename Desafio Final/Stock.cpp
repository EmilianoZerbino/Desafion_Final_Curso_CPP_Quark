#include "Stock.h"

using namespace std;

Stock::Stock(int camisaCortaMaoStandard,    int camisaCortaNormalStandard, int camisaLargaMaoStandard, 
			 int camisaLargaNormalStandard, int pantalonChupinStandard,    int pantalonNormalStandard,
		     int camisaCortaMaoPremium,     int camisaCortaNormalPremium,  int camisaLargaMaoPremium,
			 int camisaLargaNormalPremium,  int pantalonChupinPremium,     int pantalonNormalPremium)
{
	quantities[0] = camisaCortaMaoStandard;
	quantities[1] = camisaCortaNormalStandard;
	quantities[2] = camisaLargaMaoStandard;
	quantities[3] = camisaLargaNormalStandard;
	quantities[4] = pantalonChupinStandard;
	quantities[5] = pantalonNormalStandard;
	quantities[6] = camisaCortaMaoPremium;
	quantities[7] = camisaCortaNormalPremium;
	quantities[8] = camisaLargaMaoPremium;
	quantities[9] = camisaLargaNormalPremium;
	quantities[10] = pantalonChupinPremium;
	quantities[11] = pantalonNormalPremium;
}

int Stock::getClothingStock(int clothingType)
{
	return quantities[clothingType];
}

