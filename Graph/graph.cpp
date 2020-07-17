#include"graph.h"
#include"../File/File.h"
#include<iostream>
#include<fstream>

Graph::Graph(std::string provience_addr, std::string distance_addr):_name_to_index(PROVINCE_NUM){
	for (int i = 0; i < PROVINCE_NUM; i++)
		for (int j = 0; j < PROVINCE_NUM; j++) {
			_graph[i][j] = -1;
		}
	load_province(provience_addr);
	load_distance(distance_addr);
}

bool Graph::load_province(std::string provience_addr) {
	File province_file(provience_addr);
	for (int i = 0; i < PROVINCE_NUM; i++) {
		char temp[1001];
		if (!province_file.get_line(temp, 1000))return false;
		std::string line = std::string(temp);
		std::string name= line.substr(0,line.find(' '));
		std::string info= line.substr(line.find(' ')+1);
		_province_list[i].set_index(i);
		_province_list[i].set_name(name);
		_province_list[i].set_info(info);
		_name_to_index.insert(name,i);
	}
	return true;
}

bool Graph::load_distance(std::string distance_addr) {
	File distance_file(distance_addr);
	std::ifstream& in = distance_file.get_flow();
	if (!in.is_open())return false;
	for (int i = 0; i < PROVINCE_NUM; i++) {
		std::string city_x;
		std::string city_y;
		int distance;
		in >>city_x>>city_y>>distance;
		int x = _name_to_index.find_index(city_x);
		int y = _name_to_index.find_index(city_y);
		_graph[x][y] = distance;
		_graph[y][x] = distance;
	}
	return true;
}

std::string Graph::select_info(std::string name) {
	int i = _name_to_index.find_index(name);
	if (i == -1)return "Error! Your input is illegal";
	else return _province_list[i].get_info();
}

void Graph::test() {
	for (int i = 0; i < PROVINCE_NUM; i++) {
		std::cout << _province_list[i].get_name() << std::endl;
	}
}