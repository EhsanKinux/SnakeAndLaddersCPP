#include "Game.h"

Game::Game()
{
}

int Game::getCordinates()
{
	return boardLength;
}

void Game::setCordinates(int rows, int columns)
{
	boardLength = rows * columns;
}

void Game::insertPlayer(Player player)
{
	Players.push(player);
}

void Game::insertSnake(pair<int, int> snakeTailHead)
{
	Snakes.insert(snakeTailHead);
}

queue<Player> Game::getPlayers()
{
	return Players;
}

map<int, int> Game::getSnakes()
{
	return Snakes;
}

map<int, int> Game::getLadders()
{
	return Ladders;
}

bool Game::isSnakeExist(int tail, int head)
{

	bool isSExist = false;

	//check if head or tail of the snakes is exist in the key , value pair of the map
	for (auto pair : Snakes) {
		if ((pair.first == tail || pair.second == head) || (pair.first == head || pair.second == tail))
			isSExist = true;
		else
			isSExist = false;
	}

	return isSExist;
}
