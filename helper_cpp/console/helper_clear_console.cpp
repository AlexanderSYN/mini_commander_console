//
// Created by AlexanderSYN on 08.09.2025.
//
#include "../../helper_header/console/helper_clear_console.h"

void clear_console()
{
    #ifdef _WIN32 // for windows
        system("cls");
    #else // for Mac OS / Linux
        system("clear");
    #endif
}
