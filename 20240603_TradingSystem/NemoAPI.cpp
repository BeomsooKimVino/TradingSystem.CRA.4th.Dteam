#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>

using namespace std;
class NemoAPI {
public:
	void certification(string ID, string pass) {
		cout << "[NEMO]" << ID << " login GOOD\n";
	}

	void purchasingStock(string stockCode, int price, int count) {
		cout << "[NEMO]" << stockCode << " buy stock ( price : " << price << " ) * ( count : " << count << ")\n";
	}

	void sellingStock(string stockCode, int price, int count) {
		cout << "[NEMO]" << stockCode << " sell stock ( price : " << price << " ) * ( count : " << count << ")\n";
	}

	int getMarketPrice(string stockCode, int minute) {
		if (minute <= 0) minute = 1;
		Sleep(minute);
		srand(static_cast<int>(time(NULL)));
		int ret = rand() % 10 * 100 + 5000;
		return ret;
	}
};
