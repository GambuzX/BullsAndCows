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
FText GetGuess();
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
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n\n";
	return;
}

void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();

	// Loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	constexpr int32 NUMBER_OF_TURNS = 5;
	for (int32 i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		FText guess = GetGuess(); //TODO make loop checking valid

		//Submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(guess);

		//Print number of bulls and cows
		std::cout << "Bulls =  " << BullCowCount.Bulls;
		std::cout << ". Cows =  " << BullCowCount.Cows << std::endl;

	}

	// TODO summarise game
}

std::string GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	//Get a guess from the player
	FText guess = "";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, guess);	
	return guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	getline(std::cin, Response);
	char responseChar = Response[0];
	return (responseChar == 'y' || responseChar == 'Y');
}