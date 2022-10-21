#include <iostream>
using namespace std;
#include "Log.h"

/*
	Mallory Boehle
	10/21/22
	This .cpp file has the functions for the class. Mostly setting things true or false. 
*/

Log::Log()
{
	red = false; 
	green = false; 
	blue = false;
	purple = false;
	yellow = false;
	
}

bool Log::hasWon()
{

	if (red == true && green == true && blue == true && purple == true && yellow == true )
	{
		return true; 
	}
	else
	{
		return false;
	}
}

string Log::getState() const // returns the state of the log 
{
	string str = "";  

	if (red == true)
	{
		str = str + "R "; // if red is true then show 'R' otherwise show a _. Same for the other letters
	}
	else {
		str = str + "_ ";
	}
	if (green == true)
	{
		str = str + "G ";
	}
	else {
		str = str + "_ ";
	}
	if (blue == true)
	{
		str = str + "B ";
	}
	else {
		str = str + "_ ";
	}
	if (purple == true)
	{
		str = str + "P ";
	}
	else {
		str = str + "_ ";
	}
	if (yellow == true)
	{
		str = str + "Y";
	}
	else {
		str = str + "_";
	}

	return str; 
}

char Log::addAcorn(char newColor) // function to add a new color 
{
	switch (newColor) {
	case 'R':
		red = true; 
		break; 
	case 'G':
		green = true; 
		break; 
	case 'B':
		blue = true; 
		break; 
	case 'P':
		purple = true;
		break;
	case 'Y':
		yellow = true;
		break;
	}

	if (newColor == newColor) { // if that color already exsists on the log, then return nothing 
		return 0; 
	}
}

bool Log::stealAcorn(char stealColor)
{
	cout << stealColor; 

		switch (stealColor) { 
		case 'R':
			if (red == true)
			{
				red = false;
				return true; 
			}
			else
			{
				return false; 
			}
			break;
		case 'G':
			if (green == true)
			{
				green = false;
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 'B':
			if (blue == true)
			{
				blue = false;
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 'P':
			if (purple == true)
			{
				purple = false;
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 'Y':
			if (yellow == true)
			{
				yellow = false;
				return true;
			}
			else
			{
				return false;
			}
			break;
		}

	if (stealColor == stealColor) { // if that color is on the log then remove it
		return true;
	}
}

void Log::storm() // sets all colors to false and removes them. 
{
	red = false; 
	green = false; 
	blue = false; 
	purple = false; 
	yellow = false; 
}
