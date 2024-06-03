#include <string>
#include "IStockerDriver.h"
#include "NemoAPI.cpp"
using namespace std;

class NemoStockerDriver : public IStockerDriver {
public:
	// IStockerDriver을(를) 통해 상속됨
	void Login(string ID, string password) override
	{
		nemoAPI.certification(ID, password);
	}
	void Buy(string stockCode, int price, int amount) override
	{
		nemoAPI.purchasingStock(stockCode, price, amount);
	}
	void Sell(string stockCode, int price, int amount) override
	{
		nemoAPI.sellingStock(stockCode, price, amount);
	}
	int GetPrice(string stockCode) override
	{
		return nemoAPI.getMarketPrice(stockCode, 0);
	}

private:
	NemoAPI nemoAPI;
};