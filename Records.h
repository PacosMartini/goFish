#ifndef Records_h
#define Records_h

#include <fstream>
using namespace std;

class Records{
public:
	Records(int arg);
	~Records();

private:
	fstream records;
	float winPercent;
	int wins;
	int losses;
	void loadRecords();
	void showRecords();
	void updateRecords(char o);
	void resetRecords();
};

#endif