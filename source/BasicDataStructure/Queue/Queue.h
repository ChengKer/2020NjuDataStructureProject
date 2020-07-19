#pragma once
#include <stdio.h>

class Queue {
	struct Q_Node {
		int _city;
		Q_Node* next;
	};

	Q_Node* _first;
	Q_Node* _last;
public:
	Queue():_first(NULL),_last(NULL) {}

	int front();

	void pop();

	void push(int x);

	bool empty();
};