#include<string>
#include"../Node/Node.h"
#include"../BasicDataStructure/HashTable/HashTable.h"
#include"../Edge/Edge.h"
#include"../BasicDataStructure/Vector/Vector.h"

const int PROVIENCE_NUM=34;
const int EDGE_NUM = 50;
const int MAX_DISTANCE = 999999;
enum Color { UNKNOWN = 0 ,RED = 1, BLUE = 2, GREEN = 3, YELLOW = 4 };

class Graph {
	int _color_num;
	Node _province_list[PROVIENCE_NUM];
	HashTable _name_to_index;
	int _graph[PROVIENCE_NUM][PROVIENCE_NUM];
	Vector<Edge> _edges;
	Color _color[PROVIENCE_NUM];
	bool load_province(std::string provience_addr);
	bool load_distance(std::string distance_addr);
	std::string color_to_str(Color c);
public:
	Graph(std::string provience_addr, std::string distance_addr);
	std::string select_info(std::string name);
	int get_distance(std::string city_x,std::string city_y,Vector<std::string> *route=NULL);
	int plan(Vector<Edge>* routes=NULL);
	std::string get_name_by_index(int i);
	int paint_province();
	void print_color();
	void print_province();
};

