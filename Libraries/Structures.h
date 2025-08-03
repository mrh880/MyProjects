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



struct stDate
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
};

struct stDateAndDay
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
    std::string CurrentDayInText = "";
};  

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};
