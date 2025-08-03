#include "DeleteClientScreen.h"

#include <string>
#include <vector>

#include "Libraries/ClientsDataStorage.h"
#include "Libraries/PrintingOutputs.h"
#include "Libraries/ReadingInputs.h"
#include "Libraries/DealingWithStrings.h"
#include "Libraries/ClientsDataStorage.h"

using namespace std;


void DeleteClientByAccountNumber(const string &FileName)
{

    string AccountNumber = "";
    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen("!!!!!! Delete CLIENT INFO !!!!!!");
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();
    
    std::vector<stClientInfo> ClientsInof;
    LoadClientInfoFromFileAndStoreThenIntoVector(FileName, ClientsInof);

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();
    AccountNumber = ReadText::ReadTextOnScreen("Enter an account number: ");
    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines(2);

    stClientInfo client_info;
    char Answer = 'n';
    

    if (DoesClientExists(ClientsInof, AccountNumber, client_info))
    {
        PrintStructures::PrintClientInfo(client_info);
        Answer = ReadText::ReadCharacter("Do you want to delete this client[Y/N]: ");
        if (CovertLetterToLower(Answer) == 'y')
        {
            SaveClientsDataToFileWithoutSpecificClientAccountNumber(FileName, ClientsInof, AccountNumber);
            PrintingText::PrintTextOnScreen("Clients have been deleted !\n");
        }
    }
    else
        PrintingText::PrintTextOnScreen("Clients was not found !\n");
}