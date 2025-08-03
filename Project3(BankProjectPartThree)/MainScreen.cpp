#include "MainScreen.h"

// !!!!!! The main Operation to run the program !!!!!!
// -------------------------------------------------------------------
#include "ShowClientsListScreen.h"  // 1
#include "AddNewClientScreen.h"     // 2
#include "DeleteClientScreen.h"     // 3
#include "UpdateClientInfoScreen.h" // 5
#include "FindClientScreen.h"       // 6
#include "DepositScreenScreen.h"    // 7
#include "WithdrawScreenScreen.h"   // 8
#include "TotalBalancesScreen.h"    // 9
#include "ListUsersScreen.h"        // 10
#include "AddNewUserScreen.h"       // 11
#include "DeleteUserScreen.h"       // 12
#include "UpdateUserScreen.h"       // 13
#include "FindUserScreen.h"         // 14
#include "LoginPage.h"              //15
// -------------------------------------------------------------------

// The Helper function
// --------------------------------------------------
#include "Libraries\PrintingOutputs.h"
#include "Libraries\ClearingScreenFunctions.h"
#include "Libraries\ReadingInputs.h"
#include "Libraries\validingData.h"
#include <iostream>
#include "Libraries\Enums.h"
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <limits>
#include "CheckUserPermission.h"
// --------------------------------------------------

using namespace std;

stUserInfo CurrentUser;

void GoingBackToMainScreen()
{
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    PrintingText::PrintTextOnScreen("Press any key to go back to main menu..."); // cout << "Press any key to go back to main menu\n";
    cin.get(); // system("pause > 0");
    ClearScreen(); // system("cls");
    DrawingMainMenu();
}

void GoingBackToTransactionsMenu()
{
    PrintingText::PrintTextOnScreen("Press any key to go back to Transactions menu...");
    cin.get();
    ClearScreen();
    DrawingTransactionsMenu();
}

void ShowEndScreen()
{
    system("color 0F"); // for Background: Black, Text: Bright White
    PrintingText::PrintSequenceOfCharacters('=', 24);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen("Program has done :)");
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('=', 24);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen("Press any key to end the program");
    cin.get();
    return;
}

void PerformMainMenuOptions(enMainMenuOptions UserChoice)
{
    switch (UserChoice)
    {
    case enMainMenuOptions::ShowClientsListScreen:
        ClearScreen();
        system("color 02"); // for Background: Black, Text: Green
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        PrintClientsInfo(enUserPermissions::PListClients, CurrentUser.Permissions);
        GoingBackToMainScreen();
        break;
    case enMainMenuOptions::AddNewClientScreen:
        ClearScreen();
        system("color 03"); // for Background: Black, Text: Aqua
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        AddNewclient(CurrentUser.Permissions);
        GoingBackToMainScreen();
        break;
    case enMainMenuOptions::DeleteClientInfoScreen:
        ClearScreen();
        system("color 04"); // for Background: Black, Text: Red
        //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        DeleteClientByAccountNumber("Clients", CurrentUser.Permissions);
        GoingBackToMainScreen();
        break;
    case enMainMenuOptions::UpdateClientInfoScreen:
        ClearScreen();
        system("color 09"); // for Background: Black, Text: Light Blue
        //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        UpdateClientByAccountNumber("Clients", CurrentUser.Permissions);
        GoingBackToMainScreen();
        break;
    case enMainMenuOptions::FindClientInfoScreen:
        ClearScreen();
        system("color 07"); // for Background: Black, Text: White
        //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        PrintingClientInfoByAccountNumber("Clients", CurrentUser.Permissions);
        // PrintingClientInfoByAccountNumber("Clients", CurrentUser.Permissions);
        GoingBackToMainScreen();
        break;
    case enMainMenuOptions::Transactions:
        ClearScreen();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        DrawingTransactionsMenu();
        break;
    case enMainMenuOptions::ManageUsers:
        ClearScreen();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        DrawingManageUsersMenu(CurrentUser.Permissions);
        break;
    case enMainMenuOptions::Logout:
        ClearScreen();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Login(CurrentUser, "Users");
        DrawingMainMenu();
        break;
    case enMainMenuOptions::ExitScreen:
        ClearScreen();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ShowEndScreen();
        break;
    default:
        PrintingText::PrintTextOnScreen("You did not choose a valid choice, and this will never happen cuz i already forced you to choose a valid choice :)");
        break;
    }
}

short CalculateTheStarterPoint(short LengthOfRow, short LengthOfPrintedText)
{
    return (LengthOfRow - LengthOfPrintedText) / 2 + 5;
}

void PrintTextInSpecialWay(const string &Text)
{
    short LengthOfText = Text.length();
    for (short Loop = 0; Loop < LengthOfText; Loop++)
    {
        cout << Text[Loop];
        Sleep(40);
    }
}

