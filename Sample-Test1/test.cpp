#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../20240603_TradingSystem/IStockerDriver.h"
#include "../20240603_TradingSystem/KiwerAPI.cpp"
#include "../20240603_TradingSystem/NemoAPI.cpp"
#include "../20240603_TradingSystem/AutoTradingSystem.cpp"

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
	MockDriver mockdriver;
	AutoTradingSystem ats;
};

TEST_F(TradingSystemFixture, TestLogin1) {
	EXPECT_CALL(mockdriver, Login).Times(1);
	mockdriver.Login("ID", "PASSWORD");
}

TEST_F(TradingSystemFixture, TestBuy1) {
	int price = 10000;
	int amount = 100;
	EXPECT_CALL(mockdriver, Buy).Times(1);
	mockdriver.Buy("STOCKCODE", price, amount);
}

TEST_F(TradingSystemFixture, TestSell1) {
	int price = 10000;
	int amount = 100;
	EXPECT_CALL(mockdriver, Sell).Times(1);
	mockdriver.Sell("STOCKCODE", price, amount);
}

TEST_F(TradingSystemFixture, TestGetPrice10000) {
	int price = 10000;
	EXPECT_CALL(mockdriver, GetPrice).Times(1).WillRepeatedly(Return(price));
	int result = mockdriver.GetPrice("STOCKCODE");

		EXPECT_THAT(result, testing::Eq(price));
}

TEST_F(TradingSystemFixture, TestAtsLogin) {
	EXPECT_CALL(mockdriver, Login).Times(1);	

	ats.selectStockBrocker(&mockdriver);
	ats.login("ID", "PASSWORD");
}

TEST_F(TradingSystemFixture, TestAtsBuy) {
	int price = 10000;
	int amount = 100;

	EXPECT_CALL(mockdriver, Buy).Times(1);

	ats.selectStockBrocker(&mockdriver);
	ats.buy("STOCKCODE", price, amount);
}

TEST_F(TradingSystemFixture, TestAtsSell) {
	int price = 10000;
	int amount = 100;

	EXPECT_CALL(mockdriver, Sell).Times(1);

	ats.selectStockBrocker(&mockdriver);
	ats.sell("STOCKCODE", price, amount);
}

TEST_F(TradingSystemFixture, TestAtsGetPrice10000) {
	int price = 10000;
	int amount = 100;

	EXPECT_CALL(mockdriver, GetPrice).Times(1).WillRepeatedly(Return(price));;

	ats.selectStockBrocker(&mockdriver);
	int result = ats.getPrice("STOCKCODE");

	EXPECT_THAT(result, testing::Eq(price));
}

TEST_F(TradingSystemFixture, TestAtsbuyNiceTiming) {
	int price = 10000;
	int goalPrice = 10300;

	EXPECT_CALL(mockdriver, GetPrice).Times(3).WillOnce(Return(price + 100)).WillOnce(Return(price + 200)).WillOnce(Return(goalPrice));

	ats.selectStockBrocker(&mockdriver);
	ats.buyNiceTiming("STOCKCODE", goalPrice);
}

TEST_F(TradingSystemFixture, TestAtsSellNiceTiming) {
	int price = 10300;
	int amount = 100;

	EXPECT_CALL(mockdriver, GetPrice).Times(3).WillOnce(Return(price - 100)).WillOnce(Return(price - 200)).WillOnce(Return(price - 300));

	ats.selectStockBrocker(&mockdriver);
	ats.sellNiceTiming("STOCKCODE", amount);
}
