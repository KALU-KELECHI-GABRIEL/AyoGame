// gameModel.cpp : Defines the entry point for the console application.
//-------------------------------------------------------------------------------------------
/* 
PARAMETERS

Maximum of 2 players
game board has 14 cups total. 6 on each player's side, and 1 bank per player. The game starts with exactly 4 seeds in each cup.
The objective of the game is to bank the most seeds.

RULES

The game starts by placing 4 seeds in each of the 12 cups on the board, and each player sits with 6 of the cups on their side of the board.
For each turn, a player chooses a cup, takes all the seeds in that cup and goes around the board in a counterclockwise direction, 
planting one seed in each cup as they go.

SCORING

Version A: If your last seed lands in your opponent's cup, you can capture all the seeds in that cup, and add it to your bank. 

Version B: If your last seed lands in a cup that is not empty, rather than stopping, you pick up all the seeds in that cup, 
           and continue to drop one in each consecutive cup, and continue doing this until you reach an empty cup. 
		   If that empty cup is on your side of the board, you may capture all the seeds in your opponent's cup adjacent from this last cup. 
		   If it is on their side, you don't capture any seeds. 

WINNING

The game continues until one player has >24 seeds in the bank, or until one player cannot move. the player with the most seeds wins.
*/

#include <stdlib.h>
#include <iostream>
#include "Cup.h"
#include "Player.h"
#include "functions.h"
using namespace std;

int main()
{

	const int totalCups = 12;
	const int numberOfPlayers = 2;
	Cup anArrayCups[totalCups];
	Player anArrayPlayers[numberOfPlayers];
	anArrayPlayers[0].SetTurn();

	int version;
	checkGameVersion(version);
	displayStatus(anArrayCups, anArrayPlayers);

	if (version == 1)
		playGameA(anArrayCups, anArrayPlayers);
	if (version == 2)
		playGameB(anArrayCups, anArrayPlayers);

	cout << "Game Over."<<endl
		 << "final score:"<< endl
	     << "player 1 - "<<anArrayPlayers[0].GetBank()<<endl
		 << "player 2 - "<<anArrayPlayers[1].GetBank()<<endl;

	return 0; 
}



