#include "FindUserScreen.h"

#include "Libraries\UsersDateStorage.h"
#include "Libraries\PrintingOutputs.h"
#include "Libraries\ReadingInputs.h"
#include "Libraries\validingData.h"
#include <vector>
#include "CheckUserPermission.h"

using namespace std;

void FindUser(const std::string &FileName)
{
    PrintingText::PrintSequenceOfCharacters('*', 80);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen("!!!!!! Find User Info !!!!!!");
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 80);
    PrintingText::PrintLines();
    
    vector<stUserInfo> UsersInfo;

    LoadUsersInfoFromFileAndStoreInVector(FileName, UsersInfo);

    stUserInfo user_info;

    // PrintingText::PrintSequenceOfCharacters('*', 80);
    // PrintingText::PrintLines();
    ValidingUserData::ValidUserNameLength(user_info);
    // PrintingText::PrintSequenceOfCharacters('*', 80);
    // PrintingText::PrintLines();

    stUserInfo UserInfo;

    if (DoesUsersExists(UsersInfo, user_info.UserName, UserInfo))
    {
        PrintStructures::PrintUserInfo(UserInfo);
    }
    else
    {
        PrintingText::PrintSequenceOfCharacters('*', 50);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("User was not found !!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 50);
        PrintingText::PrintLines();
    }
}