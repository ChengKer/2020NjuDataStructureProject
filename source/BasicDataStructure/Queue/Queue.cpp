#include"Queue.h"

int Queue::front() {
	return _first->_city;
}

void Queue::pop() {
	Q_Node* temp = _first;
	_first = _first->next;
	if (_first == NULL)_last = NULL;
	delete temp;
}

void Queue::push(int x) {
	Q_Node* temp = new Q_Node;
	temp->_city = x;
	temp->next = NULL;
	if (_first == NULL && _last == NULL) {
		_first = temp;
		_last = temp;
	}
	else
	{
		_last->next = temp;
		_last = _last->next;
	}
}

bool Queue::empty() {
	return _first == NULL && _last == NULL;
}