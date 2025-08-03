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
    ManageUsers = 7,
    Logout = 8,
    ExitScreen = 9
};

enum class enTransactionsMenuOptions
{
    DepositScreen = 1, 
    WithDrawScreen = 2,
    TotalBalances = 3, 
    ExitScreen = 4
};




enum class enManageUsers
{
    ListUsersScreen = 1,
    AddNewUserScreen = 2,
    DeleteUserScreen = 3, 
    UpdateUserScreen = 4,
    FindUserScreen = 5,
    ShowCurrentUserInfo = 6, 
    ExitScreen = 7
};

enum enUserPermissions
{
    PAll = -1,
    PListClients = 1,
    PAddNewClient = 2,
    PDeleteClient = 4, 
    PUpdateClient = 8,
    PFindClient = 16,
    PTransaction = 32,
    PManageUsers = 64
};
