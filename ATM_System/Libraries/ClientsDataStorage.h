// ClientsDataStorage.h
#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "Structures.h"
#include "Enums.h"
// These function will deal with clients data for storing and loading clients form and to files
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void FillClientInfo(std::vector<std::string> &TempVector, stClientInfo &ClientInfo);

void ConvertLineToRecord(std::string Line, stClientInfo &ClientInfo);

void StorClientsInfoIntoVector(std::fstream &File, std::vector<stClientInfo> &ClientsInfo);

void LoadClientInfoFromFileAndStoreThenIntoVector(const std::string &FileName, std::vector<stClientInfo> &ClientsInfo);

std::string ConvertRecordToLine(stClientInfo ClientInfo);

std::string ConvertRecordToLine(stClientInfo ClientInfo);

void StoreClinetInfoInotVector(std::vector<std::string> &TempVector, stClientInfo &ClientInfo);

void SaveClientsInfoFromVectorToFile(const std::string &FileName, const std::vector<stClientInfo> &ClientsInfo, enFileMode FileMode = enFileMode::Append);


bool DoesClientExists(std::vector<stClientInfo> &ClientsInfo, const std::string &AccountNumber, stClientInfo &ClientInfo);

bool DoesClientExists(std::vector<stClientInfo> &ClientsInfo, const std::string &AccountNumber);

void SaveClientsDataToFileWithoutSpecificClientAccountNumber(const std::string &FileName,const std::vector<stClientInfo> &ClientsInfo, const std::string &AccountNumber);

void UpdateClientInfo(std::vector<stClientInfo> &ClientInof, const std::string &AccountNumber, stClientInfo &client_info);

void SaveClientsDataToFile(const std::string &FileName,const std::vector<stClientInfo> &ClientsInfo);

void WithDrawClientBalance(stClientInfo &ClientInfo, double AmountToWithDraw);

void DepositClientBalance(stClientInfo &ClientInfo, double AmountToWithDraw);

bool DoesClientExistsByAccountNumberAndPinCode(std::vector<stClientInfo> &ClientsInfo, stClientInfo &ClientInfo);
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
