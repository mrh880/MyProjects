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
        PrintingText::PrintTextOnScreen("Account balance: ");
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

    void PrintHeaderOfUserInfoTable()
    {
        PrintingText::PrintSequenceOfCharacters('-', 101);
        PrintingText::PrintLines();
        cout << left << setw(17) << "| Number of users ";
        cout << left << setw(24) << "| User name ";
        cout << left << setw(43) << "| Password ";
        cout << left << setw(3) << "| Permissions";
        PrintingText::PrintSpaces(2);
        PrintingText::PrintCharacters('|');
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('-', 101);
        PrintingText::PrintLines();
    }

    void PrintUserInfo(stUserInfo &UserInfo, int NumberOfUsers)
    {
        PrintingText::PrintSequenceOfCharacters('-', 101);
        PrintingText::PrintLines();

        cout << "| [" << NumberOfUsers << "]";
        PrintingText::PrintSpaces(14 - MathOperations::CountDigitsOfNumber(NumberOfUsers));
        cout << "| " << left << setw(22) << UserInfo.UserName;
        cout << "| " << left << setw(41) << UserInfo.Password;
        cout << "| " << left << setw(2) << UserInfo.Permissions;
        PrintingText::PrintSpaces(11);
        PrintingText::PrintCharacters('|');

        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('-', 101);
        PrintingText::PrintLines();
    }

    void PrintUserInfo(stUserInfo &UserInfo)
    {
        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("!!!!!! User Info !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();

        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();

        PrintingText::PrintTextOnScreen("User name: ");
        PrintingText::PrintTextOnScreen(UserInfo.UserName);
        PrintingText::PrintLines();

        PrintingText::PrintTextOnScreen("password: ");
        PrintingText::PrintTextOnScreen(UserInfo.Password);
        PrintingText::PrintLines();

        PrintingText::PrintTextOnScreen("Permissions: ");
        PrintNumbers::printShortNumber(UserInfo.Permissions);
        PrintingText::PrintLines();

        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();
    }

    void PrintUsersInfo(std::vector<stUserInfo> &UsersInfo)
    {

        PrintingText::PrintTabs(4);
        PrintingText::PrintTextOnScreen("Users List ");
        PrintingText::PrintCharacters('(');
        PrintNumbers::printShortNumber(UsersInfo.size());
        PrintingText::PrintCharacters(')');
        PrintingText::PrintCharacters(' ');
        PrintingText::PrintTextOnScreen("Users");
        PrintingText::PrintLines();

        PrintHeaderOfUserInfoTable();

        short CurrentNumberOfUser = 0;

        for (stUserInfo &CurrentUserInfo : UsersInfo)
        {
            CurrentNumberOfUser++;
            PrintUserInfo(CurrentUserInfo, CurrentNumberOfUser);
        }
    }

}