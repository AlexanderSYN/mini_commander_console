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
// void FILEF::findFF(std::string user_input, std::string path_f) {
//         int count_founded = 0;
//         int choice_num;
//         std::vector<std::string> founded_path;
//
//         fs::path directory = path_f;
//         std::cout << "If you are tired of waiting, press the 'Alt' key to stop!" << std::endl;
//         std::cout << "Searching for: '" << user_input << "' in: " << path_f << std::endl;
//
//         try {
//             std::stack<fs::path> dir_stack;
//             dir_stack.push(directory);
//
//             while (!dir_stack.empty()) {
//                 fs::path current_dir = dir_stack.top();
//                 dir_stack.pop();
//
//                 // Skip the system directories
//                 if (is_system_path(current_dir)) {
//                     continue;
//                 }
//
//                 // stop searching
//                 if (GetAsyncKeyState(VK_RMENU) & 0x8000 || GetAsyncKeyState(VK_LMENU) & 0x8000) {
//                     std::cout << "The search has been stopped!" << std::endl;
//                     try {
//                         if (count_founded != 0) {
//                             std::cout << "Choice number for open (file / folder) in the explorer"
//                                          " or 0 to cancel: ";
//                             std::cin >> choice_num;
//
//                         } else {
//                             std::cout << "File or Folder not found!" << std::endl;
//                             return;
//                         }
//
//                         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
//
//                         if (choice_num > count_founded) {
//                             std::cout << "No path was found under this index!" << std::endl;
//                             return;
//                         } else if (choice_num == 0) {
//                             return;
//                         }
//
//                         if (count_founded >= 1) {
//                             choice_num--;
//                         }
//
//                         FILEO::show_in_explorer(founded_path.at(choice_num));
//                         return;
//                     } catch (const std::exception& e) {
//                         std::cout << "[ERROR] " << e.what() << std::endl;
//                         return;
//                     }
//                 }
//
//                 try {
//                     for (const auto& entry : fs::directory_iterator(current_dir)) {
//                         try {
//                             // Skip system files/directories
//                             if (is_system_path(entry.path())) {
//                                 continue;
//                             }
//
//                             // Checking for a match with the name you are looking for
//                             if (entry.path().filename().string() == user_input) {
//                                 count_founded += 1;
//                                 founded_path.push_back(entry.path().string());
//                                 std::cout << count_founded << " - Founded: " << entry.path() << std::endl;
//                             }
//
//                             // If this is a directory, we add it to the stack for further traversal
//                             if (entry.is_directory()) {
//                                 dir_stack.push(entry.path());
//                             }
//
//                         } catch (const fs::filesystem_error& ex) {
//                             std::cout << "Skipping inaccessible: " << entry.path() << " - " << ex.what() << std::endl;
//                             continue;
//                         }
//                     }
//                 } catch (const fs::filesystem_error& ex) {
//                     std::cout << "Cannot access directory: " << current_dir << " - " << ex.what() << std::endl;
//                     continue;
//                 }
//             }
//
//             if (count_founded != 0) {
//                 std::cout << "Choice number for open (file / folder) in the explorer or just run file"
//                              " or 0 to cancel: ";
//                 std::cin >> choice_num;
//
//             } else {
//                 std::cout << "File or Folder not found!" << std::endl;
//                 return;
//             }
//
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
//
//             if (choice_num > count_founded) {
//                 std::cout << "No path was found under this index!" << std::endl;
//                 return;
//             } else if (choice_num == 0) {
//                 return;
//             }
//
//             if (count_founded >= 1) {
//                 choice_num--;
//             }
//
//             FILEO::show_in_explorer(founded_path.at(choice_num));
//         }
//         catch (const std::exception& e) {
//             std::cout << "[ERROR] " << e.what() << std::endl;
//             return;
//         }
//     }

