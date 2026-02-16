//
// Created by 00077 on 14.02.2026.
//

#include "../../helper_header/work_with_files/reading_file.h"

void reading_file::command_cat(const std::string &path) {
    try {
        std::ifstream file(path);

        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } else {
            std::cerr << "[ERROR] couldn't open the file" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "[ERROR_reding_file] " << e.what() << std::endl;
    }
}

void reading_file::command_cat(const std::string &path, const std::string name_file) {
    try {
        std::string full_path = name_file;
        std::ifstream file(full_path);

        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } else {
            std::string full_path = path + "\\" + name_file;
            std::ifstream file(full_path);

            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    std::cout << line << std::endl;
                }
                file.close();
            } else {
                std::cerr << "[ERROR] couldn't open the file" << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "[ERROR_reding_file] " << e.what() << std::endl;
    }
}
