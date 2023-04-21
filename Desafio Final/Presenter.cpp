#include "Presenter.h"
#include "Clothing.h"
#include "Shirt.h"
#include "Trouser.h"


Presenter::Presenter(Store& store, View& view) : store(store), view(view)
{
}

void Presenter::execute()
{
	bool check = true;
	bool incorrect = false;
	string codeEntered;
	string passwordEntered;
	Salesman actualSalesman;

	view.loadStore(store);

	while (codeEntered != "salir" && passwordEntered != "salir")
	{
		while (check && codeEntered != "salir" && passwordEntered != "salir")
		{
			view.loadSalesmanMenu(codeEntered, passwordEntered, incorrect);
			if (codeEntered != "salir" && passwordEntered != "salir") {
				for (auto salesman = store.getSalesmans().begin(); salesman != store.getSalesmans().end(); ++salesman) {
					if (check) {
						if (codeEntered == salesman->getCode()) {
							if (passwordEntered == salesman->getPassword())
							{
								actualSalesman = *salesman;
								view.loadSalesman(actualSalesman);
								check = false;
								incorrect = false;
							}
							else {
								incorrect = true;
							}
						}
						else {
							incorrect = true;
						}
					}
				}
			}
		}
		if (codeEntered != "salir" && passwordEntered != "salir") {
			string option = "0";
			while (option != "3") {
				option = view.loadMainMenu();
				if (option == "1") {
					view.loadQuotatiosHistory(store.getQuotatiosHistory());
				}
				if (option == "2") {
					int clothingType = view.loadQuoteMenu();
					if (clothingType != -1) {
						float unitPrice = view.loadPriceMenu();
						if (unitPrice != -1) {
							int quantity = view.loadQuantityMenu(store.getStock().getClothingStock(clothingType));
							if (quantity != -1) {

								Clothing* clothing;

								bool isPremium = false;
								
								if (clothingType <= 3 || (clothingType >= 6 && clothingType <=9)) {
									bool isShortSleeve=false;
									bool isMaoCollar=false;
									if (clothingType == 0 || clothingType == 1 || clothingType == 6 || clothingType == 7) {
										isShortSleeve = true;
									}
									if (clothingType % 2 == 0) {
										isMaoCollar = true;
									}
									if (clothingType >= 6) {
										isPremium = true;
									}
									clothing = new Shirt(unitPrice, isPremium, isShortSleeve, isMaoCollar);
								}else {
									bool isSkinny=false;
									if (clothingType % 2 == 0) {
										isSkinny = true;
									}
									if (clothingType >= 6) {
										isPremium = true;
									}
									else {
									}
									clothing = new Trouser(unitPrice, isPremium, isSkinny);
								}
								
								//------------------------------------------------------------------------------
								Quotation quotation = actualSalesman.quote(store.getNextIdQuo(), clothing, quantity);

								store.pushQuotation(quotation);
								view.loadQuotationResult(quotation);

							}
						}
					}
				}
			}
			check = true;
		}
	}
	view.endScreen();
}



