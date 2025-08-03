#pragma once

#include "Libraries\Enums.h"

#include <string>



void GoingBackToMainScreen();

void GoingBackToTransactionsMenu();

void ShowEndScreen();

void PerformMainMenuOptions(enMainMenuOptions UserChoice);

void DrawingMainMenu();

void MainScreen();

void GreetingMessage();

void ThisIsMe();

void JustWaitForIt();

short CalculateTheStarterPoint(short LengthOfRow, short LengthOfPrintedText);

void PrintTextInSpecialWay(const std::string &Text);

short ReadUserChoice(short From, short To);

void DrawingTransactionsMenu();

void PerformTransactionsOptions(enTransactionsMenuOptions UserChoice);

void PartThree();

void DrawingManageUsersMenu(int UserPermission);

void PerformManageUsersOptions(enManageUsers UserChoice);

void GoBackToManageUsersMenu();
