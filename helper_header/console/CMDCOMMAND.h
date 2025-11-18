//
// Created by AlexanderSYN on 18.11.2025.
//

#ifndef CMDCOMMAND_H
#define CMDCOMMAND_H

#ifdef _IOSTREAM_
    #define IOSTREAM_INCLUDED 1
#else
    #include <iostream>
    #define IOSTREAM_INCLUDED 0
#endif

#ifdef __STRINGIFY__
    #define STRING_INCLUDED 1
#else
    #include <string>
    #define STRING_INCLUDED 0
#endif

#include <cstdlib>

class CMDCOMMAND {
public :
    static void start_cmd_commands(std::string command);
};

#endif //CMDCOMMAND_H
