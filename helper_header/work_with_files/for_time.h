//
// Created by AlexanderSYN on 11.09.2025.
//

#ifndef FOR_TIME_H
#define FOR_TIME_H

#include <filesystem>
#include <ctime>

namespace fs = std::filesystem;

namespace timeff {
    std::time_t to_time_t(const fs::file_time_type& ftime);
    std::string format_time(const fs::file_time_type& ftime);
}

#endif //FOR_TIME_H
