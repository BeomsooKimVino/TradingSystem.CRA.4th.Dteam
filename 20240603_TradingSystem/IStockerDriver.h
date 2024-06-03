#pragma once

using namespace std;

class IStockerDriver {
public:
	virtual void Login(string ID, string password) = 0;
	virtual void Buy(string stockCode, int price, int amount) = 0;
	virtual void Sell(string stockCode, int price, int amount) = 0;
	virtual int GetPrice(string stockCode) = 0;
};
