#include "AddNewClientScreen.h"

#include "Libraries\ReadingInputs.h"
#include "CheckUserPermission.h"

void AddNewclient(int UserPermission)
{
       if(!CheckIfUserHasAccessToAddNewClient(UserPermission))
    {
        return;
    }

    ReadingStructures::ReadClientsInfo();
}