#pragma once
#include <stdio.h>

template <class T>
class Vector {
	//存储了元素的个数
	int _size;
	//最多能存储的元素的个数
	int _capacity;
	T *v;
public:
	explicit Vector(int init_size);
	bool push_back(T element);
	int size();
	T& operator[](unsigned int i);
	~Vector();
};

template <class T>
Vector<T>::Vector(int init_size) :_capacity(init_size), _size(0) {
	v = new T[_capacity];
}

template <class T>
bool Vector<T>::push_back(T element) {
	v[_size] = element;
	_size += 1;
	if (_size == _capacity) {
		_capacity *= 2;
		T* temp = new T[_capacity];
		if (temp == NULL)return false;
		for (int i = 0; i < _size; i++)temp[i] = v[i];
		delete[]v;
		v = temp;
	}
	return true;
}

template <class T>
int Vector<T>::size() {
	return _size;
}

template <class T>
T& Vector<T>::operator[](unsigned int i) {
	return v[i];
}

template <class T>
Vector<T>::~Vector() {
	delete[]v;
}