void ThisIsMe()

{
    short Rows = 11;
    short Columns = 61;

    // -----------------------------------------------------------------------------------------
    string ThisIsMe = "I AM MRH :)";
    short LengthOfThisIsMe = ThisIsMe.length();
    short StarterPoint = CalculateTheStarterPoint(Columns, LengthOfThisIsMe);
    StarterPoint -= 2;
    short HalfOfRows = Rows / 2;
    // -----------------------------------------------------------------------------------------

    // -----------------------------------------------------------------------------------------
    string ToContactMe = "If You want to contact me";
    short LengthOfToContactMe = ToContactMe.length();
    short _StarterPoint = CalculateTheStarterPoint(Columns, LengthOfToContactMe);
    // -----------------------------------------------------------------------------------------

    // -----------------------------------------------------------------------------------------
    string MyPhoneNumber = "+967736535350";
    short LengthOfMyPhoneNumber = MyPhoneNumber.length();
    short __StarterPoint = CalculateTheStarterPoint(Columns, LengthOfMyPhoneNumber);
    __StarterPoint -= 3;
    // -----------------------------------------------------------------------------------------

    ClearScreen();

    system("color 02");

    for (short OuterLoop = 0; OuterLoop < Rows; OuterLoop++)
    {
        for (short InnerLoop = 0; InnerLoop < Columns; InnerLoop++)
        {
            if (OuterLoop == (Rows - Rows) || OuterLoop == (Rows - 1))
            {
                cout << "* ";
            }
            else if (InnerLoop == (Columns - Columns) || InnerLoop == (Columns - 1))
            {
                cout << "* ";
            }
            else if (OuterLoop == HalfOfRows && InnerLoop == StarterPoint)
            {
                PrintTextInSpecialWay(ThisIsMe);
                PrintingText::PrintSpaces((Columns * 2) - (StarterPoint * 2 + LengthOfThisIsMe + 1) - 1);
                cout << "* ";
                break;
            }
            else if (OuterLoop == HalfOfRows + 1 && InnerLoop == _StarterPoint + 1)
            {
                PrintTextInSpecialWay(ToContactMe);
                PrintingText::PrintSpaces((Columns * 2) - (_StarterPoint * 2 + LengthOfToContactMe + 1) - 3);
                cout << "* ";
                break;
            }
            else if (OuterLoop == HalfOfRows + 2 && InnerLoop == __StarterPoint + 2)
            {
                PrintTextInSpecialWay(MyPhoneNumber);
                PrintingText::PrintSpaces((Columns * 2) - (__StarterPoint * 2 + LengthOfMyPhoneNumber + 1) - 5);
                cout << "* ";
                break;
            }
            else
            {
                cout << "  ";
            }
            cout.flush(); // Immediately print the output
            Sleep(20);    // Delay in milliseconds
        }

        cout << endl;
    }
    sleep(4);
}

void JustWaitForIt()
{
    ClearScreen();
    system("color 02");
    cout << "Just wait for it...";
    sleep(1);
}

short ReadUserChoice(short From, short To)
{
    short Number = 0;
    do
    {
        string Message = "Enter a number [" + to_string(From) + "-" + to_string(To) + "]: ";
        Number = ReadNumbers::ReadingShortNumber(Message);
    } while (!ValidingNumbers::isNumberInRange(Number, From, To)); // to force the user to enter a number from 1 to 7
    return Number;
}

void DrawingMainMenu()
{

    ClearScreen();
    system("color 0F"); // for Background: Black, Text: Bright White

    short NumberOfTabs = 1;

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs + 1);
    PrintingText::PrintTextOnScreen("Main Menu");
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[1] Show Clients List");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[2] Add New Client");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[3] Delete Client");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[4] Update Client");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[5] Find Client");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[6] Transactions");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[7] Manage Users");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[8] Logout ");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[9] Exit");
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();

    short Number = ReadUserChoice(1, 9);
    enMainMenuOptions UserChoice = (enMainMenuOptions)Number;
    PerformMainMenuOptions(UserChoice);
}

void PerformTransactionsOptions(enTransactionsMenuOptions UserChoice)
{
    switch (UserChoice)
    {
    case enTransactionsMenuOptions::DepositScreen:
        ClearScreen();
        system("color 02"); // for Background: Black, Text: Green
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        DepositBalance();
        GoingBackToTransactionsMenu();
        break;
    case enTransactionsMenuOptions::WithDrawScreen:
        ClearScreen();
        system("color 04"); // for Background: Black, Text: Red
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        WithdrawBalance();
        GoingBackToTransactionsMenu();
        break;
    case enTransactionsMenuOptions::TotalBalances:
        ClearScreen();
        system("color 04"); // for Background: Black, Text: Red
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        PrintTotalBalancesOfAllClients();
        GoingBackToTransactionsMenu();
        break;
    case enTransactionsMenuOptions::ExitScreen:
        DrawingMainMenu();
        break;
    default:
        PrintingText::PrintTextOnScreen("You will never reach to the default case, but if we reached, i believe there is a bug :(");
        break;
    }
}

