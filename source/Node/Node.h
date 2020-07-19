#include<string>
#pragma once


class Node {
	int _index;
	std::string _name;
	std::string _info;
	
public:
	explicit Node(int index = -1, std::string name = "", std::string info = "") :_index(index), _name(name), _info(info) {};
	bool is_uninit();

	//getter
	int get_index();
	std::string get_name();
	std::string get_info();

	//setter
	void set_index(int index);
	void set_name(std::string name);
	void set_info(std::string info);
};