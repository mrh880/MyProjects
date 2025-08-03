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

    void ValidateAccountNumberLength(short NumberOfcCharacters, stClientInfo &ClientInfo);

    void ValidateAccountNumberUniqueAndLength(std::vector<stClientInfo> &vClientInfo, stClientInfo &_stClientInfo);

    void ValidatePinCodeLength(short NumberOfCharacters, stClientInfo &ClientInfo);

    void ValidateClientNameLength(stClientInfo &ClientInfo);

    void ValidatePhoneNumberLength(stClientInfo &ClientInfo);

    void ValidateAccountBalanceLength(stClientInfo &ClientInfo);

    void ValidBalanceToWithdraw(long double AccountBalance, long double &AmountToWithdraw, short NumberOfCharacters, const std::string &Message = "");

    void ValidBalanceForDeposing(long double AccountBalance, long double &AmountToDepose, short NumberOfCharacters);

}

namespace ValidingUserData
{
    void ValidUserNameUniqueAndLength(const std::vector<stUserInfo> &UsersInfo, stUserInfo &user_info);

    void validPasswordLengthAndCharacters(stUserInfo &UserInfo);

     void ValidUserNameLength(stUserInfo &UserInfo);


}


