#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cassert>
#include <cassert>
using namespace std;

template<typename T>
class Stack {
public:
	Stack(int capacity = 4);
	~Stack();
	void Push(const T& val);
private:
	T* _a;
	int _size;
	int _capacity;
};
//��ģ��ĺ�������д�����⣬����д��������
//ʹ���Եü�࣬�Ӵ����ܹ��Ͽ����Ϥ������д����
//ע����ģ��ĳ�Ա����������дʱ��Ҫָ����ģ���������
template<typename T>
Stack<T>::Stack(int capacity)
	:_size(0)
	, _capacity(capacity) {
	_a = (T*)malloc(sizeof(T) * _capacity);
	assert(_a);
}
template<typename T>
Stack<T>::~Stack() {
	delete[] _a;
	_size = _capacity = 0;
}
template<typename T>
void Stack<T>::Push(const T& val) {
	if (_size == _capacity) {
		_capacity = _capacity * 2;
		T* tmp = (T*)realloc(_a, sizeof(T) * _capacity);
		assert(tmp);
		_a = tmp;
	}
	_a[_size++] = val;
}