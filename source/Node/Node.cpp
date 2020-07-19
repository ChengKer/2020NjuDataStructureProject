#include"Node.h"

int Node::get_index() {
	return _index;
}

std::string Node::get_name() {
	return _name;
}

std::string Node::get_info() {
	return _info;
}


void Node::set_index(int index) {
	_index = index;
}

void Node::set_name(std::string name) {
	_name = name;
}

void Node::set_info(std::string info) {
	_info = info;
}


bool Node::is_uninit() {
	return _index == -1;
}

