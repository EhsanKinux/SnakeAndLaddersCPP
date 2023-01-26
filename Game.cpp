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
