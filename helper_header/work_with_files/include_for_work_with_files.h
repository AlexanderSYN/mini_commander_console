//
// Created by AlexanderSYN on 12.09.2025.
//

#ifndef INCLUDE_FOR_WORK_WITH_FILES_H
#define INCLUDE_FOR_WORK_WITH_FILES_H

#ifdef _IOSTREAM_
    #define IOSTREAM_INCLUDED 1
#else
    #include <iostream>
    #define IOSTREAM_INCLUDED 0
#endif

#ifdef _WINDOWS_
    #define WINDOWS_INCLUDED 1
#else
    #include <Windows.h>
    #define WINDOWS_INCLUDED 0
#endif

#ifdef __STRINGIFY__
    #define STRING_INCLUDED 1
#else
    #include <string>
    #define STRING_INCLUDED 0
#endif

#include <filesystem>
#include <algorithm>
#include <ctime>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <system_error>

#include <conio.h>
#include <stdio.h>

namespace fs = std::filesystem;

#endif //INCLUDE_FOR_WORK_WITH_FILES_H
