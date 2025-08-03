#include "DealingWithStrings.h"

#include <ctype.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

std::string MakeAllStringToLower(const std::string &Word)
{
    std::string Result = "";
    for (const char &Character : Word)
        Result += tolower(Character);
    return Result;
}

bool CheckIfStringHasPunctuationsOrSpecialCharacters(const string &Word)
{
    for (const char &Character : Word)
    {
        if (!isalnum(Character) && Character != ' ' && Character != '_')
        {
            return true;
        }
    }
    return false;
}

bool CheckIfStringHasCharacters(const string &Word)
{
    for (const char &Character : Word)
    {
        if (isalpha(Character))
        {
            return true;
        }
    }
    return false;
}

bool CheckIfStringHasNumbers(const string &Word)
{
    for (const char &Character : Word)
    {
        if (isdigit(Character))
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

char ConvertLetterToLower(char Character)
{
    return tolower(Character);
}

std::vector<std::string> SplitWordInSentence(std::string Word, std::string Delemiter)
{
    int LengthOfDelemiter = Delemiter.length();
    int Position = 0;
    std::string TempWord = "";
    std::vector<std::string> TempVector;
    while ((Position = Word.find(Delemiter)) != std::string::npos)
    {
        TempWord = Word.substr(0, Position);
        if (!TempWord.empty())
            TempVector.push_back(TempWord);
        Word.erase(0, Position + LengthOfDelemiter);
    }
    if (!Delemiter.empty())
        TempVector.push_back(Word);
    return TempVector;
}

std::string JoinStrings(std::vector<std::string> Words, std::string Delemiter)
{
    std::string JoinedString = "";
    short LengthOfWords = Words.size();

    for (int Loop = 0; Loop < LengthOfWords; Loop++)
    {
        JoinedString += Words[Loop];
        if (Loop != LengthOfWords - 1)
            JoinedString += Delemiter;
    }
    return JoinedString;
}

bool CheckIfStringHasSpecificCharacter(const string &String, const char Character)
{
    for(const char &CurrentCharacter : String)
    {
        if(CurrentCharacter == '#')
        {
            return true;
        }
    }
    return false;
}

bool CheckIfStringStartsWithSpecificCharacter(const string &String, const char Character)
{
    if(String.empty())
    {
        return false;
    }
    return String[0] == Character;
}

bool CheckIfStringEndsWithSpecificCharacter(const std::string &String, const char Character)
{
    if(String.empty())
    {
        return false;
    }
    short LengthOfString = String.length();
    return String[LengthOfString - 1] == Character;
}

string RemoveSpacesFromString(const string &String)
{
    string Result = "";

    for(const char &CurrentCharacter : String)
    {
        if(CurrentCharacter != ' ')
        {
            Result += CurrentCharacter;
        }
    }
    return Result;
}


bool CheckIfStringHasSpaces(const std::string &String)
{
    for(const char &CurrentCharacter : String)
    {
        if(CurrentCharacter == ' ')
        {
            return true;
        }
    }
    return false;
}