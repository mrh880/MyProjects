#include "MainScreen.h"

#include "Libraries\PrintingOutputs.h"
#include "Libraries\ClearingScreenFunctions.h"
#include "Libraries\ReadingInputs.h"
#include "Libraries\validingData.h"
#include "Libraries\Structures.h"
#include <limits>
#include <iostream>

#include "Libraries\DealingWithBuffer.h"

#include "QuickWithdrawScreen.h"
#include "NormalWithdrawScreen.h"
#include "DeposingScreen.h"
#include "CheckClientBalanceScreen.h"
#include "LoginScreen.h"

using namespace std;

const string FileName = "Clients";
stClientInfo CurrentClient;

void DrawingMainMenu()
{

    ClearScreen();

    system("color 02"); // for Background: Black, Text: Green

    short NumberOfTabs = 1;
    PrintingText::PrintSequenceOfCharacters('*', 44);
    PrintingText::PrintLines();
    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintSpaces(4);
    PrintingText::PrintTextOnScreen("ATM Main Menu Screen");
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 44);
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[1] Quick withdraw");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[2] Normal withdraw");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[3] Deposit");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[4] Check balance");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[5] Logout");
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[6] Exit");
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 44);
    PrintingText::PrintLines();

    short Number = ReadNumbers::ReadUserChoice(1, 6, 44);
    enMainMenuOptionsOf_ATM_Screen UserChoice = (enMainMenuOptionsOf_ATM_Screen)Number;
    PerformMainMenuOptions(UserChoice);
}

void PerformMainMenuOptions(enMainMenuOptionsOf_ATM_Screen OPtion)
{
    switch (OPtion)
    {

    case enMainMenuOptionsOf_ATM_Screen::enQuickWithDrawScreen:
        ClearScreen();
        system("color 04"); // for Background: Black, Text: Red
        FlushInputBuffer();
        QuickWithDraw(FileName, CurrentClient);
        GoBackToMainMenu();
        break;
    case enMainMenuOptionsOf_ATM_Screen::enNormalWithDrawScreen:
        ClearScreen();
        system("color 04"); // for Background: Black, Text: Red
        NormalWithdraw(FileName, CurrentClient);
        GoBackToMainMenu();
        break;
    case enMainMenuOptionsOf_ATM_Screen::enDepositScreen:
        ClearScreen();
        system("color 02"); // for Background: Black, Text: Green
        DepositClientBalance(FileName, CurrentClient);
        GoBackToMainMenu();
        break;
    case enMainMenuOptionsOf_ATM_Screen::CheckClientBalanceScreen:
        ClearScreen();
        // FlushInputBuffer();
        // PrintingText::PrintTextOnScreen("This section is under development !!!");
        // PrintingText::PrintLines(2);
        system("color 09"); // for Background: Black, Text: Light Blue
        PrintclientBalance(FileName, CurrentClient);
        GoBackToMainMenu();
        break;
    case enMainMenuOptionsOf_ATM_Screen::LogoutScreen:
        ClearScreen();
        FlushInputBuffer();
        // PrintingText::PrintTextOnScreen("This section is under development !!!");
        // PrintingText::PrintLines(2);
        Loging(FileName, CurrentClient);
        DrawingMainMenu();
        break;
    case enMainMenuOptionsOf_ATM_Screen::ExitScreen:
        ClearScreen();
        FlushInputBuffer();
        // system("color 0F"); // for Background: Black, Text: Bright White
        ShowEndScreen();
        break;
    default:
        PrintingText::PrintTextOnScreen("If you here it means that you have mistake in your code, please review your code again !!");
        PrintingText::PrintLines();
        break;
    }
}

void GoBackToMainMenu()
{
    PrintingText::PrintTextOnScreen("Press enter to go back to main menu...");
    cin.get();
    ClearScreen();
    DrawingMainMenu();
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
    PrintingText::PrintTextOnScreen("Press enter to end the program...");
    cin.get();
}

void MainScreen()
{
    if(Loging(FileName, CurrentClient))
    {
        DrawingMainMenu();
    }
}