#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame(){ Reset();}

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}


void FBullCowGame::Reset()
{
	const int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;

	const FString HIDDEN_WORD = "potato";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::IsGuessCorrect(FString)
{
	return false;
}

//Receives a valid guess, increments turn, returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	//increment the turn number
	MyCurrentTry++;

	//setup a return variable
	BullCowCount BullCowCount;

	//loop through all letters in the guess
		//compare letters against the hidden word


	return BullCowCount;
}
