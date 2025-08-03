#include "clsString.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

clsString::clsString()
{
    _Value = "";
}

clsString::clsString(const string &Value, const char Character, const char Letter, const string &Delemiter, bool MatchCase)
{
    _Value = Value;
    _Character = Character;
    _Letter = Letter;
    _Delemiter = Delemiter;
    _MatchCase = MatchCase;
}

// Set Property
// ----------------------------------------------------------------
void clsString::SetValue(const string &Value)
{
    _Value = Value;
}

void clsString::SetCharacter(const char Character)
{
    _Character = Character;
}

void clsString::SetLetter(const char Letter)
{
    _Letter = Letter;
}

void clsString::SetDelemiter(const std::string &Delemiter)
{
    _Delemiter = Delemiter;
}

void clsString::SetMatchCase(bool MatchCase)
{
    _MatchCase = MatchCase;
}

void clsString::SetSize(short Size)
{
    _Size = Size;
}

void clsString::SetWordToReplace(const string &WordToReplace)
{
    _WordToReplace = WordToReplace;
}

void clsString::SetReplaceTo(const string &ReplaceTo)
{
    _ReplaceTo = ReplaceTo;
}
// ----------------------------------------------------------------

// Get Property
// ----------------------------------------------------------------
string clsString::Value()
{
    return _Value;
}

char clsString::Character()
{
    return _Character;
}

char clsString::Letter()
{
    return _Letter;
}

string clsString::Delemiter()
{
    return _Delemiter;
}

void clsString::PrintTheSplitSentenceWithVector()
{
    cout << "The words you enter after we split it is:\n";
    for (const string &CurentWord : _VectorOfWords)
    {
        cout << CurentWord << " ";
    }
    cout << endl;
}

void clsString::PrintTheSplitSentenceWithArray()
{
    cout << "The words your entered after we split it is:\n";
    for (short loop = 0; loop < _Size; loop++)
    {
        cout << _ArrayOfWords[loop] << " ";
    }
    cout << endl;
}

string clsString::JoinedString()
{
    return _JoinedString;
}

std::string clsString::JoinedStringForVector()
{
    return JoinStringsWithVector(_VectorOfWords, _Delemiter);
}

string clsString::JoinedStringForArray()
{
    return JoinStringsWithArray(_ArrayOfWords, _Size, _Delemiter);
}

bool clsString::MatchCase()
{
    return _MatchCase;
}
// ----------------------------------------------------------------

// Static Method
// -------------------------------------------------------------------------------------------------------------------------------
string clsString::MakeAllStringToLower(const string &Word)
{
    std::string Result = "";
    for (const char &Character : Word)
        Result += tolower(Character);
    return Result;
}

bool clsString::CheckIfStringHasPunctuationsOrSpecialCharacters(const string &Word)
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

bool clsString::CheckIfStringHasCharacters(const string &Word)
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

bool clsString::CheckIfStringHasNumbers(const string &Word)
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

string clsString::TrimFromLeft(string Word, char CharacterToTrim)
{
    short LengthOfWord = Word.length();
    for (short Loop = 0; Loop < LengthOfWord; Loop++)
    {
        if (Word[Loop] != CharacterToTrim)
            return Word.substr(Loop);
    }
    return "";
}

string clsString::TrimFromRight(string Word, char CharacterToTrim)
{
    short LengthOfWord = Word.length();
    for (short Loop = LengthOfWord - 1; Loop >= 0; Loop--)
    {
        if (Word[Loop] != CharacterToTrim)
            return Word.substr(0, Loop + 1);
    }
    return "";
}

string clsString::TrimStringFromBothSides(string Word, char CharacterToTrim)
{
    return TrimFromLeft(TrimFromRight(Word, CharacterToTrim), CharacterToTrim);
}

char clsString::ConvertLetterToLower(char Character)
{
    return tolower(Character);
}

vector<string> clsString::SplitWordsInSentenceForVector(std::string Word, std::string Delemiter)
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

