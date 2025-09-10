//
// Created by AlexanderSYN on 10.09.2025.
//

#ifndef HELPER_CREATE_FILE_H
#define HELPER_CREATE_FILE_H

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


class FILEC {
public:
    static void create_file(std::string user_input, std::string path);

private:
    static std::string get_path_for_create(std::string user_input);

};

#endif //HELPER_CREATE_FILE_H
