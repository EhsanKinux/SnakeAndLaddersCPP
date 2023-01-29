#include "Player.h"

void Player::setName(string pName)
{
	name = pName;
}

string Player::getName()
{
	return name;
}

int Player::getCurrentPos()
{
	return currentPos;
}

int Player::getPrevPos()
{
	return prevPos;
}

bool Player::getValidation()
{
	return isValid;
}

void Player::setValidation(bool validate)
{
	isValid = validate;
}

bool Player::checkFinished()
{
	return isFinished;
}

void Player::setFinished(bool finished)
{
	isFinished = finished;
}

void Player::setCurrentPos(int pos)
{
	currentPos = pos;
}

void Player::setPrevPos(int pos)
{
	prevPos = pos;
}
