#ifndef Menu_h
#define Menu_h

#include "Records.h"
#include "Game.h"

class Menu{

public:

	Menu();
	~Menu();
	void play();
	void getRecord(); //check win/loss record
	void resetRecord(); //reset win/loss record
	void quit(); //close the game

private:
	int choice;
};
#endif