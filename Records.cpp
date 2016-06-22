#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
#include "Records.h"

Records::Records(int arg){
		system("cls");

		if (arg == 1){ //argument to output read scores from text document
			resetRecords();
			return;
		}

		loadRecords(); //reads and sets win/loss variables from text document
		showRecords();
}

Records::~Records(){}

void Records::loadRecords(){ //sets wins and losses to be ready for display when loadRecord is called
		records.open("Records.txt"); //opens records file or creates a new one if not found

		records >> wins;
		records >> losses;

		if ((wins + losses) != 0)
			winPercent = (float)wins / (float)(wins + losses) * 100.0;
		else
			winPercent = 0;

		records.close();
}

void Records::showRecords(){ //displays your wins, losses, and win percentage
		cout << "Wins: " << wins << endl;
		cout << "Losses: " << losses << endl;
		cout << "Total Game: " << (wins + losses) << endl;	

		cout << fixed;
		cout << setprecision(1);
		cout << "Win percentage: " << winPercent << " %"<< endl << endl;
		system("pause");
}

void Records::updateRecords(char o){ //method to update the record after a game is completed
		if ((char)tolower(o) == 'w')
			wins++;
		else if ((char)tolower(o) == 'l')
			losses++;

		records.open("Records.txt");
		records.clear();
		records << wins;
		records << losses;
}

void Records::resetRecords(){ //method to reset record
		cout << "Resetting records..." << endl;
		wins = 0;
		losses = 0;
		winPercent = 0;

		records.open("Records.txt", ios::out);

		cout << "Record has been reset!" << endl << endl;

		records.close();
		system("pause");
}