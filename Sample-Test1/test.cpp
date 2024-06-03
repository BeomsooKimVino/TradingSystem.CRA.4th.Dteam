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

TEST_F(TradingSystemFixture, TestLogin1) {
	EXPECT_CALL(ats, Login).Times(1);
	ats.login("ID", "PASSWORD");
}

TEST_F(TradingSystemFixture, TestBuy1) {
	int price = 10000;
	int amount = 100;
	EXPECT_CALL(ats, Buy).Times(1);
	ats.Buy("STOCKCODE", price, amount);
}

TEST_F(TradingSystemFixture, TestSell1) {
	int price = 10000;
	int amount = 100;
	EXPECT_CALL(ats, Sell).Times(1);
	ats.Sell("STOCKCODE", price, amount);
}

TEST_F(TradingSystemFixture, TestGetPrice10000) {
	int price = 10000;
	EXPECT_CALL(ats, GetPrice).Times(1).WillRepeatedly(Return(price));
	int result = ats.GetPrice("STOCKCODE");

	EXPECT_THAT(result, testing::Eq(price));
}



