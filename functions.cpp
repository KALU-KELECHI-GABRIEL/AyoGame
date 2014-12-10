#include <iostream>
#include "Cup.h"
#include "Player.h"
using namespace std;

void checkGameVersion(int &version)
{
	bool valid = false;
	do
	{
		cout << "choose game version:\n enter 1 (classic version) \n enter 2 (continuous play version) " << endl;
		cin >>version;
		if ((version == 1) || (version == 2))
			valid = true;

	}while(!valid);

	return;
}

void displayStatus (Cup *currentStatus, Player *allPlayers)
{
	for (int iii=11; iii>=6; iii--)
		cout << currentStatus[iii].GetSeeds() <<"  ";
	cout <<"\n";
	for (int iii=0; iii<6; iii++)
		cout << currentStatus[iii].GetSeeds() <<"  ";

	if (allPlayers[0].GetTurn())
		cout <<"\n\nplayer 1's turn to move" << endl;
	if (allPlayers[1].GetTurn())
		cout <<"\n\nplayer 2's turn to move" << endl;
}

int getFirstPlayerMove (Cup *currentStatus, bool &gameOver)
{
	int cup = 0;
	gameOver = true;

	for (int iii=0; iii<6; iii++)
		if (currentStatus[iii].GetSeeds())
			gameOver = false;

	if (gameOver)
		return 0;

	bool valid = false;;
	while (!valid)
	{
		cout << "which Cup will player 1 draw from?" << endl;
		cin >> cup;

		if ((cup < 0) || (cup > 5) || (currentStatus[cup].GetSeeds() == 0))
			cout <<"invalid move" << endl;
		else
			valid = true;
	}
	return cup;
}

int getSecondPlayerMove (Cup *currentStatus, bool &gameOver)
{
	int cup = 0;
	gameOver = true;

	for (int iii=6; iii<12; iii++)
		if (currentStatus[iii].GetSeeds())
			gameOver = false;

	if (gameOver)
		return 0;

	bool valid = false;;
	while (!valid)
	{
		cout << "which Cup will player 2 draw from?" << endl;
		cin >> cup;

		if ((cup < 6) || (cup > 11) || (currentStatus[cup].GetSeeds() == 0))
			cout <<"invalid move" << endl;
		else
			valid = true;
	}
	return cup;
}

void makeFirstPlayerMoveA (Cup *currentStatus, int startCup, Player *allPlayers)
{

	
	int seeds = currentStatus[startCup].GetSeeds();
	currentStatus[startCup].emptyCup();
		
	for (int iii=seeds, jjj=(startCup+1); iii > 0; iii--, jjj++)
	{
		if (jjj > 11) 
			jjj -= 12;

		currentStatus[jjj].incrementSeeds();
	}

	int endCup = startCup + seeds;
	if (endCup > 11)
		endCup -= 12;

	int roundScore = 0;

	for (int iii=6; iii<12; iii++)
	{
		if (endCup == iii)
		{
			roundScore = currentStatus[endCup].GetSeeds();
			currentStatus[endCup].emptyCup();
		}
	}

	allPlayers[0].addToBank(roundScore);
	allPlayers[0].SetTurn();
	allPlayers[1].SetTurn();

	return;
}

void makeSecondPlayerMoveA (Cup *currentStatus, int startCup, Player *allPlayers)
{

	
	int seeds = currentStatus[startCup].GetSeeds();
	currentStatus[startCup].emptyCup();
		
	for (int iii=seeds, jjj=(startCup+1); iii > 0; iii--, jjj++)
	{
		if (jjj > 11) 
			jjj -= 12;

		currentStatus[jjj].incrementSeeds();
	}

	int endCup = startCup + seeds;
	if (endCup > 11)
		endCup -= 12;

	int roundScore = 0;

	for (int iii=0; iii<6; iii++)
	{
		if (endCup == iii)
		{
			roundScore = currentStatus[endCup].GetSeeds();
			currentStatus[endCup].emptyCup();
		}
	}

	allPlayers[1].addToBank(roundScore);
	allPlayers[0].SetTurn();
	allPlayers[1].SetTurn();
			
	return;
}

