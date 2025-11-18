cmake_minimum_required(VERSION 3.31)
project(MiniCommanderConsole)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(MiniCommanderConsole main.cpp
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
        helper_cpp/work_with_files/helper_delete_file.cpp
        helper_header/helper_for_find_folder_file/helper_for_find_FF.h
        helper_cpp/helper_for_find_folder_file/helper_for_find_FF.cpp
        helper_header/work_with_txt/helper_txt.h
        helper_cpp/work_with_txt/helper_txt.cpp
        helper_header/work_with_files/helper_rename_files.h
        helper_cpp/work_with_files/helper_rename_files.cpp
        helper_header/console/helper_for_help.h
        helper_cpp/console/helper_for_help.cpp
        helper_header/console/date_and_time.h
        helper_cpp/console/date_and_time.cpp
        helper_header/console/CMDCOMMAND.h
        helper_cpp/console/CMDCOMMAND.cpp
)
