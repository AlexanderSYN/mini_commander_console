//
// Created by AlexanderSYN on 13.10.2025.
//

#include "../../helper_header/work_with_files/helper_rename_files.h"

#include <cstdio>

void rename_file::rnm_file(std::string& path, const std::string new_name) {
    try {
        fs::path old_path = path;
        fs::path new_path = old_path.parent_path() / new_name;

        // check for exists file / folder
        if (!fs::exists(old_path)) {
            std::cerr << "[ERROR] Source file does not exist: " << path << std::endl;
            return;
        }

        // Checking if a file with a new name already exists.
        if (fs::exists(new_path)) {
            std::cerr << "[ERROR] Target file already exists: " << new_path << std::endl;
            return;
        }

        fs::rename(old_path, new_path);
        std::cout << "File renamed successfully!" << std::endl;
        std::cout << "From: " << old_path << std::endl;
        std::cout << "To: " << new_path << std::endl;
        // changing path
        path = new_path.string();
    }catch (const fs::filesystem_error& fs_err) {
        std::cerr << "[ERROR] Filesystem error: " << fs_err.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "[ERROR] " << ex.what() << std::endl;
    }

}
