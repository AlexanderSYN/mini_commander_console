//
// Created by AlexanderSYN on 10.09.2025.
//

#include "../../helper_header/work_with_files/helper_create_file.h"

//
// create / cr ... <- (path) ... <- (file/folder) ... <- (name file/folder)
//
void FILEC::create_file(std::string user_input, std::string path)
{
    try {
        std::string path_tmp = FILEC::get_path_for_create(user_input);
        std::string file_or_folder = FILEC::check_isFile_for_create(user_input);
        std::string name_file_folder = FILEC::get_name_file_folder_for_create(user_input);

        if (path_tmp == "path") {
            std::cout << path << std::endl;
            if (!fs::exists(path)) {
                std::cerr << "ERROR Folder not found!" << std::endl;
                return;
            }
            path_tmp = path;
        }

        // check for error
        if (!fs::exists(path_tmp)) {
            std::cerr << "ERROR Folder not found!" << std::endl;
            return;
        }
        if (file_or_folder == "ERROR") {
            std::cerr << "[ERROR][file or folder] you may have entered the command incorrectly, check the command by writing help"
                    << std::endl;
            return;
        }
        if (name_file_folder == "ERROR") {
            std::cerr << "[ERROR][name file folder] you may have entered the command incorrectly, check the command by writing help"
                    << std::endl;
            return;
        }
        // End check

        // create file / folder
        // create folder
        if (file_or_folder == "folder") {
            FILEC::createFF(path_tmp, file_or_folder, name_file_folder);
            return;
        }
        else if (file_or_folder == "file") {
            FILEC::createFF(path_tmp, file_or_folder, name_file_folder);
            return;
        }

    } catch (std::exception e) {
        std::cerr << "[ERROR] you may have entered the command incorrectly, check the command by writing help"
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
std::string FILEC::check_isFile_for_create(std::string user_input)
{
    try {
        int tmp_index_path = 0;
        std::string tmp_path, folder_or_file;

        // create
        if (user_input.substr(0, 7) == "create ") {
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

            return folder_or_file;

        }
        // cr
        else if (user_input.substr(0, 3) == "cr ") {
            tmp_path = user_input.substr(3);

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
        std::cerr << "[ERROR] you may have entered the command incorrectly, check the command by writing help"
                "[ERROR: " << e.what() << "]" << std::endl;
        return "ERROR";
    }
}

//
// find name (create path  file / folder (get) -> name <- )
//
std::string FILEC::get_name_file_folder_for_create(std::string user_input) {
    std::string result;

    try {
        int tmp_index_path = 0;
        std::string tmp_path;
        std::string tmp_name_file;

        if (user_input.substr(0, 7) == "create ") {
            tmp_path = user_input.substr(7);

            for (int i = 0; tmp_path[i] != ' '; i++, tmp_index_path++); // here find a space after path
            for (int j = 1; tmp_path[tmp_index_path + j] != ' '; j++, tmp_index_path++); // here find a space after file / folder

            tmp_index_path += 5;

            result = tmp_path.substr(tmp_index_path);
            // delete all spaces in name file or folder
            result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

            return result;

        }
        else if (user_input.substr(0, 3) == "cr ") {
            tmp_path = user_input.substr(3);

            for (int i = 0; tmp_path[i] != ' '; i++, tmp_index_path++); // here find a space after path
            for (int j = 1; tmp_path[tmp_index_path + j] != ' '; j++, tmp_index_path++); // here find a space after file / folder

            tmp_index_path += 4;

            result = tmp_path.substr(tmp_index_path);
            // delete all spaces in name file or folder
            result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

            return result;
        }

        return "ERROR";
    } catch (std::exception e) {
        std::cout << "[ERROR] " << e.what() << std::endl;
        return "ERROR";
    }
}

//
// createFF - create FF
// create folder (nameFF - name file folder)
//
void FILEC::createFF(std::string path, std::string file_or_folder, std::string nameFF) {

    // create file
    if (file_or_folder == "file")
    {
        std::string tmp_full_path_with_file;

        // checking for the validity of the file name
        if (nameFF.find(".") == std::string::npos) {
            std::cerr << "ERROR: This is not a valid file name. Please add a file extension!" << std::endl;
            return;
        }

        // checking for the validation of the file name
        if (nameFF.empty() || nameFF.find_first_of("\\/:*?\"<>|") != std::string::npos) {
            std::cerr << "ERROR: Invalid file name characters detected" << std::endl;
            return;
        }

        try {
            tmp_full_path_with_file += path;

            if (tmp_full_path_with_file.ends_with("\\"))
                tmp_full_path_with_file += nameFF;
            else {
                tmp_full_path_with_file += "\\";
                tmp_full_path_with_file += nameFF;
            }

            //
            // check file in folder, if has then just do nothing
            //
            if (fs::exists(tmp_full_path_with_file)) {
                std::cerr << "ERROR: the file already exists!" << std::endl;
                return;
            }

            // create file
            std::ofstream file(tmp_full_path_with_file);

            // checking file creation
            if (!fs::exists(tmp_full_path_with_file)) {
                std::cerr << "ERROR: failed to create file!" << std::endl;
                return;
            }

            file.close();

            std::cout << "FILE: " << nameFF << " created successfully!" << std::endl;
            std::cout << "THE FILE IS LOCATED: " << path << " !" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "ERROR creating file: " << e.what() << std::endl;
        }
    }

    // create folder
    else if (file_or_folder == "folder") {
        fs::path full_path_folder = fs::path("L") / path / nameFF;

        if (!fs::exists(full_path_folder))
        {
            if (fs::create_directory(full_path_folder)) {
                std::cout << "Folder created successfully!" << std::endl;
                return;
            }
            else
            {
                std::cerr << "ERROR: the folder already exists!" << std::endl;
                return;
            }
        }
        else {
            std::cerr << "ERROR: the folder is not created!" << std::endl;
        }
    }
    else {
        std::cerr << "ERROR: you need choice: file or folder!" << std::endl;
        return;
    }
}
