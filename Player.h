#pragma once
class Player
{
private:
	int currentPos, prevPos, diceVal;
	bool finished , notStarted;
public:
	int getCurrentPos();
	int getPrevPos();
	void setCurrentPos(int pos);
	void setPrevPos(int pos);
};

