#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../20240603_TradingSystem/KiwerAPI.cpp"
#include "../20240603_TradingSystem/NemoAPI.cpp"

using namespace testing;
using namespace std;

/*
* Kiwer APIs
 	void login(string ID, string password)
	void buy(string stockCode, int count, int price)
	void sell(string stockCode, int count, int price)
	int currentPrice(string stockCode)
* Nemo APIs
	void certification(string ID, string pass)
	void purchasingStock(string stockCode, int price, int count)
	void sellingStock(string stockCode, int price, int count)
	int getMarketPrice(string stockCode, int minute)
*/

class MockDriver : public IStockerDriver {
public:
	MOCK_METHOD(void, Login, (string ID, string password), (override));
	MOCK_METHOD(void, Buy, (string stockCode, int price, int amount), (override));
	MOCK_METHOD(void, Sell, (string stockCode, int price, int amount), (override));
	MOCK_METHOD(int, GetPrice, (string stockCode), (override));
};

class TradingSystemFixture : public testing::Test {
public:
    MockDriver mock;
	TradingSystemFixture ats{ &mock };
    
};
