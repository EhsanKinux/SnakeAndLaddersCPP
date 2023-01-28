#include <iostream>
#include "Game.h"
#include "Display.h"

using namespace std;
Game::Game()
{
}

int Game::getDimension()
{
	return boardLength;
}

void Game::setDimension(int rows, int columns)
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

void Game::insertLadder(pair<int, int> ladderDownUp)
{
	Ladders.insert(ladderDownUp);
}

void Game::showSnakesPos(map<int, int> Snakes)
{
	cout << "[Snakes Positions: {";
	for (auto pair : Snakes) {
		 cout<< "(" << pair.first << "," << pair.second << ")";
	}
	cout << "}]"<<endl<<endl;
}

void Game::showLadderPos(map<int, int> Ladders)
{
	cout << "[Ladders Positions: {";
	for (auto pair : Ladders) {
		cout << "(" << pair.first << "," << pair.second << ")";
	}
	cout << "}]" << endl << endl;
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
	//check if head or tail of the snakes is exist in the key , value pair of the map
	for (auto pair : Snakes) {
		if (pair.first == tail || pair.second == head || pair.first == head || pair.second == tail)
			return true;
		else
			continue;
	}

	return false;

}

bool Game::isLadderExist(int down, int up)
{

	//check if up or down of the snakes is exist in the key , value pair of the map
	for (auto pair : Ladders) {
		if (pair.first == down || pair.second == up || pair.first == up || pair.second == down)
			return true;
		else
			continue;
	}

	return false;

}

Player Game::playerTurn(queue<Player> players , Player player)
{
	player = players.front();
	
	//send the player to the back of the queue
	players.pop();
	players.push(player);

	return player;
}

void Game::startTheGame(Game game ,int boardDimension, queue<Player> players, map<int, int> snakes, map<int, int> ladders)
{
	system("CLS");//clear screen

	Display dis;
	Player player;
	//continue the game until last player reach the last cell
		player = game.playerTurn(players, player);
		while (!players.empty()) {
			if (player.getValidation()) {

			}
			else {
				dis.showValidationToStart(player);
			}
		}
}
