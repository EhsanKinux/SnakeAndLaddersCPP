#pragma once
#include "Player.h"
#include "Dice.h"
#include "Game.h"

class Display
{
	//TODO: WinPage, DiceThrow, start menu etc.
public:
	static void Start(Game game);
	static void GetBoard(Game game);
	static void GetPlayerNumbers(Game game);
	static void GetPlayerNames(Game game, int numberOfPlayers = 1);
	static void GetSnakes(Game game);//unfinished
	static void GetLadders(Game game);//unfinished
	static void PlayerTurn(Game game);
	static void showDiceAndPos(Player player, Dice dice);
	static void showValidationToStart(Game game, Player player);
	static void showDicePrize(Player player, Dice dice);//after congrats call showDiceAndPos
	static void showWinner();//unfinished

};

