//
// Created by AlexanderSYN on 10.11.2025.
//

#include "../../helper_header/console/helper_for_help.h"

#include <iostream>

/**
 *
 * output help for date
 *
 */
void helper_for_help::get_help_date() {
    std::cout << "date -> output current date" << std::endl;
    std::cout << "time -> output current time" << std::endl;
}

/**
 *
 * output help for disk
 *
 */
void helper_for_help::get_help_disk() {
    std::cout << "[HINT] to get started, you need to specify the disk via cd (or directory)" << std::endl;
    std::cout << "free -> outputs the free space on your disk" << std::endl;
}



//===================================
// output help for file
//===================================
void helper_for_help::get_help_file() {
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

//===================================
// output help for full txt
//===================================
void helper_for_help::get_help_txt() {
    std::cout << "echo ... <- (here text to you want to write) - first you need to write path in cd ..." << std::endl;
    std::cout << "echo clear - for clear text in text file" << std::endl;
    std::cout << "read - for read txt file (first you need to write path in cd ...)" << std::endl;
}

//===================================
// output help for full console
//===================================
void helper_for_help::get_help_console() {
    std::cout << "cd - the command to change the working directory" << std::endl;
    std::cout << "dir - allows you to display a list of files and subdirectories "
                 "for the specified directory (for windows)" << std::endl;
    std::cout << "cmd (command from cmd) - after cmd you need to write command from cmd" << std::endl;
    std::cout << "history / hist - output your history" << std::endl;
    std::cout << "clear / cls - clearing the console" << std::endl;
    std::cout << "info - information about this program" << std::endl;
    std::cout << std::endl;
    std::cout << "show path / -s -p / --show --path - to display the path in the console" << std::endl;
    std::cout << "hide path / -h -p / --hide --path - to hide the path in the console" << std::endl;
    std::cout << "pwd - get path" << std::endl;
    std::cout << std::endl;
    std::cout << "color ... <- (here name of color) - for change color in console" << std::endl;
    std::cout << "color help - to check the available colors" << std::endl;
    std::cout << std::endl;
    std::cout << "exit / ex - for exit from console" << std::endl;
}

//===================================
// output help for full help
//===================================
void helper_for_help::get_help_full() {
    std::cout << std::endl;

    std::cout << "clear / cls - clearing the console" << std::endl;
    std::cout << "info - information about this program" << std::endl;
    std::cout << std::endl;

    std::cout << "show path / -s -p / --show --path - to display the path in the console" << std::endl;
    std::cout << "hide path / -h -p / --hide --path - to hide the path in the console" << std::endl;
    std::cout << "pwd - get path" << std::endl;
    std::cout << std::endl;

    std::cout << "color ... <- (here name of color) - for change color in console" << std::endl;
    std::cout << "color help - to check the available colors" << std::endl;
    std::cout << std::endl;

    std::cout << "exit / ex - for exit from console" << std::endl;
    std::cout << std::endl;

    std::cout << "date -> output current date" << std::endl;
    std::cout << "time -> output current time" << std::endl;
    std::cout << std::endl;

    std::cout << "cd - the command to change the working directory" << std::endl;
    std::cout << "dir - allows you to display a list of files and subdirectories "
             "for the specified directory (for windows)" << std::endl;
    std::cout << "history / hist - output your history" << std::endl;
    std::cout << "cmd (command from cmd) - after cmd you need to write command from cmd" << std::endl;
    std::cout << std::endl;

    std::cout << "echo ... <- (here text to you want to write) - first you need to write path in cd ..." << std::endl;
    std::cout << "echo clear - for clear text in text file" << std::endl;
    std::cout << "read - for read txt file (first you need to write path in cd ...)" << std::endl;
    std::cout << std::endl;

    std::cout << "[HINT] to get started, you need to specify the disk via cd (or directory)" << std::endl;
    std::cout << "free -> outputs the free space on your disk" << std::endl;
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