void makeFirstPlayerMoveB (Cup *currentStatus, int startCup, Player *allPlayers)
{
	
	bool play = true;
	while (play)
	{
		int seeds = currentStatus[startCup].GetSeeds();
	    currentStatus[startCup].emptyCup();

		for (int iii=seeds, jjj=(startCup+1); iii > 0; iii--, jjj++)
		{
				if (jjj > 11) 
					jjj -= 12;
				currentStatus[jjj].incrementSeeds();
		}

		startCup += seeds;
		if (startCup > 11)
			startCup -= 12;

		if (currentStatus[startCup].GetSeeds() == 1) 
			play = false;
	}

	int roundScore = 0;

	for (int iii=0, jjj=11; iii<6; iii++,jjj--)
	{
		if (startCup == iii)
		{
			int adjacentCup = jjj;
			roundScore = currentStatus[startCup].GetSeeds() + currentStatus[adjacentCup].GetSeeds();
			currentStatus[startCup].emptyCup();
			currentStatus[adjacentCup].emptyCup();
		}
	}

	allPlayers[0].addToBank(roundScore);
	allPlayers[0].SetTurn();
	allPlayers[1].SetTurn();

	return;
}

void makeSecondPlayerMoveB (Cup *currentStatus, int startCup, Player *allPlayers)
{
	
	bool play = true;
	while (play)
	{
		int seeds = currentStatus[startCup].GetSeeds();
	    currentStatus[startCup].emptyCup();

		for (int iii=seeds, jjj=(startCup+1); iii > 0; iii--, jjj++)
		{
				if (jjj > 11) 
					jjj -= 12;
				currentStatus[jjj].incrementSeeds();
		}

		startCup += seeds;
		if (startCup > 11)
			startCup -= 12;

		if (currentStatus[startCup].GetSeeds() == 1) 
			play = false;
	}

	int roundScore = 0;

	for (int iii=6, jjj=5; iii<12; iii++,jjj--)
	{
		if (startCup == iii)
		{
			int adjacentCup = jjj;
			roundScore = currentStatus[startCup].GetSeeds() + currentStatus[adjacentCup].GetSeeds();
			currentStatus[startCup].emptyCup();
			currentStatus[adjacentCup].emptyCup();
		}
	}

	allPlayers[1].addToBank(roundScore);
	allPlayers[0].SetTurn();
	allPlayers[1].SetTurn();
			
	return;
}

void playGameA (Cup *anArrayCups, Player *anArrayPlayers)
{
	bool gameOver = false;
	while (!gameOver)
	{
		int startCup;
		if (anArrayPlayers[0].GetTurn())
		{
			startCup = getFirstPlayerMove(anArrayCups, gameOver);
			if (gameOver) break;
			makeFirstPlayerMoveA (anArrayCups, startCup, anArrayPlayers);
		}

		displayStatus(anArrayCups, anArrayPlayers);

		if (anArrayPlayers[1].GetTurn())
		{
			startCup = getSecondPlayerMove(anArrayCups, gameOver);
			if (gameOver) break;
			makeSecondPlayerMoveA (anArrayCups, startCup, anArrayPlayers);
		}

		displayStatus(anArrayCups, anArrayPlayers);

		if ((anArrayPlayers[0].GetBank() > 24)||(anArrayPlayers[1].GetBank() > 24))
			gameOver = true;
	}

	return;
}

void playGameB (Cup *anArrayCups, Player *anArrayPlayers)
{
	bool gameOver = false;
	while (!gameOver)
	{
		int startCup;
		if (anArrayPlayers[0].GetTurn())
		{
			startCup = getFirstPlayerMove(anArrayCups, gameOver);
			if (gameOver) break;
			makeFirstPlayerMoveB (anArrayCups, startCup, anArrayPlayers);
		}

		displayStatus(anArrayCups, anArrayPlayers);

		if (anArrayPlayers[1].GetTurn())
		{
			startCup = getSecondPlayerMove(anArrayCups, gameOver);
			if (gameOver) break;
			makeSecondPlayerMoveB (anArrayCups, startCup, anArrayPlayers);
		}

		displayStatus(anArrayCups, anArrayPlayers);

		if ((anArrayPlayers[0].GetBank() > 24)||(anArrayPlayers[1].GetBank() > 24))
			gameOver = true;
	}

	return;
}
