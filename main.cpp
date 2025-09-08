#include "help_header/helper_text.h"

#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");

    bool isRun = true;

    std::string path = "/", user_input;

    while (isRun)
    {
        std::cout << path << " >>";
        std::getline(std::cin, user_input);

        std::cout << "for help type help" << std::endl;

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
                std::cout << "dark_green \n green \n red \n white \n purple" << std::endl;
            }
        }

        //
        // End help
        //

        //
        // clear / cls
        //
        else if (to_lower(user_input) == "clear")





    }

    return 0;
}
