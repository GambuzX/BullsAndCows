#pragma once
#include <string>

class FBullCowGame
{
public:
	void Reset(); //TODO make a more rich return value.
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool IsGuessCorrect(std::string);

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;

};