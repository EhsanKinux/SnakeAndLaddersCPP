#include "Display.h"
#include <iostream>
#include "Game.h"
#include <queue>
#include "Dice.h"
#include <string>

using namespace std;

void Display::Start(Game game)
{
	system("CLS");//clear screen
	cout << endl << endl;
	cout << "\t\t\t\t\t\t\t%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%" << endl;
	cout << "\t\t\t\t\t\t\t%%                                               %%" << endl;
	cout << "\t\t\t\t\t\t\t%%            Snakes And Ladders Game            %%" << endl;
	cout << "\t\t\t\t\t\t\t%%                                               %%" << endl;
	cout << "\t\t\t\t\t\t\t%%                    Welcome!                   %%" << endl;
	cout << "\t\t\t\t\t\t\t%%                                               %%" << endl;
	cout << "\t\t\t\t\t\t\t%%                                               %%" << endl;
	cout << "\t\t\t\t\t\t\t%%                 #------------#                %%" << endl;
	cout << "\t\t\t\t\t\t\t%%                 |  SinaC0de  |                %%" << endl;
	cout << "\t\t\t\t\t\t\t%%     Created By: |     &      |                %%" << endl;
	cout << "\t\t\t\t\t\t\t%%                 | EhsanKinux |                %%" << endl;
	cout << "\t\t\t\t\t\t\t%%                 #------------#                %%" << endl;
	cout << "\t\t\t\t\t\t\t%%                                               %%" << endl;
	cout << "\t\t\t\t\t\t\t%%                                               %%" << endl;
	cout << "\t\t\t\t\t\t\t%%            [Press Enter To Start...]          %%" << endl;
	cout << "\t\t\t\t\t\t\t%%                                               %%" << endl;
	cout << "\t\t\t\t\t\t\t%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%" << endl << endl;
	getchar();//wait for user input
	
	//go to next page ->
	GetBoard(game);
}

void Display::GetBoard(Game game)
{
	system("CLS");//clear screen
	int rows, cols;

	do {
		cout << "\n\n\n\t\t\t*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
		cout <<       "\t\t\t|                                                           |" << endl;
		cout <<       "\t\t\t|            Please enter the number of ROWS                |" << endl;
		cout <<       "\t\t\t|                     !(Minimum : 3)!                       |" << endl;
		cout <<       "\t\t\t|                                                           |" << endl;
		cout <<       "\t\t\t*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		cout << "\n\n\t\t\t===> : ";
		cin >> rows;
		cout << "\n\n\n\t\t\t*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		cout <<       "\t\t\t|                                                           |" << endl;
		cout <<       "\t\t\t|            Please enter the number of COLUMNS             |" << endl;
		cout <<       "\t\t\t|                     !(Minimum : 3)!                       |" << endl;
		cout <<       "\t\t\t|                                                           |" << endl;
		cout <<       "\t\t\t*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		cout << "\n\n\t\t\t===> : ";
		cin >> cols;

		if (rows < 3) {
			cout << "\n\n\n\n\n\n\n\t\t\t\t\t!====================================================!" << endl;
			cout <<               "\t\t\t\t\t{                                                    }" << endl;
			cout <<               "\t\t\t\t\t{                                                    }" << endl;
			cout <<               "\t\t\t\t\t{     The board must contain at least 3 Rows!!!      }" << endl;
			cout <<               "\t\t\t\t\t{                                                    }" << endl;
			cout <<               "\t\t\t\t\t{                                                    }" << endl;
			cout <<               "\t\t\t\t\t!====================================================!" << endl;
		}

		if (cols < 3) {
			cout << "\n\n\n\n\n\n\n\t\t\t\t\t!====================================================!" << endl;
			cout <<               "\t\t\t\t\t{                                                    }" << endl;
			cout <<               "\t\t\t\t\t{                                                    }" << endl;
			cout <<               "\t\t\t\t\t{     The board must contain at least 3 Rows!!!      }" << endl;
			cout <<               "\t\t\t\t\t{                                                    }" << endl;
			cout <<               "\t\t\t\t\t{                                                    }" << endl;
			cout <<               "\t\t\t\t\t!====================================================!" << endl;
		}
	} while (rows < 3 || cols < 3); // at least 3 * 3

	//Create a board with rows * cols
	game.setDimension(rows, cols);

	//Go to next page ->
	GetPlayerNumbers(game);
}

