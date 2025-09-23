//
// Created by AlexanderSYN on 12.09.2025.
//

#include "../../helper_header/helper_for_find_folder_file/helper_for_find_FF.h"
#include "../../helper_header/work_with_files/helper_open_file.h"

//
// find (name file / folder)
//
void FILEF::findFF(std::string user_input, std::string path_f) {
    std::string nameFF = user_input.substr(5); // get file or folder
    std::string full_path;

    //---------------------------
    // for get full path
    if (!path_f.ends_with("\\")) {
        full_path += path_f += "\\";
        full_path += nameFF;
    } else {
        full_path += nameFF;
    }
    // ---------------------------

    fs::path path = path_f;

    char choice; // for choice of open in expl or not

    if (user_input.substr(0, 5) != "find ")
        return;

    if (path_f.empty() || path_f == "\\") {
        std::cout << "Enter a valid path" << std::endl;
        return;
    }

    if (!fs::exists(path)) {
        std::cout << "path is not found: " << path << std::endl;
        return;
    }

    // check for find file
    if (find_FileFolder(path, nameFF).empty()) {
        std::cout << "File / Folder do not found!" << std::endl;
        return;
    } else {
        std::cout << is_File_Or_Folder(path, nameFF) << " found: " << path << std::endl;
        std::cout << "open in explorer? (Y/N) >> ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

        if (toupper(choice) == 'Y') {
            std::cout << "[OPENING IN FILE MANAGER]" << std::endl;
            FILEO::open_file(path.string());
        }
    }
}

// find
std::string FILEF::find_FileFolder(const fs::path &directory, const std::string &NameFolderFile) {
    try {
        for (const auto &entry: fs::recursive_directory_iterator(directory)) {
            try {
                // we check whether the element is a file and whether its name matches
                if (entry.is_regular_file() && entry.path().filename() == NameFolderFile) {
                    std::string res_path = entry.path().string() += NameFolderFile;
                    return res_path; // return the path of the found file
                }
                else if (entry.is_directory() && entry.path().filename() == NameFolderFile) {
                    std::string res_path = entry.path().string() += NameFolderFile;
                    return res_path;
                }
            } catch (const fs::filesystem_error& fs_err) {
                continue;
            }
        }

        // if the file or folder is not found, we return an empty path.
        return "";
    }

    catch (const std::exception& e) {
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return "";
    }
}

//
// for get info is File or Folder
//
std::string FILEF::is_File_Or_Folder(const fs::path path, const std::string nameFF) {
    try {
        if (!path.string().ends_with("\\")) {
            path.string() += "\\";
        }

        std::string full_path = path.string() += nameFF;

        if (fs::is_regular_file(full_path)) {
            return "[FILE]";
        } else if (fs::is_directory(full_path)) {
            return "[FOLDER]";
        } else {
            return "[UNKNOWN]";
        }
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return "[UNKNOWN]";
    }
}

