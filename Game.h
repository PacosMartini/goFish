#ifndef Game_h
#define Game_h

#include <vector>
using namespace std;

class Game{

public:
	Game();
	~Game();

private:
	vector<string> deck;
	vector<string> computer;
	vector<string> player;
	void shuffleDeck();
	int books;
	void drawCard();
	bool askForCard();
};

#endif