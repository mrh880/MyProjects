// ClientsDataStorage.cpp
#include "ClientsDataStorage.h"

#include <iostream>
#include <string>
#include <vector>
#include "Structures.h"
#include "FilesOperations.h"
#include "DealingWithStrings.h"

using namespace std;

// These function deal with clients data for storing and loading clients form and to files
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void FillClientInfo(std::vector<std::string> &TempVector, stClientInfo &ClientInfo)
{
    ClientInfo.AccountNumber = TempVector[0];
    ClientInfo.PinCode = TempVector[1];
    ClientInfo.Name = TempVector[2];
    ClientInfo.PhoneNumber = TempVector[3];
    ClientInfo.AccountBalance = stod(TempVector[4]);
}

void ConvertLineToRecord(std::string Line, stClientInfo &ClientInfo)
{
    std::vector<std::string> TempVector;
    TempVector = SplitWordInSentence(Line, "#//#");
    FillClientInfo(TempVector, ClientInfo);
}

void StorClientsInfoIntoVector(std::fstream &File, std::vector<stClientInfo> &ClientsInfo)
{
    std::string Line = "";
    while (getline(File, Line))
    {
        stClientInfo client_info;
        ConvertLineToRecord(Line, client_info);
        ClientsInfo.push_back(client_info);
    }
}

void LoadClientInfoFromFileAndStoreThenIntoVector(const std::string &FileName, std::vector<stClientInfo> &ClientsInfo)
{
    std::string FilePath = FilesOperations::GetFullPathOfFile(FileName);
    std::fstream UserFile;
    FilesOperations::OpenFile(UserFile, enFileMode::Read, FilePath);
    if (!FilesOperations::Check_If_File_Was_Opend(UserFile))
    {
        std::cerr << "File could not be opend !" << FilePath << std::endl;
        return;
    }
    StorClientsInfoIntoVector(UserFile, ClientsInfo);
    FilesOperations::CloseFile(UserFile);
}

void StoreClinetInfoInotVector(std::vector<std::string> &TempVector, stClientInfo &ClientInfo)
{
    TempVector.push_back(ClientInfo.AccountNumber);
    TempVector.push_back(ClientInfo.PinCode);
    TempVector.push_back(ClientInfo.Name);
    TempVector.push_back(ClientInfo.PhoneNumber);
    TempVector.push_back(std::to_string(ClientInfo.AccountBalance));
}

std::string ConvertRecordToLine(stClientInfo ClientInfo)
{
    std::vector<std::string> TempVector;
    StoreClinetInfoInotVector(TempVector, ClientInfo);
    std::string Result = "";
    Result = JoinStrings(TempVector, "#//#");
    return Result;
}

void SaveClientsInfoFromVectorToFile(const string &FileName, const vector<stClientInfo> &ClientsInfo, enFileMode FileMode)
{
    string FilePath = FilesOperations::GetFullPathOfFile(FileName);

    fstream UserFile;

    FilesOperations::OpenFile(UserFile, FileMode, FilePath);

    if (!FilesOperations::Check_If_File_Was_Opend(UserFile))
    {
        cerr << "File could not be opened " << FilePath;
        return;
    }

    for (const stClientInfo &CurrentClient : ClientsInfo)
    {
        string Line = ConvertRecordToLine(CurrentClient);
        UserFile << Line << endl;
    }
    FilesOperations::CloseFile(UserFile);
}

bool DoesClientExists(vector<stClientInfo> &ClientsInfo, const string &AccountNumber, stClientInfo &ClientInfo)
{
    for (stClientInfo &Client : ClientsInfo)
    {
        if (Client.AccountNumber == AccountNumber)
        {
            ClientInfo = Client;
            return true;
        }
    }
    return false;
}

bool DoesClientExists(vector<stClientInfo> &ClientsInfo, const string &AccountNumber)
{
    for (stClientInfo &Client : ClientsInfo)
    {
        if (Client.AccountNumber == AccountNumber)
        {
            return true;
        }
    }
    return false;
}

void SaveClientsDataToFileWithoutSpecificClientAccountNumber(const string &FileName, const vector<stClientInfo> &ClientsInfo, const string &AccountNumber)
{
    string FilePath = FilesOperations::GetFullPathOfFile(FileName);

    fstream userFile;

    FilesOperations::OpenFile(userFile, enFileMode::Write, FilePath);

    if (!FilesOperations::Check_If_File_Was_Opend(userFile))
    {
        cerr << "File could not be opened " << FilePath << endl;
        return;
    }

    for (const stClientInfo &Client : ClientsInfo)
    {
        string Line = "";
        if (Client.AccountNumber != AccountNumber)
        {
            Line = ConvertRecordToLine(Client);
            userFile << Line << endl;
        }
    }
    FilesOperations::CloseFile(userFile);
}

void UpdateClientInfo(vector<stClientInfo> &ClientInof, const string &AccountNumber, stClientInfo &client_info)
{
    for (stClientInfo &Client : ClientInof)
    {
        if (Client.AccountNumber == AccountNumber)
        {

            Client = client_info;
            break;
        }
    }
}

void SaveClientsDataToFile(const string &FileName, const vector<stClientInfo> &ClientsInfo)
{
    string FilePath = FilesOperations::GetFullPathOfFile(FileName);

    fstream userFile;

    FilesOperations::OpenFile(userFile, enFileMode::Write, FilePath);

    if (!FilesOperations::Check_If_File_Was_Opend(userFile))
    {
        cerr << "File could not be opened " << FilePath << endl;
        return;
    }

    for (const stClientInfo &Client : ClientsInfo)
    {
        string Line = ConvertRecordToLine(Client);
        userFile << Line << endl;
    }
    FilesOperations::CloseFile(userFile);
}

void WithDrawClientBalance(stClientInfo &ClientInfo, double AmountToWithDraw)
{
    ClientInfo.AccountBalance -= AmountToWithDraw;
}

void DepositClientBalance(stClientInfo &ClientInfo, double AmountToWithDraw)
{
    ClientInfo.AccountBalance += AmountToWithDraw;
}

bool DoesClientExistsByAccountNumberAndPinCode(std::vector<stClientInfo> &ClientsInfo, stClientInfo &ClientInfo)
{
    for(stClientInfo &CurrentClient : ClientsInfo)
    {
        if(CurrentClient.AccountNumber == ClientInfo.AccountNumber && CurrentClient.PinCode == ClientInfo.PinCode)
        {
            ClientInfo = CurrentClient;
            return true;
        }
    }
    return false;
}
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
