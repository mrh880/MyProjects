#include "DealingWithStrings.h"

#include <ctype.h>
using namespace std;


std::string MakeAllStringToLower(const std::string &Word)
{
    std::string Result = "";
    for(const char &Character : Word)
        Result += tolower(Character);
    return Result;
}

bool CheckIfStringHasPunctuationsOrSpecialCharacters(const string &Word)
{
    for(const char &Character : Word)
    {
        if(!isalnum(Character) && Character != ' ')
        {
            return true;
        }
    }
    return false;
}

bool CheckIfStringHasCharacters(const string &Word)
{
    for(const char &Character : Word)
    {
        if(isalpha(Character))
        {
            return true;
        }
    }
    return false;
}

bool CheckIfStringHasNumbers(const string &Word)
{
    for(const char &Character : Word)
    {
        if(isdigit(Character))
        {
            return true;
        }
    }
    return false;
}

string TrimFromLeft(string Word, char CharacterToTrim)
{
    short LengthOfWord = Word.length();
    for (short Loop = 0; Loop < LengthOfWord; Loop++)
    {
        if (Word[Loop] != CharacterToTrim)
            return Word.substr(Loop);
    }
    return "";
}

string TrimFromRight(string Word, char CharacterToTrim)
{
    short LengthOfWord = Word.length();
    for (short Loop = LengthOfWord - 1; Loop >= 0; Loop--)
    {
        if (Word[Loop] != CharacterToTrim)
            return Word.substr(0, Loop + 1);
    }
    return "";
}

string TrimStringFromBothSides(string Word, char CharacterToTrim)
{
    return TrimFromLeft(TrimFromRight(Word, CharacterToTrim), CharacterToTrim);
}


char CovertLetterToLower(char Character)
{
    return tolower(Character); 
}