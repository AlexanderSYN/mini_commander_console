//
// Created by AlexanderSYN on 10.09.2025.
//

#include "../../helper_header/work_with_files/helper_create_file.h"

//
// create / cr ... ... ...
//
void FILEC::create_file(std::string user_input, std::string path)
{
    std::string path_tmp = FILEC::get_path_for_create(user_input);
    if (path_tmp == "path") {
        if (!fs::exists(path)) {
            std::cout << "ERROR Folder not found!" << std::endl;
            return;
        }
        path_tmp = path;
    }
    std::cout << path_tmp;

}

std::string FILEC::get_path_for_create(std::string user_input) {
    std::string tmp_path;
    std::string result;

    if (user_input.substr(0, 7) == "create ") {
        tmp_path = user_input.substr(7);
        for (int i = 0; tmp_path[i] != ' '; i++) {
            result += tmp_path[i];
        }

        return result;
    }
    else if (user_input.substr(0, 3) == "cr ") {
        tmp_path = user_input.substr(3);
        for (int i = 0; tmp_path[i] != ' '; i++) {
            result += tmp_path[i];
        }

        return result;
    }

    return "ERROR";
}


