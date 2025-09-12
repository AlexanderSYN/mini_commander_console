//
// Created by AlexanderSYN on 12.09.2025.
//

#include "../../helper_header/work_with_files/include_for_work_with_files.h"
#include "../../helper_header/work_with_files/helper_delete_file.h"

void FILED::delete_file_or_folder(std::string user_input, std::string &path) {
    char choice;

	std::string tmp_full_path_path_plus_user_input = path;
    //
	// check for option 1 - delete (path) or 2 - delete or del
	//
	if (user_input.substr(0, 7) == "delete " || user_input.substr(0, 4) == "del ") // del ... /  delete ...
	{
		std::string input_path;

		if (user_input.substr(0, 7) == "delete ")
			input_path = user_input.substr(7);

		else
			input_path = user_input.substr(4);



		if (input_path.ends_with('\\'))
			tmp_full_path_path_plus_user_input += input_path;
		else {
			tmp_full_path_path_plus_user_input += "\\";
			tmp_full_path_path_plus_user_input += input_path;
		}

		if (!fs::exists(input_path) && !fs::exists(tmp_full_path_path_plus_user_input))
		{
			std::cout << "ERROR: File / Folder is not found!" << std::endl;
			return;
		}

		// if you just to write name of folder but is not full path
		if (fs::exists(tmp_full_path_path_plus_user_input))
			input_path = tmp_full_path_path_plus_user_input;

		std::cout << "are you sure? (Y/N) >> ";
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

		if (toupper(choice) == 'N')
			return;

		try
		{
			if (fs::is_regular_file(input_path))
			{

				if (std::remove(input_path.c_str()) == 0)
				{
					std::cout << "File deleted successfully!" << std::endl;

					if (input_path == input_path) {
						if (!input_path.empty() && input_path != "/") {
							fs::path current_path(input_path);
							input_path = current_path.parent_path().string();
							return;
						}
					}


				}
				else
				{
					std::cerr << "Error: failed to delete file (" << errno << ") - "
						<< input_path << std::endl;
					perror("Reason");
					return;
				}
			}
			else if (fs::is_directory(input_path))
			{
				try
				{
					if (fs::remove(input_path))
					{
						std::cout << "Empty folder deleted successfully!" << std::endl;
						if (input_path == input_path) {
							if (!input_path.empty() && input_path != "/") {
								fs::path current_path(input_path);
								input_path = current_path.parent_path().string();
								return;
							}
						}
						return;
					}
				}
				catch (const std::filesystem::filesystem_error& fs_err)
				{
					if (fs_err.code() != std::errc::directory_not_empty)
						throw;
				}

				if (input_path != "\\")
				{
					uintmax_t uin_t = fs::remove_all(input_path);

					if (uin_t > 0)
					{
						std::cout << "Deleted " << uin_t << " items from folder succesffully!" << std::endl;
						if (input_path == input_path) {
							if (!input_path.empty() && input_path != "/") {
								fs::path current_path(input_path);
								input_path = current_path.parent_path().string();
								return;
							}
						}
						return;
					}
					else
					{
						std::cerr << "ERROR: failed to delete folder - " << input_path << " !" << std::endl;
						return;
					}
				}

			}
		}
		catch (const std::filesystem::filesystem_error& e)
		{
			std::cerr << "FILESYSTEM ERROR: " << e.what() << std::endl;
			return;
		}
		catch (const std::exception& e)
		{
			std::cerr << "[ERROR] " << e.what() << std::endl;
			return;
		}
	}
	//
	//delete / del
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
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

		if (toupper(choice) == 'N')
			return;

		try
		{

			if (fs::is_regular_file(path))
			{

				if (std::remove(path.c_str()) == 0)
				{
					std::cout << "File deleted successfully!" << std::endl;
					if (!path.empty() && path != "/") {
						fs::path current_path(path);
						path = current_path.parent_path().string();
						return;
					}
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
						if (!path.empty() && path != "/") {
							fs::path current_path(path);
							path = current_path.parent_path().string();
							return;
						}
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
						if (!path.empty() && path != "/") {
							fs::path current_path(path);
							path = current_path.parent_path().string();
							return;
						}
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
			std::cerr << "FILESYSTEM ERROR: " << e.what() << std::endl;
			return;
		}
		catch (const std::exception& e)
		{
			std::cerr << "[ERROR] " << e.what() << std::endl;
			return;
		}
	}
}

