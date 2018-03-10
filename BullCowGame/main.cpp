/*	This is the console executable, that makes use of the BullCow class.
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiates a new game

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
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n\n";
	return;
}

void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();

	// Loop for the number of turns asking for guesses	
	constexpr int32 NUMBER_OF_TURNS = 5;
	for (int32 i = 1; i <= NUMBER_OF_TURNS; i++) // TODO change from FOR to WHILE loop
	{
		FText guess = GetValidGuess();

		//Submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(guess);

		//Print number of bulls and cows
		std::cout << "Bulls =  " << BullCowCount.Bulls;
		std::cout << ". Cows =  " << BullCowCount.Cows << "\n\n";
	}
	// TODO summarise game
}

// loop until the user inputs a valid guess
std::string GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		//Get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		FText Guess = "";
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		//Check guess validity
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a lowercase word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word with no repeating letters.\n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	getline(std::cin, Response);
	char responseChar = Response[0];
	return (responseChar == 'y' || responseChar == 'Y');
}