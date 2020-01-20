#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
	delete[] this->players;
}

void Game::addPlayers(int nrOfPlayers)
{
	players = new Player[nrOfPlayers];
}

void Game::startGame()
{
	cout << "How many players are playing? : " << endl;
	cin >> nrOfPlayers;
	cin.ignore();

	addPlayers(nrOfPlayers);


	for (int i = 0; i < nrOfPlayers; i++)
	{
		cout << "what is the name of player nr " << i + 1 << "?" << endl;
		string tmpName;
		cin >> tmpName;
		cin.ignore();
		players[i].setPlayerName(tmpName);
	}

	playing = true;
	startGameLoop();
}

void Game::startGameLoop()
{
	while (playing)
	{
		for (int i = 0; i < nrOfPlayers;)
		{
			vector<Dice> *playerDices = players[i].getDices();
			int pickedDice;
			diceRollInfo dri;

			for (int rollCount = 1; rollCount < 4; rollCount++)
			{
				if (!players[i].hasFinished())
				{
					cout << players[i].getName() << " you have " << players[i].getPoints() << " points, press enter to roll the dice. Roll nr " << rollCount << endl;
					getchar();
					// Roll dices
					players[i].rollDices();
					// Display dices
					output.displayDices(playerDices);
					// Check if player rolled a full house
					if (players[i].getIndividualScoreArray()[6] == 0 && checkIfFullHouse(playerDices))
					{
						cout << "-- You got a full house! You earn 25 points! :) --\n" << endl;
						players[i].addPoints(25, 7);
					}
					else {
						// Get possible combinations and display them
						dri = getCombinations(playerDices, players[i].getIndividualScoreArray());
						cout << dri.combinationsStr << endl;
						// Let player pick desired combination
						cout << "Pick your desired combination (0 if not possible): ";
						cin >> pickedDice;
						cin.ignore();
						if (pickedDice > 0)
						{
							// Add points to player
							int points = calculateCombinationScore(pickedDice, dri.nrOfSimilarDices[pickedDice - 1]); // -1 to match array index
							players[i].addPoints(points, pickedDice);
							// Print points
							cout << "-- You got " << to_string(points) << " points! --\n" << endl;
							// Remove dices from player
							players[i].removeDices(dri.nrOfSimilarDices[pickedDice - 1]);
							getchar();
						}
					}
				}
			}
			// Reset player dice count after round is over
			players[i].addDices();

			// Make sure to reset for loop if not every player has finished
			if (i == (nrOfPlayers - 1) && !checkAllPlayersFinished(players))
			{
				i = 0;
			}
			else {
				i++;
			}
		}
		if (checkAllPlayersFinished(players)) {
			playing = false;
			endGame();
		}
	}
}

void Game::endGame()
{
	cout << "\n\n\n" << "The game has ended! These are the scores: " << endl;

	for (int i = 0; i < nrOfPlayers; i++)
	{
		cout << "Player " << players[i].getName() << ": " << players[i].getPoints() << " points!" << endl;
	}
}

diceRollInfo Game::getCombinations(vector<Dice> *dices, int *scoreArr)
{
	diceRollInfo dri;

	for (int i = 0; i < 7; i++)
	{
		dri.nrOfSimilarDices[i] = 1;
	}

	string output = "Potential dices to pick are: ";
	vector<int> foundDice;


	for (int i = 0; i < dices->size(); i++)
	{

		int diceValue = (*dices)[i].getValue() - 1;
		bool foundDiceBool = find(foundDice.begin(), foundDice.end(), diceValue) != foundDice.end();

		// If indivdial score of a certain dice is == 0, and not already found, add it as potential pick
		if ((scoreArr[diceValue] == 0) && !foundDiceBool)
		{
			output += to_string(diceValue + 1) + ", ";

			foundDice.push_back(diceValue);
		}
		if (foundDiceBool)
		{
			dri.nrOfSimilarDices[diceValue]++;
		}
	}

	// return string without ", "
	dri.combinationsStr = output.substr(0, output.length() - 2);
	return dri;
}

int Game::calculateCombinationScore(int diceNr, int dices)
{

	return diceNr * dices;
}

bool Game::checkIfFullHouse(vector<Dice>* dices)
{
	vector<int> localArr(6, 0);
	int index;

	for (int i = 0; i < dices->size(); i++)
	{
		index = (*dices)[i].getValue() - 1;
		localArr[index]++;
	}

	bool findAll2 = find(localArr.begin(), localArr.end(), 2) != localArr.end();
	bool findAll3 = find(localArr.begin(), localArr.end(), 3) != localArr.end();
	if (findAll2 && findAll3)
	{
		return true;
	}

	return false;
}

bool Game::checkAllPlayersFinished(Player * players)
{
	for (int i = 0; i < nrOfPlayers; i++)
	{
		if (!players[i].hasFinished())
		{
			return false;
		}
	}
	return true;
}
