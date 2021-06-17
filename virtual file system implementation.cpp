#include <iostream>
#include <string>
#include <vector>
#include <memory>

const std::string END = "end";
struct Node
{
	Node(){}
	Node(const Node&) = delete;
	//~Node() { std::cout << "ok"; }
	std::string FileName;
	bool is_folder;
	std::vector <std::shared_ptr <Node> > next;
	std::shared_ptr<Node> parent{};
};

class File_system
{
public:
	File_system() : m_root{ std::shared_ptr<Node>(new Node) }
	{
		m_root->next = {};
		m_root->is_folder = false;
		current = m_root;
	}
	~File_system()
	{
		//delete_memory(m_root);
	}
	void add_new_folder(const std::string& new_file)
	{
		Node* node = new Node;
		node->next;
		node->is_folder = true;
		node->FileName = new_file;
		node->parent = current;
		current->next.push_back(std::shared_ptr<Node>(node));
	}
	void add_new_file(const std::string& new_file)
	{
		Node* node = new Node;
		node->next;
		node->is_folder = false;
		node->FileName = new_file;
		current->next.push_back(std::shared_ptr<Node>(node));
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
	void delete_folder(const std::string& filename)
	{
		decltype(auto) tmp = current;				
		size_t a = 0;
		for (; a < tmp->next.size(); a++)
		{	
			if (tmp->next[a]->FileName == filename)
			{
				*tmp = *tmp->next[a];
				break;
			}
		}
		tmp->next.erase(tmp->next.begin() + a);
		return;
	}
	void delete_file(const std::string& filename)
	{
		for (size_t i = 0; i < current->next.size(); i++)
		{
			if (current->next[i]->FileName == filename && current->next[i]->is_folder == false)
			{
				current->next.erase(current->next.begin() + i);
			}
		}
	}
	void go_to_parrent_dir()
	{
		current = current->parent;
	}


private:
	std::shared_ptr<Node> m_root;
	std::shared_ptr<Node> current;
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
		else if (firstWord == "exit")
			fs.~File_system();
	}

}
/*


void print()
{
}
template <typename T, typename... Types>
void print(const T& first, const Types&... args)
{
	std::cout << first << std::endl;
	print(args...);
}


#include <limits.h>
#include <climits>
#include<ratio>
#include<chrono>
#include<ctime>
#include<list>
#include<algorithm>




using namespace std;
class A {
public:
	virtual void foo() = 0;



 };
class B :virtual public A
{
public:
	 void foo()  override
	{
		cout << "B";
	}

};

class C : virtual public A
{
	void foo() override
	{
		cout << "C";
	}
};

class D: public C, public B
{
public:
	void foo() override
	{
		cout << "D";
	}


};

#include<forward_list>
#include<map>
#include <unordered_map>
#include<fstream>
#include<compare>
#include <array>
#include <set>

int addNumbers(int number1, int number2)
{
	cout <<  __func__ << endl;
	return number1 + number2;
}
int main()
{


	std::map<int, int> vc;


	std::forward_list<int> ls;

	//cout << *vc.lower_bound(6)<<endl;\

				vc.key_comp();
	//vc.swap(ls);
	//cout << ls.size() << endl;

	std::vector<int> v2c(vc.begin(), vc.end());
	//vc.~vector<int>();


	//const int& a = 5;
	//int a,b;
	//++a = 5;
	//std::array arr{ 9, 8, 7 };
	unordered_map<int, string> mp;
	mp.insert({ 4, "A" });
	mp.insert({ 2, "nn" });
	mp.insert({ 2, "Bb" });
	mp.insert({ 542, "ll" });
	mp.insert({ 5234, "ll" });
	mp.insert({ 2345, "ll" });
	mp.insert({ 554, "ll" });
	mp.insert({ 5333, "ll" });
	mp.insert({ 5223, "ll" });
	mp.insert({ 52, "ll" });
	mp.insert({ 53, "ll" });
	mp.insert({ 25, "ll" });
	mp.insert({ 51, "ll" });
	mp.insert({ 533, "ll" });
	mp.insert({ 5222, "ll" });
	mp.insert({ 53, "ll" });
	mp.insert({ 533, "ll" });
	mp.insert({ 53, "ll" });
	mp.insert({ 59, "ll" });
	mp.insert({ 4, "ll" });
	/*sizeof(mp);
	for (auto it = mp.cbegin(); it != mp.cend(); ++it)
	{
		std::cout << it->first << " " <<   it->second << "\n";
	}
	cout << sizeof(mp);*/

	//	cout << __func__;

	//addNumbers(1, 2);
	/*int i{ 11 };
	strong_ordering result{ i <=> 0 };
	if (result == strong_ordering::less) { cout << "less" << endl; }
	if (result == strong_ordering::greater) { cout << "greater" << endl; }
	if (result == strong_ordering::equal) { cout << "equal" << endl; }*/
	/*A* ptr = new D;
	ptr->foo();
	B obj;
	cout << sizeof(obj);*/

	//	vector<int> vec {1, 2, 3, 4, 5, 6};
	//	list<int> lis {1, 2, 3, 4, 5, 6};
	//cout<<	std::equal(vec.begin(), vec.end(), lis.begin());
	//unique_copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(vec));
	//copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, "\n"));
	//copy_if(vec.begin(), vec.end(), std::back_inserter(lis), [](int x) { return (x % 2) != 0; });
	//for_each(vec.begin(), vec.end(), [](int a) { cout << a; });





		//numeric_limits<int> av;
		//cout << (std::is_pointer<int>());

		/*typedef ratio<1, 2> half;
		typedef ratio<1, 3> half1;
		using sum = std::ratio_add<half, half1>;
		cout << sum::num << "/" << sum::den;*/

		//print(3, 4.4, "hello");

//}





