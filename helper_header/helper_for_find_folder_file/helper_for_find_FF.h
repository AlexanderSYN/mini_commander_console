//
// Created by Alexander on 12.09.2025.
//

#ifndef HELPER_FOR_FIND_FF_H
#define HELPER_FOR_FIND_FF_H

#include "../work_with_files/include_for_work_with_files.h"

class FILEF {
public:
    // findFF - find File Folder
    static void findFF(std::string user_input, std::string path);
private:
    static std::string get_nameFF_for_find(std::string user_input);
    static std::string get_path_for_find(std::string user_input);
};


#endif //HELPER_FOR_FIND_FF_H
