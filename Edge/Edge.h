#pragma once

class Edge {
	int _city_x;
	int _city_y;
	int _distance;
public:
	explicit Edge(int x=-1, int y=-1, int d=-1) :_city_x(x), _city_y(y), _distance(d) {};

	//getters
	int get_x();
	int get_y();
	int get_distance();

	//setters
	void set_x(int x);
	void set_y(int y);
	void set_distance(int distance);
};