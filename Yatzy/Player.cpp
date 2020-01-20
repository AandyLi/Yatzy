#include "Player.h"



Player::Player(string name)
{
	this->name = name;
	this->totalScore = 0;
	this->fullHouse = false;
	this->dices.resize(6);

	for (int i = 0; i < 7; i++)
	{
		this->indivdualScores[i] = 0;
	}

}

Player::Player()
{
	// Make player name unique by setting name as address
	stringstream address;
	address << (void const*)this;

	this->name = address.str();
	this->totalScore = 0;
	this->fullHouse = false;
	this->dices.resize(6);

	for (int i = 0; i < 7; i++)
	{
		this->indivdualScores[i] = 0;
	}
}


Player::~Player()
{
}

void Player::rollDices()
{
	for (int i = 0; i < dices.size(); i++)
	{
		this->dices[i].rollDice();
	}
}

vector<Dice> *Player::getDices() 
{
	return &this->dices;
}

string Player::getName() const
{
	return this->name;
}

int * Player::getIndividualScoreArray()
{
	return this->indivdualScores;
}

void Player::addPoints(int points, int dice)
{
	this->totalScore += points;
	this->indivdualScores[dice - 1] = points;
}

int Player::getPoints() const
{
	return this->totalScore;
}

void Player::removeDices(int nrOfDices)
{
		int currentDiceCount = this->dices.size();
		this->dices.resize(currentDiceCount - nrOfDices);
}

void Player::addDices()
{
	this->dices.resize(6);
}

void Player::setPlayerName(string name)
{
	this->name = name;
}

bool Player::hasFinished()
{
	for (int i = 0; i < 7; i++)
	{
		if (indivdualScores[i] == 0)
		{
			return false;
		}
	}
	return true;
}
