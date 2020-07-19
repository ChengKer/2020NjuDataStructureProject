#include"Edge.h"

//getters
int Edge::get_x() {
	return _city_x;
}

int Edge::get_y() {
	return _city_y;
}


int Edge::get_distance() {
	return _distance;
}

//setters
void Edge::set_x(int x) {
	_city_x = x;
}

void Edge::set_y(int y) {
	_city_y = y;
}

void Edge::set_distance(int distance) {
	_distance = distance;
}