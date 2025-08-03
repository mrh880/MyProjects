#pragma once 

#include <string>

std::string MakeAllStringToLower(const std::string &Word);

bool CheckIfStringHasPunctuationsOrSpecialCharacters(const std::string &Word);

bool CheckIfStringHasCharacters(const std::string &Word);

bool CheckIfStringHasNumbers(const std::string &Word);

std::string TrimFromLeft(std::string Word, char CharacterToTrim);

std::string TrimFromRight(std::string Word, char CharacterToTrim);

std::string TrimStringFromBothSides(std::string Word, char CharacterToTrim);

char CovertLetterToLower(char Character);