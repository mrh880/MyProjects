#include "MainScreen.h"

// !!!!!! The main Operation to run the program !!!!!!
// -------------------------------------------------------------------
#include "ShowClientsListScreen.h"  // 1
#include "AddNewClientScreen.h"     // 2
#include "DeleteClientScreen.h"     // 3
#include "UpdateClientInfoScreen.h" // 5
#include "FindClientScreen.h"       // 6
#include "DepositScreenScreen.h"          // 7
#include "WithdrawScreenScreen.h"         // 8
#include "TotalBalancesScreen.h"    // 9
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

// --------------------------------------------------

using namespace std;

void GoingBackToMainScreen()
{
    // cin.ignore();
    PrintingText::PrintTextOnScreen("Press any key to go back to main menu...");
    cin.get();
    ClearScreen();
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
}

        
void PerformMainMenuOptions(enMainMenuOptions UserChoice)
{
    switch (UserChoice)
    {
    case enMainMenuOptions::ShowClientsListScreen:
        ClearScreen();
        system("color 02"); // for Background: Black, Text: Green
        cin.ignore();
        PrintClientsInfo();
        GoingBackToMainScreen();
        break;
    case enMainMenuOptions::AddNewClientScreen:
        ClearScreen();
        system("color 03"); // for Background: Black, Text: Aqua
        cin.ignore();
        AddNewclient();
        GoingBackToMainScreen();
        break;
    case enMainMenuOptions::DeleteClientInfoScreen:
        ClearScreen();
        system("color 04"); // for Background: Black, Text: Red
        cin.ignore(); 
        DeleteClientByAccountNumber("Clients");
        GoingBackToMainScreen();
        break;
    case enMainMenuOptions::UpdateClientInfoScreen:
        ClearScreen();
        system("color 09"); // for Background: Black, Text: Light Blue
        cin.ignore();
        UpdateClientByAccountNumber("Clients", ReadText::ReadTextOnScreen("Enter an account number: "));
        GoingBackToMainScreen();
        break;
    case enMainMenuOptions::FindClientInfoScreen:
        ClearScreen();
        system("color 07"); // for Background: Black, Text: White
        cin.ignore();
        PrintingClientInfoByAccountNumber("Clients", ReadText::ReadTextOnScreen("Enter an account number: "));
        GoingBackToMainScreen();
        break;

        case enMainMenuOptions::Transactions:
            ClearScreen();
            DrawingTransactionsMenu();
            break;

    case enMainMenuOptions::ExitScreen:
        ClearScreen();
        system("color 09"); // for Background: Black, Text: Light Blue
        cin.ignore();
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
                PrintingText::PrintSpaces((Columns * 2) - (__StarterPoint * 2 + LengthOfMyPhoneNumber + 1) -5);
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
        Number = ReadNumbers::ReadingShortNumber("Enter a number: ");
    }while(!ValidingNumbers::isNumberInRange(Number, From, To)); // to force the user to enter a number from 1 to 7 
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
    PrintingText::PrintTextOnScreen("[6] Transaction");
    PrintingText::PrintLines();
    
    PrintingText::PrintTabs(NumberOfTabs);
    PrintingText::PrintTextOnScreen("[7] Exit");
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();

    short Number = ReadUserChoice(1, 7);
    enMainMenuOptions UserChoice = (enMainMenuOptions) Number;
    PerformMainMenuOptions(UserChoice);
}



void PerformTransactionsOptions(enTransactionsMenuOptions UserChoice)
{
    switch(UserChoice)
    {
        case enTransactionsMenuOptions::DepositScreen:
            ClearScreen();
            system("color 02"); // for Background: Black, Text: Green
            cin.ignore();
            DepositBalance();
            GoingBackToTransactionsMenu();
            break;
        case enTransactionsMenuOptions::WithDrawScreen:
            ClearScreen();
            system("color 04"); // for Background: Black, Text: Red
            cin.ignore();
            WithdrawBalance();
            GoingBackToTransactionsMenu();
            break;
        case enTransactionsMenuOptions::TotalBalances:
            ClearScreen();
            system("color 04"); // for Background: Black, Text: Red
            cin.ignore();
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
    ClearScreen();
    system("color 0F"); // for Background: Black, Text: Bright White

    short NumberOfTabs = 1;

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();

    PrintingText::PrintTabs(NumberOfTabs + 1);
    PrintingText::PrintTextOnScreen("Transaction Menu");
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
    enTransactionsMenuOptions UserChoice = (enTransactionsMenuOptions) Number;
    PerformTransactionsOptions(UserChoice);
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



void PartTwo()
{
    system("color 02");
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen("Bank project part Two\n");
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    sleep(2);
}

void MainScreen()
{
    ClearScreen();
    PartTwo();
    JustWaitForIt();
    ThisIsMe();
    GreetingMessage();
    DrawingMainMenu();
}
