//
// Created by AlexanderSYN on 16.09.2025.
//

#include "../../helper_header/work_with_txt/helper_txt.h"

void FILETxt::save_text_in_file(std::string text, std::string path) {
    if (!path.ends_with(".txt")) {
        std::cerr << "ERROR: The file is not txt" << std::endl;
        return;
    }
    // for clear text file
    if (text == "clear") {
        std::ofstream out;
        out.open(path);
        if (out.is_open()) {
            out << "" << std::endl;
        }

        out.close();
        std::cout << "the text file has been cleared" << std::endl;
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




