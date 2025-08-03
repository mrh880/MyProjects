#include "ListUsersScreen.h"

#include "Libraries\Structures.h"
#include "Libraries\UsersDateStorage.h"
#include "Libraries\PrintingOutputs.h"

#include <string>
#include <vector>

using namespace std;

void ShowUsersList(const std::string &FileName)
{
    vector<stUserInfo> UsersInfo;
    LoadUsersInfoFromFileAndStoreInVector(FileName, UsersInfo);
    // PrintStructures::PrintHeaderOfUserInfoTable();
    PrintStructures::PrintUsersInfo(UsersInfo);
}

