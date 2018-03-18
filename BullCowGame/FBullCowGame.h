/* The game logic (no view code or direct user interaction)
The game is a simple guess the word game based on MasterMind */

#pragma once

#include <string>
#include <vector>

//to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

//all values initialized to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

//Enumeration of all Status related to the validation of the user input 
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
	FBullCowGame(); //Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);


private:
	FString GenerateRandomHiddenWord(FString WordList[], int arraySize) const;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;

	int32 MyCurrentTry = 1;
	FString MyHiddenWord;
	bool bIsGameWon = false;
	FString HiddenWordsList[11] = { "gambuzino", "donkey", "crow", "computer", "blanket", "rice", "lamb", "bag", "planet", "plank", "bug" };
	int32 HiddenWordsCount = 11; //This count must match the size of the above array!!!
};