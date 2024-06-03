#include "KiwerAPI.cpp"
#include "KiwerDriver.h"
#include "IStockerDriver.h"

void KiwerDriver::Login(string ID, string password) {
	kiwerAPI.login(ID, password);
}

void KiwerDriver::Buy(string stockCode, int price, int count) {
	kiwerAPI.buy(stockCode, price, count);
}

void KiwerDriver::Sell(string stockCode, int price, int count) {
	kiwerAPI.sell(stockCode, price, count);
}

int KiwerDriver::GetPrice(string stockCode) {
	return kiwerAPI.currentPrice(stockCode);
}