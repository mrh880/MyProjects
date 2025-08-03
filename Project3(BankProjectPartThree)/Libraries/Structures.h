#pragma once 


#include <string>
struct stTimeDuration
{
    int Days = 0, Hours = 0, Minutes = 0, Seconds = 0;
};

struct stClientInfo
{
    std::string AccountNumber = "";
    std::string PinCode = "";
    std::string Name = "";
    std::string PhoneNumber = "";
    long double AccountBalance = 0.0;
};

struct stUserInfo
{
    std::string UserName = "";
    std::string Password = "";
    int  Permissions = 0;
};

