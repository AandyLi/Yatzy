#include "Output.h"



string Output::getDiceRow(vector<Dice> *dices, int rowNr)
{
	string diceRow = "";
	string spacing = "   ";
	int start = rowNr * 7;
	int nrOfElements = 7;

	for (int i = 0; i < dices->size(); i++)
	{

		switch ((*dices)[i].getValue())
		{
		case 1:
			diceRow += diceOne.substr(start, nrOfElements) + spacing;
			break;
		case 2:
			diceRow += diceTwo.substr(start, nrOfElements) + spacing;
			break;
		case 3:
			diceRow += diceThree.substr(start, nrOfElements) + spacing;
			break;
		case 4:
			diceRow += diceFour.substr(start, nrOfElements) + spacing;
			break;
		case 5:
			diceRow += diceFive.substr(start, nrOfElements) + spacing;
			break;
		case 6:
			diceRow += diceSix.substr(start, nrOfElements) + spacing;
			break;
		}

	}

	return diceRow;
}

Output::Output()
{
}


Output::~Output()
{
}

void Output::displayDices(vector<Dice> *dices)
{
	
	cout << getDiceRow(dices, 0) << endl;
	cout << getDiceRow(dices, 1) << endl;
	cout << getDiceRow(dices, 2) << endl;
}
