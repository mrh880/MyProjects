#include "TotalBalancesScreen.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Libraries\ClientsDataStorage.h"
#include "Libraries\Enums.h"
#include "Libraries\PrintingOutputs.h"
#include "Libraries\MathOperations.h"

using namespace std;

void PrintHeaderOfTheTable()
{
    PrintingText::PrintSequenceOfCharacters('-', 130);
    PrintingText::PrintLines();

    std::cout << std::left << std::setw(15) << "| Client Number ";
    cout << left << setw(12) << "| Account Number ";
    cout << left << setw(82) << "| Client Name ";
    cout << left << setw(14) << "| Balance ";
    PrintingText::PrintCharacters('|');

    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('-', 130);
    PrintingText::PrintLines();
}

void PrintEachClientInfo(stClientInfo ClientInfo, short NumberOfCurrentClinets)
{
    PrintingText::PrintSequenceOfCharacters('-', 130);
    PrintingText::PrintLines();

    std::cout << "| [" << NumberOfCurrentClinets << "]";
    PrintingText::PrintSpaces(11 - MathOperations::CountDigitsOfNumber(NumberOfCurrentClinets) + 1);

    cout << "| " << left << setw(15) << ClientInfo.AccountNumber;
    cout << "| " << left << setw(80) << ClientInfo.Name;
    cout << "| " << left << setw(12) << ClientInfo.AccountBalance; 

    PrintingText::PrintCharacters('|');

    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('-', 130);
    PrintingText::PrintLines();
}

void PrintClientsInfo(std::vector<stClientInfo> &ClientsInfo)
{
    short Counter = 0;
    for(stClientInfo &CurrentClient : ClientsInfo)
    {
        Counter++;
        PrintEachClientInfo(CurrentClient, Counter);
    }
}

double SumTotalBalances(std::vector<stClientInfo> &ClientsInfo)
{
    double SumOfBalances = 0.0;
    for(stClientInfo &CurrentClientInfo : ClientsInfo)
    {
        SumOfBalances += CurrentClientInfo.AccountBalance;
    }
    return SumOfBalances;
}

void PrintTotalBalances(double TotalBalances)
{
    PrintingText::PrintTabs(6); PrintingText::PrintSequenceOfCharacters('*', 40); PrintingText::PrintLines();
    PrintingText::PrintTabs(7); PrintingText::PrintTextOnScreen("All the balances =>> "); PrintNumbers::PrintDoubleNumber(TotalBalances); 
    PrintingText::PrintLines();
    PrintingText::PrintTabs(6); PrintingText::PrintSequenceOfCharacters('*', 40); PrintingText::PrintLines();
    PrintingText::PrintLines();
}

void PrintTotalBalancesOfAllClients()
{
    // Here we load the clients data from the file to the vector
    // ---------------------------------------------------------------------
        vector<stClientInfo> ClientsInfo;
        LoadClientInfoFromFileAndStoreThenIntoVector("Clients", ClientsInfo);
    // ---------------------------------------------------------------------

    // Print Header of the table
    // ---------------------------------------------------------
        PrintHeaderOfTheTable();
    // ---------------------------------------------------------

    // Print all the clients data 
    // --------------------------------------------------------------------
        PrintClientsInfo(ClientsInfo);
    // --------------------------------------------------------------------

    // Print the sum of all balances 
    // ------------------------------------------------------------
        double TotalBalances = SumTotalBalances(ClientsInfo);
        PrintTotalBalances(TotalBalances);
    // ------------------------------------------------------------

}