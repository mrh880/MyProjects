#pragma once

#include <string>

#include "Libraries\Structures.h"

bool Loging(const std::string &FileName, stClientInfo &ClientInfo);

void PrintLoginFailedMessage(short NumberOfCharacters, const std::string &Message);