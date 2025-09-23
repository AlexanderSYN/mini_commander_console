//
// Created by Alexander on 12.09.2025.
//

#ifndef HELPER_FOR_FIND_FF_H
#define HELPER_FOR_FIND_FF_H

#include "../work_with_files/include_for_work_with_files.h"

class FILEF {
public:
    // findFF - find File Folder
    static void findFF(std::string user_input, std::string path_f);

private:
    static std::string find_FileFolder(const fs::path &directory, const std::string &NameFolderFile);
    static std::string is_File_Or_Folder(const fs::path path, const std::string nameFF);

};


#endif //HELPER_FOR_FIND_FF_H
