#include "validingData.h"

#include <string>
#include <vector>
#include <limits>

#include "Structures.h"
#include "ClientsDataStorage.h"
#include "ReadingInputs.h"
#include "PrintingOutputs.h"
#include "DealingWithStrings.h"

using namespace std;

namespace ValidingClientsData
{
    void ValidateAccountNumberExists(const vector<stClientInfo> &vClientInfo, stClientInfo &_stClientInfo)
    {

        bool DoesClientAccountNumberExistsInClientsList = false;
        do
        {
            DoesClientAccountNumberExistsInClientsList = false;

            _stClientInfo.AccountNumber = ReadText::ReadTextOnScreen("Enter an account number: ");

            for (const stClientInfo &CurrentClientInfo : vClientInfo)
            {
                if (CurrentClientInfo.AccountNumber == _stClientInfo.AccountNumber)
                {
                    DoesClientAccountNumberExistsInClientsList = true;
                    PrintingText::PrintTextOnScreen("This account number already exists, enter another account number: ");
                    break;
                }
            }
        } while (DoesClientAccountNumberExistsInClientsList);
    }

    void ValidateAccountNumberLength(stClientInfo &ClientInfo)
    {
        short MinLength = 5;
        short MaxLength = 12;

        ClientInfo.AccountNumber = ReadText::ReadTextOnScreen("Enter an account number: ");

        while (true)
        {

            if (ClientInfo.AccountNumber.empty())
            {
                PrintingText::PrintTextOnScreen("Teh account number can not be empty");
            }
            else if (CheckIfStringHasPunctuationsOrSpecialCharacters(ClientInfo.AccountNumber))
            {
                PrintingText::PrintTextOnScreen("Account number can only contain characters and letters, ");
            }
            else if (ClientInfo.AccountNumber.length() < MinLength)
            {
                PrintingText::PrintTextOnScreen("The account number must be at least 5 character");
            }
            else if (ClientInfo.AccountNumber.length() > MaxLength)
            {
                PrintingText::PrintTextOnScreen("The Account must be less or equal 12 character");
            }
            else
            {

                break;
            }
            ClientInfo.AccountNumber = ReadText::ReadTextOnScreen("Enter a valid account number: ");
        }
    }

    void ValidateAccountNumberUniqueAndLength(std::vector<stClientInfo> &vClientInfo, stClientInfo &_stClientInfo)
    {
        short MinLengthOfAccountNumber = 5;
        short MaxLengthOfAccountNumber = 12;

        _stClientInfo.AccountNumber = ReadText::ReadTextOnScreen("Enter your account number: ");
        bool isClientListExistsInClientList = false;

        while (true)
        {

            isClientListExistsInClientList = false;
            for (const stClientInfo &CurrentClient : vClientInfo)
            {
                if (CurrentClient.AccountNumber == _stClientInfo.AccountNumber)
                {
                    PrintingText::PrintTextOnScreen("This account number has been taken, ");
                    isClientListExistsInClientList = true;
                    break;
                }
            }

            if (CheckIfStringHasPunctuationsOrSpecialCharacters(_stClientInfo.AccountNumber))
            {
                PrintingText::PrintTextOnScreen("Account number can only contain characters and letters, ");
            }
            else
            {
                if (_stClientInfo.AccountNumber.empty())
                {
                    PrintingText::PrintTextOnScreen("Teh account number can not be empty, ");
                }
                else if (_stClientInfo.AccountNumber.length() < MinLengthOfAccountNumber)
                {
                    PrintingText::PrintTextOnScreen("The account number must be at least 5 character, ");
                }
                else if (_stClientInfo.AccountNumber.length() > MaxLengthOfAccountNumber)
                {
                    PrintingText::PrintTextOnScreen("The Account must be less or equal 12 character, ");
                }
                else if (!isClientListExistsInClientList)
                {
                    break;
                }
            }

            _stClientInfo.AccountNumber = ReadText::ReadTextOnScreen("Enter a valid account number: ");
        }
        _stClientInfo.AccountNumber = TrimStringFromBothSides(_stClientInfo.AccountNumber, ' ');
    }

