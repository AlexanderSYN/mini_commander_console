//
// Created by Alexander on 12.09.2025.
//

#ifndef HELPER_FOR_FIND_FF_H
#define HELPER_FOR_FIND_FF_H

#include "../work_with_files/include_for_work_with_files.h"


#include <stack>
#include <algorithm>

class FILEF {
public:
    // findFF - find File Folder
    static void findFF(std::string user_input, std::string path_f);

private:

    //
    // The list of system directories to skip (can be expanded)
    //
    static const std::vector<std::string> SYSTEM_DIRECTORIES;

    //
    // List of system file extensions (can be expanded)
    //
    static const std::vector<std::string> SYSTEM_EXTENSIONS;

    //
    // The function of checking whether the path is system-defined
    //
    static bool is_system_path(const fs::path& path);
};


#endif //HELPER_FOR_FIND_FF_H