//
// Created by AlexanderSYN on 16.09.2025.
//

#ifndef HELPER_TXT_H
#define HELPER_TXT_H

#include "../work_with_files/include_for_work_with_files.h"

class FILETxt {
public:
    static void work_with_txt(std::string user_input, std::string path);

    static void save_text_in_file(std::string text, std::string path);
private:
    static void get_help_for_txt();
};


#endif //HELPER_TXT_H
