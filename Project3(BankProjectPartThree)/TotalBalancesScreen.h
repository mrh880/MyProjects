#pragma once

#include <vector>

#include "Libraries\Structures.h"


void PrintHeaderOfTheTable();

void PrintEachClientInfo(stClientInfo ClientInfo, short NumberOfCurrentClinets);

void PrintClientsInfo(std::vector<stClientInfo> &ClientsInfo);

double SumTotalBalances(std::vector<stClientInfo> &ClientsInfo);

void PrintTotalBalances(double TotalBalances);

void PrintTotalBalancesOfAllClients();