void clsString::SplitWordsInSentenceForArray(std::string Word, std::string ArrayOfStrings[], std::string Delemiter, int &Size, int MaxSize)
{
    int LengthOfDelemiter = Delemiter.length();
    int Position = 0;
    int Counter = 0;

    while ((Position = Word.find(Delemiter)) != std::string::npos && Counter < MaxSize)
    {
        std::string TempWord = Word.substr(0, Position);
        if (!TempWord.empty())
        {
            ArrayOfStrings[Counter++] = TempWord;
        }
        Word.erase(0, Position + LengthOfDelemiter);
    }

    if (!Word.empty() && Counter < Size)
    {
        ArrayOfStrings[Counter++] = Word;
    }

    Size = Counter;

    if (Size == 0)
    {
        cout << "Your array is empty :(\n";
    }
}

string clsString::JoinStringsWithVector(std::vector<std::string> Words, std::string Delemiter)
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

string clsString::JoinStringsWithArray(string Array[], int LengthOfArray, string Delemiter)
{
    string JoinedString = "";
    for (int Loop = 0; Loop < LengthOfArray; Loop++)
    {
        JoinedString += Array[Loop];
        if (Loop != LengthOfArray - 1)
            JoinedString += Delemiter;
    }
    return JoinedString;
}

bool clsString::CheckIfStringHasSpecificCharacter(const string &String, const char Character)
{
    for (const char &CurrentCharacter : String)
    {
        if (CurrentCharacter == Character)
        {
            return true;
        }
    }
    return false;
}

bool clsString::CheckIfStringStartsWithSpecificCharacter(const string &String, const char Character)
{
    if (String.empty())
    {
        return false;
    }
    return String[0] == Character;
}

bool clsString::CheckIfStringEndsWithSpecificCharacter(const std::string &String, const char Character)
{
    if (String.empty())
    {
        return false;
    }

    short LengthOfString = String.length();
    return String[LengthOfString - 1] == Character;
}

string clsString::RemoveSpacesFromString(const string &String)
{
    string Result = "";

    for (const char &CurrentCharacter : String)
    {
        if (CurrentCharacter != ' ')
        {
            Result += CurrentCharacter;
        }
    }
    return Result;
}

bool clsString::CheckIfStringHasSpaces(const std::string &String)
{
    for (const char &CurrentCharacter : String)
    {
        if (CurrentCharacter == ' ')
        {
            return true;
        }
    }
    return false;
}

short clsString::Length(const string &Word)
{
    return Word.length();
}

void clsString::PrintFirstLetterFromEachWordInString(const string &Word)
{
    bool FirstLetterWasFound = false;

    for (const char &Character : Word)
    {
        if (Character != ' ' && !FirstLetterWasFound)
        {
            cout << Character << " ";
            FirstLetterWasFound = true;
        }
        else
        {
            if (Character == ' ' && FirstLetterWasFound)
                FirstLetterWasFound = false;
        }
    }
}

void clsString::MakeEveryFirstLetterOfEachWordCapital(string &Sentence)
{
    bool FirstLetterWasFound = false;
    for (char &Character : Sentence)
    {
        if (Character != ' ' && !FirstLetterWasFound)
        {
            Character = toupper(Character);
            FirstLetterWasFound = true;
        }
        else
        {
            if (Character == ' ' && FirstLetterWasFound)
                FirstLetterWasFound = false;
        }
    }
}

void clsString::MakeEveryFirstLetterOfEachWordSmall(string &Sentence)
{
    bool FirstLetterWasFound = false;
    for (char &Character : Sentence)
    {
        if (Character != ' ' && !FirstLetterWasFound)
        {
            Character = tolower(Character);
            FirstLetterWasFound = true;
        }
        else
        {
            if (Character == ' ' && FirstLetterWasFound)
                FirstLetterWasFound = false;
        }
    }
}

