#include "Dice.h"
#include <time.h>
#include <iostream>

using namespace std;

void Dice::throwDice()
{
	/*The Time function is called because the value of seed changes with time
	 So every time we run the program, a new set of random numbers is generated.*/
	srand(time(0));
	int diceNumber = (rand()%6) + 1;//generate random dice number

	showDice(diceNumber);
}

// Generate dice image in console 
void Dice::showDice(int n)
{	
	string dice;
	switch (n)
	{
	case 1:
		dice = "*---------*\n"
			   "|         |\n"
			   "|    O    |\n"
		       "|         |\n"
			   "*---------*\n";
		break;
	case 2:
		dice = "*---------*\n"
			   "|  O      |\n"
			   "|         |\n"
	           "|      O  |\n"
			   "*---------*\n";
		break;
	case 3:
		dice = "*---------*\n"
			   "|  O      |\n"
			   "|    O    |\n"
			   "|      O  |\n"
			   "*---------*\n";
		break;
	case 4:
		dice = "*---------*\n"
			   "| O     O |\n"
			   "|         |\n"
			   "| O     O |\n"
			   "*---------*\n";
		break;
	case 5:
		dice = "*---------*\n"
			   "| O     O |\n"
			   "|    O    |\n"
			   "| O     O |\n"
			   "*---------*\n";
		break;
	case 6:
		dice = "*---------*\n"
			   "| O     O |\n"
			   "| O     O |\n"
			   "| O     O |\n"
			   "*---------*\n";
	}
	cout << dice;
}
