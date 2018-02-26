#pragma once

class FBullCowGame
{
public:
	void Reset(); //TODO make a more rich return value.
	int GetMaxTries();
	int GetCurrentTry();
	void GameOver();
	bool bIsGameWon();
	bool bVerifyGuess();

private:
	int MyCurrentTry;
	int MyMaxTries;

};