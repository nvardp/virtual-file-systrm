#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

const std::string END = "end";

struct Node
{
	std::string FileName{};
	bool is_folder;
	std::vector <std::shared_ptr <Node> > next;
	std::shared_ptr<Node> parent{};
};

class File_system
{
public:
	File_system();

	void add_new_folder(const std::string& new_file);
	void add_new_file(const std::string& new_file);
	void show_folder(const std::string name) const;
	void enter_into_file(const std::string& filename);
	void delete_folder(const std::string& filename);
	void delete_file(const std::string& filename);
	void go_to_parrent_dir();

private:
	std::shared_ptr<Node> m_root;
	std::shared_ptr<Node> current;
};