    void ValidatePinCodeLength(stClientInfo &ClientInfo)
    {
        short MinLengthOfPinCode = 4;
        short MaxLengthOfPinCode = 8;

        ClientInfo.PinCode = ReadText::ReadTextOnScreen("Enter you pin code: ");

        while (true)
        {
            if (ClientInfo.PinCode.empty())
            {
                PrintingText::PrintTextOnScreen("The Pin Code can not be empty, ");
            }
            else if (CheckIfStringHasPunctuationsOrSpecialCharacters(ClientInfo.PinCode) || CheckIfStringHasCharacters(ClientInfo.PinCode))
            {
                PrintingText::PrintTextOnScreen("The Pin code can only contain numbers, ");
            }
    
            else if (ClientInfo.PinCode.length() < MinLengthOfPinCode)
            {
                PrintingText::PrintTextOnScreen("The Pin code must be less than or equal to 8 characters, ");
            }
            else if (ClientInfo.PinCode.length() > MaxLengthOfPinCode)
            {
                PrintingText::PrintTextOnScreen("The Pin code must be less than or equals to 8 character, ");
            }
            else
            {
                break;
            }
            ClientInfo.PinCode = ReadText::ReadTextOnScreen("Enter a correct pin code: ");
        }
        ClientInfo.PinCode = TrimStringFromBothSides(ClientInfo.PinCode, ' ');
    }

    void ValidateClientNameLength(stClientInfo &ClientInfo)
    {
        short MinLengthOfName = 2;
        short MaxLengthOfName = 82;

        ClientInfo.Name = ReadText::ReadTextOnScreen("Enter your name: ");

        while (true)
        {
            if (ClientInfo.Name.empty())
            {
                PrintingText::PrintTextOnScreen("The Name can not be empty, ");
            }
            else if (CheckIfStringHasNumbers(ClientInfo.Name) || CheckIfStringHasPunctuationsOrSpecialCharacters(ClientInfo.Name))
            {
                PrintingText::PrintTextOnScreen("Name can only contain alphabetic characters (no numbers or special characters), ");
            }

            else if (ClientInfo.Name.length() < MinLengthOfName)
            {
                PrintingText::PrintTextOnScreen("The name can not be less than 2 characters, ");
            }
            else if (ClientInfo.Name.length() > MaxLengthOfName)
            {
                PrintingText::PrintTextOnScreen("The name must be less than or equals to 80 characters, ");
            }
            else
            {
                break;
            }
            ClientInfo.Name = ReadText::ReadTextOnScreen("Enter a valid name: ");
        }
        ClientInfo.Name = TrimStringFromBothSides(ClientInfo.Name, ' ');
    }

    void ValidatePhoneNumberLength(stClientInfo &ClientInfo)
    {
        short MinLengthOfPhoneNumber = 7;
        short MaxLengthOfPhoneNumber = 20;

        ClientInfo.PhoneNumber = ReadText::ReadTextOnScreen("Enter your Phone Number: ");

        while (true)
        {
            if (ClientInfo.PhoneNumber.empty())
            {
                PrintingText::PrintTextOnScreen("The phone number code can not be empty, ");
            }
            if(CheckIfStringHasPunctuationsOrSpecialCharacters(ClientInfo.PhoneNumber) || CheckIfStringHasCharacters(ClientInfo.PhoneNumber))
            {
                PrintingText::PrintTextOnScreen("The phone number can only contain numbers, ");
            }
            else if (ClientInfo.PhoneNumber.length() < MinLengthOfPhoneNumber)
            {
                PrintingText::PrintTextOnScreen("The phone number can not be less than 7 characters, ");
            }
            else if (ClientInfo.PhoneNumber.length() > MaxLengthOfPhoneNumber)
            {
                PrintingText::PrintTextOnScreen("The phone number can not more than 20 characters, ");
            }
            else
            {
                break;
            }
            ClientInfo.PhoneNumber = ReadText::ReadTextOnScreen("Enter a valid phone number: ");
        }
        ClientInfo.PhoneNumber = TrimStringFromBothSides(ClientInfo.PhoneNumber, ' ');
    }

    void ValidateAccountBalanceLength(stClientInfo &ClientInfo)
    {

        short MinBalance = 10;
        long double MaxBalance = 99999999999999;
        ClientInfo.AccountBalance = ReadNumbers::ReadingDoubleNumber("Enter your balance account: ");

        while (true)
        {

            if (ClientInfo.AccountBalance < std::numeric_limits<long double>::min() ||
                ClientInfo.AccountBalance > std::numeric_limits<long double>::max())
            {
                PrintingText::PrintTextOnScreen("The account balance is out of the valid range, ");
            }
            else if (ClientInfo.AccountBalance < MinBalance)
            {
                PrintingText::PrintTextOnScreen("Account number must be at least 10, ");
            }
            else if (ClientInfo.AccountBalance > MaxBalance)
            {
                PrintingText::PrintTextOnScreen("Account balance can not be more than 99999999999999, ");
            }
            else
            {
                break;
            }
            ClientInfo.AccountBalance = ReadNumbers::ReadingDoubleNumber("Enter a valid account balance: ");
        }
    }
}

namespace ValidingNumbers
{
    bool isNumberInRange(short Number, short From, short To)
    {
        return (Number >= From && Number <= To);
    }
}