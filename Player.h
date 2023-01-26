#pragma once
#include <string>

using namespace std;
class Player
{
private:
	string name;
	int currentPos, prevPos, diceVal;
	bool finished , notStarted;
public:
	void setName(string pName);
	string getName();
	/*int getCurrentPos();
	int getPrevPos();
	void setCurrentPos(int pos);
	void setPrevPos(int pos);*/
};

