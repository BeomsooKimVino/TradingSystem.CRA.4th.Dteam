#include <iostream>
#include <string>
#include "IBroker.h"

using namespace std;

class AutoTradingSystem {
public:
	void selectStockBrocker(string type) {
		if (type == "Kiwer")
			broker = new KiwerBroker();
		else if (type == "Nemo")
			broker = new NemoBroker();
	}

	void login() {

	}

	void buy() {

	}

	void sell() {

	}

	int getPrice() {

	}

	void buyNiceTiming(string stockCode, int price) {
		int prevPrice = 0;
		int climbCount = 0;

		for (int checkCnt = 0; checkCnt < MAX_BUY_CECHK_COUNT; checkCnt++)
		{
			int currentPrice = broker->currentPrice(stockCode);
			if (prevPrice < currentPrice) {
				climbCount = 0;
				continue;
			}

			climbCount++;
			if (climbCount > MAX_BUY_CLIMB_COUNT)
			{
				broker->buy(stockCode, price / currentPrice, currentPrice);
			}
			prevPrice = currentPrice;
		}
	}

	void sellNiceTiming() {	
		
	}

private:
	IBroker* broker;

	const int MAX_BUY_CECHK_COUNT = 24;
	const int MAX_BUY_CLIMB_COUNT = 3;
};
