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
        std::ofstream out(path, std::ios::app);

        if (out.is_open())
            out << text << std::endl;

        out.close();

    } catch (std::exception e) {
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return;
    }

}
//
// End echo
//

//
// Read
//
void FILETxt::Read_txt(std::string user_input, std::string path) {
    if (!path.ends_with(".txt")) {
        std::cerr << "ERROR: The file is not txt" << std::endl;
        return;
    }

    std::string line;

    std::ifstream in(path);
    if (in.is_open()) {
        while (std::getline(in, line))
            std::cout << line << std::endl;
    }

    in.close();
}

//
// End Read
//

//
// work with txt
//
void FILETxt::work_with_txt(std::string user_input, std::string & path) {
    std::string tmp_path;
    std::string user_input_txt;
    std::string text;

    bool isRun = true;
    bool rewrite = false;

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

        std::getline(std::cin, user_input_txt);

        if (user_input_txt == "help") {
            get_help_for_txt();
        }

        else if (user_input_txt.substr(0, 4) == "path ") {
            path = user_input_txt.substr(4);
            std::cout << path << std::endl;
        }

        else if (user_input_txt == "get path") {
            std::cout << path << std::endl;
        }

        // write
        else if (user_input_txt == "write") {
            if (!rewrite) {
                std::getline(std::cin, text);
                save_text_in_file(text, path);
            }
            else {
                std::getline(std::cin, text);
                std::ofstream out;
                out.open(path);
                if (out.is_open())
                {
                    out << text << std::endl;
                }
                out.close();
            }
        }

        // read
        else if (user_input_txt == "read") {
            Read_txt(user_input_txt, path);
        }

        // rewrite
        else if (user_input_txt == "-rw on") {
            rewrite = true;
            std::cout << "notification: rewrite on!" << std::endl;
        }
        else if (user_input_txt == "-rw off") {
            rewrite = false;
            std::cout << "notification: rewrite off!" << std::endl;
        }
        else if (user_input_txt == "--rewrite on") {
           rewrite = true;
            std::cout << "notification: rewrite on!" << std::endl;
        }
        else if (user_input_txt == "--rewrite off") {
            rewrite = false;
            std::cout << "notification: rewrite off!" << std::endl;
         }

        else if (user_input_txt == "exit" || user_input_txt == "ex") {
            isRun = false;
            break;
        }

    }

}

void FILETxt::get_help_for_txt() {
    std::cout << "Avaliable commands: " << std::endl;
    std::cout << "help - for help" << std::endl;
    std::cout << "write - for write text in file" << std::endl;
    std::cout << "read - for read file" << std::endl;
    std::cout << "-rw / --rewrite on / off - to choose whether to overwrite the file or not";
    std::cout << "ex / exit - for exit" << std::endl;
}



