#include "UpdateUserScreen.h"

#include "Libraries\UsersDateStorage.h"
#include "Libraries\Structures.h"
#include "Libraries\PrintingOutputs.h"
#include "Libraries\ReadingInputs.h"
#include "Libraries\DealingWithStrings.h"
#include "Libraries\validingData.h"


#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void UpdateUser(const string &FileName)
{

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();
    PrintingText::PrintTabs(1);
    PrintingText::PrintSpaces(3);
    PrintingText::PrintTextOnScreen("UPDATE USER INFO");
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines(2);


    stUserInfo user_info;


    // PrintingText::PrintSequenceOfCharacters('*', 60);
    // PrintingText::PrintLines();
    ValidingUserData::ValidUserNameLength(user_info);
    // PrintingText::PrintSequenceOfCharacters('*', 60);
    PrintingText::PrintLines(1);


    vector<stUserInfo> UsersInfo;
    
    LoadUsersInfoFromFileAndStoreInVector(FileName, UsersInfo);



    if(DoesUsersExists(UsersInfo, user_info.UserName, user_info))
    {

        if(user_info.UserName == "Admin")
        {
            PrintingText::PrintTextOnScreen("This user can not be updated !!!!");
            return;
        }
        
        PrintStructures::PrintUserInfo(user_info);

        PrintingText::PrintLines();

        PrintingText::PrintSequenceOfCharacters('*', 50);
        PrintingText::PrintLines();
        char Answer = ReadText::ReadCharacter("Do you want to update this user [y/n]: ");
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // we use this fuction to not get problem with buffer of character
        PrintingText::PrintSequenceOfCharacters('*', 50);
        PrintingText::PrintLines(2);

        if(ConvertLetterToLower(Answer) == 'y')
        {
            ReadingStructures::ReadUserInfoWithoutUserName(user_info);
            UpdateUserInfoByUserName(UsersInfo, user_info.UserName, user_info);
            SaveUsersDataToFile(FileName, UsersInfo);
            PrintingText::PrintSequenceOfCharacters('*', 50);
            PrintingText::PrintLines();
            PrintingText::PrintTextOnScreen("user has been successfully updated !!");
            PrintingText::PrintLines();
             PrintingText::PrintSequenceOfCharacters('*', 50);
            PrintingText::PrintLines(2);
        }
    }
    else 
    {
        PrintingText::PrintTextOnScreen("User was not found :(");
    }

    PrintingText::PrintLines();
}