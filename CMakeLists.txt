cmake_minimum_required(VERSION 3.31)
project(mini_commander_console)

set(CMAKE_CXX_STANDARD 20)

add_executable(mini_commander_console main.cpp
        help_header/helper_open_file.h
        help_header/helper_text.h
        help_cpp/helper_text.cpp
        help_header/console/helper_clear_console.h
        help_cpp/console/helper_clear_console.cpp)
