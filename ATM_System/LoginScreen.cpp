#include "LoginScreen.h"

#include "Libraries\ClientsDataStorage.h"
#include "Libraries\PrintingOutputs.h"
#include "Libraries\validingData.h"
#include "Libraries\ClearingScreenFunctions.h"

#include <vector>

using namespace std;

bool Loging(const std::string &FileName, stClientInfo &ClientInfo)
{
    short NumberOfCharacters = 60;

    vector<stClientInfo> ClientsInfo;

    LoadClientInfoFromFileAndStoreThenIntoVector(FileName, ClientsInfo);

    bool Matches = false;

    bool isItFirstTimeToLoginFail = false;

    string LogingFailMessage = "Invalid account number or pin code, Please try again";

    do
    {

        ClearScreen();
        system("color 02"); // for Background: Black, Text: Green

        if (isItFirstTimeToLoginFail)
        {
            PrintLoginFailedMessage(NumberOfCharacters, LogingFailMessage);
        }

        PrintingText::PrintHeader(NumberOfCharacters, "!!!! LOGIN PAGE !!!!");

        PrintingText::PrintLines();

        ValidingClientsData::ValidateAccountNumberLength(NumberOfCharacters, ClientInfo);

        PrintingText::PrintLines();

        ValidingClientsData::ValidatePinCodeLength(NumberOfCharacters, ClientInfo);

        Matches = DoesClientExistsByAccountNumberAndPinCode(ClientsInfo, ClientInfo);

        if (!Matches)
        {
            PrintLoginFailedMessage(NumberOfCharacters, LogingFailMessage);
        }

        isItFirstTimeToLoginFail = true;
    } while (!Matches);
    return true;
}

void PrintLoginFailedMessage(short NumberOfCharacters, const std::string &Message)
{
    PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen(Message);
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
    PrintingText::PrintLines();
}