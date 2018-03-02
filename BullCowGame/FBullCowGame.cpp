#include "FBullCowGame.h"

void FBullCowGame::Reset()
{
	return;
}

int FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::IsGuessCorrect(std::string)
{
	return false;
}
