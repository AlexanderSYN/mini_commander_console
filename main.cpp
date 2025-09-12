#include <iostream>

#include "helper_header/helper_text.h"
#include "helper_header/console/helper_clear_console.h"
#include "helper_header/work_with_files/helper_open_file.h"
#include "helper_header/console/color_console.h"
#include "helper_header/console/debug_some_command.h"
#include "helper_header/work_with_files/helper_create_file.h"
#include "helper_header/work_with_files/helper_delete_file.h"

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(CP_UTF8);

    bool isRun = true;
    bool isRunDebug = true;

    std::string path = "/", user_input;
    std::cout << "for help type help" << std::endl;

    while (isRun)
    {
        std::cout << path << " >>";
        std::getline(std::cin, user_input);

        if (user_input == "exit" || user_input == "ex")
        {
            isRun = false;
            break;
        }

        //
        // help
        //
        else if (user_input == "help")
        {
            std::cout << "help - just help" << std::endl;
            std::cout << "help color - help for change color" << std::endl;
            std::cout << "clear / cls - clearing the console" << std::endl;
            std::cout << "info - information about this program" << std::endl;
            std::cout << "color ... <- (here name of color) - for change color in console" << std::endl;
            std::cout << "color help - to check the available colors" << std::endl;
            std::cout << "exit / ex - for exit from console" << std::endl;
            std::cout << std::endl;
            std::cout << "cd - the command to change the working directory" << std::endl;
            std::cout << "dir - allows you to display a list of files and subdirectories "
                         "for the specified directory (for windows)" << std::endl;
            std::cout << std::endl;
            std::cout << "openf ... <- (path with file or just folder) - "
                         "opening a file or folder through OS programs (for all OS)" << std::endl;
            std::cout << "open ... <- (path) - allows you to display "
                         "a list of files and subdirectories for the specified directory (for all OS)" << std::endl;
            std::cout << std::endl;
            std::cout << "find ... <- (name file / folder) - first you need to specify "
                         "the path via cd, then you can search for a file / folder" << std::endl;
            std::cout << std::endl;
            std::cout << "create / cr ... <- (path) ... <- (file or folder) ... <- "
                         "(name file / folder) - the command to create a file or folder" << std::endl;
            std::cout << std::endl;
            std::cout << "delete ... <- (1 option: name file / folder or 2 option: "
                         "first you need to specify the path via cd, then just write delete) - "
                         "delete file / folder" << std::endl;
        }

        else if (user_input.substr(0, 5) == "help ")
        {
            if (user_input.substr(5) == "color")
                ColorConsole::choice_color("color help");
            else
                std::cout << "you entered it incorrectly, look here by writing -> help" << std::endl;

        }

        //
        // End help
        //

        //
        // for debug
        //
        else if (user_input == "debug")
            debug_some_command(isRunDebug, user_input, path);

        //
        // End for debug
        //

        //
        // Info
        //
        else if (user_input == "info")
        {
            std::cout << "___MINI_COMMANDER_CONSOLE___" << std::endl;
            std::cout << "_________VERSION_1__________" << std::endl;
            std::cout << "______AUTHOR: ALEXANDER_____" << std::endl;
            std::cout << "_____GIT-HUB: ALEXANDERSYN_____" << std::endl;
            std::cout << "_________JUST FUN ;)________" << std::endl;
        }
        //
        // End info
        //

        //
        // color
        //
        else if (user_input.substr(0, 6) == "color ")
        {
            std::cout << ColorConsole::choice_color(user_input) << std::endl;
        }
        else if (user_input == "color")
            std::cout << "you need to write like this -> color ... <- (color name)" << std::endl;
        //
        // End color
        //

        //
        // clear / cls
        //
        else if (user_input == "clear" || user_input == "cls")
            clear_console();
        //
        // End clear / cls
        //

        //
        // cd
        //
        else if (user_input.substr(0, 3) == "cd ")
            FILEO::set_path_in_cd(user_input, path);
        //
        // End cd
        //

        //
        // dir
        // only for windows
        //
        else if (user_input == "dir")
            FILEO::open_folder_use_dir(path);
        //
        // End dir
        //

        //
        // open && openf
        // for all OS
        //
        else if (user_input.substr(0, 5) == "open ")
            FILEO::output_all_files_command_open(user_input.substr(5));
        else if (user_input == "open")
            FILEO::output_all_files_command_open(path);

        else if (user_input.substr(0, 6) == "openf ")
            FILEO::open_file(user_input.substr(6));
        else if (user_input == "openf")
            FILEO::open_file(path);
        //
        // End open && openf
        //

        //
        // create / cr
        //

        else if (user_input.substr(0, 7) == "create " || user_input.substr(0, 3) == "cr ")
            FILEC::create_file(user_input, path);
        else if (user_input == "create" || user_input == "cr")
            std::cout << "it's not the correct command. You need to write like this -> create ... <-(path) ... <- (file or folder) ... (name file/folder)" <<
                "\nor \ncr ... <-(path) ... <- (file or folder) ... (name file/folder)" << std::endl;
        //
        // End create / cr
        //

        //
        // delete
        //
        else if (user_input == "delete" || user_input.substr(0, 7) == "delete ")
            FILED::delete_file_or_folder(user_input, path);
        //
        // End delete
        //

        else
            std::cout << "The command was not found! \n"
                         "for help type help" << std::endl;




    }

    return 0;
}
