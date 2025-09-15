//
// Created by AlexanderSYN on 12.09.2025.
//

#include "../../helper_header/helper_for_find_folder_file/helper_for_find_FF.h"
#include "../../helper_header/work_with_files/helper_open_file.h"

//
// find (name file / folder) or find (name file / folder) (path)
//
void FILEF::findFF(std::string user_input, std::string path_f) {
    std::string nameFF = FILEF::get_nameFF_for_find(user_input);
    char choice;

    if (user_input.substr(0, 5) != "find ")
        return;

    if (path_f.empty() || path_f == "\\")
    {
        std::cout << "Enter a valid path" << std::endl;
        return;
    }

    std::string target = user_input.substr(5);
    std::string path = path_f + (path_f.back() == '\\' ? "" : "\\") + target;

    if (!fs::exists(path))
    {
        std::cout << "path is not found: " << path << std::endl;
        return;
    }

    std::cout << (fs::exists(path) ? "[FOLDER]" : "[FILE]");
    std::cout << " found: " << path << std::endl;

    std::cout << "open in explorer? (Y/N) >> ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

    if (toupper(choice) == 'Y')
    {
        std::cout << "[OPENING IN FILE MANAGER]" << std::endl;
        FILEO::open_file(path);
    }

}

// find
bool FILEF::find_file( const fs::path & dir_path,         // in this directory,
                const std::string & file_name, // search for this name,
                fs::path & path_found )            // placing path here if found
{
    using namespace fs;
    if ( !exists( dir_path ) ) return false;
    directory_iterator end_itr; // default construction yields past-the-end
    for ( directory_iterator itr( dir_path );
          itr != end_itr;
          ++itr )
    {
        try {
            if ( is_directory(itr->status()) )
            {
                if ( find_file( itr->path(), file_name, path_found ) ) return true;
            }
            else if ( path().filename() == file_name ) // see below
            {
                path_found = itr->path();
                return true;
            }
        } catch (std::exception e) {
            continue;
        }
    }
    return false;
}

// for get name file folder (find ... <- get this )
std::string FILEF::get_nameFF_for_find(std::string user_input) {
    std::string result;

    try {
        result = user_input.substr(5);

        return result;
    } catch (std::out_of_range out_of_range) {
        return "name don't find!";
    } catch (std::exception e) {
        result += "ERROR: ";
        result += e.what();
        return result;
    }
}
