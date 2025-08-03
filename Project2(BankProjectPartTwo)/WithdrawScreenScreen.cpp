#include "WithdrawScreenScreen.h"

#include <vector>

#include "Libraries\PrintingOutputs.h"
#include "Libraries\ClientsDataStorage.h"
#include "Libraries\ReadingInputs.h"
#include "Libraries\Enums.h"
#include <iostream>
#include "Libraries\DealingWithStrings.h"
#include <limits>

using namespace std;

bool DoesClientHasEnoughMoneyToWithdraw(double ClientBalance, double WithDrawBalance)
{
    return (WithDrawBalance <= ClientBalance);
}

void WithdrawBalance()
{
    // This is for the header of the screen
    // ---------------------------------------------------------------------------
    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen("!!!!!! Withdraw Screen !!!!!!");
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
        PrintingText::PrintLines();
    }
    // ------------------------------------------------------------------------------------------------------------------------------

    // Here we print the client info
    // -----------------------------------------------------------------------
    PrintStructures::PrintClientInfo(client_info);
    // -----------------------------------------------------------------------

    // Here we ask the user to enter the amount to withdraw
    // ------------------------------------------------------------------------------------------------
    double AmountToWithdraw = 0.0;

    AmountToWithdraw = ReadNumbers::ReadingDoubleNumber("Enter an amount to withdraw: ");
    cin.ignore();

    while (!DoesClientHasEnoughMoneyToWithdraw(client_info.AccountBalance, AmountToWithdraw))
    {
        PrintingText::PrintTextOnScreen("The amount you entered is more than you have, ");
        AmountToWithdraw = ReadNumbers::ReadingDoubleNumber("enter a valid amount: ");
        PrintingText::PrintLines();
    }

    char Answer = 'n';
    Answer = ReadText::ReadCharacter("Are you sure you want to withdraw this amount to this account: ");

    if (CovertLetterToLower(Answer) == 'y')
    {
        client_info.AccountBalance -= AmountToWithdraw;
        PrintingText::PrintTextOnScreen("Your new balance is =>> ");
        PrintNumbers::PrintDoubleNumber(client_info.AccountBalance);
        PrintingText::PrintLines();
    }
    else 
    {
        PrintingText::PrintTextOnScreen("no withdraw was made \n");
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
