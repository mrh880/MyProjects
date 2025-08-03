#include "validingData.h"

#include <string>
#include <vector>
#include <limits>
#include <math.h>

#include "Structures.h"
#include "ClientsDataStorage.h"
#include "ReadingInputs.h"
#include "PrintingOutputs.h"
#include "DealingWithStrings.h"

namespace ValidingNumbers
{
    bool isNumberInRange(short Number, short From, short To)
    {
        return (Number >= From && Number <= To);
    }
}

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

    void ValidateAccountNumberLength(short NumberOfCharacters, stClientInfo &ClientInfo)
    {
        short MinLength = 5;
        short MaxLength = 12;

        bool isFirstTimeToAskAboutInput = false;

        PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters + 20);
        PrintingText::PrintLines();

        while (true)
        {

            if (!isFirstTimeToAskAboutInput)
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                ClientInfo.AccountNumber = ReadText::ReadTextOnScreen("Enter an account number: ");
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                isFirstTimeToAskAboutInput = true;
            }
            else
            {
                ClientInfo.AccountNumber = ReadText::ReadTextOnScreen("Enter an account number: ");
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
            }

            if (CheckIfStringHasPunctuationsOrSpecialCharacters(ClientInfo.AccountNumber))
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("The account number can contain characters and letters, ");
                PrintingText::PrintLines();
            }
            else if (ClientInfo.AccountNumber.empty())
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("Teh account number can not be empty");
                PrintingText::PrintLines();
            }
            else if (ClientInfo.AccountNumber.length() < MinLength)
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("The account number must be at least 5 character");
                PrintingText::PrintLines();
            }
            else if (ClientInfo.AccountNumber.length() > MaxLength)
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("The Account must be less or equal 12 character");
                PrintingText::PrintLines();
            }
            else
            {
                break;
            }
            // ClientInfo.AccountNumber = ReadText::ReadTextOnScreen("enter a valid username: ");
            // PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
            // PrintingText::PrintLines();
        }

        PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters + 20);
        PrintingText::PrintLines();

        ClientInfo.AccountNumber = TrimStringFromBothSides(ClientInfo.AccountNumber, ' ');
        
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

    void ValidatePinCodeLength(short NumberOfCharacters, stClientInfo &ClientInfo)
    {
        short MinLengthOfPinCode = 4;
        short MaxLengthOfPinCode = 8;

        bool isItFirstTimeToAskAboutInput = false;

        
        PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters + 20);
        PrintingText::PrintLines();
        
        while (true)
        {
            
            if(!isItFirstTimeToAskAboutInput)
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                ClientInfo.PinCode = ReadText::ReadTextOnScreen("Enter you pin code: ");
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();

            }
            else 
            {
                ClientInfo.PinCode = ReadText::ReadTextOnScreen("Enter you pin code: ");
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
            }
            
            if (ClientInfo.PinCode.empty())
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("The Pin Code can not be empty, ");
                PrintingText::PrintLines();
            }
            else if (CheckIfStringHasPunctuationsOrSpecialCharacters(ClientInfo.PinCode) || CheckIfStringHasCharacters(ClientInfo.PinCode))
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("The Pin code can only contain numbers, ");
                PrintingText::PrintLines();
            }

            else if (ClientInfo.PinCode.length() < MinLengthOfPinCode)
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("The Pin code must be less than or equal to 8 characters, ");
                PrintingText::PrintLines();

            }
            else if (ClientInfo.PinCode.length() > MaxLengthOfPinCode)
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("The Pin code must be less than or equals to 8 character, ");
                PrintingText::PrintLines();
            }
            else
            {
                break;
            }
            ClientInfo.PinCode = ReadText::ReadTextOnScreen("Enter a correct pin code: ");
            PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
            PrintingText::PrintLines();
        }

        PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
        PrintingText::PrintLines();

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
            if (CheckIfStringHasPunctuationsOrSpecialCharacters(ClientInfo.PhoneNumber) || CheckIfStringHasCharacters(ClientInfo.PhoneNumber))
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

    void ValidBalanceToWithdraw(long double AccountBalance, long double &AmountToWithdraw, short NumberOfCharacters, const std::string &Message)
    {
        bool isFirstTimeToAskAboutInput = false;
        do
        {
            if (!isFirstTimeToAskAboutInput)
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                AmountToWithdraw = ReadNumbers::ReadingLongDoubleNumber(Message);
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                isFirstTimeToAskAboutInput = true;
            }
            else
            {
                AmountToWithdraw = ReadNumbers::ReadingLongDoubleNumber(Message);
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
            }
            if (AmountToWithdraw > AccountBalance)
            {

                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("Amount to withdraw is greater than your balance, ");
                PrintingText::PrintLines();
            }
            else if (AmountToWithdraw <= 0)
            {

                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("Amount to withdraw must be great than 0, ");
                PrintingText::PrintLines();
            }
            else if(fmod(AmountToWithdraw, 5) != 0)
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("Amount to withdraw must be multiple by 5");
                PrintingText::PrintLines();
            }
        } while (AmountToWithdraw > AccountBalance || AmountToWithdraw <= 0 || (int) AmountToWithdraw % 5 != 0);
    }

    void ValidBalanceForDeposing(long double AccountBalance, long double &AmountToDepose, short NumberOfCharacters)
    {
        bool isFirstTimeToAskAboutInput = false;
        do
        {
            if (!isFirstTimeToAskAboutInput)
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                AmountToDepose = ReadNumbers::ReadingLongDoubleNumber("Enter an amount to depose: ");
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                isFirstTimeToAskAboutInput = true;
            }
            else
            {
                AmountToDepose = ReadNumbers::ReadingLongDoubleNumber("Enter an amount to depose: ");
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
            }

            if (AmountToDepose <= 0)
            {
                PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("Amount can not be less than or equals to 0, ");
                PrintingText::PrintLines();
            }
        } while (AmountToDepose <= 0);
    }

}

