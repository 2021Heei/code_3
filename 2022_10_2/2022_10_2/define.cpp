#include "statement.h"

void Init(size_t capacity) {
	_array = (int*)malloc(sizeof(int) * capacity);
	if (_array == nullptr) {
		perror("Init file");
		exit(-1);
	}
	_top = 0;
	_capacity = capacity;
}

void Stack::Destroy() {
	free(_array);
	_array = nullptr;
	_top = _capacity = 0;
}

bool Stack::Empty() {
	return _top == 0;
}


void Init() {
	_head = _tail = nullptr;
	_size = 0;
}

void Queue::Destroy() {
	while (!Empty()) {
		LTNode* del = _head;
		_head = _head->next;
		free(del);
	}
	_head = _tail = nullptr;
	_size = 0;
}
bool Queue::Empty() {
	return _head == nullptr;
}
