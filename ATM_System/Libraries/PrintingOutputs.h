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

namespace PrintStructures
{
    void PrintClientInfo(const stClientInfo &ClientInfo, short NumberOfCharacters);

    void CustomPrintClientInfo(stClientInfo &ClientInfo, int NumberOfCurrentClinets);

    void CustomPrintClientsInfo(std::vector<stClientInfo> &ClientInfo);

    void PrintClientsInfoList(std::string FileName);

    void PrintClientInfoWasNotFound(stClientInfo, short NumberOfCharacters, const std::string &Message = "");

    void PrintHeaderOfUserInfoTable();

    void PrintUserInfo(stUserInfo &UserInfo, int NumberOfUsers);

    void PrintUserInfo(stUserInfo &UserInfo);

    void PrintUsersInfo(std::vector<stUserInfo> &UsersInfo);

    void PrintClientsBalance(stClientInfo &ClientInfo, short NumberOfCharacters);

}