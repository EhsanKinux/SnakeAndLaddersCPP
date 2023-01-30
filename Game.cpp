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
		cout << "(" << pair.first << "," << pair.second << ")";
	}
	cout << "}]" << endl << endl;
}

void Game::showLaddersPos(map<int, int> Ladders)
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
			///dis.showSnakeEncounter()
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
			///dis.showLadderEncounter()
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

	Display dis;
	Player player;
	queue<Player> players = game.getPlayers();
	queue<Player> winners;



	//continue the game until last player reach the last cell


	while (!players.empty()) {

		system("CLS");//clear screen

		players = game.getPlayers();//get all players
		player = playerTurn(players);//get first player in the players queue

		if (player.getValidation()) {

			if (!player.checkFinished()) {


				cout << player.getName() << "'s TURN: " << endl;

				Dice dice;
				dice.throwDice();
				if (dice.getValue() != 6) {
					dis.showDiceAndPos(game, player, dice);
				}
				else {//if dice value is 6 => roll prize dice 
					dis.showDicePrize(game, player, dice);///TODO_NOT FINISHED CODING...
					continue;//don't change player's turn
				}

				//if player reaches the end cell
				if (player.getCurrentPos() >= game.getDimension()) {
					player.setFinished(true);
					winners.push(player);
					players.pop();
					game.setPlayers(players);
					
					cout << endl << endl;
					cout << "*-----------------------------------------------------------------------*"<<endl;
					cout << "|--   	 Congratulations! You have successfully finished the game	   --|"<<endl;
					cout << "*-----------------------------------------------------------------------*";

					getchar();

					continue;//prevent from setNextPlayer
				}

			}
			else {//if player has already finished the game
				continue;
			}



			///1_if isFinished -> continue
			///2_else -> dice throw 
			///2.1_show previous position (current pos)
			///2.2_change currentPosition to curr + diceVal
			///2.3_check for ladders and snakes with first pair 
			///    and change the value of current position to the second pair in the snakes and ladders map.
			///2.4_if(dice.val() == 6) => don't go to next player
			///2.5_if(currentPosition > boardlentgh) => player.setIsFinished(true)
			///2.6_push player to the winners queue
			///*2.7_always show players count
			///2.8_show snakes & ladders position
			///2.9_DICE PRIZE


		}
		else {//check if the player can enter the game
			dis.showValidationToStart(game, players, player);
		}
		game.setNextPlayer(players, player);

	}
}
