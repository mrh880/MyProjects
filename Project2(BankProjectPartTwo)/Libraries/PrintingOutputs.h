// printingOutputs.h

#pragma once

#include <string>
#include <vector>
#include "Structures.h"

namespace PrintingText
{
    void PrintTextOnScreen(const std::string &Text);

    void PrintLines(short NumberOfLines = 1);

    void PrintTabs(short NumberOfTabs);

    void PrintSpaces(short NumberOfSpaces);

    void PrintSequenceOfCharacters(char Character, short TimeToRepeat);

    void PrintCharacters(char Character);
}

namespace PrintNumbers
{
    void printShortNumber(short Number);

    void PrintIntegerNumber(int Number);

    void PrintFloatNumber(float Number);

    void PrintDoubleNumber(double Number);

}

namespace PrintStructures
{
    void PrintClientInfo(const stClientInfo &ClientInfo);

    void CustomPrintClientInfo(stClientInfo &ClientInfo, int NumberOfCurrentClinets);

    void CustomPrintClientsInfo(std::vector<stClientInfo> &ClientInfo);

    void PrintClientsInfoList(std::string FileName);

}