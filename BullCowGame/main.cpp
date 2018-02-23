#include <iostream>
#include <string>

using namespace std;

int main()
{
	constexpr int WORD_LENGTH = 9;

	//introduce the game
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n\n";

	//get a guess from the player
	string guess = "";
	cout << "What's your guess? ";
	cin >> guess;
	cin.ignore(10000, '\n'); //clear input stream

	//repeat the guess back to the player
	cout << "Your guess was: " << guess;

		
	cout << endl << endl;
	return 0;
}