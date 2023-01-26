#pragma once
#include "Player.h"
#include <vector>
#include "Dice.h"

class Game
{
private:
	int boardLength;
public:
	Game();
	int getCordinates();
	void setCordinates(int rows, int columns);
	void startTheGame(vector<Player> players, int boardDimension, Dice dice);
};

