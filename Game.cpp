#include "Game.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

/* ~~~ GO-FISH RULESET ~~~
Five cards are dealt from a standard 52-card deck to each player
The remaining cards are shared between the players, usually spread out in a disorderly pile referred to as the "ocean" or "pool".
The player whose turn it is to play asks another player for his or her cards of a particular face value. 
For example Alice may ask, "Bob, do you have any threes?" Alice must have at least one card of the rank she requested
Bob must hand over all cards of that rank if possible. If he has none, Bob tells Alice to "go fish" (or simply "fish"), and Alice draws a card from the pool and places it in her own hand. 
Then it is the next player's turn – unless the card Alice drew is the card she asked for, in which case she shows it to the other players, and she gets another turn. 
When any player at any time has all four cards of one face value, it forms a book, and the cards must be placed face up in front of that player.
When all sets of cards have been laid down in books, the game ends. The player with the most books wins
*/

Game::Game(){ //includes all game logic
	shuffleDeck();

	cout << "Dealing Cards..." << endl << endl;;

	for (int i = 0; i < 5; ++i){ //deals 5 cards to player, and 5 cards to computer
		for (int p = 0; p < 2; ++p)
			if (p == 0){
				player.push_back(deck.back());
				deck.pop_back();
			}
			else {
				computer.push_back(deck.back());
				deck.pop_back();
			}
	}

	cout << "Your hand: ";
	for (int i = 0; i < player.size(); ++i)
		cout << player.at(i) << " ";

	cout << endl;

	system("pause");
}

Game::~Game(){
	delete this;
}

void Game::shuffleDeck(){
	//create deck
	cout << "Creating Deck..." << endl << endl;

	vector<string> temp;

	for (int i = 1; i <= 13; ++i){ //Ace to King
		string val;
		switch (i){
		case 1:
			val = "A";
			break;
		case 2:
			val = "2";
			break;
		case 3:
			val = "3";
			break;
		case 4:
			val = "4";
			break;
		case 5:
			val = "5";
			break;
		case 6:
			val = "6";
			break;
		case 7:
			val = "7";
			break;
		case 8:
			val = "8";
			break;
		case 9:
			val = "9";
			break;
		case 10:
			val = "10";
			break;
		case 11:
			val = "J";
			break;
		case 12:
			val = "Q";
			break;
		case 13:
			val = "K";
			break;
		}
		for (int s = 1; s <= 4; ++s){ //Hearts, Spades, Diamonds, and Clubs
			string suit;
			switch (s){
			case 1:
				suit = (char)3;
				break;
			case 2:
				suit = (char)4;
				break;
			case 3:
				suit = (char)5;
				break;
			case 4:
				suit = (char)6;
				break;
			}
			string card = val + suit;

			temp.push_back(card);
		}
	}

	cout << "Shuffling deck..." << endl << endl;

	srand (time(NULL)); //generates time-based "random" seed

	for (int i = 0; !temp.empty(); ++i){ //removes random cards from ordered "deck" and pushes them into game "deck"
		int c = rand() % temp.size();
		string card = temp.at(c);
		temp.erase(temp.begin() + c);
		deck.push_back(card);
	}
}

void Game::drawCard(){

}

bool Game::askForCard(){
	return false;
}