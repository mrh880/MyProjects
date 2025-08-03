#include "NormalWithdrawScreen.h"

#include "Libraries\PrintingOutputs.h"
#include "Libraries\ClientsDataStorage.h"
#include "Libraries\ReadingInputs.h"
#include "Libraries\DealingWithBuffer.h"
#include "Libraries\validingData.h"
#include "Libraries\DealingWithBuffer.h"

#include <string>
#include <vector>

using namespace std;
#include <iostream>
#include <unistd.h>

void PerformNormalWithdraw(const string &FileName, stClientInfo &ClientInfo)
{
    short NumberOfCharacters = 90;

    vector<stClientInfo> ClientsInfo;

    LoadClientInfoFromFileAndStoreThenIntoVector(FileName, ClientsInfo); // load clients data from the file or database

    PrintingText::PrintLines();

    PrintStructures::PrintClientInfo(ClientInfo, NumberOfCharacters); // print current client data

    long double AmountToWithdraw = 0;

    if (ClientInfo.AccountBalance <= 0)
    {
        PrintingText::PrintTextOnScreen("Your account balance is zero, you can not withdraw");
        PrintingText::PrintLines(2);
        FlushInputBuffer();
        return; // Stop the function here
    }
    else if (AmountToWithdraw > ClientInfo.AccountBalance)
    {
        PrintingText::PrintTextOnScreen("Amount is greater than your balance");
        PrintingText::PrintLines(2);
        FlushInputBuffer();
        return; // Stop the function here
    }


    ValidingClientsData::ValidBalanceToWithdraw(ClientInfo.AccountBalance, AmountToWithdraw, NumberOfCharacters, "Enter an amount multiple of 5's: ");

    PrintingText::PrintLines();

    char Answer = 'n';

    Answer = ReadText::ReadingAnswer(NumberOfCharacters, AmountToWithdraw, "Do you want to with draw");

    // FlushInputBuffer();

    if (Answer == 'y')
    {
        // PrintingText::PrintLines();

        WithDrawClientBalance(ClientInfo, AmountToWithdraw);

        UpdateClientInfo(ClientsInfo, ClientInfo.AccountNumber, ClientInfo);

        SaveClientsDataToFile(FileName, ClientsInfo);

        PrintingText::PrintLines();

        PrintStructures::PrintClientsBalance(ClientInfo, NumberOfCharacters);
    }
    PrintingText::PrintLines(1);

}

void NormalWithdraw(const string &FileName, stClientInfo &ClientInfo)
{
    short NumberOfCharacters = 90;
    PrintingText::PrintHeader(NumberOfCharacters, "!!!! NORMAL WITHDRAW !!!!");
    PerformNormalWithdraw(FileName, ClientInfo);
}