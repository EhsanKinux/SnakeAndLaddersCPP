#include "Display.h"
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include "Game.h"
#include <vector>

using namespace std;

void Display::Start(Game game)
{
	system("CLS");//clear screen
	cout << "Welcome to the game" << endl << "[Press Enter To Start...]"<<endl;
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
	GetPlayerNumbers();
}

void Display::GetPlayerNumbers()
{
	system("CLS");//clear screen
	int numberOfPlayers;
	
	do {
		cout << "Please enter the number of players (Between 1 to 6): ";
		cin >> numberOfPlayers;
	} while (numberOfPlayers > 6 && numberOfPlayers < 1);
	
	GetPlayerNames(numberOfPlayers);
}

void Display::GetPlayerNames(int numberOfPlayers)
{
	system("CLS");//clear screen

	vector<Player> p;
	string playerName;

	for (int i = 0; i < numberOfPlayers; i++) {
		cout << "Please enter player no. " << i + 1 << " Name: ";
		cin >> playerName;
		Player player;
		player.setName(playerName);
		p.push_back(player);
	}

	cout << endl << "Let's Start the game..." << endl;
	getchar();//wait for user input

	GetSnakes();

}

void Display::GetSnakes()
{

	GetLadders();
}

void Display::GetLadders()
{
}

void Display::PlayerTurn(Player player)
{
}


void Display::showValidationToStart(Player player, Dice dice)
{
	system("CLS");//clear screen
	if (dice.getValue() != 6) {
		cout << "OH NO! you can't start the game right now! Next Player's turn...";
	}
	else {
		cout<<"Wow! You can start the Game Now!"<<endl;
		//set the value of 1 to the players current position
		cout << "Your current Position is :";//player.getCurrentPosition()
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
