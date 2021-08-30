#ifndef APPLE_H
#define APPLE_H
#include <iostream>

using namespace std;

class Apple{
	private:
    int totalAmount;
    int currentAmount;
		pair<int,int> coords;

	public:
    int getTotalAmout();
    int getCurrentAmount();

    void setTotalAmout(int amount);
    void setCurrentAmount(int amount);

    void generateCoords();
    void setCoords(pair<int, int> coord);
};

#endif
