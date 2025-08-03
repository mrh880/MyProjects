#pragma once

#include <string>
#include <vector>

#include "Structures.h"

std::string MakeAllStringToLower(const std::string &Word);

bool CheckIfStringHasPunctuationsOrSpecialCharacters(const std::string &Word);

bool CheckIfStringHasCharacters(const std::string &Word);

bool CheckIfStringHasNumbers(const std::string &Word);

std::string TrimFromLeft(std::string Word, char CharacterToTrim);

std::string TrimFromRight(std::string Word, char CharacterToTrim);

std::string TrimStringFromBothSides(std::string Word, char CharacterToTrim);

char ConvertLetterToLower(char Character);

std::vector<std::string> SplitWordInSentence(std::string Word, std::string Delemiter);

std::string JoinStrings(std::vector<std::string> Words, std::string Delemiter);

bool CheckIfStringHasSpecificCharacter(const std::string &String, const char Character);

bool CheckIfStringStartsWithSpecificCharacter(const std::string &String, const char Character);

bool CheckIfStringEndsWithSpecificCharacter(const std::string &String, const char Character);

std::string RemoveSpacesFromString(const std::string &String);

bool CheckIfStringHasSpaces(const std::string &String);