//
// Created by AlexanderSYN on 08.09.2025.
//

#ifndef HELPER_OPEN_FILE_H
#define HELPER_OPEN_FILE_H

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
#include <vector>

namespace fs = std::filesystem;

class FILEO {
public:
    static void set_path_in_cd(std::string user_input, std::string & path);
    static void open_folder_use_dir(const std::string path);
    static void open_file(const std::string path);
};

#endif //HELPER_OPEN_FILE_H
