//
// Created by AlexanderSYN on 12.09.2025.
//

#include "../../helper_header/helper_for_find_folder_file/helper_for_find_FF.h"
#include "../../helper_header/work_with_files/helper_open_file.h"

#include "../helper/print.cpp"
#include "../helper/debug.cpp"

using namespace print;
using namespace Debug;

std::vector<std::string> directories_for_recurs_search;

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
            //========================================
            // Searching so -> find (filename/folder)
            //========================================

            for (const auto &entry: fs::directory_iterator(path_f)) {
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
        } else if (parametr == "-lf" || parametr == "--local-file") {
            //========================================
            // Searching so -> *.(extension)
            //========================================
            if (search_term.substr(0, 2) == "*.") {
                std::string target_extension = search_term.substr(1);

                std::cout << "Searching only files with extension: " << search_term.substr(2) << std::endl;
                try {
                    for (const auto &entry: fs::directory_iterator(path_f)) {
                        if (GetAsyncKeyState(VK_RMENU) & 0x8000 || GetAsyncKeyState(VK_LMENU) & 0x8000) {
                            std::cout << "\nSearch stopped by user!" << std::endl;
                            break;
                        }

                        if (entry.is_regular_file() && entry.path().extension().string() == target_extension) {
                            paths_founded_ff.push_back(entry.path().string());
                            std::cout << paths_founded_ff.size() << " - Found: " << entry.path() << std::endl;
                        }
                    }
                } catch (const std::exception &e) {
                    std::cerr << "[ERROR_FIND_FILE] " << e.what() << std::endl;
                }
            }
            //========================================
            // Searching so -> (filename).(extension)
            //========================================
            else {
                std::string target_extension = search_term.substr(1);

                std::cout << "Searching only files with extension: " << search_term.substr(2) << std::endl;
                try {
                    for (const auto &entry: fs::directory_iterator(path_f)) {
                        if (GetAsyncKeyState(VK_RMENU) & 0x8000 || GetAsyncKeyState(VK_LMENU) & 0x8000) {
                            std::cout << "\nSearch stopped by user!" << std::endl;
                            break;
                        }
                        // if you write extension
                        if (!entry.path().filename().string().ends_with(".*") && entry.is_regular_file()
                            && entry.path().extension().string() == target_extension
                            && entry.path().filename().string() == search_term) {
                            paths_founded_ff.push_back(entry.path().string());
                            std::cout << paths_founded_ff.size() << " - Found: " << entry.path() << std::endl;
                        }
                        // if you write (filename).*
                        else {
                            if (entry.is_regular_file() && entry.path().stem().string() == search_term.substr(
                                    0, search_term.size() - 2)) {
                                paths_founded_ff.push_back(entry.path().string());
                                std::cout << paths_founded_ff.size() << " - Found: " << entry.path() << std::endl;
                            }
                        }
                    }
                } catch (const std::exception &e) {
                    std::cerr << "[ERROR_FIND_FILE] " << e.what() << std::endl;
                }
            }
        } else if (parametr == "-ld" || parametr == "--local-dir") {
            try {
                std::cout << "Only folders" << std::endl;
                for (const auto &entry: fs::directory_iterator(path_f)) {
                    // for stop searching
                    if (GetAsyncKeyState(VK_RMENU) & 0x8000 || GetAsyncKeyState(VK_LMENU) & 0x800) {
                        std::cout << "\nSearch stopped by user!" << std::endl;
                        break;
                    }

                    if (is_directory(entry.path()) &&
                        entry.path().filename().string() == search_term) {
                        paths_founded_ff.push_back(entry.path().string());
                        std::cout << paths_founded_ff.size() << " - Found Folder: " << entry.path() << std::endl;
                    }
                }
            } catch (const std::exception &e) {
                std::cerr << "[ERROR_FIND_LD] " << e.what() << std::endl;
            }
        }
        //
        // global searching (don't finished)
        //
        else if (parametr == "-g" || parametr == "--global"
                 || parametr == "-r" || parametr == "--recursive"
                 || parametr == "-gd" || parametr == "--global-directory"
                 || parametr == "-gf" || parametr == "--global-file") {
            recurs_search(search_term, path_f, paths_founded_ff, parametr);
        }

        // Handle results
        if (!paths_founded_ff.empty()) {
            std::cout << "\nFound " << paths_founded_ff.size() << " item(s)." << std::endl;
            std::cout << "Enter number to open (0-" << paths_founded_ff.size() - 1
                    << ") or -1 to exit: ";
            int choice;
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

            if (choice >= 0 && choice < paths_founded_ff.size()) {
                open_file_folder_with_choice(paths_founded_ff, choice);
            }
        } else {
            std::cout << "No files or folders found matching '" << search_term << "'" << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "[ERROR_FIND] " << e.what() << std::endl;
    }
}

