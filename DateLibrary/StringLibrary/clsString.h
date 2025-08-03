#pragma once

#include <string>
#include <vector>

const int _MaxSize = 1000;

class clsString
{
private:
    std::string _Value = "";
    char _Character = ' ';
    char _Letter = ' ';
    std::string _Delemiter = " ";
    std::vector<std::string> _VectorOfWords;
    std::string _ArrayOfWords[_MaxSize];
    std::string _JoinedString = "";
    std::string _WordToReplace = "";
    std::string _ReplaceTo = "";
    bool _MatchCase = false;
    int _Size = 0;

public:
    clsString();

    clsString(const std::string &Value, const char Character, const char Letter, const std::string &Delemiter, bool MatchCase);

    // Set Property
    // ----------------------------------------------------------------
    void SetValue(const std::string &Value);

    void SetCharacter(const char Character);

    void SetLetter(const char Letter);

    void SetDelemiter(const std::string &Delemiter);

    void SetMatchCase(bool MatchCase);

    void SetSize(short Size);

    void SetWordToReplace(const std::string &WordToReplace);

    void SetReplaceTo(const std::string &ReplaceTo);
    // ----------------------------------------------------------------

    // Get Property
    // ----------------------------------------------------------------
    std::string Value();
    char Character();
    char Letter();
    std::string Delemiter();
    void PrintTheSplitSentenceWithVector();
    void PrintTheSplitSentenceWithArray();
    std::string JoinedString();
    std::string JoinedStringForVector();
    std::string JoinedStringForArray();
    std::string WordToReplace();
    std::string ReplaceTo();
    bool MatchCase();
    // ----------------------------------------------------------------

    // Static Method
    // -------------------------------------------------------------------------------------------------------------
    static std::string MakeAllStringToLower(const std::string &Word);

    static bool CheckIfStringHasPunctuationsOrSpecialCharacters(const std::string &Word);

    static bool CheckIfStringHasCharacters(const std::string &Word);

    static bool CheckIfStringHasNumbers(const std::string &Word);

    static std::string TrimFromLeft(std::string Word, char CharacterToTrim);

    static std::string TrimFromRight(std::string Word, char CharacterToTrim);

    static std::string TrimStringFromBothSides(std::string Word, char CharacterToTrim);

    static char ConvertLetterToLower(char Character);

    static std::vector<std::string> SplitWordsInSentenceForVector(std::string Word, std::string Delemiter);

    static void SplitWordsInSentenceForArray(std::string Word, std::string ArrayOfString[], std::string Delemiter, int &Size, int MaxSize);

    static std::string JoinStringsWithVector(std::vector<std::string> Words, std::string Delemiter);

    static std::string JoinStringsWithArray(std::string Array[], int LengthOfArray, std::string Delemiter);

    static bool CheckIfStringHasSpecificCharacter(const std::string &String, const char Character);

    static bool CheckIfStringStartsWithSpecificCharacter(const std::string &String, const char Character);

    static bool CheckIfStringEndsWithSpecificCharacter(const std::string &String, const char Character);

    static std::string RemoveSpacesFromString(const std::string &String);

    static bool CheckIfStringHasSpaces(const std::string &String);

    static short Length(const std::string &Word);

    static void PrintFirstLetterFromEachWordInString(const std::string &Word);

    static void MakeEveryFirstLetterOfEachWordCapital(std::string &Sentence);

    static void MakeEveryFirstLetterOfEachWordSmall(std::string &Sentence);

    static void MakeWholeSentenceUpper(std::string &Sentence);

    static void MakeWholeSentenceLower(std::string &Sentence);

    static void ChangeLetterCaseToTheOpssiteCase(char &Character);

    static void MakeTheWholeSentenceToTheOpssiteCase(std::string &Word);

    static int CountCapitalLettersInString(const std::string &Word);

    static int CountSmallLettersInString(const std::string &Word);

    static int CountOfLetterInString(const std::string &Word, const char &CharacterToLookFor);

    static int CountOfLetterInStringWithMatchCase(const std::string &Word, const char &CharacterToLookFor, bool MatchCase = true);

    static bool isVowel(char Character);

    static int CountOfVowelsInString(const std::string &Word);

    static void PrintVowelsInString(const std::string &Word);

    static void PrintEachWordInString(std::string Word);

    static int CountWordsInStirng(std::string Word);

    static std::string ReverseString(std::string Word);

    static std::string ReplaceWordInStirngUsingBuiltInFunction(std::string Word, std::string WordToReplace, std::string ReplaceTo);

    static std::string ChangeWordToUpperCase(std::string Word);

    static std::string ChangeWordToLowerCase(std::string Word);

    static void ReplaceWordsInVector(std::vector<std::string> &Words, std::string WordToReplace, std::string ReplaceTo, bool MatchCase);

    static std::string ReplaceFunctionWithSplitFunction(std::string Word, std::string WordToReplace, std::string ReplaceTo, std::string Delemiter = " ", bool MatchCase = true);

    static std::string RemovePunctuations(std::string Word);
    // -------------------------------------------------------------------------------------------------------------

    // Non Static Method
    // -------------------------------------------------------------------------------------------------------------
    void MakeAllStringToLower();

    bool CheckIfStringHasPunctuationsOrSpecialCharacters();

    bool CheckIfStringHasCharacters();

    bool CheckIfStringHasNumbers();

    void TrimFromLeft();

    void TrimFromRight();

    void TrimStringFromBothSides();

    void ConvertLetterToLower();

    void SplitWordsInSentenceForVector();

    void SplitWordsInSentenceForArray();

    void JoinStringsWithVector();

    void JoinStringsWithArray();

    bool CheckIfStringHasSpecificCharacter();

    bool CheckIfStringStartsWithSpecificCharacter();

    bool CheckIfStringEndsWithSpecificCharacter();

    void RemoveSpacesFromString();

    bool CheckIfStringHasSpaces();

    short Length();

    void PrintFirstLetterFromEachWordInString();

    void MakeEveryFirstLetterOfEachWordCapital();

    void MakeEveryFirstLetterOfEachWordSmall();

    void MakeWholeSentenceUpper();

    void MakeWholeSentenceLower();

    void ChangeLetterCaseToTheOpssiteCase();

    void MakeTheWholeSentenceToTheOpssiteCase();

    int CountCapitalLettersInString();

    int CountSmallLettersInString();

    int CountOfLetterInString();

    int CountOfLetterInStringWithMatchCase();

    bool isVowel();

    int CountOfVowelsInString();

    void PrintVowelsInString();

    void PrintEachWordInString();

    int CountWordsInStirng();

    void ReverseString();

    void ReplaceWordInStirngUsingBuiltInFunction();

    void ChangeWordToUpperCase();

    void ChangeWordToLowerCase();

    void ReplaceWordsInVector();

    void ReplaceFunctionWithSplitFunction();

    void RemovePunctuations();
    // -------------------------------------------------------------------------------------------------------------
};