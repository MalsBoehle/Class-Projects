#include <iostream>
#include <iomanip>
using namespace std;
#include "Log.h" //   ___//__//___
				 //  (@)_LOG_GAME_)  I made you a log to enjoy while grading :)

/*
	Mallory Boehle
	10/21/22
	This main file is where a brunt of the work happens. It is where the wheel is supn and game is played. 
*/

//lines 8 through 11 are the function protoypes 
long spin(); 
void printState(Log[], long); 
char colorPicker(); 
void playTurn(Log[], long, long); 


static const int PLAYERS = 4; //global variable & max number of players.  
int main()
{
	int numOfPlayers; 
    Log playerArry[PLAYERS];
	int currentPlayer = -1; 
	
	srand(time(0)); 

	cout << "How many people are playing?" << endl; 
	cin >> numOfPlayers; // gets the number of players
	printState(playerArry, numOfPlayers); //print header 

	do
	{
		currentPlayer++;
		if (numOfPlayers == currentPlayer)
		{
			currentPlayer = 0; 
		}
		playerArry[currentPlayer].getState(); //print log
		cout << "Player  " << currentPlayer + 1 << "'s turn:" << endl;
		system("pause");
		cout << endl;
		playTurn(playerArry,currentPlayer, numOfPlayers);
		printState(playerArry, numOfPlayers); //print header 
		
	} while (playerArry[currentPlayer].hasWon() == false);
	return 0; 
}

long spin()
{

	return (rand() % 10) + 0; // returns a number 0-9 that goes with the playTurn function 

}

void printState(Log playerArry[], long numOfPlayers) //prints the state of the log 
{
	system("cls");

	for (int i = 0; i < numOfPlayers; i++) //prints the "Player (enter number here)'s log" header thing 
	{
		cout << setw(10) << "Player " << i + 1;
	}

	cout << endl;

	for (int i = 0; i < numOfPlayers; i++) //prints the log
	{
		cout << setw(12) << playerArry[i].getState();
	}

	cout << endl;

}

char colorPicker() //purpose?
{
	char colorChoice; 
	cout << "Please pick a color" << endl; 

		cin >> colorChoice; //enter one of the colors 
		//cout << colorChoice << " "; 

		switch (colorChoice)
		{
		case 'r':
		case 'R':
			return 'R';
			break;
		case 'g':
		case 'G':
			return 'G';
			break;
		case 'b':
		case 'B':
			return 'B';
			break;
		case 'p':
		case 'P':
			return 'P';
			break;
		case 'y':
		case 'Y':
			return 'Y';
			break;
		}
		//add validation (while true loop) 
}

void playTurn(Log playerArry[], long currentPlayer, long numOfPlayers)
{
	char acornChoice;
	int x;
	int playerChocie; 
	long playerStolenFrom; 
	char stolenAcornChoice; 


	 x = spin(); 
	//cout << x << " ";// i want to see what number it outputs while some cases dont have sentences rn 


	switch (x)
	{
	case 0: // player loses turn 
		cout << "Oh nuts! The squirrels got confused and stole your turn instead of an acorn!" << endl;
		system("pause");
		break;
	case 1: //blue
		cout << "Congrats! You get a blue acorn!" << endl;
		playerArry[currentPlayer].addAcorn('B');
		system("pause");
		break;
	case 2://green
		cout << "Congrats! You get a green acorn!" << endl;
		playerArry[currentPlayer].addAcorn('G');
		system("pause");
		break;
	case 3: // player steals 1 accorn 
		cout << "Your friend was foolish and left his accorns unattended. You must teach him a lesson. Go take one accorn." << endl;
		cout << "Please enter the number of player you would like to steal from:"; 
		cin >> playerStolenFrom; //pick player to steal from 
		while (playerStolenFrom - 1  == currentPlayer || numOfPlayers < playerStolenFrom || playerStolenFrom < 1)
		{
			cout << "Invaild player. Please enter a player to steal from. (1 - " << numOfPlayers << ")" << endl; //can't pick themselves 
			cout << "Please enter the number of player you would like to steal from: "; 
			cin >> playerStolenFrom;

		}
		cout << "What color would you like to steal?" << endl; 
		stolenAcornChoice = colorPicker();  
		if (playerArry[playerStolenFrom - 1].stealAcorn(stolenAcornChoice) == false) 
		{
			cout << "The player you tried to steal from does not have that color." << endl;
		} else 
		{
			playerArry[currentPlayer].addAcorn(stolenAcornChoice); //give to currentPlayer
		}
		system("pause");
		break;
	case 4: //pick 2
		cout << "Lucky squirrel! You get to pick two acorns! " << endl;
		acornChoice = colorPicker();
		playerArry[currentPlayer].addAcorn(acornChoice);
		acornChoice = colorPicker(); 
		playerArry[currentPlayer].addAcorn(acornChoice);
		system("pause");
		break;
	case 5: // storm roll
		cout << "A rouge squirrel accidently summoned a storm when trying to eat breakfast. All acorns wash away." << endl;
		playerArry[currentPlayer].storm();
		system("pause");
		break;
	case 6://red
		cout << "Congrats! You get a red acorn!" << endl;
		playerArry[currentPlayer].addAcorn('R');
		system("pause");
		break;
	case 7:// Pick an acorn color 
		cout << "The Squirrel God has smiled upon you, enter an accorn color of your choice! ";
		acornChoice = colorPicker();
		playerArry[currentPlayer].addAcorn(acornChoice);
		//cout << acornChoice; 
		system("pause");
		break;
	case 8: // purple
		cout << "Congrats! You get a purple acorn!" << endl;
		playerArry[currentPlayer].addAcorn('P');
		system("pause");
		break;
	case 9://yellow
		cout << "Congrats! You get a yellow acorn!" << endl;
		playerArry[currentPlayer].addAcorn('Y');
		system("pause");
		break;
	}

}