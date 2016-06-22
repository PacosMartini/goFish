#include <iostream>
using namespace std;
#include "Menu.h"

Menu::Menu(){

	do{
		//(char)3 Heart << (char)4 Diamond << (char)5 Club << (char)6 Spade

		cout << "---Please make a selection---\n" << endl
			<< "1--Play vs Computer\n" << endl
			<< "2--Check Records\n" << endl
			<< "3--Reset Records\n" << endl
			<< "4--Exit Game\n" << endl
			<< "--> ";

		cin >> choice;
		cout << endl;

		while (cin.fail()){
				cout << "Please input a valid choice (1-4): ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> choice;
				cout << endl;
		}

		switch (choice){
		case 1:
			play();
			break;
		case 2:
			getRecord();
			break;
		case 3:
			resetRecord();
			break;
		case 4:
			quit();
			break;
		//default:
			//nothing yet
		}
	} while (choice > 4 && choice < 0);
}

Menu::~Menu(){
	delete this;
}

void Menu::play(){
	Game* g = new Game();
}

void Menu::getRecord(){
	Records* r = new Records(0);
	delete r;
} //check win/loss record

void Menu::resetRecord(){
	Records* r = new Records(1);
	delete r;
} //reset win/loss record

void Menu::quit(){
	cout << "Now closing game..." << endl;
	system("cls");

	cout << "Thanks for playing! Game now closed." << endl << endl;

	system("pause");
	exit(1);
} //close the game