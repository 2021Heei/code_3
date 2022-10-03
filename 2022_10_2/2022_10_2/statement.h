#pragma once
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

class Stack {
public:
	//缺省值能声明或定义一处给出
	void Init(size_t capacity = 4);
	inline void Destroy();
	bool Empty();
	
private:
	int* _array;
	size_t _top;
	size_t _capacity;
};

class Queue {
public:
	void Init();
	void Destroy();
	bool Empty();

private:
	typedef struct ListNode {
		int val;
		struct ListNode* next;
	}LTNode;
	LTNode* _head;
	LTNode* _tail;
	size_t _size;
};