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
	cout << "\n\t\t\t[Snakes Positions: {";
	for (auto pair : Snakes) {
		cout << "(" << pair.second << "," << pair.first << ")";
	}
	cout << "}]" << endl;
}

void Game::showLaddersPos(map<int, int> Ladders)
{
	cout << "\n\t\t\t[Ladders Positions: {";
	for (auto pair : Ladders) {
		cout << "(" << pair.first << "," << pair.second << ")";
	}
	cout << "}]" << endl;
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

void Game::setPlayers(queue<Player>& players)
{
	Players = players;
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

/*check for snakes& ladders in the cells*/
bool Game::checkForSnakes(Game game, int currentPos, Player& player)
{
	bool snakeEncounter = false;

	for (auto pair : game.getSnakes()) {
		if (currentPos == pair.second) {//if current pos is at the same position as the snake's head
			currentPos = pair.first;//send player to the tail of the snake
			player.setCurrentPos(currentPos);
			Display::showSnakeEncounter(pair.second, pair.first);
			snakeEncounter = true;
		}
	}

	return snakeEncounter;
}

bool Game::checkForLadders(Game game, int currentPos, Player& player)
{
	bool ladderEncounter = false;

	for (auto pair : game.getLadders()) {
		if (currentPos == pair.first) {//if current pos is at the same position as the bottom of the ladder
			currentPos = pair.second;//send player to top of the ladder
			player.setCurrentPos(currentPos);
			Display::showLadderEncounter(pair.first, pair.second);
			ladderEncounter = true;
		}
	}

	return ladderEncounter;
}

Player Game::playerTurn(queue<Player>& players)
{
	return players.front(); //front player in the queue
}

void Game::setNextPlayer(queue<Player>& players, Player& player)
{
	players = getPlayers();

	players.pop();
	players.push(player);

	setPlayers(players);
}

void Game::startTheGame(Game game)
{
	system("CLS");//clear screen

	Player player;
	queue<Player> players = game.getPlayers();
	queue<Player> winners;

	//continue the game until last player reach the last cell
	while (!players.empty()) {

		system("CLS");//clear screen

		if (players.size() < 2) {//only 1 player left
			player = playerTurn(players);
			winners.push(player);
			players.pop();
			game.setPlayers(players);
			break;
		}

		cout << "\n\t\t\tCOUNT OF PLAYERS IN GAME : " << players.size() << endl;

		players = game.getPlayers();//get all players
		player = playerTurn(players);//get first player in the players queue

		if (player.getValidation()) {

			if (!player.checkFinished()) {
				cout << "\n\t\t\t" << player.getName() << "'s TURN: " << endl;

				Dice dice;
				dice.throwDice();
				if (dice.getValue() != 6) {
					Display::showDiceAndPos(game, player, dice);
				}
				else {//if dice value is 6 => roll prize dice 
					Display::showDicePrize(game, player, dice);
					players.front().setCurrentPos(player.getCurrentPos());
					game.setPlayers(players);

					//player has reached the last cell (finished)
					if (player.getCurrentPos() >= game.getDimension()) {
						player.setFinished(true);
						winners.push(player);
						players.pop();
						game.setPlayers(players);

						cout << endl << endl;
						cout << "\n\t\t\t*-----------------------------------------------------------------------*" << endl;
						cout << "\t\t\t|--    Congratulations! You have successfully finished the game	      --|" << endl;
						cout << "\t\t\t*-----------------------------------------------------------------------*";

						getchar();
					}

					continue;//skip setNextPlayer
				}

				//if player has reached the end cell
				if (player.getCurrentPos() >= game.getDimension()) {
					player.setFinished(true);
					winners.push(player);
					players.pop();
					game.setPlayers(players);

					cout << endl << endl;
					cout << "\n\t\t\t*-----------------------------------------------------------------------*" << endl;
					cout << "\t\t\t|--    Congratulations! You have successfully finished the game	      --|" << endl;
					cout << "\t\t\t*-----------------------------------------------------------------------*";

					getchar();

					continue;//prevent from setNextPlayer
				}

			}

		}

		else {//check if the player can enter the game
			Display::showValidationToStart(game, players, player);
		}

		game.setNextPlayer(players, player);

	}//end of while(!player.empty())


	Display::showWinner(winners);


}
