#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

//the entry point for our application
int main()
{
	PrintIntro();
	GetGuessAndPrintBack();
		
	cout << endl << endl;
	return 0;
}

//Introduce the game
void PrintIntro()
{	
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n\n";
	return;
}

//get a guess from the player
string GetGuessAndPrintBack()
{
	string guess = "";
	cout << "What's your guess? ";
	getline(cin, guess);

	//repeat the guess back to the player
	cout << "Your guess was: " << guess;
	
	return guess;
}