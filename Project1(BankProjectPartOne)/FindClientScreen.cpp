#include "FindClientScreen.h"


#include <string>
#include <vector>

#include "Libraries/Structures.h"
#include "Libraries/ClientsDataStorage.h"
#include "Libraries/PrintingOutputs.h"

using namespace std;


void PrintingClientInfoByAccountNumber(const string FileName, const string &AccountNumber)
{
    vector<stClientInfo> ClientsInfo;
    LoadClientInfoFromFileAndStoreThenIntoVector(FileName, ClientsInfo);
    stClientInfo ClientInfo;
    if (DoesClientExists(ClientsInfo, AccountNumber, ClientInfo))
        PrintStructures::PrintClientInfo(ClientInfo);
    else
        PrintingText::PrintTextOnScreen("Client not found");
}