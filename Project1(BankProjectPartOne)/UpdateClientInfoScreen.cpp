#include "UpdateClientInfoScreen.h"

#include <vector>
#include <string>

#include "Libraries\Structures.h"
#include "Libraries\ClientsDataStorage.h"
#include "Libraries\PrintingOutputs.h"
#include "Libraries\ReadingInputs.h"
#include "Libraries\DealingWithStrings.h"

using  namespace std;

void UpdateClientByAccountNumber(const string &FileName, const string &AccountNumber)
{
    vector<stClientInfo> ClientsInfo;

     // load all the clients in vector as structures
    LoadClientInfoFromFileAndStoreThenIntoVector(FileName, ClientsInfo); 
   

    stClientInfo client_info; // to save the clients inof to replace with the old client info
    char Answer = 'n';

    if (DoesClientExists(ClientsInfo, AccountNumber, client_info))
    {
        PrintStructures::PrintClientInfo(client_info);
        
        Answer = ReadText::ReadCharacter("Do you want to update this client info [Y/N]: ");

        if (CovertLetterToLower(Answer) == 'y')
        {
            ReadingStructures::ReadClientInfoWithoutAccountNumber(client_info);
            UpdateClientInfo(ClientsInfo, AccountNumber, client_info);
            SaveClientsDataToFile(FileName, ClientsInfo, AccountNumber);
            PrintingText::PrintTextOnScreen("Clients info has beed updated !");
            PrintingText::PrintLines();
        }
    }
    else
    {
        PrintingText::PrintTextOnScreen("Clients was not found !\n");
        PrintingText::PrintLines();
    }
}