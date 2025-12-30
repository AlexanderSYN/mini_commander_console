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
4) CMDCOMMAND -> for work with cmd commands
5) date_and_time -> for date and time

## FOLDER: helper_for_find_folder_file
1) helper_for_find_FF -> for work with command -> find

## FOLDER: work_with_files
1) helper_open_file -> for opens files, commands: cd, dir, open, openf
2) helper_create_file -> for create files, commands: public -> create_file ; 
private -> get_path_for_create, check_isFile_for_create, get_name_file_folder_for_create, createFF
3) for_time -> for use in command open: namespace -> to_time_t, format_time
4) free_space -> get_info_free_disk_space
5) helper_delete_file -> delete_file_or_folder(string user_input, string path) (for delete file)
6) include_for_work_with_files -> all libraries necessary for faster inclusion in the file are included.

## FOLDER: work_with_txt
1) helper_txt -> for work with txt files

commands:
# EN

cd (full path)
cd (name folder (if you write path before))
cd .. <- this means exit their current folder and go to the previous one.
```
cd ...
```
```
cd
```

pwd - get path
```
pwd
```

cmd (cmd command) - for using cmd commands
```
cmd (command)
```

history - show your history commands
```
history
```

date - output date in console
```
date
```
time - output time in console
```
time
```

show path or hide path - choose between showing the full path or just $
```
show path / -s -p / --show --path 
```
```
hide path / -h -p / --hide --path
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

dir / ls-> to display all files and folders (but first you need to specify the path use command cd ...) 
```
dir
```
```
ls
```
## I do not recommend using the search in a regular disk, because the search will take longer. I advise you to look for a file or folders in at least one folder.
find ... <- (name file / folder) - first you need to specify the path via cd, then you can search for a file / folder
```
find ...
```
## I do not recommend using the search in a regular disk, because the search will take longer. I advise you to look for a file or folders in at least one folder.
## The search skips
### folders
1) "System32", "System64", "Windows", "Program Files", "ProgramData",
2) "AppData", "Temp", "tmp", "Recycle.Bin", "Recovery",
3) "$Recycle.Bin", "System Volume Information", "Windows.old"
### files
5) ".drv", ".vxd", ".386", ".ocx",".cpl", ".msc", ".scr",
6) ".com", ".tmp",".inf", ".cat", ".mui"

>[!TIP]
> to get started, you need to specify the disk via cd (or directory)
free - outputs the free space on your disk
```
free
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

create / cr ... <- (path) ... <- (file or folder) ... <- (name file / folder) - the command to create a file or folder
```
create ... ... ...
```
```
cr ... ... ...
```

delete / del ... <- (1 option: name file / folder or 2 option: first you need to specify the path via cd, then just write delete) - delete file / folder
```
delete ...
```
```
del ...
```

echo ... <- (here text to you want to write) - first you need to write path in cd ...
echo clear - for clear text in text file
```
echo ...
```
```
echo clear
```

read - for read txt file (first you need to write path in cd ...)
```
read
```

exit / ex -> to exit the program
```
exit
```
```
ex
```
# RU
команды:
cd (полный путь)
cd (название папки (если вы уже указывали путь ранее))
cd .. <- это означает выход из текущей папки и переход к предыдущей.
```
cd ...
```
```
cd
```

pwd -> вывести путь на которым вы сейчас находитесь
```
pwd
```

cmd (cmd command) - для использования cmd комманд
```
cmd (command)
```

history - показать вашу историю команд
```
history
```

date - вывести дату в консоль
```
date
```
time - вывести в консоль
```
time
```

help --full -> отображения всех команд
help --color -> для отображения цвета команд
```
help --full
```
```
help --color
```

clear / cls -> для очистки консоли
```
clear
```
```
cls
```

info - > информация об этой программе
```
info
```


color ... < - (укажите цвет здесь) - > команда для изменения цвета в консоли
```
color ...
```

dir / ls -> для отображения всех файлов и папок (но сначала вам нужно указать путь в команде) используйте cd ...
```
dir
```
```
ls
```

find ... < - (имя / папка) - сначала вам нужно указать путь к компакт-диску, затем вы можете выполнить поиск файла / папки

>[!TIP]
> Я не рекомендую использовать поиск на обычном диске, так как поиск займет больше времени. Я советую вам искать файл или папки хотя бы в одной папке.
find ... < - (имя / папка) - сначала вам нужно указать путь к компакт-диску, затем вы можете выполнить поиск файла / папки

```
find ...
```
## Я не рекомендую использовать поиск на обычном диске, потому что поиск займет больше времени. Я советую вам искать файл или папки хотя бы в одной папке.
## поиск пропускает
### папки
1) "System32", "System64", "Windows", "Program Files", "ProgramData",
2) "AppData", "Temp", "tmp", "Recycle.Bin", "Recovery",
3) "$Recycle.Bin", "System Volume Information",
### файлы
5) ".drv", ".vxd", ".386", ".ocx",".cpl", ".msc", ".scr",
6) ".com", ".tmp",".inf", ".cat", ".mui"

>[!TIP]
> для начала вам необходимо указать диск через cd (или каталог)
free - выводит количество свободного места на вашем диске
```
free
```

open ... < - (здесь путь) или открыть - >, чтобы отобразить все файлы и папки, но во втором примере вам нужно указать путь в cd ..
```
open ...
```
```
open
```

openf ... <- (здесь путь) вы также можете просто использовать openf. Только путь папки будет использоваться из команды cd ... -> команды для открытия файлов или папок
```
openf ...
```
```
openf
```

create / cr ... <- (путь) ... <- (файл или папка) ... < - (имя файла / папки) - команда для создания файла или папки
```
create ... ... ...
```
```
cr ... ... ...
```

delete / del ... < - (1 вариант: введите файл/папку или 2 вариант: сначала нужно указать путь через cd, затем просто удалите его) - удалить файл / папку
```
delete ...
```
```
del ...
```

echo ... < - (тут текст, который вы хотите записать) - сначала вам нужно написать путь в cd ...
echo clear -> для очистки текстового файла
```
echo ...
```
```
echo clear
```

read - чтения текстового файла (сначала вам нужно написать путь в cd ...)
```
read
```

exit / ex - > для выхода из программы
```
exit
```
```
ex
```


