#include "Display.h"
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include "Game.h"
#include <queue>
#include "Dice.h"

using namespace std;

void Display::Start(Game game)
{
	system("CLS");//clear screen
	cout << "Welcome to the game" << endl << "[Press Enter To Start...]" << endl;
	getchar();//wait for user input

	//go to next page ->
	GetBoard(game);

}

void Display::GetBoard(Game game)
{
	system("CLS");//clear screen
	int rows, cols;

	do {
		cout << "Please enter the number of ROWS: ";
		cin >> rows;
		cout << "Please enter the number of COLUMNS: ";
		cin >> cols;

		if (rows < 1) {
			cout << "Rows of the board can't be zero or negative!!!" << endl;
		}

		if (cols < 2) {
			cout << "The board must contain at least 2 columns!!!" << endl;
		}
	} while (rows < 1 || cols < 2);

	//Create a board with rows * cols
	game.setDimension(rows, cols);

	//Go to next page ->
	GetPlayerNumbers(game);
}

void Display::GetPlayerNumbers(Game game)
{
	system("CLS");//clear screen
	int numberOfPlayers;

	do {
		cout << "Please enter the number of players (Between 1 to 6): ";
		cin >> numberOfPlayers;
	} while (numberOfPlayers > 6 && numberOfPlayers < 1);

	GetPlayerNames(game, numberOfPlayers);
}

void Display::GetPlayerNames(Game game, int numberOfPlayers)
{
	system("CLS");//clear screen

	string playerName;

	for (int i = 0; i < numberOfPlayers; i++) {
		cout << "Please enter player no. " << i + 1 << " Name: ";
		cin >> playerName;
		Player player;
		player.setName(playerName);
		game.insertPlayer(player);
	}
	getchar();//wait for user input

	GetSnakes(game);

}

void Display::GetSnakes(Game game)
{
	system("CLS");//clear screen

	int numberOfSnakes, snakeTail, snakeHead;
	bool isSnakeExist = false;

	do {

		cout << "Please Enter number of snakes: ";
		cin >> numberOfSnakes;

		if (numberOfSnakes >= game.getDimension() / 4) //if snakes limit reached
			cout << "TOO MUCH SNAKES!!! Try Again." << endl;

		if (numberOfSnakes < 1) {
			cout << ":) Where Are the snakes?! Please enter at least 1 snakes to the game!" << endl;
		}

	} while ((numberOfSnakes >= game.getDimension() / 4) || numberOfSnakes < 1);//snakes count must be less than (rows*cols) / 4

	for (int i = 1; i <= numberOfSnakes; i++) {

		do {
			cout << "Please Enter the tail of the snake no. " << i << " : ";
			cin >> snakeTail;

			cout << "Please Enter the Head of the snake no. " << i << " : ";
			cin >> snakeHead;

			isSnakeExist = game.isSnakeExist(snakeTail, snakeHead);//check for snake extistence

			if (snakeHead <= snakeTail) {
				cout << "!!! Head of the snake can't be in a lower position than it's tail !!! Try Again... " << endl;
			}

			if (isSnakeExist) {
				cout << "!!! There is already an snake in this postitions !!! Try Again... " << endl;
			}

			if (snakeTail < 1) {
				cout << "!!! Snake tail can't be outside of the game board !!! Try Again..." << endl;
			}

			if (snakeHead < 2) {
				cout << "!!! Snake head position can't be less than 2 !!! Try Again..." << endl;
			}

			if (snakeTail > game.getDimension()) {
				cout << "!!! Snake tail position can't be bigger than game board !!! Try Again..." << endl;
			}

			if (snakeHead > game.getDimension()) {
				cout << "!!! Snake head position can't be bigger than game board !!! Try Again..." << endl;
			}

		} while ((snakeHead <= snakeTail) || isSnakeExist || snakeTail < 1 || snakeHead < 2 || (snakeTail > game.getDimension() || snakeHead > game.getDimension()));

		//add snake to the game map
		game.insertSnake(pair<int, int>(snakeTail, snakeHead));
	}

	GetLadders(game);
}

