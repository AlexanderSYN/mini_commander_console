//
// Created by AlexanderSYN on 08.09.2025.
//

#include "../helper_header/helper_text.h"

std::string to_lower(std::string text)
{
    for (auto& x : text)
        x = tolower(x);

    return text;
}

