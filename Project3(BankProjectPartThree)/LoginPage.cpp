#include "LoginPage.h"

#include "Libraries\Structures.h"
#include "Libraries\PrintingOutputs.h"
#include "Libraries\validingData.h"
#include "Libraries\UsersDateStorage.h"
#include "Libraries\ClearingScreenFunctions.h"

#include <string>
#include <vector>

using namespace std;

bool Login(stUserInfo &UserInfo, const string &FileName)
{

    vector<stUserInfo> UsersInfo;
    LoadUsersInfoFromFileAndStoreInVector(FileName, UsersInfo);
    bool Matches = false;

    ClearScreen();
    system("color 02"); // for Background: Black, Text: Green

    do
    {

        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines();
        PrintingText::PrintTabs(2);
        PrintingText::PrintTextOnScreen("!!!!!! Login Page !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines(2);

        ValidingUserData::ValidUserNameLength(UserInfo);
        PrintingText::PrintLines();
        ValidingUserData::validPasswordLengthAndCharacters(UserInfo);
        Matches = DoesUserNameAndPasswordMatchesUsersList(UsersInfo, UserInfo);
        ClearScreen();
        system("color 02"); // for Background: Black, Text: Green

        if (!Matches)
        {
            PrintingText::PrintSequenceOfCharacters('*', 60);
            PrintingText::PrintLines();
            PrintingText::PrintTextOnScreen("Invalid username or password. Please try again");
            PrintingText::PrintLines();
            PrintingText::PrintSequenceOfCharacters('*', 60);
            PrintingText::PrintLines();
        }

    } while (!Matches);
    return true;
}

bool DoesUserNameAndPasswordMatchesUsersList(const vector<stUserInfo> &UsersInfo, stUserInfo &user_info)
{
    for (const stUserInfo &CurrentUserInfo : UsersInfo)
    {
        if (CurrentUserInfo.UserName == user_info.UserName && CurrentUserInfo.Password == user_info.Password)
        {
            user_info = CurrentUserInfo;
            return true;
        }
    }
    return false;
}