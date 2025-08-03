#include "FindClientScreen.h"

#include "Libraries\ReadingInputs.h"
#include <string>
#include <vector>

#include "Libraries\Structures.h"
#include "Libraries\ClientsDataStorage.h"
#include "Libraries\PrintingOutputs.h"
#include "CheckUserPermission.h"

using namespace std;

void PrintingClientInfoByAccountNumber(const string FileName, int UserPermission)
{
    if (!CheckIfUserHasAccessToFindClient(UserPermission))
    {
        return;
    }

    vector<stClientInfo> ClientsInfo;
    LoadClientInfoFromFileAndStoreThenIntoVector(FileName, ClientsInfo);

    string AccountNumber = ReadText::ReadTextOnScreen("Enter an account number: ");

    stClientInfo ClientInfo;
    if (DoesClientExists(ClientsInfo, AccountNumber, ClientInfo))
        PrintStructures::PrintClientInfo(ClientInfo);
    else
        PrintingText::PrintTextOnScreen("Client not found\n");
}