#pragma once

#include "Structures.h"

#include <string>
#include <vector>

void ConvertLineToRecord(std::string Line, stUserInfo &UserInfo);

void FillUserInfoFromVectorToStructure(stUserInfo &UserInfo, std::vector<std::string> &TempVector);

void StoreUsersInofInotVector(std::fstream &UserFile, std::vector<stUserInfo> &UsersInfo);

void LoadUsersInfoFromFileAndStoreInVector(const std::string &ileName, std::vector<stUserInfo> &UsersInfo);


void FillUserInfoIntoVectorOfStringToConvertItToLine(std::vector<std::string> &TempVector, stUserInfo UserInfo);

std::string ConvertRecordToLine(stUserInfo UserInfo);

bool DoesUsersExists(std::vector<stUserInfo> &UsersInfo, std::string UserName, stUserInfo &user_info);

void SaveUsersDataToFileWithoutSpecificUserName(const std::string &FileName, const std::vector<stUserInfo> &UsersInfo, const std::string &UserName);


void SaveUsersDataToFile(const std::string &FileName, const std::vector<stUserInfo> &UsersInfo);

void UpdateUserInfoByUserName(std::vector<stUserInfo> &UsersInfo, const std::string &UserName, stUserInfo &user_info);

