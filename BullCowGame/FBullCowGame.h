#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame();//Constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value.
	bool IsGuessCorrect(std::string);
	// provide a method for counting bulls and cows, and increasing turn number


private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;

};