#include"File.h"

bool File::get_line(char* line,int len) {
	if (_in.is_open() && !_in.eof()) {
		_in.getline(line,len);
		return true;
	}
	return false;
}

std::ifstream& File::get_flow() {
	return _in;
}

File::~File() {
	if (_in.is_open()) {
		_in.close();
	}
}