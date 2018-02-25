#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

//The entry point for our application
int main()
{
	PrintIntro();

	// Loop for the number of turns asking for guesses
	const int NUMBER_OF_TURNS = 5;
	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
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

//Get a guess from the player
string GetGuessAndPrintBack()
{
	string guess = "";
	cout << "What's your guess? ";
	getline(cin, guess);

	//repeat the guess back to the player
	cout << "Your guess was: " << guess << endl << endl;
	
	return guess;
}