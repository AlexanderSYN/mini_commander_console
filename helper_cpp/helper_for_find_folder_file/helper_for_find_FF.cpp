//
// Created by AlexanderSYN on 12.09.2025.
//

#include "../../helper_header/helper_for_find_folder_file/helper_for_find_FF.h"
#include "../../helper_header/work_with_files/helper_open_file.h"

//-------------------------------------------------------
// find (name file / folder)
//
//search for files or folders and add count_founded
//by 1 each time you find them to access the array
//with the paths of the found files or folders and
//quickly open them
//-------------------------------------------------------
void FILEF::findFF(std::string user_input, std::string path_f) {
    int count_founded = 0;
    int choice_num;
    std::vector<std::string> founded_path;


    fs::path directory = path_f;
    std::cout << user_input << std::endl;

    try {
        for (const auto& entry : fs::recursive_directory_iterator(directory)) {
            if (entry.path().filename().string() == user_input) {
                //
                // save a path in the vector
                //
                count_founded += 1;
                founded_path.push_back(entry.path().string());

                std::cout << count_founded << " - Founded: " << entry.path() << std::endl;
            }
        }

        if (count_founded != 0) {
            std::cout << "choice number for open file / folder in the explorer or just run file"
                         " or 0 to cancel" << std::endl;
            std::cin >> choice_num;

        } else {
            std::cout << "File or Folder not found!" << std::endl;
            return;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

        if (choice_num > count_founded) {
            std::cout << "no path was found under this index!" << std::endl;
            return;
        } else if (choice_num == 0) {
            return;
        }

        if (count_founded > 1) {
            choice_num--;
        }

        FILEO::open_file(founded_path.at(choice_num));
    } catch (std::exception e) {
        std::cout << "[ERROR] " << e.what() << std::endl;
        return;
    }

}
