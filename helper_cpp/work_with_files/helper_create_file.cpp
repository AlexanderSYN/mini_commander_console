//
// Created by AlexanderSYN on 10.09.2025.
//

#include "../../helper_header/work_with_files/helper_create_file.h"

//
// create / cr ... ... ...
//
void FILEC::create_file(std::string user_input, std::string path)
{
    try {
        std::string path_tmp = FILEC::get_path_for_create(user_input);
        std::string file_or_folder = FILEC::check_isFile_for_create(user_input);

        // check for error in file_or_folder
        if (file_or_folder == "ERROR") {
            std::cout << "[ERROR] you may have entered the command incorrectly, check the command by writing help"
                      << std::endl;
            return;
        }
        // End check


        if (path_tmp == "path") {
            if (!fs::exists(path)) {
                std::cout << "ERROR Folder not found!" << std::endl;
                return;
            }
            path_tmp = path;
        }

        // create file / folder
        // create folder
        if (file_or_folder == "folder") {
            
        }

    } catch (std::exception e) {
        std::cout << "[ERROR] you may have entered the command incorrectly, check the command by writing help"
                     "[ERROR: " << e.what() << "]" << std::endl;
        return;
    }

}


//
// get path (create ... <- (here get a path), you can also write path and there has your path when you write in cd)
//
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

//
// check file or folder ( create path ... <- (file/folder) ) if true - file otherwise false - folder
//
std::string FILEC::check_isFile_for_create(std::string user_input) {
    try {
        int tmp_index_path = 0;
        std::string tmp_path, folder_or_file;

        if (user_input.substr(0, 7) == "create ")
        {
            tmp_path = user_input.substr(7);

            for (int i = 0; tmp_path[i] != ' '; i++, tmp_index_path++);

            for (int j = 1; tmp_path[tmp_index_path + j] != ' '; j++)
                folder_or_file += tmp_path[tmp_index_path + j];

            if (folder_or_file == "file" || folder_or_file == "file ")
                return "file";
            else if (folder_or_file == "folder" || folder_or_file == "folder ")
                return "folder";
            else
                return "ERROR";

            std::cout << folder_or_file;

            return folder_or_file;
        }

        return "ERROR";
    } catch (std::exception e) {
        std::cout << "[ERROR] you may have entered the command incorrectly, check the command by writing help"
                     "[ERROR: " << e.what() << "]" << std::endl;
        return "ERROR";
    }
}



