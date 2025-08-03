#pragma once

#include "Libraries\Structures.h"

#include <string>
#include <vector>


bool Login(stUserInfo &UserInfo, const std::string &FileName);

bool DoesUserNameAndPasswordMatchesUsersList(const std::vector<stUserInfo> &UsersInfo, stUserInfo &user_info);