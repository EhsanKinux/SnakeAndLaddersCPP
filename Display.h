#pragma once
#include "Player.h"
#include "Dice.h"
#include "Game.h"

class Display
{ 
public:
	static void Start(Game game);
	static void GetBoard(Game game);
	static void GetPlayerNumbers(Game game);
	static void GetPlayerNames(Game game, int numberOfPlayers = 1);
	static void GetSnakes(Game game);
	static void GetLadders(Game game);
	static void showDiceAndPos(Game game, Player &player, Dice dice);
	static void showValidationToStart(Game game, queue<Player>& players, Player& player);
	static void showDicePrize(Game game, Player &player, Dice dice);
	static void showSnakeEncounter(int head, int tail);
	static void showLadderEncounter(int bottom, int top);
	static void showWinner(queue<Player> winners);

};