void Display::GetPlayerNumbers(Game game)
{
	int numberOfPlayers;

	do {
		system("CLS");//clear screen

		cout << "\n\n\n\t\t\t*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		cout << "\t\t\t|                                                           |" << endl;
		cout << "\t\t\t|            Please enter the number of players :           |" << endl;
		cout << "\t\t\t|                     !(Minimum : 2)!                       |" << endl;
		cout << "\t\t\t|                                                           |" << endl;
		cout << "\t\t\t*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		cout << "\n\n\t\t\t===> : ";

		cin >> numberOfPlayers;
		
		if (numberOfPlayers < 2) {
			cout << "[!!! At least 1 Player is required to play the game !!!]"<<endl;
			getchar();
		}
	} while (numberOfPlayers < 2);

	GetPlayerNames(game, numberOfPlayers);
}

void Display::GetPlayerNames(Game game, int numberOfPlayers)
{

	string playerName;

	for (int i = 0; i < numberOfPlayers; i++) {
		cout << "\n\t\t\tPlease enter player no. " << i + 1 << " Name: ";
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

			cout << "Please Enter Head's position of the snake no. " << i << " : ";
			cin >> snakeHead;

			cout << "Please Enter Tail's position of the snake no. " << i << " : ";
			cin >> snakeTail;

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
			cout << "Please Enter Bottom's position of the ladder no. " << i << " : ";
			cin >> ladderDown;

			cout << "Please Enter Top's position of the ladder no. " << i << " : ";
			cin >> ladderUp;

			isSnakeExist = game.isSnakeExist(ladderDown, ladderUp);//check for snake extistence
			isLadderExist = game.isLadderExist(ladderDown, ladderUp);//check for ladder extistence

			if (ladderUp <= ladderDown) {
				cout << "!!! Top of the ladder can't be in a lower position than it's Bottom !!! Try Again... " << endl;
			}

			if (isSnakeExist) {
				cout << "!!! There is already an Snake in this postitions !!! Try Again... " << endl;
			}

			if (isLadderExist) {
				cout << "!!! There is already a ladder in this postitions !!! Try Again... " << endl;
			}

			if (ladderDown < 1) {
				cout << "!!! ladder Bottom position can't be outside of the game board !!! Try Again..." << endl;
			}

			if (ladderUp < 2) {
				cout << "!!! ladder Top position can't be less than 2 !!! Try Again..." << endl;
			}

			if (ladderDown > game.getDimension()) {
				cout << "!!! ladder Bottom position can't be bigger than game board !!! Try Again..." << endl;
			}

			if (ladderUp > game.getDimension()) {
				cout << "!!! ladder Top position can't be bigger than game board !!! Try Again..." << endl;
			}

		} while ((ladderUp <= ladderDown) || isSnakeExist || isLadderExist || ladderDown < 1 || ladderUp < 2 || (ladderDown > game.getDimension() || ladderUp > game.getDimension()));

		//add ladder to the game map
		game.insertLadder(pair<int, int>(ladderDown, ladderUp));
	}

	//show ladders & snakes position
	cout << endl;
	game.showSnakesPos(game.getSnakes());
	game.showLaddersPos(game.getLadders());

	cout << "Everything's set... Let's start the game!" << endl;
	getchar();
	getchar();

	//start the game
	game.startTheGame(game);

}


