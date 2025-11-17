//
// Created by AlexanderSYN on 18.11.2025.
//

#include "../../helper_header/console/date_and_time.h"

/**
 *
 * output -> (day of the week) month (day of the month) hour:min:sec yy
 * (24 hour)
 *
 */
void time_and_date::output_local_date_and_time() {
    try {
        // current date/time based on current system
        time_t now = time(0);

        // convert now to string form
        char* dt = ctime(&now);

        std::cout << dt;

    } catch (const std::exception &e) {
        std::cerr << "[ERROR] " << e.what() << std::endl;
    }
}

/**
 *
 * output time -> hh:min::sec
 *
 */
void time_and_date::output_time() {
    try {
        time_t now = time(0);

        tm *ltm = localtime(&now);

        std::cout << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "[ERROR] " << e.what() << std::endl;
    }
}



