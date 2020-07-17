#include<string>

class BinarySearchTree{
	struct tree_node {
		std::string name;
		int index;
		tree_node* left_child;
		tree_node* right_child;
	};
	tree_node* _root;
	int _size;
	tree_node* init_new_node(std::string name, int index);
	void delete_tree(tree_node* root);
public:
	explicit BinarySearchTree() :_root(NULL),_size(0) {};

	bool insert(std::string name, int index);
	
	int get_size();
	
	int find(std::string name);
	
	~BinarySearchTree();
};

