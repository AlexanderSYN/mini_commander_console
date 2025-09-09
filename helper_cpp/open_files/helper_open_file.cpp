//
// Created by AlexanderSYN on 09.09.2025.
//

#include "../../helper_header/open_files/helper_open_file.h"

//
// for cd to check path before writing
//
void FILEO::set_path_in_cd(std::string user_input, std::string & path)
{
    std::string tmp_path;
    std::string path_f = user_input.substr(3);

    if (user_input[user_input.size()] != '\\')
        tmp_path = path + '\\' + path_f;
    else
        tmp_path = path + path_f;

    if (path_f == "..") {
        if (!path.empty() && path != "/") {
            fs::path current_path(path);
            path = current_path.parent_path().string();
        }
        return;

    }


    if (!fs::exists(path_f))
    {
        if (fs::exists(tmp_path))
        {
            path = tmp_path;
            return;
        }

        std::cout << "Folder is not found!" << std::endl;
        return;
    }

    path = path_f;
}

//
// open folder use dir
//
void FILEO::open_folder_use_dir(const std::string path)
{
    if (!fs::exists(path)) {
        std::cout << "ERROR: folder is not found!" << std::endl;
        return;
    }

    try
    {
        std::string command = "dir /a \"" + path + "\"";
        system(command.c_str());
    }
    catch (const std::exception& e)
    {
        std::cout << "[ERROR] " << e.what() << std::endl;
    }
}

//
// open file
//
void FILEO::open_file(const std::string path) {
    try
    {
#if defined(_WIN32) //Windows
        std::string command = "start \"\" \"" + path + "\"";
#elif defined(__APPLE__) // MacOs
        std::string command = "open \"" + path + "\"";
#elif defined(__linux__) //Linux
        std::string command = "xdg-open \"" + path + "\"";
#else
        std::cerr << "Unsupported OS" << std::endl;
        return;
#endif

        bool result = system(command.c_str());

        if (!result)
            std::cout << "[SUCCESS OPEN]" << std::endl;
        else
            std::cerr << "[ERROR OPEN]" << std::endl;

    }
    catch (const std::exception& e)
    {
        std::cerr << "[ERROR OPEN FILE] " << e.what() << std::endl;
        return;
    }

}

