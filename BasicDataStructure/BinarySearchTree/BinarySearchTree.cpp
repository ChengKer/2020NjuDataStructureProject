#include"BinarySearchTree.h"

BinarySearchTree::tree_node* BinarySearchTree::init_new_node(std::string name, int index) {
	tree_node* temp = new tree_node;
	temp->name = name;
	temp->index = index;
	temp->left_child = NULL;
	temp->right_child = NULL;
	return temp;
}

bool BinarySearchTree::insert(std::string name, int index) {
	if (_root == NULL) {
		_root = init_new_node(name, index);
		_size++;
		return true;
	}
	tree_node* search_p = _root;
	while (true) {
		if (name > search_p->name) {
			if (search_p->right_child != NULL)search_p = search_p->right_child;
			else break;
		}
		else if (name < search_p->name) {
			if (search_p->left_child != NULL)search_p = search_p->left_child;
			else break;
		}
		else break;
	}
	if (search_p->name==name) {
		return false;
	}
	else if(name>search_p->name){
		search_p->right_child = init_new_node(name, index);
		_size++;
		return true;
	}
	else {
		search_p->left_child = init_new_node(name, index);
		_size++;
		return true;
	}
}

int BinarySearchTree::get_size() {
	return _size;
}

void BinarySearchTree::delete_tree(tree_node* root) {
	if (_root == NULL)return;
	else {
		delete_tree(root->left_child);
		delete_tree(root->right_child);
		delete root;
	}
}

int BinarySearchTree::find(std::string name) {
	tree_node* search_p = _root;
	while (search_p != NULL) {
		if (name > search_p->name) {
			search_p = search_p->right_child;
		}
		else if (name < search_p->name) {
			search_p = search_p->left_child;
		}
		else return search_p->index;
	}
	return -1;
}

BinarySearchTree::~BinarySearchTree() {
	delete_tree(_root);
	_size = 0;
	_root = NULL;
}