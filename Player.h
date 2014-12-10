#ifndef PLAYER_H
#define PLAYER_H

//class represents each individual player
class Player
{
private:
	int m_bank;
	bool m_isTurn;

public:
	//Default Constructor
	Player() { m_bank = 0; m_isTurn = false; }

	int GetTurn() { return m_isTurn; }
	int GetBank() { return m_bank; }
	void SetTurn() { m_isTurn = !m_isTurn; }

	void addToBank(int seeds) { m_bank+=seeds; }
};

#endif