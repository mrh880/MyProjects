#include "DeposingScreen.h"

#include "Libraries\PrintingOutputs.h"
#include "Libraries\ClientsDataStorage.h"
#include "Libraries\ReadingInputs.h"
#include "Libraries\DealingWithBuffer.h"
#include "Libraries\validingData.h"

#include <string>
#include <vector>

using namespace std;

void DepositClientBalance(const string &FileName, stClientInfo &ClientInfo)
{
    short NumberOfCharacters = 50;

    PrintingText::PrintHeader(NumberOfCharacters, "!!!! DEPOSIT SCREEN !!!!");

    vector<stClientInfo> ClientsInfo;

    LoadClientInfoFromFileAndStoreThenIntoVector(FileName, ClientsInfo);

    PrintingText::PrintLines();

    PrintStructures::PrintClientInfo(ClientInfo, NumberOfCharacters);

    long double AmountToDepose = 0;
    ValidingClientsData::ValidBalanceForDeposing(ClientInfo.AccountBalance, AmountToDepose, NumberOfCharacters);

    PrintingText::PrintLines();

    char Answer = 'n';

    Answer = ReadText::ReadingAnswer(NumberOfCharacters, AmountToDepose, "Do you want to with depose");

    if (Answer == 'y')
    {
        // PrintingText::PrintLines();

        DepositClientBalance(ClientInfo, AmountToDepose);

        UpdateClientInfo(ClientsInfo, ClientInfo.AccountNumber, ClientInfo);

        SaveClientsDataToFile(FileName, ClientsInfo);

        PrintingText::PrintLines();

        PrintStructures::PrintClientsBalance(ClientInfo, NumberOfCharacters);
    }
    PrintingText::PrintLines();
}