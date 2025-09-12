//
// Created by AlexanderSYN on 10.09.2025.
//

#ifndef HELPER_CREATE_FILE_H
#define HELPER_CREATE_FILE_H

#include "include_for_work_with_files.h"

class FILEC {
public:
    static void create_file(std::string user_input, std::string path);

private:
    static std::string get_path_for_create(std::string user_input);
    static std::string check_isFile_for_create(std::string user_input);
    static std::string get_name_file_folder_for_create(std::string user_input);
    static void createFF(std::string path, std::string file_or_folder, std::string nameFF);
};

#endif //HELPER_CREATE_FILE_H
