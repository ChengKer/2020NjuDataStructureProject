#include<string>
#include"../Node/Node.h"
#include"../BasicDataStructure/HashTable/HashTable.h"
#include"../Edge/Edge.h"
#include"../BasicDataStructure/Vector/Vector.h"
#include"../BasicDataStructure/MergeSort/MergeSort.h"

const int PROVINCE_NUM=34;
const int EDGE_NUM = 50;
const int MAX_DISTANCE = 999999;

class Graph {
	Node _province_list[PROVINCE_NUM];
	HashTable _name_to_index;
	int _graph[PROVINCE_NUM][PROVINCE_NUM];
	Vector<Edge> _edges;
public:
	Graph(std::string provience_addr, std::string distance_addr);
	bool load_province(std::string provience_addr);
	bool load_distance(std::string distance_addr);
	std::string select_info(std::string name);
	int get_distance(std::string city_x,std::string city_y,Vector<std::string> *route=NULL);
	int plan(Vector<Edge>* routes=NULL);
	std::string get_name_by_index(int i);
};

