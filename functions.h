#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void checkGameVersion(int &);
void displayStatus (Cup *, Player *);
int getFirstPlayerMove (Cup *, bool &);
int getSecondPlayerMove (Cup *, bool &);
void makeFirstPlayerMoveA (Cup *, int, Player *);
void makeSecondPlayerMoveA (Cup *, int, Player *);
void makeFirstPlayerMoveB (Cup *, int, Player *);
void makeSecondPlayerMoveB (Cup *, int, Player *);
void playGameA (Cup *, Player *);
void playGameB (Cup *, Player *);

#endif