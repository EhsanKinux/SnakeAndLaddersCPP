#pragma once
#include <string>

using namespace std;
class Dice
{
private:
	int value;
public:
	void throwDice();
	void showDice(int n);
	int getValue();
	void setValue(int value);
};

