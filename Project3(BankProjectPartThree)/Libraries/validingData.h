#pragma once

#include "Structures.h"
#include <vector>

namespace ValidingNumbers
{
    bool isNumberInRange(short Number, short From, short To);
}

namespace ValidingClientsData
{
    void ValidateAccountNumberExists(const std::vector<stClientInfo> &vClientInfo, stClientInfo &_stClientInfo);

    void ValidateAccountNumberLength(stClientInfo &ClientInfo);

    void ValidateAccountNumberUniqueAndLength(std::vector<stClientInfo> &vClientInfo, stClientInfo &_stClientInfo);

    void ValidatePinCodeLength(stClientInfo &ClientInfo);

    void ValidateClientNameLength(stClientInfo &ClientInfo);

    void ValidatePhoneNumberLength(stClientInfo &ClientInfo);

    void ValidateAccountBalanceLength(stClientInfo &ClientInfo);
}

namespace ValidingUserData
{
    void ValidUserNameUniqueAndLength(const std::vector<stUserInfo> &UsersInfo, stUserInfo &user_info);

    void validPasswordLengthAndCharacters(stUserInfo &UserInfo);

     void ValidUserNameLength(stUserInfo &UserInfo);


}


