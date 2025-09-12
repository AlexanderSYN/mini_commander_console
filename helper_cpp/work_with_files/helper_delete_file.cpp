//
// Created by AlexanderSYN on 12.09.2025.
//

#include "../../helper_header/work_with_files/include_for_work_with_files.h"
#include "../../helper_header/work_with_files/helper_delete_file.h"

void FILED::delete_file_or_folder(std::string user_input, std::string &path) {
    char choice;
	std::string tmp_full_path_path_plus_user_input = path;
    //
	// check for option 1 - delete (path) or 2 - delete
	//
	if (user_input.substr(0, 7) == "delete ") // delete ...
	{
		std::string path = user_input.substr(7);

		if (path.ends_with('\\'))
			tmp_full_path_path_plus_user_input += user_input.substr(7);
		else {
			tmp_full_path_path_plus_user_input += "\\";
			tmp_full_path_path_plus_user_input += user_input.substr(7);
		}

		if (!fs::exists(path) && !fs::exists(tmp_full_path_path_plus_user_input))
		{
			std::cout << "ERROR: File / Folder is not found!" << std::endl;
			return;
		}

		// if you just to write name of folder but is not full path
		if (fs::exists(tmp_full_path_path_plus_user_input))
			path = tmp_full_path_path_plus_user_input;

		std::cout << "are you sure? (Y/N) >> ";
		std::cin >> choice;

		if (toupper(choice) == 'N')
			return;

		try
		{
			if (fs::is_regular_file(path))
			{

				if (std::remove(path.c_str()) == 0)
				{
					std::cout << "File deleted successfully!" << std::endl;

					if (path == path)
						path = "\\";
					return;

				}
				else
				{
					std::cerr << "Error: failed to delete file (" << errno << ") - "
						<< path << std::endl;
					perror("Reason");
					return;
				}
			}
			else if (fs::is_directory(path))
			{
				try
				{
					if (fs::remove(path))
					{
						std::cout << "Empty folder deleted successfully!" << std::endl;
						if (path == path)
							path = "\\";
						return;
					}
				}
				catch (const std::filesystem::filesystem_error& fs_err)
				{
					if (fs_err.code() != std::errc::directory_not_empty)
						throw;
				}

				if (path != "\\")
				{
					uintmax_t uin_t = fs::remove_all(path);

					if (uin_t > 0)
					{
						std::cout << "Deleted " << uin_t << " items from folder succesffully!" << std::endl;
						if (path == path)
							path = "\\";
						return;
					}
					else
					{
						std::cerr << "Error: failed to delete folder - " << path << " !" << std::endl;
						return;
					}
				}

			}
		}
		catch (const std::filesystem::filesystem_error& e)
		{
			std::cerr << "Filesystem error: " << e.what() << std::endl;
			return;
		}
		catch (const std::exception& e)
		{
			std::cerr << "[ERROR] " << e.what() << std::endl;
			return;
		}
	}
	//
	//delete
	//
	else // delete
	{
		if (!fs::exists(path))
		{
			std::cout << "File is not found!" << std::endl;
			return;
		}

		std::cout << "are you sure? (Y/N) >> ";
		std::cin >> choice;

		if (toupper(choice) == 'N')
			return;

		try
		{

			if (fs::is_regular_file(path))
			{

				if (std::remove(path.c_str()) == 0)
				{
					std::cout << "File deleted successfully!" << std::endl;
					path = "\\";
					return;
				}
				else
				{
					std::cerr << "Error: failed to delete file (" << errno << ") - "
						<< path << std::endl;
					perror("Reason");
					return;
				}
			}
			else if (fs::is_directory(path))
			{
				try
				{
					if (fs::remove(path))
					{
						std::cout << "Empty folder deleted successfully!" << std::endl;
						path = "\\";
						return;
					}
				}
				catch (const fs::filesystem_error& fs_err)
				{
					if (fs_err.code() != std::errc::directory_not_empty)
						throw;
				}

				if (path != "\\")
				{
					uintmax_t uin_t = fs::remove_all(path);

					if (uin_t > 0)
					{
						std::cout << "Deleted " << uin_t << " items from folder succesffully!" << std::endl;
						path = "\\";
						return;
					}
					else
					{
						std::cerr << "ERROR: failed to delete folder - " << path << " !" << std::endl;
						return;
					}
				}

			}
		}
		catch (const fs::filesystem_error& e)
		{
			std::cerr << "Filesystem error: " << e.what() << std::endl;
			return;
		}
		catch (const std::exception& e)
		{
			std::cerr << "[ERROR] " << e.what() << std::endl;
			return;
		}
	}
}

