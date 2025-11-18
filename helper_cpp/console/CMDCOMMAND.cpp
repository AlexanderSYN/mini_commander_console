//
// Created by AlexanderSYN on 18.11.2025.
//
#include "../../helper_header/console/CMDCOMMAND.h"

void CMDCOMMAND::start_cmd_commands(std::string command) {
    try {
        system(command.c_str());
    } catch (const std::exception &e) {
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return;
    }
}
