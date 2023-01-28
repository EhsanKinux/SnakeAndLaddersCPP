#include "Display.h"
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include "Game.h"
#include <queue>

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
	cout << "Please enter the number of ROWS: ";
	cin >> rows;
	cout << "Please enter the number of COLUMNS: ";
	cin >> cols;
	//Create a board with rows * cols
	game.setCordinates(rows, cols);

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

	//TEST Datas in Queue
	cout << game.getPlayers().front().getName() << endl;
	cout << game.getPlayers().back().getName() << endl;

	cout << endl << "Let's Start the game..." << endl;
	getchar();//wait for user input

	GetSnakes(game);

}

void Display::GetSnakes(Game game)
{
	int numberOfSnakes, snakeTail, snakeHead;
	bool isSnakeExist = false;

	do {

		cout << "Please Enter number of snakes: ";
		cin >> numberOfSnakes;

		if (numberOfSnakes >= game.getCordinates() / 4) //if snakes limit reached
			cout << "TOO MUCH SNAKES!!! Try Again." << endl;

	} while (numberOfSnakes >= game.getCordinates() / 4);//snakes count must be less than (rows*cols) / 4

	for (int i = 0; i < numberOfSnakes; i++) {

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
				cout << "!!! There is already an snake in this postitions !!! Try Again..." << endl;
			}

			if (snakeHead < 2) {
				cout << "!!! There is already an snake in this postitions !!! Try Again..." << endl;
			}

		} while ((snakeHead <= snakeTail) || isSnakeExist || snakeTail < 1 || snakeHead < 2);

		//add snake to the game map
		game.insertSnake(pair<int, int>(snakeTail, snakeHead));
	}

	int i = 1;
	for (auto pair : game.getSnakes()) {
		cout << "snake no. " << " : Tail Position: " << pair.first << " Head Position: " << pair.second<<endl;
		i++;
	}

	GetLadders(game);
}

void Display::GetLadders(Game game)
{
}

void Display::PlayerTurn(Game game)
{

}


void Display::showValidationToStart(Player player, Dice dice)
{
	system("CLS");//clear screen
	if (dice.getValue() != 6) {
		cout << "OH NO! you can't start the game right now! Next Player's turn...";
	}
	else {
		cout << "Wow! You can start the Game Now!" << endl;
		//set player current position to 1
		player.setCurrentPos(1);
		cout << "Your current Position is : " << player.getCurrentPos();
	}
}

void Display::showDiceAndPos(Player player, Dice dice)
{
	system("CLS");//clear screen

	int diceValue = dice.getValue();
	printf("%d\n", diceValue);
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
