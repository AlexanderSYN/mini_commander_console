#include <iostream>
#include <string>

#include "../../helper_header/console/helper_clear_console.h"
#include "../../helper_header/console/debug_some_command.h"

#include "../../helper_header/helper_text.h"

//
// for debugging some commands!
//
//
// Created by AlexanderSYN on 09.09.2025.
//
void debug_some_command(bool & isRunDebug, std::string user_input, std::string path)
{
    std::cout << "_____WELCOME TO DEBUG CONSOLE_____" << std::endl;
    std::cout << "What do you want to debug?" << std::endl;

    while (isRunDebug)
    {
        std::cout << "Debug << ";
        std::getline(std::cin, user_input);

        if (user_input == "to_lower")
        {
            std::getline(std::cin, user_input);
            std::cout << "output: " << to_lower(user_input) << std::endl;
        }
        else if (user_input == "current_path")
        {
            std::cout << "output: " << get_current_path(path) << std::endl;
        }
        else if (user_input == "help")
        {
            std::cout << "to_lower -> check for to_lower words when input any words" << std::endl;
            std::cout << "current_path -> display current path" << std::endl;
            std::cout << "ex / exit -> exit from debug" << std::endl;
        }

        else if (user_input == "ex" || user_input == "exit")
        {
            isRunDebug = false;
            std::cout << "exit from debug" << std::endl;
            break;
        }
        else {
            std::cout << "The command was not found!" << std::endl;
        }
    }
}

