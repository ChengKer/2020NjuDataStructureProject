#include<string>
#include"../Node/Node.h"
#include"../BasicDataStructure/HashTable/HashTable.h"
#include<string>

const int PROVINCE_NUM = 34;

class Graph {
	Node _province_list[PROVINCE_NUM];
	HashTable _name_to_index;
	int _graph[PROVINCE_NUM][PROVINCE_NUM];
public:
	Graph(std::string provience_addr, std::string distance_addr);
	bool load_province(std::string provience_addr);
	bool load_distance(std::string distance_addr);
	std::string select_info(std::string name);
	void test();
};

