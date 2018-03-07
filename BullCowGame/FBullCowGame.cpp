#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){ Reset();}

int FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}


void FBullCowGame::Reset()
{
	const int MAX_TRIES = 8;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::IsGuessCorrect(std::string)
{
	return false;
}
