#include"../BinarySearchTree/BinarySearchTree.h"


class HashTable {
	const int _size;
	int _totoal_num;
	BinarySearchTree* _table;
	int calc_key(int hash);
	int calc_hash(std::string name);
public:
	explicit HashTable(int size) :_size(size), _totoal_num(0) {
		_table = new BinarySearchTree[34];
	};

	bool insert(std::string name, int index);

	int find_index(std::string name);

	int totoal_num();

	~HashTable();
};