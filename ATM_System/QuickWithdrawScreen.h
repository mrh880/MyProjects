#pragma once

#include "Libraries\Structures.h"

#include <string>


void PrintMenuOfQuickWithdraw(short NumberOfCharacters);

short GetAmountOfQuickWithDraw(short Number);

void PerformQuickWithdraw(const std::string &FileName, stClientInfo &ClientInfo);

void QuickWithDraw(const std::string &Filename, stClientInfo &ClientInfo);
