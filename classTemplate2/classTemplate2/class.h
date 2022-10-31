#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class A {
public:
	//构造
	A(T a = 1);
	//拷贝构造
	A(A& a);
	//赋值运算符重载
	A& operator=(const A& a);
	//析构
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