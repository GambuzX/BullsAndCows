#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

//The entry point for our application
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();

		cout << endl << endl;
	} while (bPlayAgain);

	return 0; //exit the application
}


void PrintIntro()
{	
	//Introduce the game
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n\n";
	return;
}

void PlayGame()
{
	// Loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		string guess = GetGuess();
		cout << "Your guess was: " << guess << endl << endl;
	}
}

string GetGuess()
{
	//Get a guess from the player
	string guess = "";
	cout << "What's your guess? ";
	getline(cin, guess);	
	return guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again (y/n)? ";
	string Response = "";
	getline(cin, Response);
	char responseChar = Response[0];
	return (responseChar == 'y' || responseChar == 'Y');
}