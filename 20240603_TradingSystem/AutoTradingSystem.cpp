#include <iostream>
#include <string>
#include "IStockerDriver.h"

using namespace std;

class AutoTradingSystem {
public:

	void selectStockBrocker(IStockerDriver* driver) {
		stockDriver = driver;
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
			int currentPrice = stockDriver->GetPrice(stockCode);
			if (prevPrice < currentPrice) {
				climbCount = 0;
				continue;
			}

			climbCount++;
			if (climbCount > MAX_BUY_CLIMB_COUNT)
			{
				stockDriver->Buy(stockCode, price / currentPrice, currentPrice);
			}
			prevPrice = currentPrice;
		}
	}

	void sellNiceTiming() {	
		
	}

private:
	IStockerDriver* stockDriver;

	const int MAX_BUY_CECHK_COUNT = 24;
	const int MAX_BUY_CLIMB_COUNT = 3;
};
