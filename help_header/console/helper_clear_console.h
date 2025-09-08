//
// Created by AlexanderSYN on 08.09.2025.
//
#ifndef HELPER_CLEAR_H
#define HELPER_CLEAR_H

#ifdef _WIN32 // for windows
    #include <Windows.h>
#else // if Mac OS / Linux
    #include <stdlib.h>
#endif


void clear_console();

#endif //HELPER_CLEAR_H
