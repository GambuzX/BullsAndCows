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

	const FString HIDDEN_WORD = "gambuzino";
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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment the turn number
	MyCurrentTry++;

	//setup a return variable
	FBullCowCount BullCowCount;

	//loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	int32 GuessLength = Guess.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {

		//compare letters against the hidden word
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
