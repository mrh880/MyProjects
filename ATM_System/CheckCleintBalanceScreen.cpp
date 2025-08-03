#include "CheckClientBalanceScreen.h"

#include "Libraries\ClientsDataStorage.h"
#include "Libraries\Structures.h"
#include "Libraries\ReadingInputs.h"
#include "Libraries\PrintingOutputs.h"
#include "Libraries\DealingWithBuffer.h"

#include <string>
#include <vector>

using namespace std;

void PrintclientBalance(const string &FileName, stClientInfo &ClientInfo)
{
    short NumberOfCharacters = 40;

    PrintingText::PrintHeader(NumberOfCharacters, "!!!! PRINTING CLIENT BALANCE !!!!");

    vector<stClientInfo> ClientsInfo;

    LoadClientInfoFromFileAndStoreThenIntoVector(FileName, ClientsInfo);

    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen("Your balance is =>> ");
    PrintNumbers::PrintLongDoubleNumber(ClientInfo.AccountBalance);
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
    PrintingText::PrintLines(2);

    FlushInputBuffer();
}