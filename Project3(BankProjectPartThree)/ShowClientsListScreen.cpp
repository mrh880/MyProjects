#include "ShowClientsListScreen.h"

#include "Libraries\PrintingOutputs.h"
#include "CheckUserPermission.h"

void PrintClientsInfo(enUserPermissions CurrentPermissionForThisPage, int UserPermission)
{
    if(!CheckIfUserHasAccessToListClients(UserPermission))
    {
        return;
    }
    PrintStructures::PrintClientsInfoList("Clients");
}

