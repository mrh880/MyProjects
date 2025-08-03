#pragma once

enum enFileMode
{
    Read = 1,
    Write,
    Append
};

enum class enMainMenuOptions
{
    ShowClientsListScreen = 1, 
    AddNewClientScreen = 2, 
    DeleteClientInfoScreen = 3, 
    UpdateClientInfoScreen = 4,
    FindClientInfoScreen = 5,
    Transactions = 6,
    ExitScreen = 7
};

enum class enTransactionsMenuOptions
{
    DepositScreen = 1, 
    WithDrawScreen = 2,
    TotalBalances = 3, 
    ExitScreen = 4
};



