#include "QuickWithdrawScreen.h"

#include "Libraries\PrintingOutputs.h"
#include "Libraries\ReadingInputs.h"
#include "Libraries\validingData.h"
#include "Libraries\ClientsDataStorage.h"
#include "Libraries\DealingWithStrings.h"
#include "Libraries\DealingWithBuffer.h"

#include <string>
#include <string>
#include <limits>
#include <iostream>

using namespace std;

void PrintMenuOfQuickWithdraw(short NumberOfCharacters)
{

    short Amounts[8] = {20, 50, 100, 200, 400, 600, 800, 1000};

    short Counter = 0;
    for (short loop = 1; loop <= 8; loop++)
    {
        Counter = loop - 1;

        if (loop % 2 == 1 && loop > 1)
        {
            PrintingText::PrintLines();
        }

        PrintingText::PrintTabs(1);
        PrintingText::PrintCharacters('[');
        PrintNumbers::printShortNumber(loop);
        PrintingText::PrintCharacters(']');
        PrintingText::PrintSpaces(1);
        PrintNumbers::printShortNumber(Amounts[Counter]);
        PrintingText::PrintSpaces(2);
    }

    PrintingText::PrintLines();
    PrintingText::PrintTabs(1);
    PrintingText::PrintCharacters('[');
    PrintNumbers::printShortNumber(9);
    PrintingText::PrintCharacters(']');
    PrintingText::PrintSpaces(1);
    PrintingText::PrintTextOnScreen("Exit");
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
    PrintingText::PrintLines();
}

short GetAmountOfQuickWithDraw(short Number)
{
    switch (Number)
    {
    case 1:
        return 20;
    case 2:
        return 50;
    case 3:
        return 100;
    case 4:
        return 200;
    case 5:
        return 400;
    case 6:
        return 600;
    case 7:
        return 800;
    case 8:
        return 1000;
    default:
        return 0;
    }
    return 0;
}

void PerformQuickWithdraw(const string &FileName, stClientInfo &ClientInfo)
{
    double NumberOfCharacters = 50;

    short AmountToWithdraw = GetAmountOfQuickWithDraw(ReadNumbers::ReadUserChoice(1, 9, NumberOfCharacters));

    if (AmountToWithdraw == 0)
    {
        PrintingText::PrintLines();
        FlushInputBuffer();
        return;
    }

    vector<stClientInfo> ClientsInfo;

    LoadClientInfoFromFileAndStoreThenIntoVector(FileName, ClientsInfo);

    PrintingText::PrintLines();

    PrintStructures::PrintClientInfo(ClientInfo, NumberOfCharacters);

    if (ClientInfo.AccountBalance <= 0)
    {
        PrintingText::PrintTextOnScreen("Your account balance is zero, you can not withdraw");
        PrintingText::PrintLines(2);
        FlushInputBuffer();
        return; // Stop the function here
    }
    else if (AmountToWithdraw > (int)ClientInfo.AccountBalance)
    {
        PrintingText::PrintTextOnScreen("Amount is greater than your balance");
        PrintingText::PrintLines(2);
        FlushInputBuffer();
        return; // Stop the function here
    }

    char Answer = 'n';

    Answer = ReadText::ReadingAnswer(NumberOfCharacters, AmountToWithdraw, "Do you want to with draw");

    if (Answer == 'y')
    {
        WithDrawClientBalance(ClientInfo, AmountToWithdraw);

        UpdateClientInfo(ClientsInfo, ClientInfo.AccountNumber, ClientInfo);

        SaveClientsDataToFile(FileName, ClientsInfo);

        PrintingText::PrintLines();

        PrintStructures::PrintClientsBalance(ClientInfo, NumberOfCharacters);
    }

    PrintingText::PrintLines();
}

void QuickWithDraw(const string &FileName, stClientInfo &ClientInfo)
{
    short NumberOfCharacters = 50;
    PrintingText::PrintHeader(NumberOfCharacters, "!!!!!! QUICK WITHDRAW !!!!!!");
    PrintMenuOfQuickWithdraw(NumberOfCharacters);
    PerformQuickWithdraw(FileName, ClientInfo);
}