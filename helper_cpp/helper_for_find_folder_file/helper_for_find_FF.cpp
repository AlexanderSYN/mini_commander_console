//
// Created by AlexanderSYN on 12.09.2025.
//

#include "../../helper_header/helper_for_find_folder_file/helper_for_find_FF.h"

void FILEF::findFF(std::string user_input, std::string path) {
    std::string nameFF = FILEF::get_nameFF_for_find(user_input);
    std::cout << nameFF;
}

std::string FILEF::get_nameFF_for_find(std::string user_input) {
    std::string tmp_name;
    std::string result;

    tmp_name = user_input.substr(5);
    try {
        for (int i = 0; tmp_name[i] != ' '; i++) {
            result += tmp_name[i];
        }
    }
    catch (const std::out_of_range& out_of_range) {
        return result;
    }
    catch (std::exception e) {
        return "ERROR";
    }

    return result;
}

