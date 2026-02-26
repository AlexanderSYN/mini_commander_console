//
// Created by AlexanderSYN on 12.09.2025.
//

#include "../../helper_header/helper_for_find_folder_file/helper_for_find_FF.h"
#include "../../helper_header/work_with_files/helper_open_file.h"

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
        else if (parametr == "-lf" || parametr == "--local-file") {
            //========================================
            // Searching so -> *.(extension)
            //========================================
            if (search_term.substr(0, 2) == "*.") {
                std::string target_extension = search_term.substr(1);

                std::cout << "Searching only files with extension: " << search_term.substr(2) << std::endl;
                try {
                    for (const auto& entry : fs::directory_iterator(path_f)) {
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
                    for (const auto& entry : fs::directory_iterator(path_f)) {
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
                            if (entry.is_regular_file() && entry.path().stem().string() == search_term.substr(0, search_term.size() - 2)) {
                                paths_founded_ff.push_back(entry.path().string());
                                std::cout << paths_founded_ff.size() << " - Found: " << entry.path() << std::endl;
                            }
                        }
                    }
                } catch (const std::exception &e) {
                    std::cerr << "[ERROR_FIND_FILE] " << e.what() << std::endl;
                }
            }
        }
        //
        // global searching (don't finished)
        //
        else if (parametr == "-g" || parametr == "--global"
             || parametr == "-r" || parametr == "--recursive") {
            std::error_code ec;

            //========================================
            // Searching all
            //========================================
            std::cout << "Searching: " << search_term << std::endl;
            fs::recursive_directory_iterator it(
                path_f,
                ec);

            fs::recursive_directory_iterator end;

            for (; it != end; it.increment(ec)) {
                if (GetAsyncKeyState(VK_RMENU) & 0x8000 || GetAsyncKeyState(VK_LMENU) & 0x8000) {
                    std::cout << "\nSearch stopped by user!" << std::endl;
                    break;
                }

                if (ec) {
                    it.disable_recursion_pending();
                    ec.clear();
                    continue;
                }

                const auto& entry = *it;

                std::string filename = entry.path().filename().string();

                std::string filename_lower = filename;
                std::string search_lower = search_term;

                std::transform(filename_lower.begin(), filename_lower.end(), filename_lower.begin(), ::tolower);
                std::transform(search_lower.begin(), search_lower.end(), search_lower.begin(), ::tolower);

                if (entry.is_symlink()) {
                    it.disable_recursion_pending();
                    return;
                }
                if (is_system_path(entry.path())) {
                    it.disable_recursion_pending();
                }


                if (filename_lower.find(search_lower) != std::string::npos) {
                    paths_founded_ff.push_back(entry.path().string());
                    std::cout << paths_founded_ff.size() << " - Found: " << entry.path() << std::endl;
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
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

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

void FILEF::search(const fs::path& dir,
            const std::string& search_term,
            std::vector<std::string>& results)
{
    std::error_code ec;

    if (!fs::is_directory(dir, ec))
        return;

    std::vector<fs::path> subdirs;

    // 1️⃣ Сначала проходим файлы
    for (const auto& entry : fs::directory_iterator(dir, fs::directory_options::skip_permission_denied, ec))
    {
        if (ec) { ec.clear(); continue; }

        if (entry.is_regular_file())
        {
            std::string name = entry.path().filename().string();

            std::string lower_name = name;
            std::string lower_search = search_term;

            std::transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);
            std::transform(lower_search.begin(), lower_search.end(), lower_search.begin(), ::tolower);

            if (lower_name.find(lower_search) != std::string::npos)
            {
                results.push_back(entry.path().string());
                std::cout << results.size()
                          << " - Found file: "
                          << entry.path() << std::endl;
            }
        }
        else if (entry.is_directory())
        {
            subdirs.push_back(entry.path());
        }
    }

    // 2️⃣ Потом проверяем папки по имени
    for (const auto& folder : subdirs)
    {
        std::string name = folder.filename().string();

        std::string lower_name = name;
        std::string lower_search = search_term;

        std::transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);
        std::transform(lower_search.begin(), lower_search.end(), lower_search.begin(), ::tolower);

        if (lower_name.find(lower_search) != std::string::npos)
        {
            results.push_back(folder.string());
            std::cout << results.size()
                      << " - Found folder: "
                      << folder << std::endl;
        }
    }

    // 3️⃣ Теперь заходим по одной папке (DFS)
    for (const auto& folder : subdirs)
    {
        search(folder, search_term, results);
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
    "$Recycle.Bin", "System Volume Information", "Windows.old",
    "$RECYCLE.BIN", "D:\\DrWeb Quarantine"
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