void clsString::MakeWholeSentenceUpper(string &Sentence)
{
    for (char &Character : Sentence)
        Character = toupper(Character);
}

void clsString::MakeWholeSentenceLower(string &Sentence)
{
    for (char &Character : Sentence)
        Character = tolower(Character);
}

void clsString::ChangeLetterCaseToTheOpssiteCase(char &Character)
{
    Character = isupper(Character) ? tolower(Character) : toupper(Character);
}

void clsString::MakeTheWholeSentenceToTheOpssiteCase(string &Sentence)
{
    for (char &Character : Sentence)
        ChangeLetterCaseToTheOpssiteCase(Character);
}

int clsString::CountCapitalLettersInString(const string &Word)
{
    int Counter = 0;
    for (const char &Character : Word)
    {
        if (isupper(Character))
            Counter++;
    }
    return Counter;
}

int clsString::CountSmallLettersInString(const string &Word)
{
    int Counter = 0;
    for (const char &Character : Word)
    {
        if (islower(Character))
            Counter++;
    }
    return Counter;
}

int clsString::CountOfLetterInString(const string &Word, const char &CharacterToLookFor)
{
    int Counter = 0;
    for (const char &CurrentCharacter : Word)
    {
        if (CurrentCharacter == CharacterToLookFor)
            Counter++;
    }
    return Counter;
}

int clsString::CountOfLetterInStringWithMatchCase(const string &Word, const char &CharacterToLookFor, bool MatchCase)
{
    int Counter = 0;
    for (const char &CurrentCharacter : Word)
    {

        if (MatchCase) // if you do not care about letter case !
        {
            if (CurrentCharacter == CharacterToLookFor)
                Counter++;
        }
        else
        {
            if (tolower(CurrentCharacter) == tolower(CharacterToLookFor))
                Counter++;
        }
    }
    return Counter;
}

bool clsString::isVowel(char Character)
{
    Character = tolower(Character);
    return (Character == 'a' || Character == 'e' || Character == 'i' || Character == 'o' || Character == 'u');
}

int clsString::CountOfVowelsInString(const string &Word)
{
    int Counter = 0;
    for (const char &Character : Word)
    {
        if (isVowel(Character))
            Counter++;
    }
    return Counter;
}

void clsString::PrintVowelsInString(const string &Word)
{
    int LengthOfWord = Word.length();
    for (int Loop = 0; Loop < LengthOfWord; Loop++)
    {
        if (isVowel(tolower(Word[Loop])))
        {
            if (Loop != LengthOfWord - 1)
                cout << Word[Loop] << " ";
            else
                cout << Word[Loop];
        }
    }
}

void clsString::PrintEachWordInString(string Word)
{
    string Delimiter = " ";
    int Position = 0;
    string TempWord = "";

    while ((Position = Word.find(Delimiter)) != string::npos)
    {
        TempWord = Word.substr(0, Position);
        if (!TempWord.empty())
            cout << TempWord << endl;
        Word.erase(0, Position + Delimiter.length());
    }

    if (!Word.empty())
        cout << Word;
}

int clsString::CountWordsInStirng(string Word)
{
    string Delemiter = " ";
    int Position = 0;
    string TempWord = "";
    int Counter = 0;

    while ((Position = Word.find(Delemiter)) != string::npos)
    {
        TempWord = Word.substr(0, Position);
        if (!Word.empty())
            Counter++;
        Word.erase(0, Position + Delemiter.length());
    }

    if (!Word.empty())
        Counter++;
    return Counter;
}

string clsString::ReverseString(string Word) //
{
    vector<string> TempString;
    TempString = SplitWordsInSentenceForVector(Word, " ");

    short LengthOfTempStirng = TempString.size();
    string FinalResult = "";

    for (short Loop = LengthOfTempStirng - 1; Loop >= 0; Loop--)
    {
        FinalResult += TempString[Loop];
        if (Loop != 0)
            FinalResult += " ";
    }
    return FinalResult;
}

