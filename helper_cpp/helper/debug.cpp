//
// Created by 00077 on 01.03.2026.
//

#include "../../helper_header/helper/debug.h"

template<typename ... Args>
void Debug::debug(Args&&... args) {
    std::cout << "[DEBUG] ";
    ((std::cout << args << ' '), ...);
    std::cout << std::endl;
}


