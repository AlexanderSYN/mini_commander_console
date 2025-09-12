cmake_minimum_required(VERSION 3.30.5)
project(mini_commander_console)

set(CMAKE_CXX_STANDARD 20)

add_executable(mini_commander_console main.cpp
        helper_header/work_with_files/helper_open_file.h
        helper_header/helper_text.h
        helper_cpp/helper_text.cpp
        helper_header/console/helper_clear_console.h
        helper_cpp/console/helper_clear_console.cpp
        helper_cpp/console/debug_some_command.cpp
        helper_header/console/debug_some_command.h
        helper_header/console/color_console.h
        helper_cpp/console/color_console.cpp
        helper_cpp/work_with_files/helper_open_file.cpp
        helper_header/work_with_files/helper_create_file.h
        helper_cpp/work_with_files/helper_create_file.cpp
        helper_header/work_with_files/for_time.h
        helper_cpp/work_with_files/for_time.cpp
        helper_header/work_with_files/helper_delete_file.h
        helper_header/work_with_files/include_for_work_with_files.h
        helper_cpp/work_with_files/helper_delete_file.cpp)
