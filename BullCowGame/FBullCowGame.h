#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame
{
public:
	FBullCowGame();//Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value.
	bool IsGuessCorrect(FString);
	// provide a method for counting bulls and cows, and increasing turn number


private:
	int32 MyCurrentTry = 1;
	int32 MyMaxTries = 5;

};