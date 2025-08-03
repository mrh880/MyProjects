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
        cin.ignore();
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
            Permissions+= enUserPermissions::PDeleteClient;
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
