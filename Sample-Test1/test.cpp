#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../20240603_TradingSystem/IStockerDriver.h"
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
//	TradingSystem ats{ &mock };
};

TEST_F(TradingSystemFixture, TestLogin1) {
	EXPECT_CALL(mock, Login).Times(1);
	mock.Login("ID", "PASSWORD");
}

TEST_F(TradingSystemFixture, TestBuy1) {
	int price = 10000;
	int amount = 100;
	EXPECT_CALL(mock, Buy).Times(1);
	mock.Buy("STOCKCODE", price, amount);
}

TEST_F(TradingSystemFixture, TestSell1) {
	int price = 10000;
	int amount = 100;
	EXPECT_CALL(mock, Sell).Times(1);
	mock.Sell("STOCKCODE", price, amount);
}

TEST_F(TradingSystemFixture, TestGetPrice10000) {
	int price = 10000;
	EXPECT_CALL(mock, GetPrice).Times(1).WillRepeatedly(Return(price));
	int result = mock.GetPrice("STOCKCODE");

	EXPECT_THAT(result, testing::Eq(price));
}



