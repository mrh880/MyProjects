// ReadingInputs.h
#pragma once

#include "Structures.h"
#include <string>

namespace ReadText
{
    std::string ReadTextOnScreen(const std::string &Text = "");

    char ReadCharacter(const std::string &Text = "");

    std::string ReadingAccountNumber(short NumberOfCharacters, const std::string &Message);

    char ReadingAnswer(short NumberOfCharacters, double AmountToWithDrawconst, const std::string &Message);
}
    
namespace ReadNumbers
{
    short ReadingShortNumber(const std::string &Message = "");

    int ReadingIntegerNumber(const std::string &Message = "");

    float ReadFloatingPointNumber(const std::string &Message = "");
    
    double ReadingDoubleNumber(const std::string &Message = "");
    
    double  ReadingDoubleNumber(short NumberOfCharacters, const std::string &Message = "");

    long double ReadingLongDoubleNumber(const std::string &Message = "");

    std::string ReadingAccountNumber(short NumberOfCharacter, const std::string &Message = "");

    short ReadUserChoice(short From, short To, short NumberOfCharacters);
}

namespace ReadingStructures
{
    void ReadClientInfoWithoutAccountNumber(stClientInfo &ClientInof);

    void ReadClientInfo(stClientInfo &ClientInfo);

    void ReadClientsInfo();

    void ReadUserInfo(const std::string &Filename);

    void ReadUsersInfo(const std::string &Filename);

    void ReadUserPermissions(stUserInfo &UserInfo);

    void ReadUserInfoWithoutUserName(stUserInfo &UserInfo);
}
