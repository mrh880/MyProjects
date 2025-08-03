#include "UsersDateStorage.h"

#include <iostream>
#include <string>
#include <vector>

#include "DealingWithStrings.h"
#include "FilesOperations.h"

using namespace std;

void ConvertLineToRecord(string Line, stUserInfo &UserInfo)
{
    vector<string> TempVector;
    TempVector = SplitWordInSentence(Line, "#//#");
    FillUserInfoFromVectorToStructure(UserInfo, TempVector);
}

void FillUserInfoFromVectorToStructure(stUserInfo &UserInfo, std::vector<std::string> &TempVector)
{
    try
    {
        UserInfo.UserName = TempVector[0];
        UserInfo.Password = TempVector[1];
        UserInfo.Permissions = stoi(TempVector[2]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cerr << "One of the info are missing, review your code again !\n";
    }
    
}

void StoreUsersInofInotVector(std::fstream &UserFile, vector<stUserInfo> &UsersInfo)

{
    string Line = "";
    stUserInfo user_info;
    while(getline(UserFile, Line))
    {
        ConvertLineToRecord(Line, user_info);
        UsersInfo.push_back(user_info);
    }
}

void LoadUsersInfoFromFileAndStoreInVector(const string &FileName, std::vector<stUserInfo> &UsersInfo)
{
    string FilePath = FilesOperations::GetFullPathOfFile(FileName); // Get the full path of the file

    fstream UserFile; // make an object from fstream 

    FilesOperations::OpenFile(UserFile, enFileMode::Read, FilePath); // open the file

    if(!FilesOperations::Check_If_File_Was_Opend(UserFile)) // Check if the file was not open 
    {
        cerr << "File could not be opened " << FilePath << endl;
        return;
    }

    StoreUsersInofInotVector(UserFile, UsersInfo); // store the users info inot the vector 
    FilesOperations::CloseFile(UserFile);
}


void FillUserInfoIntoVectorOfStringToConvertItToLine(std::vector<std::string> &TempVector, stUserInfo UserInfo)
{
    TempVector.push_back(UserInfo.UserName);
    TempVector.push_back(UserInfo.Password);
    for(short loop = 0; loop < TempVector.size(); loop++)
    TempVector.push_back(to_string(UserInfo.Permissions));
}

std::string ConvertRecordToLine(stUserInfo UserInfo)
{
    vector<string> Tempvector;
    FillUserInfoIntoVectorOfStringToConvertItToLine(Tempvector, UserInfo);
    string Line = "";
    Line = JoinStrings(Tempvector, "#//#");
    return Line;
}

bool DoesUsersExists(std::vector<stUserInfo> &UsersInfo, std::string UserName, stUserInfo &user_info)
{
    for(stUserInfo &CurrentUserInfo : UsersInfo)
    {
        if(CurrentUserInfo.UserName == UserName)
        {
            user_info = CurrentUserInfo;
            return true;
        }
    }
    return false;
}

void SaveUsersDataToFileWithoutSpecificUserName(const string &FileName, const vector<stUserInfo> &UsersInfo, const string &UserName)
{
    string FilePath = FilesOperations::GetFullPathOfFile(FileName);

    fstream UserFile;

    FilesOperations::OpenFile(UserFile, enFileMode::Write, FilePath);

    if(!FilesOperations::Check_If_File_Was_Opend(UserFile))
    {
        cerr << "File could not be opened " << FilePath << endl;
        return;
    }

    for(const stUserInfo &CurrentUser : UsersInfo)
    {
        string Line = "";
        if(CurrentUser.UserName != UserName)
        {
            Line = ConvertRecordToLine(CurrentUser);
            UserFile << Line << endl;
        }
    }
    FilesOperations::CloseFile(UserFile);
}

void SaveUsersDataToFile(const string &FileName, const vector<stUserInfo> &UsersInfo)
{
    string FilePath = FilesOperations::GetFullPathOfFile(FileName);

    fstream UserFile;

    FilesOperations::OpenFile(UserFile, enFileMode::Write, FilePath);

    if(!FilesOperations::Check_If_File_Was_Opend(UserFile))
    {
        cerr << "File could not be opened " << FilePath << endl;
        return;
    }

    for(const stUserInfo &CurrentUser : UsersInfo)
    {
        string Line = "";
        Line = ConvertRecordToLine(CurrentUser);
        UserFile << Line << endl;
    }
    FilesOperations::CloseFile(UserFile);
}

void UpdateUserInfoByUserName(std::vector<stUserInfo> &UsersInfo, const std::string &UserName, stUserInfo &user_info)
{
    for(stUserInfo &CurrentUserInfo : UsersInfo)
    {
        if(CurrentUserInfo.UserName == UserName)
        {
            CurrentUserInfo = user_info;
            break;
        }
    }
}