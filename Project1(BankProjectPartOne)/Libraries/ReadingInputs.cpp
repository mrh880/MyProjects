// ReadingInputs.cpp
#include <iostream>
#include <string>
#include <limits>

#include "ReadingInputs.h"
#include "PrintingOutputs.h"
#include "ClientsDataStorage.h"
#include "validingData.h"
#include "FilesOperations.h"
#include "DealingWithStrings.h"
#include "ClearingScreenFunctions.h"

using namespace std;

namespace ReadText
{
    string ReadTextOnScreen(const string &Text)
    {
        // cin.ignore();
        if (!Text.empty())
            cout << Text;
        string UserInput = "";
        getline(cin, UserInput);
        return UserInput;
    }

    char ReadCharacter(const string &Text)
    {
        if (!Text.empty())
            cout << Text;
        char Character = ' ';
        cin >> Character;
        return Character;
    }
}

namespace ReadNumbers
{
    short ReadingShortNumber(const string &Message)
    {
        if (!Message.empty())
            cout << Message;
        short Number = 0;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            PrintingText::PrintTextOnScreen("Invalid number, enter a valid number: ");
            cin >> Number;
        }
        return Number;
    }

    int ReadingIntegerNumber(const string &Message)
    {
        if (!Message.empty())
            cout << Message;
        int Number = 0;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            PrintingText::PrintTextOnScreen("Invalid number, enter a valid number: ");
            cin >> Number;
        }
        return Number;
    }

    float ReadFloatingPointNumber(const string &Message)
    {
        if (!Message.empty())
            cout << Message;
        float Number = 0;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            PrintingText::PrintTextOnScreen("Invalid number, enter a valid number: ");
            cin >> Number;
        }
        PrintingText::PrintLines();
        return Number;
    }

    double ReadingDoubleNumber(const string &Message)
    {
        if (!Message.empty())
            cout << Message;
        long double Number = 0;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            PrintingText::PrintTextOnScreen("Invalid number, enter a valid number: ");
            cin >> Number;
        }
        return Number;
    }
}

namespace ReadingStructures
{
    void ReadClientInfoWithoutAccountNumber(stClientInfo &ClientInfo)
    {
        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("!!!!!! READING CLIENT INFO !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();

        PrintingText::PrintSequenceOfCharacters('*', 158);
        PrintingText::PrintLines();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ValidingClientsData::ValidatePinCodeLength(ClientInfo);
        ValidingClientsData::ValidateClientNameLength(ClientInfo);
        ValidingClientsData::ValidatePhoneNumberLength(ClientInfo);
        ValidingClientsData::ValidateAccountBalanceLength(ClientInfo);
        PrintingText::PrintSequenceOfCharacters('*', 158);
        PrintingText::PrintLines();
   
    }

    void ReadClientInfo(stClientInfo &ClientInfo)
    {
        vector<stClientInfo> ClientsInfo;
        LoadClientInfoFromFileAndStoreThenIntoVector("Clients", ClientsInfo);

        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("!!!!!! READING CLIENT INFO !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();

        PrintingText::PrintSequenceOfCharacters('*', 158);
        PrintingText::PrintLines();
        ValidingClientsData::ValidateAccountNumberUniqueAndLength(ClientsInfo, ClientInfo);
        ValidingClientsData::ValidatePinCodeLength(ClientInfo);
        ValidingClientsData::ValidateClientNameLength(ClientInfo);
        ValidingClientsData::ValidatePhoneNumberLength(ClientInfo);
        ValidingClientsData::ValidateAccountBalanceLength(ClientInfo);
        PrintingText::PrintSequenceOfCharacters('*', 158);
        PrintingText::PrintLines();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void ReadClientsInfo()
    {
        stClientInfo ClientInfo;
        string Answer = "";
        short Counter = 0;

        do
        {
            Counter++;
            ReadClientInfo(ClientInfo);                                                    // Read client data
            FilesOperations::SaveLineToVector("Clients", ConvertRecordToLine(ClientInfo)); // clear the vector to jsut stor one client data

            Answer = ReadText::ReadTextOnScreen("Do you want to add one more client: ");
            Answer = MakeAllStringToLower(Answer);
            PrintingText::PrintLines();
            ClearScreen();
        } while (Answer == "yes" || Answer == "y");

        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines();
        (Counter == 1 ?  PrintingText::PrintTextOnScreen("!!!!!! CLIENT HAS BEEN SUCCESSFULLY SAVED !!!!!!") : 
        PrintingText::PrintTextOnScreen("!!!!!! CLIENTs Have BEEN SUCCESSFULLY SAVED !!!!!!"));
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines();
    }
}
