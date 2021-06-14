#include <iostream>
#include <string>
#include <vector>
#include <map>

const std::string END = "end";
struct Node
{
	std::string FileName;
	bool is_folder;
	std::vector<Node*> next;
	Node* parent;
};

class File_system
{
public:
	File_system()
	{
		m_root = new Node;
		m_root->next = {};
		m_root->is_folder = false;
		current = m_root;
	}
	~File_system()
	{
		delete_memory(m_root);
	}
	void add_new_folder(const std::string& new_file)
	{
		Node* node = new Node;
		node->next = {};
		node->is_folder = true;
		node->FileName = new_file;
		node->parent = current;
		current->next.push_back(node);
	}
	void add_new_file(const std::string& new_file)
	{
		Node* node = new Node;
		node->next = {};
		node->is_folder = false;
		node->FileName = new_file;
		current->next.push_back(node);
	}

	void show_folder(const std::string name) const
	{
		for (size_t i = 0; i < current->next.size(); i++)
		{
			std::cout << current->next[i]->FileName << "\t";
		}
	}

	void enter_into_file(const std::string& filename)
	{
		for (size_t i = 0; i < current->next.size(); i++)
		{
			if (current->next[i]->FileName == filename
				&& current->next[i]->is_folder == true)
			{
				current->parent = current;
				current = current->next[i];
			}
			else std::cout << "Can't cange directory";
		}
	}
	void delete_folder(const std::string& filename)
	{
		for (size_t i = 0; i < current->next.size(); i++)
		{
			if (current->next[i]->FileName == filename)
				current = current->next[i];
		}
		if (current->next.empty())
			return;
		for (size_t i = 0; i < current->next.size(); i++)
		{
			delete_memory(current->next[i]);
			delete current->next[i];
			current->next[i] = nullptr;
		}
	}

	void delete_file(const std::string& filename)
	{
		for (size_t i = 0; i < current->next.size(); i++)
		{
			if (current->next[i]->FileName == filename && current->next[i]->is_folder==false)
			{
				delete	current->next[i];
				current->next.erase(current->next.begin() + i);
			}
		}
	}

	void go_to_parrent_dir()
	{
		current = current->parent;
	}

private:


	void delete_memory(Node* root)
	{
		if (root->next.empty())
			return;
		for (size_t i = 0; i < root->next.size(); i++)
		{
			delete_memory(root->next[i]);
			delete root->next[i];
			root->next[i] = nullptr;
		}
	}
private:
	Node* m_root;
	Node* current;
};

//std::string(File_system::* mkdir) (const std::string&) = &File_system::add_new_folder;
//std::string(File_system::* ls) (const std::string&) = &File_system::show_folder;
//std::string(File_system::* cd) (const std::string&) = &File_system::enter_into_file;
//std::string(File_system::* touch) (const std::string&) = &File_system::add_new_file;
//std::string(File_system::* rm) (const std::string&) = &File_system::delete_file;
//std::string(File_system::* rmdir) (const std::string&) = &File_system::delete_folder;

int main()
{
	std::string lines;
	File_system fs;
	std::map<std::string, void(*)(std::string) > mp;
	while (lines!=END)
	{
		
		std::getline(std::cin, lines);
		std::string firstWord = lines.substr(0, lines.find(" "));
		lines.erase(0, firstWord.size() + 1);
		//mp["mkdir"]= (ob.*ptfptr_sum)(a, b);
		
		if (firstWord == "mkdir")
			fs.add_new_folder(lines);
		else if (firstWord == "ls")
		{
			fs.show_folder(lines);
		}
		else if (firstWord == "cd")
		{
			fs.enter_into_file(lines);
		}
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