void Display::GetLadders(Game game)
{
	system("CLS");//clear screen

	int numberOfLadders, ladderDown, ladderUp;
	bool isLadderExist = false, isSnakeExist = false;

	game.showSnakesPos(game.getSnakes());

	do {

		cout << "Please Enter number of Ladders: ";
		cin >> numberOfLadders;

		if (numberOfLadders >= game.getDimension() / 4) //if snakes limit reached
			cout << "TOO MUCH Ladders!!! Try Again." << endl;

		if (numberOfLadders < 1) {
			cout << ":) Where Are the ladders?! Please enter at least 1 ladders to the game!" << endl;
		}

	} while ((numberOfLadders >= game.getDimension() / 4) || numberOfLadders < 1);//Ladder count must be less than (rows*cols) / 4

	for (int i = 1; i <= numberOfLadders; i++) {

		do {
			cout << "Please Enter the tail of the ladder no. " << i << " : ";
			cin >> ladderDown;

			cout << "Please Enter the Head of the ladder no. " << i << " : ";
			cin >> ladderUp;

			isSnakeExist = game.isSnakeExist(ladderDown, ladderUp);//check for snake extistence
			isLadderExist = game.isLadderExist(ladderDown, ladderUp);//check for ladder extistence

			if (ladderUp <= ladderDown) {
				cout << "!!! Head of the ladder can't be in a lower position than it's tail !!! Try Again... " << endl;
			}

			if (isSnakeExist) {
				cout << "!!! There is already an Snake in this postitions !!! Try Again... " << endl;
			}

			if (isLadderExist) {
				cout << "!!! There is already a ladder in this postitions !!! Try Again... " << endl;
			}

			if (ladderDown < 1) {
				cout << "!!! ladder tail can't be outside of the game board !!! Try Again..." << endl;
			}

			if (ladderUp < 2) {
				cout << "!!! ladder head position can't be less than 2 !!! Try Again..." << endl;
			}

			if (ladderDown > game.getDimension()) {
				cout << "!!! ladder down position can't be bigger than game board !!! Try Again..." << endl;
			}

			if (ladderUp > game.getDimension()) {
				cout << "!!! ladder Up position can't be bigger than game board !!! Try Again..." << endl;
			}

		} while ((ladderUp <= ladderDown) || isSnakeExist || isLadderExist || ladderDown < 1 || ladderUp < 2 || (ladderDown > game.getDimension() || ladderUp > game.getDimension()));

		//add ladder to the game map
		game.insertLadder(pair<int, int>(ladderDown, ladderUp));
	}

	int i = 1;
	for (auto pair : game.getLadders()) {
		cout << "Ladder no. " << i << " => Tail Position: " << pair.first << " | Head Position: " << pair.second << endl;
		i++;
	}

	cout << "Everything's set... Let's start the game!" << endl;
	getchar();

	game.startTheGame(game);

}

void Display::PlayerTurn(Game game)
{
}


void Display::showValidationToStart(Game game,queue<Player> &players, Player &player)
{
	Dice dice;
	system("CLS");//clear screen

	cout << "It's " << player.getName() << "'s turn :)"<<endl;

	dice.throwDice();

	//Player nextPlayer = game.playerTurn(game.getPlayers(), player);

	if (dice.getValue() != 6) {
		cout << "OH NO! you can't start the game right now!"; // " << nextPlayer.getName() << "'s turn...";
		getchar();
	}
	else {
		cout << "Wow! You have permission to start the Game! But after others turn..."; // << nextPlayer.getName() << "'s turn..." <<endl;
		
		//set player isValid to true
		player.setValidation(true);
		
		getchar();
	}
}

void Display::showDiceAndPos(Player player, Dice dice)
{
	system("CLS");//clear screen

	int diceValue = dice.getValue();
	printf("Dice Number = %d\n", diceValue);
	dice.showDice(diceValue);
	//int prevPos = player.getCurrentPos();
	//int currentPos = prevPos + diceValue;
	//check for ladders and snakes
	//if(finished player) ... show finished players

}


void Display::showDicePrize(Player player, Dice dice)
{
	system("CLS");//clear screen
	cout << "WOW!!! You got a prize! so your turn again :)";

}


void Display::showWinner()
{
}
