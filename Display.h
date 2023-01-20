#pragma once
#include "Player.h"
#include "Dice.h"

class Display
{
	//TODO: WinPage, DiceThrow, start menu etc.
public:
	static void Start();
	static void GetBoard();
	static void GetPlayerNumber();
	static void GetPlayerNames(int numberOfPlayers = 1);
	static void GetSnakes();//unfinished
	static void GetLadders();//unfinished
	static void PlayerTurn(Player player);
	static void showDiceAndPos(Player player, Dice dice);
	static void showValidationToStart(Player player ,Dice dice);
	static void showDicePrize(Player player , Dice dice);//after congrats call showDiceAndPos
	static void showWinner();//unfinished

};

