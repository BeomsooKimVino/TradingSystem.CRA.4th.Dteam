#include <iostream>
#include <string>
#include <windows.h>
#include "IStockerDriver.h"

using namespace std;

class AutoTradingSystem {
public:
	void selectStockBrocker(IStockerDriver* driver) {
		stockDriver = driver;
	}

	void login(string ID, string password) {
		stockDriver->Login(ID, password);
	}

	void buy(string stockCode, int price, int amount) {
		stockDriver->Buy(stockCode, price, amount);
	}

	void sell(string stockCode, int price, int amount) {
		stockDriver->Sell(stockCode, price, amount);
	}

	int getPrice(string stockCode) {
		return stockDriver->GetPrice(stockCode);
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

	void sellNiceTiming(string stockCode, int quantity) {
		int prevPrice;
		int currentPrice;

		while (1) {
			prevPrice = stockDriver->GetPrice(stockCode);
			Sleep(1);
			currentPrice = stockDriver->GetPrice(stockCode);
			if (prevPrice > currentPrice) {
				stockDriver->Sell(stockCode, currentPrice, quantity);
				break;
			}
		}
	}

private:
	IStockerDriver* stockDriver;

	const int MAX_BUY_CECHK_COUNT = 24;
	const int MAX_BUY_CLIMB_COUNT = 3;
};
