// printingOutputs.h

#pragma once

#include <string>
#include <vector>

namespace PrintingText
{
    void PrintTextOnScreen(const std::string &Text);

    void PrintLines(short NumberOfLines = 1);

    void PrintTabs(short NumberOfTabs);

    void PrintSpaces(short NumberOfSpaces);

    void PrintSequenceOfCharacters(char Character, short TimeToRepeat);

    void PrintCharacters(char Character);

    void PrintHeader(short NumberOfCharacters, const std::string &Title);
}

namespace PrintNumbers
{
    void printShortNumber(short Number);

    void PrintIntegerNumber(int Number);

    void PrintFloatNumber(float Number);

    void PrintDoubleNumber(double Number);

    void PrintLongDoubleNumber(long double Number);

}

