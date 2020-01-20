#pragma once
#include "Player.h"
#include <iostream>
#include "Output.h"
#include <algorithm>

struct diceRollInfo {
	string combinationsStr;
	int nrOfSimilarDices[7];
};

using namespace std;
class Game
{
private:
	Player *players;
	Output output;
	int nrOfPlayers;
	bool playing;
	diceRollInfo DRI;
public:
	Game();
	virtual ~Game();

	void addPlayers(int nrOfPlayers);

	void startGame();

	void startGameLoop();

	void endGame();

	diceRollInfo getCombinations(vector<Dice> *dices, int *scoreArr);

	int calculateCombinationScore(int diceNr, int dices);

	bool checkIfFullHouse(vector<Dice> *dices);
	bool checkAllPlayersFinished(Player *players);
};

