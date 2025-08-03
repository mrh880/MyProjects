#include "CheckUserPermission.h"

#include "Libraries\Enums.h"

#include "Libraries\PrintingOutputs.h"

bool CheckIfUserHasPermissionToEnterThisPage(enUserPermissions CurrentPermissionForThisPage, int UserPermission)
{
    if (UserPermission == enUserPermissions::PAll)
    {
        return true;
    }

    if ((CurrentPermissionForThisPage & UserPermission) == CurrentPermissionForThisPage)
    {
        return true;
    }

    return false;
}

bool CheckIfUserHasAccessToListClients(int UserPermission)
{
    if (!CheckIfUserHasPermissionToEnterThisPage(enUserPermissions::PListClients, UserPermission))
    {

        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines();
        PrintingText::PrintTabs(1);
        PrintingText::PrintSpaces(4);
        PrintingText::PrintTextOnScreen("!!!!!! Client List Screen !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines(2);

        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("You do not have Permission to enter this page, please contact your admin !!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines(2);
        return false;
    }
    return true;
}

bool CheckIfUserHasAccessToAddNewClient(int UserPermission)
{
    if (!CheckIfUserHasPermissionToEnterThisPage(enUserPermissions::PAddNewClient, UserPermission))
    {
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines();
        PrintingText::PrintTabs(1);
        PrintingText::PrintSpaces(4);
        PrintingText::PrintTextOnScreen("!!!!!! Add Client Screen !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines(2);

        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("You do not have Permission to enter this page, please contact your admin !!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines(2);
        return false;
    }
    return true;
}

bool CheckIfUserHasAccessToDeleteClient(int UserPermission)
{
    if (!CheckIfUserHasPermissionToEnterThisPage(enUserPermissions::PDeleteClient, UserPermission))
    {
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines();
        PrintingText::PrintTabs(1);
        PrintingText::PrintSpaces(4);
        PrintingText::PrintTextOnScreen("!!!!!! Delete Client Screen !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines(2);

        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("You do not have Permission to enter this page, please contact your admin !!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines(2);
        return false;
    }
    return true;
}

bool CheckIfUserHasAccessToUpdateClient(int UserPermission)
{
    if (!CheckIfUserHasPermissionToEnterThisPage(enUserPermissions::PUpdateClient, UserPermission))
    {
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines();
        PrintingText::PrintTabs(1);
        PrintingText::PrintSpaces(4);
        PrintingText::PrintTextOnScreen("!!!!!! Update Client Screen !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines(2);

        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("You do not have Permission to enter this page, please contact your admin !!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines(2);
        return false;
    }
    return true;
}

bool CheckIfUserHasAccessToFindClient(int UserPermission)
{
    if (!CheckIfUserHasPermissionToEnterThisPage(enUserPermissions::PFindClient, UserPermission))
    {
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines();
        PrintingText::PrintTabs(1);
        PrintingText::PrintSpaces(4);
        PrintingText::PrintTextOnScreen("!!!!!! Find Client Screen !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines(2);

        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("You do not have Permission to enter this page, please contact your admin !!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines(2);
        return false;
    }
    return true;
}

bool CheckIfUserHasAccessToTransactionMenu(int UserPermission)
{
    if (!CheckIfUserHasPermissionToEnterThisPage(enUserPermissions::PTransaction, UserPermission))
    {
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines();
        PrintingText::PrintTabs(1);
        PrintingText::PrintSpaces(4);
        PrintingText::PrintTextOnScreen("!!!!!! Transactions Menu !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines(2);

        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("You do not have Permission to enter this page, please contact your admin !!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines(2);
        return false;
    }
    return true;
}

bool CheckIfUserHasAccessToManageUsersMenu(int UserPermission)
{
    if (!CheckIfUserHasPermissionToEnterThisPage(enUserPermissions::PManageUsers, UserPermission))
    {
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines();
        PrintingText::PrintTabs(1);
        PrintingText::PrintSpaces(4);
        PrintingText::PrintTextOnScreen("!!!!!! Manage Users Menu !!!!!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('*', 60);
        PrintingText::PrintLines(2);

        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines();
        PrintingText::PrintTextOnScreen("You do not have Permission to enter this page, please contact your admin !!!");
        PrintingText::PrintLines();
        PrintingText::PrintSequenceOfCharacters('-', 80);
        PrintingText::PrintLines(2);
        return false;
    }
    return true;
}
