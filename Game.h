#pragma once
#include "Player.h"
#include <queue>
#include <map>
#include "Dice.h"

class Game
{
private:
	int boardLength;
	queue<Player> Players;
	map<int, int> Snakes, Ladders;
public:
	Game();//default constructor
	int getCordinates();
	queue<Player> getPlayers();
	map<int, int> getSnakes();
	map<int, int> getLadders();
	void setCordinates(int rows, int columns);
	void insertPlayer(Player player);
	void insertSnake(pair<int, int> snakeTailHead);
	bool isSnakeExist(int tail, int head);

		//void startTheGame(vector<Player> players, int boardDimension, Dice dice, );
};

