# EN

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
2) helper_create_file -> for create files, commands: public -> create_file ; 
private -> get_path_for_create, check_isFile_for_create, get_name_file_folder_for_create, createFF
3) for_time -> for use in command open: namespace -> to_time_t, format_time

commands:
cd (full path)
cd (name folder (if you write path before))
cd .. <- this means exit their current folder and go to the previous one.
```
cd ...
```

help -> for show all commands
help color -> for show commands color
```
help
```
```
help color
```

clear / cls -> for clear console
```
clear
```
```
cls
```

info -> show information about this programm
```
info
```

color ... <- (here write a color) -> the command to change the color in console
```
color ...
```

dir -> to display all files and folders (but first you need to specify the path use command cd ...) (for windows)
```
dir
```

open ... <- (here path) or open -> to display all files and folders, but in the 2nd example, you need to specify the path to the cd ...
```
open ...
```
```
open
```

openf ... <- (here is the path), you can also use just openf. Only the folder path will be used from the command cd ... -> command to open files or folders
```
openf ...
```
```
openf 
```

exit / ex -> to exit the program
```
exit
```
```
ex
```
