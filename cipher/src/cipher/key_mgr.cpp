#include "cipher/key_mgr.h"

#include <iostream>
#include <string>
#include <vector>

key_mgr::key_mgr()
{
}

key_mgr::~key_mgr()
{
}

void key_mgr::add_key(key const &k)
{
	_keys.push_back(k);
}

void key_mgr::print()
{
	for(int i = 0; i < _keys.size(); i++)
	{
		std::cout << "id:          " << std::to_string(i) << std::endl;
		std::cout << "name:        " << _keys[i].get_name() << std::endl;
		std::cout << "description: " << _keys[i].get_description() << std::endl;
		std::cout << "---" << std::endl;
	}

	// int i_id_max_length = 0;
	// int i_name_max_length = 0;
	// int i_description_max_length = 0;

	// std::string s_id = "id";
	// std::string s_name = "name";
	// std::string s_description = "description";

	// i_id_max_length = s_id.size();
	// i_name_max_length = s_name.size();
	// i_description_max_length = s_description.size();

	// struct process
	// {
	//     int id;
	//     std::string name;
	//     std::string description;
	// };

	// std::vector<process> processes;

	// for (int i = 0; i < _keys.size(); i++)
	// {
	//     process p;
	//     p.id = i;
	//     p.name = _keys[i].get_name();
	//     p.description = _keys[i].get_description();
	//     processes.push_back(p);

	//     int n = 1;
	//     while ((p.id /= 10) > 0)
	//     {
	//         n++;
	//     }

	//     if (n > i_id_max_length)
	//     {
	//         i_id_max_length = n;
	//     }

	//     if (p.name.size() > i_name_max_length)
	//     {
	//         i_name_max_length = p.name.size();
	//     }

	//     if (p.description.size() > i_description_max_length)
	//     {
	//         i_description_max_length = p.description.size();
	//     }
	// }

	// std::string out = "";

	// for (int i = 0; i < processes.size(); i++)
	// {
	//     out += " ";

	//     out += "";
	// }
}