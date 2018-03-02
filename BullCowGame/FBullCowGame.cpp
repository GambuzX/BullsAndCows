#include "FBullCowGame.h"

void FBullCowGame::Reset()
{
	return;
}

int FBullCowGame::GetMaxTries(){return MyMaxTries;}

int FBullCowGame::GetCurrentTry(){return MyCurrentTry;}

bool FBullCowGame::IsGameWon()
{
	return false;
}

bool FBullCowGame::IsGuessCorrect(std::string)
{
	return false;
}