string clsString::ReplaceWordInStirngUsingBuiltInFunction(string Word, string WordToReplace, string ReplaceTo)
{
    short Position = Word.find(WordToReplace);
    short LengthOfWordToReplace = WordToReplace.length();
    while (Position != string::npos)
    {
        Word = Word.replace(Position, LengthOfWordToReplace, ReplaceTo);
        Position = Word.find(WordToReplace);
    }
    return Word;
}

string ChangeWordToUpperCase(string Word)
{
    for (char &Character : Word)
        Character = toupper(Character);
    return Word;
}
string clsString::ChangeWordToUpperCase(string Word)
{

    for (char &CurrentCharacter : Word)
    {
        CurrentCharacter = toupper(CurrentCharacter);
    }
    return Word;
}

string clsString::ChangeWordToLowerCase(string Word)
{
    for (char &CurrentCharacter : Word)
    {
        CurrentCharacter = tolower(CurrentCharacter);
    }
    return Word;
}

void clsString::ReplaceWordsInVector(vector<string> &Words, string WordToReplace, string ReplaceTo, bool MatchCase)
{
    for (string &Word : Words)
    {
        if (MatchCase)
        {
            if (Word == WordToReplace)
                Word = ReplaceTo;
        }
        else
        {
            if (ChangeWordToUpperCase(Word) == ChangeWordToUpperCase(WordToReplace))
                Word = ReplaceTo;
        }
    }
}

string clsString::ReplaceFunctionWithSplitFunction(string Word, string WordToReplace, string ReplaceTo, string Delemiter, bool MatchCase)
{
    vector<string> TempVector;
    TempVector = SplitWordsInSentenceForVector(Word, Delemiter);                 // store the word after split them
    ReplaceWordsInVector(TempVector, WordToReplace, ReplaceTo, MatchCase); // Replace the word with the word to replace with
    string Result = JoinStringsWithVector(TempVector, Delemiter);                // To store the word after it was replaced
    return Result;                                                         // no need to tell this just return the sentence after it was replaced
}

string clsString::RemovePunctuations(string Word)
{
    string Result = "";
    for (char &Character : Word)
        if (!ispunct(Character))
            Result += Character;
    return Result;
}
// -------------------------------------------------------------------------------------------------------------------------------

// Non Static Method
// -------------------------------------------------------------------------------------------------------------------------------

void clsString::MakeAllStringToLower()
{
    _Value = MakeAllStringToLower(_Value);
}

bool clsString::CheckIfStringHasPunctuationsOrSpecialCharacters()
{
    return CheckIfStringHasPunctuationsOrSpecialCharacters(_Value);
}

bool clsString::CheckIfStringHasCharacters()
{
    return CheckIfStringHasCharacters(_Value);
}

bool clsString::CheckIfStringHasNumbers()
{
    return CheckIfStringHasNumbers(_Value);
}

void clsString::TrimFromLeft()
{
    _Value = TrimFromLeft(_Value, _Character);
}

void clsString::TrimFromRight()
{
    _Value = TrimFromRight(_Value, _Character);
}

void clsString::TrimStringFromBothSides()
{
    _Value = TrimStringFromBothSides(_Value, _Character);
}

void clsString::ConvertLetterToLower()
{
    _Letter = ConvertLetterToLower(_Letter);
}

void clsString::SplitWordsInSentenceForVector()
{
    _VectorOfWords = SplitWordsInSentenceForVector(_Value, _Delemiter);
}

void clsString::SplitWordsInSentenceForArray()
{
    _Size = _MaxSize; // ← allow max capacity first

    SplitWordsInSentenceForArray(_Value, _ArrayOfWords, _Delemiter, _Size, _MaxSize);
}

void clsString::JoinStringsWithVector()
{
    _JoinedString = JoinStringsWithVector(_VectorOfWords, _Delemiter);
}

