#include"UnionFindSet.h"


UnionFindSet::UnionFindSet(int size) {
	_size = size;
	_parent = new int[size];
	for (int i = 0; i < _size; i++)_parent[i] = -1;
}

bool UnionFindSet::Union(int x, int y) {
	int x_parent = Find(x);
	int y_parent = Find(y);
	if (x_parent == y_parent)return false;
	else {
		if (_parent[x_parent] == _parent[y_parent]) {
			_parent[y_parent] = x_parent;
			_parent[x_parent] -= 1;
		}//x更高，把y挂在x下
		else if (_parent[x_parent] < _parent[y_parent]) {
			_parent[y_parent] = x_parent;
		}
		else _parent[x_parent] = y_parent;	
		return true;
	}
}

int UnionFindSet::Find(int x) {
	int i = x;
	while (_parent[i] >=0)i = _parent[i];
	return i;
}

UnionFindSet::~UnionFindSet() {
	delete[]_parent;
}