void FILEF::findFF(std::string user_input, std::string path_f) {
    try {
        std::vector<std::string> paths_founded_ff; // ff - file and folder
        std::string parametr;
        std::string search_term = user_input;
        size_t pos;

        if (user_input[0] == '-') {
            pos = user_input.find(' ');

            if (pos != std::string::npos) {
                parametr = user_input.substr(0, pos);
                search_term = user_input.substr(pos + 1);
            }
        }

        if (!fs::is_directory(path_f) || !fs::exists(path_f)) {
            std::cerr << "Error find: the folder doesn't exist!\n";
            return;
        }

        std::cout << "If you are tired of waiting, press the 'Alt' key to stop!" << std::endl;
        std::cout << "Searching for: '" << search_term << "' in: " << path_f << std::endl;

        //===================================================
        // if parametr = local then searching only in local
        // folder
        //====================================================
        if (parametr == "-l" || parametr == "--local") {
            for (const auto& entry : fs::directory_iterator(path_f)) {
                if (GetAsyncKeyState(VK_RMENU) & 0x8000 || GetAsyncKeyState(VK_LMENU) & 0x8000) {
                    std::cout << "\nSearch stopped by user!" << std::endl;
                    break;
                }

                // check if filename contains search term (case-insensitive)
                std::string filename = entry.path().filename().string();
                std::string search_lower = search_term;
                std::string filename_lower = filename;

                std::transform(search_term.begin(), search_term.end(), search_lower.begin(), ::tolower);
                std::transform(filename_lower.begin(), filename_lower.end(), filename_lower.begin(), ::tolower);

                if (filename_lower.find(search_lower) != std::string::npos) {
                    paths_founded_ff.push_back(entry.path().string());
                    std::cout << paths_founded_ff.size() << " - Found: " << entry.path() << std::endl;
                }
            }
        }
        else {
            // recursive search - through all subdirectories (like original code)
            std::stack<fs::path> dir_stack;
            dir_stack.push(path_f);

            while (!dir_stack.empty()) {
                //Check for Alt key press to stop
                if (GetAsyncKeyState(VK_RMENU) & 0x8000 || GetAsyncKeyState(VK_LMENU) & 0x8000) {
                    std::cout << "\nSearch stopped by user!" << std::endl;
                    break;
                }

                fs::path current_dir = dir_stack.top();
                dir_stack.pop();

                if (is_system_path(current_dir)) {
                    continue;
                }

                 try {
                    for (const auto& entry : fs::directory_iterator(current_dir)) {
                        if (is_system_path(entry.path())) {
                            continue;
                        }

                        // Check if filename contains search term (case-insensitive)
                        std::string filename = entry.path().filename().string();
                        std::string search_lower = search_term;
                        std::string filename_lower = filename;

                        std::transform(search_lower.begin(), search_lower.end(), search_lower.begin(), ::tolower);
                        std::transform(filename_lower.begin(), filename_lower.end(), filename_lower.begin(), ::tolower);

                        if (filename_lower.find(search_lower) != std::string::npos) {
                            paths_founded_ff.push_back(entry.path().string());
                            std::cout << paths_founded_ff.size() << " - Found: " << entry.path() << std::endl;
                        }

                        // Add subdirectories to stack
                        if (entry.is_directory()) {
                            dir_stack.push(entry.path());
                        }
                    }
                } catch (const fs::filesystem_error& e) {
                    std::cout << "Cannot access: " << current_dir << std::endl;
                    continue;
                }
            }
        }

        // Handle results
        if (!paths_founded_ff.empty()) {
            std::cout << "\nFound " << paths_founded_ff.size() << " item(s)." << std::endl;
            std::cout << "Enter number to open (0-" << paths_founded_ff.size() - 1
                      << ") or -1 to exit: ";
            int choice;
            std::cin >> choice;

            if (choice >= 0 && choice < paths_founded_ff.size()) {
                open_file_folder_with_choice(paths_founded_ff, choice);
            }
        } else {
            std::cout << "No files or folders found matching '" << search_term << "'" << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "[ERROR_FIND] " << e.what() << std::endl;
    }
}

void FILEF::open_file_folder_with_choice(std::vector<std::string> paths_founded_ff, int choice) {
    try {

#if defined(_WIN32) //Windows
        std::string command = "start \"\" \"" + paths_founded_ff.at(choice) + "\"";
#elif defined(__APPLE__) // MacOs
        std::string command = "open \"" + path + "\"";
#elif defined(__linux__) //Linux
        std::string command = "xdg-open \"" + path + "\"";
#else
        std::cerr << "Unsupported OS" << std::endl;
        return;
#endif

        bool result = system(command.c_str());

        if (!result)
            std::cout << "[SUCCESS OPEN]" << std::endl;
        else
            std::cerr << "[ERROR OPEN]" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[ERROR_FIND] " << e.what() << std::endl;
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