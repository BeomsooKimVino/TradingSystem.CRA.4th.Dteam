#include <iostream>
#include <string>
#include "KiwerDriver.h"
using namespace std;

class AutoTradingSystem {
public:
	void selectStockBrocker(string type) {
		if (type == "Kiwer") {
			stockerDriver = new KiwerDriver();
		}
	}

	void login() {

	}

	void buy() {

	}

	void sell() {

	}

	int getPrice() {

	}

	void buyNiceTiming() {

	}

	void sellNiceTiming() {

	}

	IStockerDriver* stockerDriver;
};