namespace ValidingUserData
{
    void ValidUserNameUniqueAndLength(const std::vector<stUserInfo> &UsersInfo, stUserInfo &user_info)
    {

        PrintingText::PrintSequenceOfCharacters('*', 120);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("!!!!!! Reading Username !!!!!!");
        PrintingText::PrintLines();

        short MinUserNameLength = 4;
        short MaxUserNameLength = 20;

        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();
        user_info.UserName = ReadText::ReadTextOnScreen("Enter a username: ");
        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();

        bool isUserNameTaken = false;

        while (true)
        {
            isUserNameTaken = false;

            for (const stUserInfo &CurrentUser : UsersInfo)
            {
                if (RemoveSpacesFromString(user_info.UserName) == RemoveSpacesFromString(CurrentUser.UserName))
                {
                    PrintingText::PrintSequenceOfCharacters('*', 100);
                    PrintingText::PrintLines();
                    PrintingText::PrintTextOnScreen("user name has taken, ");
                    PrintingText::PrintLines();
                    isUserNameTaken = true;
                    break;
                }
            }

            if (CheckIfStringHasPunctuationsOrSpecialCharacters(user_info.UserName))
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("User name can not contain special character !!!!");
                PrintingText::PrintLines();
            }
            else if (user_info.UserName.empty())
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("user name can be empty, ");
                PrintingText::PrintLines();
            }
            else if (user_info.UserName.length() < MinUserNameLength)
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("Username can not be less than 4 characters, ");
                PrintingText::PrintLines();
            }
            else if (user_info.UserName.length() > MaxUserNameLength)
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("user name can not be greater than 20 characters, it can be less than or equal 20 characters, ");
                PrintingText::PrintLines();
            }
            else
            {
                if (!isUserNameTaken)
                {
                    break;
                }
            }
            user_info.UserName = ReadText::ReadTextOnScreen("enter a valid username: ");
            PrintingText::PrintSequenceOfCharacters('*', 100);
            PrintingText::PrintLines();
        }
        PrintingText::PrintSequenceOfCharacters('*', 120);
        PrintingText::PrintLines();

        user_info.UserName = RemoveSpacesFromString(user_info.UserName);
    }

    void validPasswordLengthAndCharacters(stUserInfo &UserInfo)
    {

        PrintingText::PrintSequenceOfCharacters('*', 120);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("!!!!!! Reading PASSWORD !!!!!!");
        PrintingText::PrintLines();

        short MinPasswordLength = 8;
        short MaxPasswordLength = 40;

        bool isPasswordCorrect = false;

        bool isFirstTimeToAskForPassword = false;

        while (true)
        {

            if (!isFirstTimeToAskForPassword)
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                UserInfo.Password = ReadText::ReadTextOnScreen("Enter your password: ");
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                isFirstTimeToAskForPassword = true;
            }
            else
            {
                UserInfo.Password = ReadText::ReadTextOnScreen("Enter your password: ");
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
            }

            if (CheckIfStringStartsWithSpecificCharacter(UserInfo.Password, '#'))
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("Password can not be starts with #, ");
                PrintingText::PrintLines();
            }
            else if (CheckIfStringEndsWithSpecificCharacter(UserInfo.Password, '#'))
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("Password can not be ends with #, ");
                PrintingText::PrintLines();
            }
            else if (UserInfo.Password.empty())
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("Password can not be empty, ");
                PrintingText::PrintLines();
            }
            else if (UserInfo.Password.length() < MinPasswordLength)
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("password can not be less 8 characters, ");
                PrintingText::PrintLines();
            }
            else if (UserInfo.Password.length() > MaxPasswordLength)
            {
                PrintingText::PrintTextOnScreen("Password can not be greater than 40 characters, ");
                PrintingText::PrintLines();
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
            }
            else
            {
                break;
            }
        }

        PrintingText::PrintSequenceOfCharacters('*', 120);
        PrintingText::PrintLines(2);
    }

    void ValidUserNameLength(stUserInfo &UserInfo)
    {
        PrintingText::PrintSequenceOfCharacters('*', 120);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("!!!!!! Reading Username !!!!!!");
        PrintingText::PrintLines();

        short MinUserNameLength = 4;
        short MaxUserNameLength = 20;

        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();
        UserInfo.UserName = ReadText::ReadTextOnScreen("Enter a username: ");
        PrintingText::PrintSequenceOfCharacters('*', 100);
        PrintingText::PrintLines();

        while (true)
        {

            if (CheckIfStringHasSpaces(UserInfo.UserName))
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("User name can not contain spaces !!!!");
                PrintingText::PrintLines();
            }
            else if (CheckIfStringHasPunctuationsOrSpecialCharacters(UserInfo.UserName))
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("User name can not contain special character !!!!");
                PrintingText::PrintLines();
            }
            else if (UserInfo.UserName.empty())
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("user name can be empty, ");
                PrintingText::PrintLines();
            }
            else if (UserInfo.UserName.length() < MinUserNameLength)
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("Username can not be less than 4 characters, ");
                PrintingText::PrintLines();
            }
            else if (UserInfo.UserName.length() > MaxUserNameLength)
            {
                PrintingText::PrintSequenceOfCharacters('*', 100);
                PrintingText::PrintLines();
                PrintingText::PrintTextOnScreen("user continue can not be greater than 20 characters, it can be less than or equal 20 characters, ");
                PrintingText::PrintLines();
            }
            else
            {
                break;
            }
            UserInfo.UserName = ReadText::ReadTextOnScreen("enter a valid username: ");
            PrintingText::PrintSequenceOfCharacters('*', 100);
            PrintingText::PrintLines();
        }
        PrintingText::PrintSequenceOfCharacters('*', 120);
        PrintingText::PrintLines();
    }
}
