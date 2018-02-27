#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

//The entry point for our application
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();

		std::cout << std::endl << std::endl;
	} while (bPlayAgain);

	return 0; //exit the application
}


void PrintIntro()
{	
	//Introduce the game
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n\n";
	return;
}

void PlayGame()
{
	// Loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		std::string guess = GetGuess();
		std::cout << "Your guess was: " << guess << std::endl << std::endl;
	}
}

std::string GetGuess()
{
	//Get a guess from the player
	std::string guess = "";
	std::cout << "What's your guess? ";
	std::getline(std::cin, guess);	
	return guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	getline(std::cin, Response);
	char responseChar = Response[0];
	return (responseChar == 'y' || responseChar == 'Y');
}