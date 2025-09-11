//
// Created by AlexanderSYN on 11.09.2025.
//
#include "../../helper_header/work_with_files/for_time.h"

//
//function for convert from file_time_type to time_t
//
std::time_t timeff::to_time_t(const fs::file_time_type& ftime)
{
    auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
        ftime - fs::file_time_type::clock::now() + std::chrono::system_clock::now()
    );

    return std::chrono::system_clock::to_time_t(sctp);
}

//
//function for formatter to output date and time
//
std::string timeff::format_time(const fs::file_time_type& ftime)
{
    std::time_t cftime = to_time_t(ftime);
    char buffer[80];

#ifdef  _WIN32
    struct tm timeinfo;
    localtime_s(&timeinfo, &cftime);
    std::strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", &timeinfo);
#else // if MacOS / Linux
    std::strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", std::localtime(&cftime));
#endif

    return buffer;
}
