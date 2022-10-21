#ifndef LOG_H
#define LOG_H

#include <string>
using namespace std;

/*
	Mallory Boehle
	10/21/22
	This .h file is where are the functions are named outside of the main. These are for the Log class. 
	*/

class Log {
public:
	bool hasWon(); 
	string getState() const;
	char addAcorn(char); 
	bool stealAcorn(char); 
	void storm(); 
	Log();

private: 
	bool red; 
	bool green; 
	bool blue;
	bool purple; 
	bool yellow; 
};
#endif
