#include "DepositScreenScreen.h"

#include <vector>

using namespace std;

#include "Libraries\PrintingOutputs.h"
#include "Libraries\ClientsDataStorage.h"
#include "Libraries\ReadingInputs.h"
#include "Libraries\Enums.h"
#include <iostream>
#include "Libraries\DealingWithStrings.h"
#include <limits>

void DepositBalance()
{

    // This is for the header of the screen
    // ---------------------------------------------------------------------------
    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen("!!!!!! Deposit Screen !!!!!!");
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();
    // ---------------------------------------------------------------------------

    // Here where we load all the client data from a file inot vector
    // ---------------------------------------------------------------------------
    vector<stClientInfo> ClientsInfo;
    LoadClientInfoFromFileAndStoreThenIntoVector("Clients", ClientsInfo);
    // ---------------------------------------------------------------------------

    // Here we ask the user to enter an account number and if the account is invalid number, we will keep ask them for a valid one
    // ------------------------------------------------------------------------------------------------------------------------------
        string AccountNumber = "";
        AccountNumber = ReadText::ReadTextOnScreen("Enter an account number: ");

        stClientInfo client_info;

        while (!DoesClientExists(ClientsInfo, AccountNumber, client_info))
        {
            PrintingText::PrintTextOnScreen("No client was found, ");
            AccountNumber = ReadText::ReadTextOnScreen("enter a valid account number: ");
        }
    // ------------------------------------------------------------------------------------------------------------------------------

    // Here we print the client info
    // -----------------------------------------------------------------------
        PrintStructures::PrintClientInfo(client_info);
    // -----------------------------------------------------------------------

    // Here we ask the user to enter the amount to depose
    // ------------------------------------------------------------------------------------------------
        double AmountToDeposit = 0.0;

        AmountToDeposit = ReadNumbers::ReadingDoubleNumber("Enter an amount to deposit: ");
        cin.ignore();

        char Answer = 'n';

        Answer = ReadText::ReadCharacter("Are you sure you want to depose this amount to this account: ");
        
        if(ConvertLetterToLower(Answer) == 'y')
        {
            client_info.AccountBalance += AmountToDeposit;

            PrintingText::PrintTextOnScreen("Your new balance is =>> ");
            PrintNumbers::PrintDoubleNumber(client_info.AccountBalance);
            PrintingText::PrintLines();
        }
        else 
        {
            PrintingText::PrintTextOnScreen("no deposit was made \n");
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');


       
    // ------------------------------------------------------------------------------------------------

    // update the client info we deposed their balance
    // ----------------------------------------------------------------
        UpdateClientInfo(ClientsInfo, AccountNumber, client_info);
    // ----------------------------------------------------------------

    // Save clients info to the file again after we deposing the balance
    // -------------------------------------------------------------------------
        SaveClientsInfoFromVectorToFile("Clients", ClientsInfo, enFileMode::Write);
    // -------------------------------------------------------------------------
}