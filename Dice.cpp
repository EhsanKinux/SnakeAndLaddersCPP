#include "Dice.h"
#include <time.h>
#include <iostream>

using namespace std;

void Dice::throwDice()
{

	cout << "\n\t\t\tPress Enter to roll the dice...";
	getchar();

	srand(time(0));
	int diceNumber = (rand() % 6) + 1;//generate random dice number

	setValue(diceNumber);

	showDice(diceNumber);
}

// Generate dice image in console 
void Dice::showDice(int n)
{
	string dice;
	switch (n)
	{
	case 1:
		dice = "\n\t\t\t*---------*\n"
			"\t\t\t|         |\n"
			"\t\t\t|    O    |\n"
			"\t\t\t|         |\n"
			"\t\t\t*---------*\n";
		break;
	case 2:
		dice = "\n\t\t\t*---------*\n"
			"\t\t\t|  O      |\n"
			"\t\t\t|         |\n"
			"\t\t\t|      O  |\n"
			"\t\t\t*---------*\n";
		break;
	case 3:
		dice = "\n\t\t\t*---------*\n"
			"\t\t\t|  O      |\n"
			"\t\t\t|    O    |\n"
			"\t\t\t|      O  |\n"
			"\t\t\t*---------*\n";
		break;
	case 4:
		dice = "\n\t\t\t*---------*\n"
			"\t\t\t| O     O |\n"
			"\t\t\t|         |\n"
			"\t\t\t| O     O |\n"
			"\t\t\t*---------*\n";
		break;
	case 5:
		dice = "\n\t\t\t*---------*\n"
			"\t\t\t| O     O |\n"
			"\t\t\t|    O    |\n"
			"\t\t\t| O     O |\n"
			"\t\t\t*---------*\n";
		break;
	case 6:
		dice = "\n\t\t\t*---------*\n"
			"\t\t\t| O     O |\n"
			"\t\t\t| O     O |\n"
			"\t\t\t| O     O |\n"
			"\t\t\t*---------*\n";
	}
	cout << dice;
}

//get dice value
int Dice::getValue()
{
	return value;
}

//set dice value
void Dice::setValue(int value)
{
	this->value = value;
}
