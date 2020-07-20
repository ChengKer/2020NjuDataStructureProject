#include"../Graph/Graph.h"


class Controller {
	Graph _g;
	void show_main_page();
	void print_provience();
	void clear();
	void paint_graph();
	void plan();
	void distance();
	void select_info();
	bool is_continue();
public:
	explicit Controller(std::string provience_addr, std::string distance_addr):
		_g(provience_addr,distance_addr) {};
	void Control();
	void test();
};


