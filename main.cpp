#include <iostream>
#include <random>

#include <locale>
#include <codecvt>

#include "helper_header/helper_text.h"
#include "helper_header/console/helper_clear_console.h"
#include "helper_header/work_with_files/helper_open_file.h"
#include "helper_header/console/color_console.h"
#include "helper_header/console/debug_some_command.h"
#include "helper_header/work_with_txt/helper_txt.h"
#include "helper_header/work_with_files/helper_rename_files.h"
#include "helper_header/helper_for_find_folder_file/helper_for_find_FF.h"
#include "helper_header/work_with_files/helper_create_file.h"
#include "helper_header/work_with_files/helper_delete_file.h"

int main()
{
    std::locale::global(std::locale(""));
    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(CP_UTF8);

    bool isRun = true;
    bool isRunDebug = true;
    bool isShowPathWhenStartLoop = true;

    std::string path = "/", user_input;
    std::cout << "for help type help" << std::endl;

    while (isRun)
    {
        if (isShowPathWhenStartLoop)
            std::cout << path << " >>";
        else
            std::cout << "$ ";

        std::getline(std::cin, user_input);

        if (user_input == "exit" || user_input == "ex")
        {
            isRun = false;
            break;
        }

        //
        // hide path and show
        //
        else if (user_input == "hide path" || user_input == "-h -p" || user_input == "--hide --path")
            isShowPathWhenStartLoop = false;
        else if (user_input == "show path" || user_input == "-s -p" || user_input == "--show --path")
            isShowPathWhenStartLoop = true;

        //
        // help
        //
        else if (user_input == "help" || user_input == "-h" || user_input == "--help")
        {
            std::cout << "help / -h / --help - just help" << std::endl;
            std::cout << "help full / -fll / --full - for advanced help" << std::endl;
            std::cout << "help color / col / -col / --color - help for change color" << std::endl;
            std::cout << "help file / -f / --file - help for command file" << std::endl;
            std::cout << "help txt / text / -t / --txt - help for command txt" << std::endl;
            std::cout << "help console / cons / -cons / --console - help for command console" << std::endl;
            std::cout << "help console / cons / -cons / --console - help for command console" << std::endl;
        }

        else if (user_input.substr(0, 5) == "help ")
        {
            if (user_input.substr(5) == "full" || user_input.substr(5) == "-fll"
                || user_input.substr(5) == "--full") {
                std::cout << std::endl;
                std::cout << "clear / cls - clearing the console" << std::endl;
                std::cout << "info - information about this program" << std::endl;
                std::cout << std::endl;
                std::cout << "show path / -s -p / --show --path - to display the path in the console" << std::endl;
                std::cout << "show path / -s -p / --show --path - to display the path in the console" << std::endl;
                std::cout << "pwd - get path" << std::endl;
                std::cout << std::endl;
                std::cout << "color ... <- (here name of color) - for change color in console" << std::endl;
                std::cout << "color help - to check the available colors" << std::endl;
                std::cout << std::endl;
                std::cout << "exit / ex - for exit from console" << std::endl;
                std::cout << std::endl;
                std::cout << "cd - the command to change the working directory" << std::endl;
                std::cout << "dir - allows you to display a list of files and subdirectories "
                         "for the specified directory (for windows)" << std::endl;
                std::cout << std::endl;
                std::cout << "echo ... <- (here text to you want to write) - first you need to write path in cd ..." << std::endl;
                std::cout << "echo clear - for clear text in text file" << std::endl;
                std::cout << "read - for read txt file (first you need to write path in cd ...)" << std::endl;
                std::cout << std::endl;
                std::cout << "openf ... <- (path with file or just folder) - "
                         "opening a file or folder through OS programs (for all OS)" << std::endl;
                std::cout << "open ... <- (path) - allows you to display "
                         "a list of files and subdirectories for the specified directory (for all OS)" << std::endl;
                std::cout << std::endl;
                std::cout << "rnm / rename / mv ... <- (new_name) - the command to rename a file / folder "
                             "(first, enter the path to the cd, only then you can change the name of the "
                             "file or folder)" << std::endl;
                std::cout << std::endl;
                std::cout << "find ... <- (name file / folder) - first you need to specify "
                         "the path via cd, then you can search for a file / folder" << std::endl;
                std::cout << std::endl;
                std::cout << "create / cr ... <- (path) ... <- (file or folder) ... <- "
                         "(name file / folder) - the command to create a file or folder" << std::endl;
                std::cout << std::endl;
                std::cout << "delete / del ... <- (1 option: name file / folder or 2 option: "
                         "first you need to specify the path via cd, then just write delete) - "
                         "delete file / folder" << std::endl;
            }

            else if (user_input.substr(5) == "color" || user_input.substr(5) == "--color"
                || user_input.substr(5) == "-col" || user_input.substr(5) == "col")
                ColorConsole::choice_color("color help");

            else if (user_input.substr(5) == "file" || user_input.substr(5) == "-f"
                || user_input.substr(5) == "--file") {
                std::cout << "openf ... <- (path with file or just folder) - "
                         "opening a file or folder through OS programs (for all OS)" << std::endl;
                std::cout << "open ... <- (path) - allows you to display "
                             "a list of files and subdirectories for the specified directory (for all OS)" << std::endl;
                std::cout << std::endl;
                std::cout << "rnm / rename / mv ... <- (new_name) - the command to rename a file / folder "
                             "(first, enter the path to the cd, only then you can change the name of the "
                             "file or folder)" << std::endl;
                std::cout << std::endl;
                std::cout << "find ... <- (name file / folder) - first you need to specify "
                             "the path via cd, then you can search for a file / folder" << std::endl;
                std::cout << std::endl;
                std::cout << "create / cr ... <- (path) ... <- (file or folder) ... <- "
                             "(name file / folder) - the command to create a file or folder" << std::endl;
                std::cout << std::endl;
                std::cout << "delete / del ... <- (1 option: name file / folder or 2 option: "
                             "first you need to specify the path via cd, then just write delete) - "
                             "delete file / folder" << std::endl;
            }
            else if (user_input.substr(5) == "txt" || user_input.substr(5) == "text"
                || user_input.substr(5) == "-t" || user_input.substr(5) == "--txt") {
                std::cout << "echo ... <- (here text to you want to write) - first you need to write path in cd ..." << std::endl;
                std::cout << "echo clear - for clear text in text file" << std::endl;
                std::cout << "read - for read txt file (first you need to write path in cd ...)" << std::endl;
            }
            else if (user_input.substr(5) == "console" || user_input.substr(5) == "cons"
                || user_input.substr(5) == "-cons" || user_input.substr(5) == "--console") {
                std::cout << "cd - the command to change the working directory" << std::endl;
                std::cout << "dir - allows you to display a list of files and subdirectories "
                             "for the specified directory (for windows)" << std::endl;
                std::cout << "clear / cls - clearing the console" << std::endl;
                std::cout << "info - information about this program" << std::endl;
                std::cout << std::endl;
                std::cout << "show path / -s -p / --show --path - to display the path in the console" << std::endl;
                std::cout << "show path / -s -p / --show --path - to display the path in the console" << std::endl;
                std::cout << "pwd - get path" << std::endl;
                std::cout << std::endl;
                std::cout << "color ... <- (here name of color) - for change color in console" << std::endl;
                std::cout << "color help - to check the available colors" << std::endl;
                std::cout << std::endl;
                std::cout << "exit / ex - for exit from console" << std::endl;

            }

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
            std::cout << "_________VERSION_3__________" << std::endl;
            std::cout << "______AUTHOR: ALEXANDER_____" << std::endl;
            std::cout << "_____GIT_HUB: SYNEATION_____" << std::endl;
            std::cout << "____GIT-HUB: ALEXANDERSYN___" << std::endl;
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
        // echo and read
        //
        else if (user_input.substr(0, 5) == "echo ")
            FILETxt::save_text_in_file(user_input.substr(5), path);

        else if (user_input == "echo")
            std::cout << "you need to write so echo ..." << std::endl;

        else if (user_input == "read")
            FILETxt::Read_txt(user_input, path);
        //
        // End echo
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
        else if (user_input == "cd")
            std::cout << path << std::endl;
        //
        // End cd
        //

        //
        // dir or ls
        // it's seem only for windows
        //
        else if (user_input == "dir")
            FILEO::open_folder_use_dir(path);
        //
        // End dir
        //

        //
        // pwd
        //
        else if (user_input == "pwd")
            std::cout << path << std::endl;

        //
        // open && openf
        // for all OS
        //
        else if (user_input.substr(0, 5) == "open ")
            FILEO::output_all_files_command_open(user_input.substr(5));
        else if (user_input == "open" || user_input == "ls")
            FILEO::output_all_files_command_open(path);

        else if (user_input.substr(0, 6) == "openf ")
            FILEO::open_file(user_input.substr(6));
        else if (user_input == "openf")
            FILEO::open_file(path);
        //
        // End open && openf
        //

        //
        // find
        //
        else if (user_input.substr(0, 5) == "find ")
            FILEF::findFF(user_input.substr(5), path);
	    else if (user_input == "find")
	        std::cout << "you need to write like this find ... <- here name file \nor find (name file) (path)!" << std::endl;

        //-----------------------------
        // rename file
        //-----------------------------
        else if (user_input.substr(0, 4) == "rnm ") {
            rename_file::rnm_file(path, user_input.substr(4));

        }
        else if (user_input.substr(0, 3) == "mv ") {
            rename_file::rnm_file(path, user_input.substr(3));
        }
        else if (user_input.substr(0, 7) == "rename ") {
            rename_file::rnm_file(path, user_input.substr(7));
        }

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
        else if (user_input == "delete" || user_input.substr(0, 7) == "delete "
            || user_input == "del" || user_input.substr(0, 4) == "del ")
            FILED::delete_file_or_folder(user_input, path);
        //
        // End delete
        //

        else
            std::cout << "The command was not found! \nfor help type help! \n";

    }

    return 0;
}
