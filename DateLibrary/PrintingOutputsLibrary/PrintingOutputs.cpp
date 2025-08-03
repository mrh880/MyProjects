#include "PrintingOutputs.h"

#include <iostream>

using namespace std;

namespace PrintingText
{
    void PrintTextOnScreen(const std::string &Text)
    {
        if (!Text.empty())
            cout << Text;
    }

    void PrintLines(short NumberOfLines)
    {
        for (short Lines = 0; Lines < NumberOfLines; Lines++)
            cout << endl;
    }

    void PrintTabs(short NumberOfTabs)
    {
        for (short Tabs = 0; Tabs < NumberOfTabs; Tabs++)
            cout << '\t';
    }

    void PrintSpaces(short NumberOfSpaces)
    {
        for (short Spaces = 0; Spaces < NumberOfSpaces; Spaces++)
            cout << ' ';
    }

    void PrintSequenceOfCharacters(char Character, short TimeToRepeat)
    {
        for (short Reapeat = 0; Reapeat < TimeToRepeat; Reapeat++)
            cout << Character;
    }

    void PrintCharacters(char Character)
    {
        cout << Character;
    }

    void PrintHeader(short NumberOfCharacters, const string &Title)
    {
        PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
        PrintingText::PrintLines();
        PrintingText::PrintSpaces((NumberOfCharacters - Title.length()) / 2);
        PrintingText::PrintTextOnScreen(Title);
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
        PrintingText::PrintLines();
    }
}

namespace PrintNumbers
{
    void printShortNumber(short Number)
    {
        cout << Number;
    }

    void PrintIntegerNumber(int Number)
    {
        cout << Number;
    }

    void PrintFloatNumber(float Number)
    {
        cout << Number;
    }

    void PrintDoubleNumber(double Number)
    {
        cout << Number;
    }

    void PrintLongDoubleNumber(long double Number)
    {
        cout << Number;
    }

}

