#include"HashTable.h"
#include<cmath>

int HashTable::calc_key(int hash) { 
	return abs(hash) % _size; 
};

int HashTable::calc_hash(std::string name) {
	int hash = 0;
	for (char i : name)hash += i;
	return hash;
}

bool HashTable::insert(std::string name, int index) {
	int hash = calc_hash(name);
	int key = calc_key(hash);
	if (_table[key].insert(name, index)) {
		_totoal_num++;
		return true;
	}return false;
}

int HashTable::find_index(std::string name) {
	int hash = calc_hash(name);
	int key = calc_key(hash);
	return _table[key].find(name);
}

int HashTable::totoal_num() {
	return _totoal_num;
}

HashTable::~HashTable() {
	delete[]_table;
	_totoal_num = 0;
}