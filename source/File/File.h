#include<iostream>
#include<fstream>

class File {
	std::ifstream _in;
	std::string _addr;
public:
	explicit File(std::string addr) :_addr(addr) { _in.open(_addr.c_str()); };
	bool get_line(char* line, int len);
	std::ifstream& get_flow();
	~File();
};