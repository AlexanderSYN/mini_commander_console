//
// Created by AlexanderSYN on 08.09.2025.
//

#ifndef HELPER_OPEN_FILE_H
#define HELPER_OPEN_FILE_H

#include "include_for_work_with_files.h"

class FILEO {
public:
    static void set_path_in_cd(std::string user_input, std::string & path);
    static void open_folder_use_dir(const std::string path);
    static void open_file(const std::string path);
    static void output_all_files_command_open(const fs::path path_f);
};

#endif //HELPER_OPEN_FILE_H
