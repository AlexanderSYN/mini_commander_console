#include "helper_header/helper_text.h"
#include "helper_header/console/helper_clear_console.h"

#include <iostream>

#include "helper_header/console/debug_some_command.h"

int main() {
    setlocale(LC_ALL, "ru");

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
            std::cout << "exit / ex - for exit from console" << std::endl;
            std::cout << std::endl;
            std::cout << "cd - the command to change the working directory" << std::endl;
            std::cout << "dir - allows you to display a list of files and subdirectories "
                         "for the specified directory" << std::endl;
            std::cout << std::endl;
            std::cout << "openf ... <- (path with file or just folder) - "
                         "opening a file or folder through OS programs" << std::endl;
            std::cout << "open ... <- (path) - allows you to display "
                         "a list of files and subdirectories for the specified directory" << std::endl;
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
            if (user_input.substr(5) == "color") {
                std::cout << "_____helper for color_____" << std::endl;
                std::cout << "color ... <- (here name of color) - for change color in console" << std::endl;
                std::cout << "_____allows colors________" << std::endl;
                std::cout << " dark_green \n green \n red \n white \n purple" << std::endl;
            }
        }

        //
        // End help
        //

        //
        // for debug
        //
        else if (user_input == "debug")
        {
            debug_some_command(isRunDebug, user_input);
        }
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
            std::cout << "_____GIT-HUB: SYNEATION_____" << std::endl;
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

        }
        else if (user_input == "color")
            std::cout << "you need write like so -> color ... <- (name of color)" << std::endl;





        //
        // clear / cls
        //
        else if (user_input == "clear" || user_input == "cls")
            clear_console();

        else
            std::cout << "for help type help" << std::endl;


    }

    return 0;
}
