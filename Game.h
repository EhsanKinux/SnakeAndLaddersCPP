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
	void insertLadder(pair<int, int> ladderDownUp);
	void showSnakesPos(map<int, int> Snakes);
	void showLadderPos(map<int, int> Ladders);
	bool isSnakeExist(int tail, int head);
	bool isLadderExist(int down, int up);

		//void startTheGame(vector<Player> players, int boardDimension, Dice dice, );
};

