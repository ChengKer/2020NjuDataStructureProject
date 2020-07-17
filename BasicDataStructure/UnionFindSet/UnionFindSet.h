class UnionFindSet {
	int _size;
	int* _parent;
public:
	UnionFindSet(int size);
	bool Union(int x,int y);
	int Find(int x);
	~UnionFindSet();
};