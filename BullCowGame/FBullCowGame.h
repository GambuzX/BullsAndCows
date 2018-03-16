#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//all values initialized to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
	Non_Alpha_Chars,
	Empty
};

class FBullCowGame
{
public:
	FBullCowGame();//Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset(); //TODO make a more rich return value.
	FBullCowCount SubmitValidGuess(FString);


private:
	int32 MyCurrentTry = 1;
	int32 MyMaxTries = 5;
	FString MyHiddenWord;
	bool bIsGameWon = false;

};