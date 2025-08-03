#pragma once

#include "Libraries\Enums.h"

bool CheckIfUserHasPermissionToEnterThisPage(enUserPermissions CurrentPermissionForThisPage, int  UserPermission);

bool CheckIfUserHasAccessToListClients(int UserPermission);

bool CheckIfUserHasAccessToAddNewClient(int UserPermission);

bool CheckIfUserHasAccessToDeleteClient(int UserPermission);

bool CheckIfUserHasAccessToUpdateClient(int UserPermission);


bool CheckIfUserHasAccessToFindClient(int UserPermission);

bool CheckIfUserHasAccessToTransactionMenu(int UserPermission);

bool CheckIfUserHasAccessToManageUsersMenu(int UserPermission);






