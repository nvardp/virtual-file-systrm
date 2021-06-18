#include "virtual_files.h"

int main()
{
	std::string lines;
	File_system fs;
	while (lines != END)
	{
		std::getline(std::cin, lines);
		std::string firstWord = lines.substr(0, lines.find(" "));
		lines.erase(0, firstWord.size() + 1);
		//mp["mkdir"]= (ob.*ptfptr_sum)(a, b);

		if (firstWord == "mkdir")
			fs.add_new_folder(lines);
		else if (firstWord == "ls")
			fs.show_folder(lines);
		else if (firstWord == "cd")
			fs.enter_into_file(lines);
		else if (firstWord == "touch")
			fs.add_new_file(lines);
		else if (firstWord == "rm")
			fs.delete_file(lines);
		else if (firstWord == "rmdir")
			fs.delete_folder(lines);
		else if (firstWord == "cd..")
			fs.go_to_parrent_dir();

	}

}

//std::string(File_system::* mkdir) (const std::string&) = &File_system::add_new_folder;
//std::string(File_system::* ls) (const std::string&) = &File_system::show_folder;
//std::string(File_system::* cd) (const std::string&) = &File_system::enter_into_file;
//std::string(File_system::* touch) (const std::string&) = &File_system::add_new_file;
//std::string(File_system::* rm) (const std::string&) = &File_system::delete_file;
//std::string(File_system::* rmdir) (const std::string&) = &File_system::delete_folder;
