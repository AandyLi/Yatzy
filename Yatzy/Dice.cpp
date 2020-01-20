#include "Dice.h"



Dice::Dice(int nrOfFaces )
{
	srand(time(NULL));
	this->nrOfFaces = nrOfFaces;
}


Dice::~Dice()
{
}

void Dice::rollDice()
{
	this->value = rand() % this->nrOfFaces + 1;
}

int Dice::getValue()const {
	return this->value;
}