void DrawingTransactionsMenu()
{
    if (!CheckIfUserHasAccessToTransactionMenu(CurrentUser.Permissions))
    {
        GoingBackToMainScreen();
        return;
    }

    ClearScreen();
    system("color 0F"); // for Background: Black, Text: Bright White

    short NumberOfTabs = 1;

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs + 1);
    PrintingText::PrintTextOnScreen("Transactions Menu");
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[1] Deposit");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[2] Withdraw");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[3] Total Balances");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[4] Exit");
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();
    
    short Number = ReadUserChoice(1, 4);
    enTransactionsMenuOptions UserChoice = (enTransactionsMenuOptions)Number;
    PerformTransactionsOptions(UserChoice);
}

void DrawingManageUsersMenu(int UserPermission)
{
    if (!CheckIfUserHasAccessToManageUsersMenu(UserPermission))
    {
        GoingBackToMainScreen();
        return;
    }

    ClearScreen();

    system("color 0F"); // for Background: Black, Text: Bright White

    short NumberOfTabs = 1;

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintSpaces(4);
    PrintingText::PrintTextOnScreen("Manage Users Menu");
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[1] List users");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[2] Add new user");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[3] Delete User");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[4] Update User");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[5] Find User");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[6] Current User");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[7] Exit");
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();

    short Number = ReadUserChoice(1, 7);
    enManageUsers UserChoice = (enManageUsers)Number;
    PerformManageUsersOptions(UserChoice);
}

void PerformManageUsersOptions(enManageUsers UserChoice)
{
    switch (UserChoice)
    {
    case enManageUsers::ListUsersScreen:
        ClearScreen();
        system("color 02"); // for Background: Black, Text: Green
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ShowUsersList("Users");
        GoBackToManageUsersMenu();
        break;
    case enManageUsers::AddNewUserScreen:
        ClearScreen();
        system("color 02"); // for Background: Black, Text: Green
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        AddNewUser("Users");
        GoBackToManageUsersMenu();
        break;
    case enManageUsers::DeleteUserScreen:
        ClearScreen();
        system("color 04"); // for Background: Black, Text: Red
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        DeleteUser("Users");
        GoBackToManageUsersMenu();
        break;
    case enManageUsers::UpdateUserScreen:
        ClearScreen();
        system("color 09"); // for Background: Black, Text: Light Blue
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        UpdateUser("Users");
        GoBackToManageUsersMenu();
        break;
    case enManageUsers::FindUserScreen:
        ClearScreen();
        system("color 07"); // for Background: Black, Text: White
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        FindUser("Users");
        GoBackToManageUsersMenu();
        break;
    case enManageUsers::ShowCurrentUserInfo:
        ClearScreen();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("color 09"); // for Background: Black, Text: Light Blue
        PrintStructures::PrintUserInfo(CurrentUser);
        GoBackToManageUsersMenu();
        break;
    case enManageUsers::ExitScreen:
        ClearScreen();
        GoingBackToMainScreen();
        break;
    default:
        PrintingText::PrintTextOnScreen("if we reach here that mean that you got a problem :(");
        PrintingText::PrintLines();
        break;
    }
}

void GreetingMessage()
{

    ClearScreen();
    system("color 02"); // for Background: Black, Text: Green
    PrintingText::PrintSequenceOfCharacters('=', 160);
    PrintingText::PrintLines();
    PrintingText::PrintTabs(2);
    PrintingText::PrintTextOnScreen("Welcome To Our Bank Project, We Hope you will enjoy and have good experience, the program will start in few seconds :)\n");
    PrintingText::PrintSequenceOfCharacters('=', 160);
    PrintingText::PrintLines();
    sleep(8);
    ClearScreen();
}

void GoBackToManageUsersMenu()
{
    PrintingText::PrintTextOnScreen("Press any key to go back to manage users...");
    cin.get();
    ClearScreen();
    DrawingManageUsersMenu(CurrentUser.Permissions);
}

void PartThree()
{
    system("color 02");
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen("Bank project part Three\n");
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    sleep(2);
}

void MainScreen()
{

    if (Login(CurrentUser, "Users"))
    {
        ClearScreen();
        PartThree();
        JustWaitForIt();
        ThisIsMe();
        GreetingMessage();
        DrawingMainMenu();
    }
}