void Display::showValidationToStart(Game game, queue<Player>& players, Player& player)
{
	Dice dice;
	system("CLS");//clear screen

	cout << "COUNT OF PLAYERS IN GAME : " << players.size() << endl;

	cout << "It's " << player.getName() << "'s turn :) (NOT STARTED YET)" << endl;

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

void Display::showDiceAndPos(Game game, Player &player, Dice dice)
{
	system("CLS");//clear screen

	cout << "[Player: " << player.getName() << " ]" << endl;

	int diceValue = dice.getValue();
	printf("Dice Number = %d\n", diceValue);
	dice.showDice(diceValue);

	int prevPos = player.getCurrentPos();
	int currentPos = prevPos + diceValue;

	//check for ladders and snakes
	if (game.checkForSnakes(game, currentPos, player)) {
		currentPos = player.getCurrentPos();
	}
	else if (game.checkForLadders(game, currentPos, player)) {
		currentPos = player.getCurrentPos();
	}

	//set player positions
	player.setCurrentPos(currentPos);
	player.setPrevPos(prevPos);

	//show snakes and ladders position
	cout << "SNAKES & LADDERS POSITION:" << endl;
	game.showSnakesPos(game.getSnakes());
	game.showLaddersPos(game.getLadders());


	//show player's position
	cout << "Previous Position: " << player.getPrevPos() << endl
		<< "Current Position: " << player.getCurrentPos() << endl<<endl;

	//SHOW OTHER PLAYERS POSITION
	cout << "----------------------------------------------------" << endl;
	cout << "           Other Players current position           " << endl << endl;
	queue<Player> tempPlayers = game.getPlayers();
	tempPlayers.pop();
	while (!tempPlayers.empty()) {
		string playerName = tempPlayers.front().getName();
		int playerCurrentPos = tempPlayers.front().getCurrentPos();
		cout << playerName << " : " << playerCurrentPos << endl;
		tempPlayers.pop();
	}
	cout << "----------------------------------------------------" << endl;

	getchar();
}


void Display::showDicePrize(Game game, Player &player, Dice dice)
{
	system("CLS");//clear screen

	cout << "[Player: " << player.getName() << " ]" << endl;

	int diceValue = 6;
	printf("Dice Number = %d\n", diceValue);
	dice.showDice(6);

	int prevPos = player.getCurrentPos();
	int currentPos = prevPos + diceValue;

	//check for ladders and snakes
	if (game.checkForSnakes(game, currentPos, player)) {
		currentPos = player.getCurrentPos();
	}
	else if (game.checkForLadders(game, currentPos, player)) {
		currentPos = player.getCurrentPos();
	}

	//set player positions
	player.setCurrentPos(currentPos);
	player.setPrevPos(prevPos);

	//show snakes and ladders position
	cout << "SNAKES & LADDERS POSITION:" << endl;
	game.showSnakesPos(game.getSnakes());
	game.showLaddersPos(game.getLadders());


	//show player's position
	cout << "Previous Position: " << player.getPrevPos() << endl
		<< "Current Position: " << player.getCurrentPos() << endl;
	if (currentPos > game.getDimension()) {
		cout << "[* YOU GOT 6! But you have already finished the game! *]"<<endl<<endl;
	}
	else {
	cout << "[* WOW!!! You got a prize! So it's your turn again :) *]"<<endl<<endl;
	}

	//SHOW OTHER PLAYERS POSITION
	cout << "----------------------------------------------------" << endl;
	cout << "           Other Players current position           " << endl << endl;
	queue<Player> tempPlayers = game.getPlayers();
	tempPlayers.pop();
	while (!tempPlayers.empty()) {
		string playerName = tempPlayers.front().getName();
		int playerCurrentPos = tempPlayers.front().getCurrentPos();
		cout << playerName << " : " << playerCurrentPos << endl;
		tempPlayers.pop();
	}
	cout << "----------------------------------------------------" << endl;

	getchar();
}

void Display::showSnakeEncounter(int head, int tail)
{
	cout << "--------------------------------------" << endl;
	cout << "[OH NO!! You Were Bitten by an snake!]" << endl << endl;

	printf(" %d\n ", head);
	cout
		<< "   $ " << endl
		<< "    ()" << endl
		<< "     \\" << endl
		<< "     /" << endl
		<< "     \\/  " << tail << endl << endl;
	cout << "--------------------------------------" << endl;

}


void Display::showLadderEncounter(int bottom, int top)
{
	cout << "--------------------------------------" << endl;
	cout << "[Congrats!! You have reached a ladder!]" << endl << endl;

	cout << "  " << top << " " << endl;
	cout << " " << "|_|" << " " << endl;
	cout << " " << "|_|" << " " << endl;
	cout << " " << "|_|" << " " << endl;
	cout << " " << "|_|" << " " << endl;
	cout << " " << "|_|" << " " << endl;
	cout << "  " << bottom << " " << endl;

	cout << "--------------------------------------" << endl;
}

void Display::showWinner(queue<Player> winners)
{
	//display winner of the game
	cout << "*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#" << endl << endl
		<< "           Winner is " << winners.front().getName() << endl << endl
		<< "*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#" << endl;

	cout << endl << "-------------------------------------"<<endl;

	//Display players ranking...
	cout << "Players Ranking:" << endl;
	int i = 1;
	while (!winners.empty()) {
		string playerName = winners.front().getName();
		cout << i << "_ " << playerName<<endl;
		winners.pop();
		i++;
	}

	cout << endl << "-------------------------------------" << endl;


	/*ASK if user wants to play again*/
askAgain:
	char userInput;
	cout << "DO YOU WANT TO PLAY A NEW GAME?!(Y/N): ";
	cin >> userInput;

	Game newGame;

	switch (toupper(userInput)) {
	case 'Y': //Start a new Game
		system("CLS");//clear screen
		Display::Start(newGame);
		break;
	case 'N': //Close the game
		system("CLS");//clear screen
		cout << "GOOD LUCK! SEE YOU SOON :)" << endl;
		break;
	default:
		system("CLS");//clear screen
		cout << "Wrong input!!!" << endl;
		goto askAgain;
	}

}
