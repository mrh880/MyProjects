#include "PrintingOutputs.h"

#include <iostream>
#include <iomanip>

#include "MathOperations.h"
#include "ClientsDataStorage.h"

using namespace std;

namespace PrintingText
{
    void PrintTextOnScreen(const std::string &Text)
    {
        if (!Text.empty())
            cout << Text;
    }

    void PrintLines(short NumberOfLines)
    {
        for (short Lines = 0; Lines < NumberOfLines; Lines++)
            cout << endl;
    }

    void PrintTabs(short NumberOfTabs)
    {
        for (short Tabs = 0; Tabs < NumberOfTabs; Tabs++)
            cout << '\t';
    }

    void PrintSpaces(short NumberOfSpaces)
    {
        for (short Spaces = 0; Spaces < NumberOfSpaces; Spaces++)
            cout << ' ';
    }

    void PrintSequenceOfCharacters(char Character, short TimeToRepeat)
    {
        for (short Reapeat = 0; Reapeat < TimeToRepeat; Reapeat++)
            cout << Character;
    }

    void PrintCharacters(char Character)
    {
        cout << Character;
    }
}

namespace PrintNumbers
{
    void printShortNumber(short Number)
    {
        cout << Number;
    }

    void PrintIntegerNumber(int Number)
    {
        cout << Number;
    }

    void PrintFloatNumber(float Number)
    {
        cout << Number;
    }

    void PrintDoubleNumber(double Number)
    {
        cout << Number;
    }

}

namespace PrintStructures
{
    void PrintClientInfo(const stClientInfo &ClientInfo)
    {
        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("!!!!!! PRINTING CLIENT INFO !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();

        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("Account number: ");
        PrintingText::PrintTextOnScreen(ClientInfo.AccountNumber);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("Pin code: ");
        PrintingText::PrintTextOnScreen(ClientInfo.PinCode);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("Name: ");
        PrintingText::PrintTextOnScreen(ClientInfo.Name);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("Phone number: ");
        PrintingText::PrintTextOnScreen(ClientInfo.PhoneNumber);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen ("Account balance: ");
        PrintNumbers::PrintDoubleNumber(ClientInfo.AccountBalance);
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines(2);
    }

    void CustomPrintClientInfo(stClientInfo &ClientInfo, int NumberOfCurrentClinets)
    {
        PrintingText::PrintSequenceOfCharacters('-', 161);
        PrintingText::PrintLines();

        std::cout << "| [" << NumberOfCurrentClinets << "]";
        PrintingText::PrintSpaces(11 - MathOperations::CountDigitsOfNumber(NumberOfCurrentClinets) + 1);
        std::cout << "| " << std::left << std::setw(15) << ClientInfo.AccountNumber;
        std::cout << "| " << std::left << std::setw(9) << ClientInfo.PinCode;
        std::cout << "| " << std::left << std::setw(80) << ClientInfo.Name;
        std::cout << "| " << std::left << std::setw(18) << ClientInfo.PhoneNumber;
        std::cout << "| " << std::left << std::setw(11) << ClientInfo.AccountBalance;
        PrintingText::PrintSpaces(1);
        PrintingText::PrintCharacters('|');

        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('-', 161);
        PrintingText::PrintLines();
    }

    void CustomPrintClientsInfo(std::vector<stClientInfo> &ClientInfo)
    {
        int Counter = 0;
        for (stClientInfo &client_info : ClientInfo)
        {
            Counter++;
            CustomPrintClientInfo(client_info, Counter);
        }
    }

    void PrintClientsInfoList(std::string FileName)
    {
        //     //              toe load the data from a file and then convert them into structure and store them in vector
        //     // ------------------------------------------------------------------------------------------------------------
        std::vector<stClientInfo> ClientsInfo;
        LoadClientInfoFromFileAndStoreThenIntoVector(FileName, ClientsInfo);
        // ------------------------------------------------------------------------------------------------------------

        //                              print the header of the table
        // -----------------------------------------------------------------------------------------
        PrintingText::PrintTabs(8);
        PrintingText::PrintTextOnScreen("Clients List ");
        PrintingText::PrintCharacters('(');
        PrintNumbers::printShortNumber(ClientsInfo.size());
        PrintingText::PrintCharacters(')');
        PrintingText::PrintCharacters(' ');
        PrintingText::PrintTextOnScreen("Clinets");
        PrintingText::PrintLines();
        // -----------------------------------------------------------------------------------------

        // print the clients data
        // -----------------------------------------------------------------------------------------
        PrintingText::PrintSequenceOfCharacters('-', 161);
        PrintingText::PrintLines();

        std::cout << std::left << std::setw(15) << "| Client Number ";

        std::cout << std::left << std::setw(12) << "| Account Number ";
        std::cout << std::left << std::setw(8) << "| Pin Code ";
        std::cout << std::left << std::setw(82) << "| Client Name ";
        std::cout << std::left << std::setw(20) << "| Phone Number ";
        std::cout << std::left << std::setw(14) << "| Balance ";
        PrintingText::PrintCharacters('|');

        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('-', 161);
        PrintingText::PrintLines();
        CustomPrintClientsInfo(ClientsInfo);
        // -----------------------------------------------------------------------------------------
    }

}