void clsString::JoinStringsWithArray()
{
    _JoinedString = JoinStringsWithArray(_ArrayOfWords, _Size, _Delemiter);
}
bool clsString::CheckIfStringHasSpecificCharacter()
{
    return CheckIfStringHasSpecificCharacter(_Value, _Character);
}

bool clsString::CheckIfStringStartsWithSpecificCharacter()
{
    return CheckIfStringStartsWithSpecificCharacter(_Value, _Character);
}

bool clsString::CheckIfStringEndsWithSpecificCharacter()
{
    return CheckIfStringEndsWithSpecificCharacter(_Value, _Character);
}

void clsString::RemoveSpacesFromString()
{
    _Value = RemoveSpacesFromString(_Value);
}

bool clsString::CheckIfStringHasSpaces()
{
    return CheckIfStringHasSpaces(_Value);
}

short clsString::Length()
{
    return Length(_Value);
}

void clsString::PrintFirstLetterFromEachWordInString()
{
    PrintFirstLetterFromEachWordInString(_Value);
}

void clsString::MakeEveryFirstLetterOfEachWordCapital()
{
    // _Value = StaticMakeEveryFirstLetterOfEachWordCapital(_Value);
    MakeEveryFirstLetterOfEachWordCapital(_Value);
}

void clsString::MakeEveryFirstLetterOfEachWordSmall()
{
    MakeEveryFirstLetterOfEachWordSmall(_Value);
}

void clsString::MakeWholeSentenceUpper()
{
    MakeWholeSentenceUpper(_Value);
}

void clsString::MakeWholeSentenceLower()
{
    MakeWholeSentenceLower(_Value);
}

void clsString::ChangeLetterCaseToTheOpssiteCase()
{
    ChangeLetterCaseToTheOpssiteCase(_Letter);
}

void clsString::MakeTheWholeSentenceToTheOpssiteCase()
{
    MakeTheWholeSentenceToTheOpssiteCase(_Value);
}

int clsString::CountCapitalLettersInString()
{
    return CountCapitalLettersInString(_Value);
}

int clsString::CountSmallLettersInString()
{
    return CountSmallLettersInString(_Value);
}

int clsString::CountOfLetterInString()
{
    return CountOfLetterInString(_Value, _Character);
}

int clsString::CountOfLetterInStringWithMatchCase()
{
    return CountOfLetterInStringWithMatchCase(_Value, _Character, _MatchCase);
}

bool clsString::isVowel()
{
    return isVowel(_Character);
}

int clsString::CountOfVowelsInString()
{
    return CountOfVowelsInString(_Value);
}

void clsString::PrintVowelsInString()
{
    PrintVowelsInString(_Value);
}

void clsString::PrintEachWordInString()
{
    PrintEachWordInString(_Value);
}

int clsString::CountWordsInStirng()
{
    return CountWordsInStirng(_Value);
}

void clsString::ReverseString()
{
    _Value = ReverseString(_Value);
}

void clsString::ReplaceWordInStirngUsingBuiltInFunction()
{
    _Value = ReplaceWordInStirngUsingBuiltInFunction(_Value, _WordToReplace, _ReplaceTo);
}

void clsString::ChangeWordToUpperCase()
{
    _Value = ChangeWordToUpperCase(_Value);
}

void clsString::ChangeWordToLowerCase()
{
    _Value = ChangeWordToLowerCase(_Value);
}

void clsString::ReplaceWordsInVector()
{
    ReplaceWordsInVector(_VectorOfWords, _WordToReplace, _ReplaceTo, _MatchCase);
}

void clsString::ReplaceFunctionWithSplitFunction()
{
    _JoinedString = ReplaceFunctionWithSplitFunction(_Value, _WordToReplace, _ReplaceTo, _Delemiter, _MatchCase);
}

void clsString::RemovePunctuations()
{
    _Value = RemovePunctuations(_Value);
}
// -------------------------------------------------------------------------------------------------------------------------------
