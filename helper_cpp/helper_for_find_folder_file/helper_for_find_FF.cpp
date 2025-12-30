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
        std::cout << "If you are tired of waiting, press the 'Alt' key to stop!" << std::endl;
        std::cout << "Searching for: '" << user_input << "' in: " << path_f << std::endl;

        try {
            std::stack<fs::path> dir_stack;
            dir_stack.push(directory);

            while (!dir_stack.empty()) {
                fs::path current_dir = dir_stack.top();
                dir_stack.pop();

                // Skip the system directories
                if (is_system_path(current_dir)) {
                    continue;
                }

                // stop searching
                if (GetAsyncKeyState(VK_RMENU) & 0x8000 || GetAsyncKeyState(VK_LMENU) & 0x8000) {
                    std::cout << "The search has been stopped!" << std::endl;
                    try {
                        if (count_founded != 0) {
                            std::cout << "Choice number for open (file / folder) in the explorer"
                                         " or 0 to cancel: ";
                            std::cin >> choice_num;

                        } else {
                            std::cout << "File or Folder not found!" << std::endl;
                            return;
                        }

                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

                        if (choice_num > count_founded) {
                            std::cout << "No path was found under this index!" << std::endl;
                            return;
                        } else if (choice_num == 0) {
                            return;
                        }

                        if (count_founded >= 1) {
                            choice_num--;
                        }

                        FILEO::show_in_explorer(founded_path.at(choice_num));
                        return;
                    } catch (const std::exception& e) {
                        std::cout << "[ERROR] " << e.what() << std::endl;
                        return;
                    }
                }

                try {
                    for (const auto& entry : fs::directory_iterator(current_dir)) {
                        try {
                            // Skip system files/directories
                            if (is_system_path(entry.path())) {
                                continue;
                            }

                            // Checking for a match with the name you are looking for
                            if (entry.path().filename().string() == user_input) {
                                count_founded += 1;
                                founded_path.push_back(entry.path().string());
                                std::cout << count_founded << " - Founded: " << entry.path() << std::endl;
                            }

                            // If this is a directory, we add it to the stack for further traversal
                            if (entry.is_directory()) {
                                dir_stack.push(entry.path());
                            }

                        } catch (const fs::filesystem_error& ex) {
                            std::cout << "Skipping inaccessible: " << entry.path() << " - " << ex.what() << std::endl;
                            continue;
                        }
                    }
                } catch (const fs::filesystem_error& ex) {
                    std::cout << "Cannot access directory: " << current_dir << " - " << ex.what() << std::endl;
                    continue;
                }
            }

            if (count_founded != 0) {
                std::cout << "Choice number for open (file / folder) in the explorer or just run file"
                             " or 0 to cancel: ";
                std::cin >> choice_num;

            } else {
                std::cout << "File or Folder not found!" << std::endl;
                return;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

            if (choice_num > count_founded) {
                std::cout << "No path was found under this index!" << std::endl;
                return;
            } else if (choice_num == 0) {
                return;
            }

            if (count_founded >= 1) {
                choice_num--;
            }

            FILEO::show_in_explorer(founded_path.at(choice_num));
        }
        catch (const std::exception& e) {
            std::cout << "[ERROR] " << e.what() << std::endl;
            return;
        }
    }

//
// Defining static class members
//
const std::vector<std::string> FILEF::SYSTEM_DIRECTORIES = {
    "System32", "System64", "Windows", "Program Files", "ProgramData",
    "AppData", "Temp", "tmp", "Recycle.Bin", "Recovery",
    "$Recycle.Bin", "System Volume Information", "Windows.old"
};

const std::vector<std::string> FILEF::SYSTEM_EXTENSIONS = {
    ".drv", ".vxd", ".386", ".ocx",".cpl", ".msc", ".scr",
    ".com", ".tmp",".inf", ".cat", ".mui"
};
//
//  The function of checking whether the path is system-defined
//
bool FILEF::is_system_path(const fs::path& path) {
    std::string path_str = path.string();
    std::string filename = path.filename().string();

    // Skip hidden files/folders (starting with a dot in Linux/Mac)
    if (filename[0] == '.') {
        return true;
    }

    // Skip the system directories
    for (const auto& sys_dir : SYSTEM_DIRECTORIES) {
        if (path_str.find(sys_dir) != std::string::npos) {
            return true;
        }
    }

    // Skipping files with system extensions
    if (path.has_extension()) {
        std::string ext = path.extension().string();
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

        for (const auto& sys_ext : SYSTEM_EXTENSIONS) {
            if (ext == sys_ext) {
                return true;
            }
        }
    }

    // Skipping temporary files
    if (filename.find("~") != std::string::npos ||
        filename.find(".tmp") != std::string::npos ||
        filename.find("temp") != std::string::npos) {
        return true;
        }

    return false;
}