#pragma once
#include <time.h>
#include <stdlib.h>
class Dice
{
private:
	int value; // 1-6
	int nrOfFaces;
public:
	Dice(int nrOfFaces = 6);
	virtual ~Dice();

	void rollDice();
	int getValue() const;
};