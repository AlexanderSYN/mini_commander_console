//
// Created by AlexanderSYN on 14.02.2026.
//

#ifndef READING_H
#define READING_H

#include "include_for_work_with_files.h"

class reading_file {

public:
    static void command_cat(const std::string& path);
    static void command_cat(const std::string &path, const std::string name_file);

};

#endif //READING_H
