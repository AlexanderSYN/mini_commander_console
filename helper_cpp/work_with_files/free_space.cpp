//
// Created by AlexanderSYN on 31.12.2025.
//

#include "../../helper_header/work_with_files/free_space.h"

void free_space::get_info_free_disk_space(std::string path) {
    std::string disk = path.substr(0, 3); // get disk from path
    try {
        fs::space_info si = fs::space(disk);

        // si.available is the number of free bytes available to the current user
        std::uintmax_t available_bytes = si.available;
        std::uintmax_t total_capacity_bytes = si.capacity;

        // convert bytes to MB, GB, TB
        double available_gb = static_cast<double>(available_bytes) / (1024 * 1024 * 1024);
        double total_capacity_gb = static_cast<double>(total_capacity_bytes) / (1024 * 1024 * 1024);

        std::cout << "Disk space info for: " << disk << std::endl;
        std::cout << "Total capacity: " << total_capacity_gb << " GB (" << total_capacity_bytes << " bytes)" << std::endl;
        std::cout << "Available space: " << available_gb << " GB (" << available_bytes << " bytes)" << std::endl;

    } catch (std::exception e) {
        std::cerr << "[ERROR] " << e.what();
        std::cout << "please write correctly disk or ex for exit >> ";
        std::cin >> disk;
        if (disk == "ex" || disk == "exit") {
            return;
        } else {
            get_info_free_disk_space(disk);
        }
    }
}

