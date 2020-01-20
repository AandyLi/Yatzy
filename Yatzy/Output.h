#pragma once
#include "Player.h"
#include <iostream>

using namespace std;
class Output
{
private:
	string diceOne =	"|     ||  o  ||     |";
	string diceTwo =	"|o    ||     ||    o|";
	string diceThree =	"|o    ||  o  ||    o|";
	string diceFour =	"|o   o||     ||o   o|";
	string diceFive =	"|o   o||  o  ||o   o|";
	string diceSix =	"|o   o||o   o||o   o|";

	string getDiceRow(vector<Dice> *dices, int rowNr);

public:
	Output();
	virtual ~Output();

	void displayDices(vector<Dice> *dices);
};


/*
-------
|     |
|  o  |
|     |
-------
|o    |
|     |
|    o|
-------
|o    |
|  o  |
|    o|
-------
|o   o|
|     |
|o   o|
-------
|o   o|
|  o  |
|o   o|
-------
|o   o|
|o   o|
|o   o|
-------
*/
