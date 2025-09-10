# EN

you can write 
cd (full path)
cd (name folder (if you write path before))
cd .. <- this means exit their current folder and go to the previous one.

//
// ColCons - Color Console (file color_console)
// FILEO - File Open (file help_open_file)
// 

# Folder Structure Description
## helper_cpp folder
1) Contains .cpp helper files for the Commander module
2)These files provide utility functions and support functionality
## helper_header folder
1) Contains .h header files for the corresponding .cpp files
2) These headers are required to include the helper functions in main()

# INCLUDED MODULES
## FOLDER: console
1) debug_some_command -> for debuging some commands in console
2) helper_clear_console -> code for clean console
3) color_console -> for change color in console
## FOLDER: work_with_files
1) helper_open_file -> for opens files, commands: cd, dir, open, openf
2) helper_create_file -> for create files, commands: public -> create_file ; private -> get_path_for_create