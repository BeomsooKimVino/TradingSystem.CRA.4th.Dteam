#pragma once
#include "IStockerDriver.h"
#include "KiwerAPI.cpp"
using namespace std;

class KiwerDriver : public IStockerDriver {
public:
	void Login(string ID, string password) override;
	void Buy(string stockCode, int price, int count) override;
	void Sell(string stockCode, int price, int count) override;
	int GetPrice(string stockCode) override;
private:
	KiwerAPI kiwerAPI;
};