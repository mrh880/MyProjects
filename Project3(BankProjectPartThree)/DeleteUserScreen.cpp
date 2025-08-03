#include "DeleteUserScreen.h"

#include "Libraries\Structures.h"
#include "Libraries\UsersDateStorage.h"
#include "Libraries\PrintingOutputs.h"
#include "Libraries\ReadingInputs.h"
#include "Libraries\DealingWithStrings.h"
#include "Libraries\validingData.h"

using namespace std;

#include <vector>
#include <limits>
#include <iostream>

void DeleteUser(const string &FileName)
{
    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen("!!!!!! Delete User INFO !!!!!!");
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();
    
    stUserInfo user_info;

    // PrintingText::PrintSequenceOfCharacters('*', 50);
    ValidingUserData::ValidUserNameLength(user_info);
    // PrintingText::PrintSequenceOfCharacters('*', 50);
    PrintingText::PrintLines(1);


    vector<stUserInfo> UsersInfo;

    LoadUsersInfoFromFileAndStoreInVector(FileName, UsersInfo);

    char Answer = 'n';

    if (DoesUsersExists(UsersInfo, user_info.UserName, user_info))
    {

        if (user_info.UserName == "Admin")
        {
            PrintingText::PrintTextOnScreen("I am sorry you can not delete this user !!!!");
            return;
        }

        PrintStructures::PrintUserInfo(user_info);

        PrintingText::PrintLines();

        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();
        Answer = ReadText::ReadCharacter("Do your want to delete this user: ");
        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines(2);

        Answer = ConvertLetterToLower(Answer);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (Answer == 'y')
        {
            SaveUsersDataToFileWithoutSpecificUserName(FileName, UsersInfo, user_info.UserName);
            PrintingText::PrintSequenceOfCharacters('*', 40);
            PrintingText::PrintLines();
            PrintingText::PrintTextOnScreen("User has deleted successful !");
            PrintingText::PrintLines();

            PrintingText::PrintSequenceOfCharacters('*', 40);
            PrintingText::PrintLines();
        }
    }
    else
    {
        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("Clients was not found !!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 40);
        PrintingText::PrintLines();
    }

    PrintingText::PrintLines(1);
}