// recursive searching
void FILEF::recurs_search(std::string search_term, std::string path_f,
                          std::vector<std::string> &paths_founded_ff, std::string param) {
    std::error_code ec;

    fs::recursive_directory_iterator it(path_f, ec);
    fs::recursive_directory_iterator end;

    std::string search_lower = search_term;
    std::transform(search_lower.begin(), search_lower.end(),
        search_lower.begin(), ::tolower);

    const bool only_files = (param == "-gf" || param == "--global-file");
    const bool only_dirs = (param == "-gd" || param == "--global-directory");
    // search only extension file
    const bool special_search_file_ext = search_term.substr(0, 2) == "*.";
    // search only name file
    const bool special_search_file_name = search_term.ends_with(".*");

    for (; it != end; it.increment(ec)) {

        if (GetAsyncKeyState(VK_RMENU) & 0x8000 ||
            GetAsyncKeyState(VK_LMENU) & 0x8000) {
            std::cout << "\n Search stopped by user!\n";
            break;
        }

        const auto& entry = *it;

        if (entry.is_symlink()) {
            it.disable_recursion_pending();
            continue;
        }

        if (is_system_path(entry.path())) {
            it.disable_recursion_pending();
            continue;
        }

        std::string filename = entry.path().filename().string();
        std::transform(filename.begin(), filename.end(),
                    filename.begin(), ::tolower);

        if (filename.find(search_lower) == std::string::npos
            && !special_search_file_name
            && !special_search_file_ext) continue;

        // check only files (without special search)
        if (only_files && !fs::is_regular_file(entry.path())
            && !special_search_file_ext && !special_search_file_name) {
            continue;
        }

        if (only_dirs && !fs::is_directory(entry.path())) continue; // check only dirs

        // special search
        // only for extension
        if (special_search_file_ext) {
            std::string ext = entry.path().extension().string();
            std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

            std::string target_ext = search_term.substr(1);
            std::transform(target_ext.begin(), target_ext.end(), target_ext.begin(), ::tolower);


            if (ext != target_ext) continue;
            else  {
                paths_founded_ff.push_back(entry.path().string());
                println(paths_founded_ff.size(), " - Found: ", entry.path());
            }
        }
        // only for name
        if (special_search_file_name) {
            std::string name = entry.path().stem().string();
            std::transform(name.begin(), name.end(), name.begin(), ::tolower);

            std::string target_name = search_term.substr(0, search_term.size() - 2);
            std::transform(target_name.begin(), target_name.end(), target_name.begin(), ::tolower);

            if (name != target_name || fs::is_directory(entry.path())) continue;
            else  {
                paths_founded_ff.push_back(entry.path().string());
                println(paths_founded_ff.size(), " - Found: ", entry.path());
            }
        }

        paths_founded_ff.push_back(entry.path().string());
        println(paths_founded_ff.size(), " - Found: ", entry.path());
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
    } catch (const std::exception &e) {
        std::cerr << "[ERROR_FIND] " << e.what() << std::endl;
    }
}

//
// Defining static class members
//
const std::vector<std::string> FILEF::SYSTEM_DIRECTORIES = {
    "System32", "System64", "Windows", "Program Files", "ProgramData",
    "AppData", "Temp", "tmp", "Recycle.Bin", "Recovery",
    "$Recycle.Bin", "System Volume Information", "Windows.old",
    "$RECYCLE.BIN", "D:\\DrWeb Quarantine"
};

const std::vector<std::string> FILEF::SYSTEM_EXTENSIONS = {
    ".drv", ".vxd", ".386", ".ocx", ".cpl", ".msc", ".scr",
    ".com", ".tmp", ".inf", ".cat", ".mui"
};
//
//  The function of checking whether the path is system-defined
//
bool FILEF::is_system_path(const fs::path &path) {
    std::string path_str = path.string();
    std::string filename = path.filename().string();

    // Skip hidden files/folders (starting with a dot in Linux/Mac)
    if (filename[0] == '.') {
        return true;
    }

    // Skip the system directories
    for (const auto &sys_dir: SYSTEM_DIRECTORIES) {
        if (path_str.find(sys_dir) != std::string::npos) {
            return true;
        }
    }

    // Skipping files with system extensions
    if (path.has_extension()) {
        std::string ext = path.extension().string();
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

        for (const auto &sys_ext: SYSTEM_EXTENSIONS) {
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