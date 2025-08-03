#pragma once

#include "Structures.h"
#include <vector>

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

namespace ValidingNumbers
{
    bool isNumberInRange(short Number, short From, short To);
}