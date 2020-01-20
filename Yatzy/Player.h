#pragma once
#include <string>
#include "Dice.h"
#include <vector>
#include <sstream>
using namespace std;
class Player
{
private:
	string name;
	vector<Dice> dices;
	int totalScore;
	int indivdualScores[7];
	bool fullHouse;
public:
	Player(string name);
	Player();
	virtual ~Player();

	vector<Dice> *getDices() ;
	string getName() const;
	
	void setPlayerName(string name);

	int *getIndividualScoreArray();
	int getPoints() const;

	void rollDices();
	void addPoints(int points, int dice);

	void addDices();
	void removeDices(int nrOfDices);


	bool hasFinished();
};