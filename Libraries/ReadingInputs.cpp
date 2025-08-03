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
#include "Structures.h"
#include "UsersDateStorage.h"
#include "DealingWithBuffer.h"

using namespace std;

namespace ReadText
{
    string ReadTextOnScreen(const string &Text)
    {
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

    string ReadingAccountNumber(short NumberOfCharacters, const string &Message)
    {
        // PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
        // PrintingText::PrintLines();
        FlushInputBuffer();
        string AccountNumber = "";
        stClientInfo ClientInfo;
        ValidingClientsData::ValidateAccountNumberLength(NumberOfCharacters, ClientInfo);
        AccountNumber = ClientInfo.AccountNumber;
        // PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
        // PrintingText::PrintLines();

        return AccountNumber;
    }

    char ReadingAnswer(short NumberOfCharacters, double AmountToWithDrawconst, const string &Message)
    {
        PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen(Message);
        PrintingText::PrintCharacters(' ');
        PrintNumbers::PrintDoubleNumber(AmountToWithDrawconst);
        PrintingText::PrintTextOnScreen("$ [y/n]: ");
        char Answer = ReadText::ReadCharacter();
        PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
        PrintingText::PrintLines();

        Answer = ConvertLetterToLower(Answer);

        FlushInputBuffer();

        return Answer;
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
        double Number = 0;
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

    double ReadingDoubleNumber(short NumberOfCharacters, const std::string &Message)
    {
        PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
        PrintingText::PrintLines();
        double Number = ReadingIntegerNumber(Message);
        PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
        PrintingText::PrintLines();

        return Number;
    }

    long double ReadingLongDoubleNumber(const std::string &Message)
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

    short ReadUserChoice(short From, short To, short NumberOfCharacters)
    {
        short Number = 0;
        do
        {
            PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
            PrintingText::PrintLines();
            string Message = "Enter a number [" + to_string(From) + "-" + to_string(To) + "]: ";
            Number = ReadNumbers::ReadingShortNumber(Message);
            PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
            PrintingText::PrintLines();
        } while (!ValidingNumbers::isNumberInRange(Number, From, To)); // to force the user to enter a number from 1 to 7
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
        cin.ignore();
        ValidingClientsData::ValidatePinCodeLength(0, ClientInfo);
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
        ValidingClientsData::ValidatePinCodeLength(0, ClientInfo);
        ValidingClientsData::ValidateClientNameLength(ClientInfo);
        ValidingClientsData::ValidatePhoneNumberLength(ClientInfo);
        ValidingClientsData::ValidateAccountBalanceLength(ClientInfo);
        PrintingText::PrintSequenceOfCharacters('*', 158);
        PrintingText::PrintLines();
        cin.ignore();
    }

    void ReadClientsInfo()
    {
        stClientInfo ClientInfo;
        string Answer = "";
        short Counter = 0;

        do
        {
            Counter++;
            ReadClientInfo(ClientInfo);                                                  // Read client data
            FilesOperations::SaveLineToFile("Clients", ConvertRecordToLine(ClientInfo)); // clear the vector to jsut stor one client data

            Answer = ReadText::ReadTextOnScreen("Do you want to add one more client: ");
            Answer = MakeAllStringToLower(Answer);
            PrintingText::PrintLines();
            ClearScreen();
        } while (Answer == "yes" || Answer == "y");

        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines();
        if (Counter == 1)
        {
            PrintingText::PrintTextOnScreen("!!!!!! CLIENT HAS BEEN SUCCESSFULLY SAVED !!!!!!");
        }
        else if (Counter >= 2)
        {
            PrintingText::PrintTextOnScreen("!!!!!! CLIENTS Have BEEN SUCCESSFULLY SAVED !!!!!!");
        }
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines();
    }

    void ReadUserInfo(const string &FileName)
    {
        vector<stUserInfo> UsersInfo;

        LoadUsersInfoFromFileAndStoreInVector("Users", UsersInfo);

        stUserInfo user_info;

        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("!!!!!! READING USER INFO !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();

        ValidingUserData::ValidUserNameUniqueAndLength(UsersInfo, user_info);
        PrintingText::PrintLines();
        ValidingUserData::validPasswordLengthAndCharacters(user_info);

        PrintingText::PrintLines();

        ReadUserPermissions(user_info);

        FilesOperations::SaveLineToFile("Users", ConvertRecordToLine(user_info));
    }

    void ReadUsersInfo(const string &FileName)
    {
        char Answer = 'n';

        do
        {
            ReadUserInfo(FileName);

            Answer = ReadText::ReadCharacter("Do you want to add one more user: ");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Answer = ConvertLetterToLower(Answer);

            ClearScreen();
        } while (Answer == 'y' || Answer == 'Y');
    }

    void ReadUserPermissions(stUserInfo &UserInfo)
    {

        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("!!!!!! READING USER PERMISSIONS !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();

        char Answer = 'n';
        short Permissions = 0;

        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();
        string Message = "Do you want to give [" + UserInfo.UserName + "] full access: ";
        Answer = ReadText::ReadCharacter(Message);
        Answer = ConvertLetterToLower(Answer);
        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();
        if (Answer == 'y')
        {
            Permissions += enUserPermissions::PAll;
            UserInfo.Permissions = Permissions;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            PrintingText::PrintSequenceOfCharacters('-', 100);
            PrintingText::PrintLines();
            PrintingText::PrintCharacters('[');
            PrintingText::PrintTextOnScreen(UserInfo.UserName);
            PrintingText::PrintCharacters(']');
            PrintingText::PrintTextOnScreen(" has got full access to the system !!!");
            PrintingText::PrintLines();
            PrintingText::PrintSequenceOfCharacters('-', 100);
            PrintingText::PrintLines(2);
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();
        Message = "Do you want to give [" + UserInfo.UserName + "] access to client list [y/n]: ";
        Answer = ReadText::ReadCharacter(Message);
        Answer = ConvertLetterToLower(Answer);
        if (Answer == 'y')
        {
            Permissions += enUserPermissions::PListClients;
        }
        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();
        Message = "Do you want to give [" + UserInfo.UserName + "] access to add new client [y/n]: ";
        Answer = ReadText::ReadCharacter(Message);
        Answer = ConvertLetterToLower(Answer);
        if (Answer == 'y')
        {
            Permissions += enUserPermissions::PAddNewClient;
        }
        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();
        Message = "Do you want to give [" + UserInfo.UserName + "] access to add delete client [y/n]: ";
        Answer = ReadText::ReadCharacter(Message);
        Answer = ConvertLetterToLower(Answer);
        if (Answer == 'y')
        {
            Permissions += enUserPermissions::PDeleteClient;
        }
        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();
        Message = "Do you want to give [" + UserInfo.UserName + "] access to add update client [y/n]: ";
        Answer = ReadText::ReadCharacter(Message);
        Answer = ConvertLetterToLower(Answer);
        if (Answer == 'y')
        {
            Permissions += enUserPermissions::PUpdateClient;
        }
        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();
        Message = "Do you want to give [" + UserInfo.UserName + "] access to add find client [y/n]: ";
        Answer = ReadText::ReadCharacter(Message);
        Answer = ConvertLetterToLower(Answer);
        if (Answer == 'y')
        {
            Permissions += enUserPermissions::PFindClient;
        }
        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();
        Message = "Do you want to give [" + UserInfo.UserName + "] access to transactions [y/n]: ";
        Answer = ReadText::ReadCharacter(Message);
        Answer = ConvertLetterToLower(Answer);
        if (Answer == 'y')
        {
            Permissions += enUserPermissions::PTransaction;
        }
        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();
        Message = "Do you want to give [" + UserInfo.UserName + "] access to manage users [y/n]: ";
        Answer = ReadText::ReadCharacter(Message);
        Answer = ConvertLetterToLower(Answer);
        if (Answer == 'y')
        {
            Permissions += enUserPermissions::PManageUsers;
        }
        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines(2);

        UserInfo.Permissions = Permissions;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void ReadUserInfoWithoutUserName(stUserInfo &UserInfo)
    {

        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("!!!!!! READING USER INFO !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();

        PrintingText::PrintLines();

        ValidingUserData::validPasswordLengthAndCharacters(UserInfo);

        ReadUserPermissions(UserInfo);
    }

}
