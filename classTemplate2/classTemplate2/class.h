#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class A {
public:
	//����
	A(T a = 1);
	//��������
	A(A& a);
	//��ֵ���������
	A& operator=(const A& a);
	//����
	~A();
	void Print();
private:
	T _a;
};

template<typename T>
A<T>::A(T a)
	:_a(a) {}

template<typename T>
A<T>::A(A& a) {
	_a = a._a;
}
template<typename T>
A<T>& A<T>::operator=(const A<T>& a) {
	_a = a._a;
	return *this;
}

template<typename T>
A<T>::~A() {
	_a = 0;
}

template<typename T>
void A<T>::Print() {
	cout << _a << endl;
}