//
// Created by AlexanderSYN on 09.09.2025.
//

#include "../../helper_header/work_with_files/helper_open_file.h"

#include "../../helper_header/work_with_files/for_time.h"

//
// for cd to check path before writing (cd ... <-)
//
void FILEO::set_path_in_cd(std::string user_input, std::string & path)
{
    std::string tmp_path;
    std::string path_f = user_input.substr(3);

    if (user_input[user_input.size()] != '\\' && !path.ends_with("\\"))
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
// open folder use dir (i.e. D:\ >> dir)
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
void FILEO::open_file(const std::string path)
{

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

//
// out all files for all OS (work like dir)
//
void FILEO::output_all_files_command_open(const fs::path path_f) {
    try
    {
        if (!fs::exists(path_f) || !fs::is_directory(path_f))
        {
            std::cout << "ERROR: folder ( " << path_f << " ) is not found!" << std::endl;
            return;
        }

        std::cout << "Contents of " << path_f << ":" << std::endl;

        for (const auto& entry : fs::directory_iterator(path_f))
        {
            auto ftime = entry.last_write_time();
            std::string hidden_marker = "";

#ifdef _WIN32
            DWORD attrs = GetFileAttributesA(entry.path().string().c_str());
            if (attrs != INVALID_FILE_ATTRIBUTES && (attrs & FILE_ATTRIBUTE_HIDDEN))
            {
                hidden_marker = " [HIDDEN]";
            }
#else // for MacOS / Linux
            if (entry.path().filename().string()[0] == ".")
            {
                hidden_marker = " [HIDDEN]";
            }
#endif

            if (fs::is_directory(entry.status()))
            {
                std::cout << std::setw(20) << timeff::format_time(ftime)
                    << std::setw(8) << "[DIR]"
                    << std::setw(10) << hidden_marker
                    << entry.path().filename() << std::endl;
            }
            else
            {
                std::cout << std::setw(20) << timeff::format_time(ftime)
                    << std::setw(10) << std::to_string(entry.file_size()) << " bytes"
                    << std::setw(8) << "[FILE]"
                    << std::setw(10) << hidden_marker
                    << entry.path().filename() << std::endl;
            }
        }
    }
    catch (const fs::filesystem_error& fs_err)
    {
        std::cerr << "[ERROR] " << fs_err.what() << std::endl;
    }
}


