#include "ClearingScreenFunctions.h"

#include <cstdlib> 

// This function clear the screen for most modern terminal
// -----------------------------------------------------------------------------
void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033c" << std::flush; // ANSI: reset terminal (Git Bash compatible)
#endif
}
// -----------------------------------------------------------------------------
