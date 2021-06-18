#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "virtual_files.h"


File_system::File_system() : m_root{ std::shared_ptr<Node>(new Node) }
	{
		m_root->next = {};
		m_root->is_folder = false;
		current = m_root;
	}

	void File_system::add_new_folder(const std::string& new_file)
	{
		Node* node = new Node;
		node->is_folder = true;
		node->FileName = new_file;
		node->parent = current;
		current->next.push_back(std::shared_ptr<Node>(node));
	}
	void File_system::add_new_file(const std::string& new_file)
	{
		Node* node = new Node;
		node->is_folder = false;
		node->parent = nullptr;
		node->FileName = new_file;
		current->next.push_back(std::shared_ptr<Node>(node));
	}
	void File_system::show_folder(const std::string name) const
	{
		for (size_t i = 0; i < current->next.size(); i++)
		{
			std::cout << current->next[i]->FileName << "\t";
		}
	}
	void File_system::enter_into_file(const std::string& filename)
	{
		bool notentered = true;
		for (size_t i = 0; i < current->next.size(); i++)
		{
			if (current->next[i]->FileName == filename
				&& current->next[i]->is_folder == true)
			{
				current->parent = current;
				current = current->next[i];
				notentered = false;
				break;
			}

		}
		if (notentered)
			std::cout << "Can't change directory";
	}
	void File_system::delete_folder(const std::string& filename)
	{
		for (size_t i = 0; i < current->next.size(); ++i)
		{
			if ((current->next[i]->FileName == filename)
				&& (current->next[i]->is_folder == true))
			{
				current->next.erase(current->next.begin() + i);
				break;
			}
		}
	}
	void File_system::delete_file(const std::string& filename)
	{
		for (size_t i = 0; i < current->next.size(); i++)
		{
			if ((current->next[i]->FileName == filename)
				&& (current->next[i]->is_folder == false))
			{
				current->next.erase(current->next.begin() + i);
				break;
			}
		}
	}
	void File_system::go_to_parrent_dir()
	{
		current = current->parent;
	}
