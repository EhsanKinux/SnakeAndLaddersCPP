#pragma once
#include <string>

using namespace std;
class Player
{
private:
	string name;
	int currentPos = 0, prevPos = 0, diceVal = 0;
	bool isFinished = false , isValid = false;
public:
	void setName(string pName);
	string getName();
	int getCurrentPos();
	int getPrevPos();
	bool getValidation();
	void setValidation(bool validate);
	bool checkFinished();
	void setFinished(bool finished);
	void setCurrentPos(int pos);
	void setPrevPos(int pos);
};

