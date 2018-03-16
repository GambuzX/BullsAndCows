#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame(){ Reset();}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}

int32 FBullCowGame::GetHiddenWordLength() const { return (int32) MyHiddenWord.length();}


void FBullCowGame::Reset()
{
	const int32 MAX_TRIES = 3;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
	bIsGameWon = false;

	const FString HIDDEN_WORD = "gambuzino";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (false) //if the guess isnt an isogram
	{
		return EGuessStatus::Not_Isogram; //TODO write function
	}
	else if (false) {	//if the guess isnt all lowercase
		return EGuessStatus::Not_Lowercase; //TODO write function
	}
	else if (guess.length() != GetHiddenWordLength()) {//if the guess length is wrong
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}

	return EGuessStatus::OK; //TODO make actual error
}

//Receives a valid guess, increments turn, returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = GetHiddenWordLength();
	int32 GuessLength = (int32) Guess.length();

	//If the guess is correct
	if (Guess == MyHiddenWord)
		bIsGameWon = true;
	else
		bIsGameWon = false;

	//loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		//compare letters against the guess
		for (int32 GChar = 0; GChar < GuessLength; GChar++) {
			if (MyHiddenWord[MHWChar] == Guess[GChar]) {
				if (MHWChar == GChar) { //if they are at the same position
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}
