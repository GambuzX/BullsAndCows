/* Contains the definitions for the FBullCowGame class functions */

#pragma once

#include "FBullCowGame.h"
#include <map>
#include <time.h>
#include <stdlib.h> 
#define TMap std::map

//to make syntax Unreal friendly
using int32 = int;

FBullCowGame::FBullCowGame(){ Reset();}

int32 FBullCowGame::GetMaxTries() const	{
	TMap<int32, int32> WordLengthToMaxTries = { {3,5}, {4,7}, {5,10}, {6,15}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}

int32 FBullCowGame::GetHiddenWordLength() const { return (int32) MyHiddenWord.length();}


void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	bIsGameWon = false;

	FString HIDDEN_WORD = GenerateRandomHiddenWord(HiddenWordsList, HiddenWordsCount); //this MUST be an Isogram
	MyHiddenWord = HIDDEN_WORD;

	return;
}

bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (!IsIsogram(guess)) //if the guess isnt an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(guess)) {	//if the guess isnt all lowercase
		return EGuessStatus::Not_Lowercase;
	}
	else if (guess.length() != GetHiddenWordLength()) {//if the guess length is wrong
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}

	return EGuessStatus::OK; //TODO make actual error
}

//Receives a valid guess, increments turn, returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = GetHiddenWordLength();
	int32 GuessLength = (int32) Guess.length();

	//If the guess is correct
	if (Guess == MyHiddenWord)
		bIsGameWon = true;
	else
		bIsGameWon = false;

	//loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		//compare letters against the guess
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

FString FBullCowGame::GenerateRandomHiddenWord(FString WordList[], int arraySize) const
{
	srand(time(NULL));
	int index = rand() % arraySize;
	FString hiddenWord = WordList[index];
	return hiddenWord;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//Treat 0 and 1 letter words as isograms
	if (Word.length() <= 1)	return true;

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word)  //for all letters in the word
	{
		Letter = tolower(Letter); //handle mixed case
		if (LetterSeen[Letter]) //if the letter is is the map
		{
			return false; // we do NOT have an isogram
		} else	{
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::IsLowercase(FString word) const
{
	if (word.length() == 0) return true;

	for (auto letter : word)
	{
		if (letter == ' ')
			continue;
		if (isupper(letter))
			return false;
	}
	return true;
}
