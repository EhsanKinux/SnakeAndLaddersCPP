#include "Display.h"
#include <stdlib.h>
#include <cstdio>
#include <iostream>

using namespace std;
void Display::Start()
{
	system("CLS");//clear screen
	cout << "Welcome to the game" << endl << "[Press Enter To Start...]"<<endl;
	getchar();
	Display::GetBoard();

}

void Display::GetBoard()
{
	system("CLS");//clear screen
	int rows, cols;
	cout << "Please enter the number of ROWS: ";
	cin >> rows;
	cout << "Please enter the number of COLUMNS: ";
	cin >> cols;
	//Create a board with 1 -- rows* cols
}

void Display::GetPlayerNumber()
{
	system("CLS");//clear screen
	int numberOfPlayers;
	
	do {
		cout << "Please enter the number of players (Between 1 to 6): ";
		cin >> numberOfPlayers;
	} while (numberOfPlayers > 6 && numberOfPlayers < 1);
	
	Display::GetPlayerNames(numberOfPlayers);
}

void Display::GetPlayerNames(int numberOfPlayers)
{
	system("CLS");//clear screen
	for (int i = 0; i < numberOfPlayers; i++) {
		//create players object...
	}

	cout << endl << "Let's Start the game..." << endl;

}

void Display::showDiceAndPos(Player player, Dice dice)
{
	int diceValue = dice.getValue();
	system("CLS");//clear screen
	printf("%d\n", diceValue);
	dice.showDice(diceValue);
	int prevPos = player.getCurrentPos();
	int currentPos = prevPos + diceValue;
	//check for ladders and snakes
	//if(finished player) ... show finished players

}

void Display::showValidationToStart(Player player, Dice dice)
{
	system("CLS");//clear screen
	if (dice.getValue() != 6) {
		cout << "OH NO! you can't start the game right now! Next Player...";
	}
	else {
		cout<<"Wow! You can start the Game Now!"<<endl;
		//set the value of 1 to the players current position
		cout << "Your current Position is :";//player.getCurrentPosition()
	}
}

void Display::showDicePrize(Player player, Dice dice)
{
	system("CLS");//clear screen
	cout << "WOW!!! You got a prize! so your turn again :)";
	
}
