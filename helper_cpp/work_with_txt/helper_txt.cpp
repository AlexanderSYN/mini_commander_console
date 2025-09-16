//
// Created by AlexanderSYN on 16.09.2025.
//

#include "../../helper_header/work_with_txt/helper_txt.h"

void FILETxt::save_text_in_file(std::string text, std::string path) {
    if (!path.ends_with(".txt")) {
        std::cerr << "ERROR: The file is not txt" << std::endl;
        return;
    }

    try {
        std::ofstream out;
        out.open(path);
        if (out.is_open()) {
            out << text;
        }
        out.close();
    } catch (std::exception e) {
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return;
    }

}


void FILETxt::work_with_txt(std::string user_input, std::string path) {
    std::string tmp_path;
    std::string user_input_txt;

    bool isRun = true;

    if (user_input.size() > 4) {
        tmp_path = user_input.substr(4);

        if (fs::exists(tmp_path)) {
            if (!tmp_path.ends_with(".txt")) {
                std::cerr << "ERROR: the file is not txt" << std::endl;
                return;
            }
        }

        if (!fs::exists(tmp_path)) {
            std::cerr << "ERROR: the path is not found!" << std::endl;
            return;
        }
    } else {
        tmp_path = path;
    }

    while (isRun) {
        std::cout << "_____WELCOME TO WORK WITH TXT_____" << std::endl;
        std::cout << "for help type help" << std::endl;

        std::cin >> user_input_txt;

        if (user_input_txt == "help") {
            get_help_for_txt();
        }
        //else if (user_input_txt == "save")

        else if (user_input_txt == "exit" || user_input_txt == "ex") {
            isRun = false;
            break;
        }

    }

}

void FILETxt::get_help_for_txt() {
    std::cout << "Avaliable commands: " << std::endl;
    std::cout << "help - for help" << std::endl;
    std::cout << "save - for save file" << std::endl;
    std::cout << "ex / exit - for exit" << std::endl;
}



