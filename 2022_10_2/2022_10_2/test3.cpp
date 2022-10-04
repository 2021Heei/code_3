//#include <stdio.h>
//
//void Print1(struct A* p) {
//	p->a = p->b = 1;
//	printf("%d %d\n", p->a, p->b);
//}
//struct A {
//	int a;
//	int b;
//};
//
//void Print2(struct A* p) {
//	p->a = p->b = 2;
//	printf("%d %d\n", p->a, p->b);
//}
//
//int main() {
//	struct A A1;
//	//Print1(&A1);//error
//	Print2(&A1);//true
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//class Stack {
//public:
//	//ջ��ʼ��
//	void Init(int capacity = 4) {
//		_val = (int*)malloc(sizeof(int) * capacity);
//		if (_val == nullptr) {
//			perror("Init file");
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//	//ѹջ
//	void Push(int val) {
//		if (_top == _capacity) {
//			int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//			int* tmp = (int*)realloc(_val, sizeof(int) * newcapacity);
//			if (tmp == nullptr) {
//				perror("realloc file");
//				exit(-1);
//			}
//			_val = tmp;
//			_capacity = newcapacity;
//		}
//		_val[_top] = val;
//		++(_top);
//	}
//	//��ջ
//	void Pop() {
//		--(_top);
//	}
//	//ȡջ��Ԫ��
//	int Top() {
//		return _val[_top - 1];
//	}
//	//ջ�Ƿ�Ϊ��
//	bool Empty() {
//		return _top == 0;
//	}
//	//����ջ
//	void Destroy() {
//		free(_val);
//		_val = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _val;
//	int _top;
//	int _capacity;
//};