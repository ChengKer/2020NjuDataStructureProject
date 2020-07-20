#include"Graph.h"
#include"../File/File.h"
#include"../BasicDataStructure/UnionFindSet/UnionFindSet.h"
#include"../BasicDataStructure/Queue/Queue.h"
#include"../BasicDataStructure/MergeSort/MergeSort.h"
#include <iomanip>
const int PROVIENCE_STR_LEN = 16;


Graph::Graph(std::string provience_addr, std::string distance_addr):_name_to_index(PROVIENCE_NUM),_edges(EDGE_NUM){
	_color_num = 0;
	for (int i = 0; i < PROVIENCE_NUM; i++)
		for (int j = 0; j < PROVIENCE_NUM; j++) {
			_graph[i][j] = -1;
		}
	for (int i = 0; i < PROVIENCE_NUM; i++)_color[i] = UNKNOWN;
	load_province(provience_addr);
	load_distance(distance_addr);
}

bool Graph::load_province(std::string provience_addr) { 
	File province_file(provience_addr);
	for (int i = 0; i < PROVIENCE_NUM; i++) {
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
	while(!in.eof()) {
		std::string city_x;
		std::string city_y;
		int distance;
		in >>city_x>>city_y>>distance;
		int x = _name_to_index.find_index(city_x);
		int y = _name_to_index.find_index(city_y);
		_graph[x][y] = distance;
		_graph[y][x] = distance;
		_edges.push_back(Edge(x,y,distance));
	}
	return true;
}

std::string Graph::select_info(std::string name) {
	int i = _name_to_index.find_index(name);
	if (i == -1)return "Error! Your input is illegal";
	else return _province_list[i].get_info();
}

int Graph::get_distance(std::string city_x, std::string city_y, Vector<std::string>* route) {
	//Using Behrman-Ford Algorithm to solve this problem
	int dis_matrix[PROVIENCE_NUM][PROVIENCE_NUM];
	for (int i = 0; i < PROVIENCE_NUM; i++) {
		for (int j = 0; j < PROVIENCE_NUM; j++) {
			dis_matrix[i][j] = MAX_DISTANCE;
		}
	}
	int x = _name_to_index.find_index(city_x);
	int y = _name_to_index.find_index(city_y);
	if (x == -1 || y == -1)return -1;
	dis_matrix[x][x] = 0;
	int last_city[PROVIENCE_NUM];
	for (int i = 0; i < PROVIENCE_NUM - 1; i++) {
		for (int j = 0; j < _edges.size(); j++) {
			int e_x = _edges[j].get_x();
			int e_y = _edges[j].get_y();
			int dis = _edges[j].get_distance();
			if (dis_matrix[x][e_y] > dis_matrix[x][e_x] +dis ) {
				dis_matrix[x][e_y] = dis_matrix[x][e_x] + dis;
				last_city[e_y] = e_x;
			}
		}
	}
	if (route != NULL && dis_matrix[x][y]!=MAX_DISTANCE && x!=y){
		route->push_back(_province_list[y].get_name());
		int last = last_city[y];
		while (last != x) {
			route->push_back(_province_list[last].get_name());
			last = last_city[last];
		}
		route->push_back(_province_list[x].get_name());
	}
	return dis_matrix[x][y];
}

std::string Graph::get_name_by_index(int i) {
	return _province_list[i].get_name();
}

void Graph::print_province() {
	for (int i = 0; i < PROVIENCE_NUM; i++)
		std::cout << _province_list[i].get_name() << std::endl;
}

int Graph::plan(Vector<Edge> *routes) {
	MergeSort(_edges, 0, _edges.size()-1);
	int cost = 0;
	UnionFindSet ufs(PROVIENCE_NUM);
	for (int i = 0; i < _edges.size(); i++) {
		if (ufs.Find(_edges[i].get_x()) != ufs.Find(_edges[i].get_y())) {
			ufs.Union(_edges[i].get_x(), _edges[i].get_y());
			cost += _edges[i].get_distance();
			if (routes != NULL)routes->push_back(_edges[i]);
		}
	}
	return cost;
}


int Graph::paint_province() {
		for (int i = 0; i < PROVIENCE_NUM; i++) {
			if (_color[i] == UNKNOWN) { //bfs
				Queue q;
				q.push(_province_list[i].get_index());
				while (!q.empty()) {
					int node = q.front();
					q.pop();
					bool color[5] = { 0,0,0,0,0 };
					for (int j = 0; j < PROVIENCE_NUM; j++) {
						if (_graph[node][j] != -1) {
							if (_color[j] != UNKNOWN)color[_color[j]] = true;
							else q.push(j);
						}
					}
					for (int k = 1; k <=4; k++) {
						if (!color[k]) {
							_color[node] = Color(k);
							if (k > _color_num)_color_num = k;
							break;
						}
					}
				}
			}
		}
	return _color_num;
}

std::string Graph::color_to_str(Color c) {
	switch (c) {
	case RED:
		 return "red";
	case BLUE:
		return "blue";
	case GREEN:
		return "green";
	case YELLOW:
		return "yellow";
	default:
		return "unknown";
	}
}

void Graph::print_color() {
	for (int i = 0; i < PROVIENCE_NUM; i++) {
		std::string color=color_to_str(_color[_province_list[i].get_index()]);
		std::cout << std::setw(PROVIENCE_STR_LEN) << _province_list[i].get_name() << " color:" << color << std::endl;
	}
}

