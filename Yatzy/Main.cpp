#include <stdio.h>
#include <iostream>
#include "Player.h"
#include "Output.h"
#include "Game.h"
#include <crtdbg.h>
using namespace std;
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Game game;

	game.startGame();

	getchar();
	return 0;
}