//类的引入
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

//复习C语言结构体 C++向前兼容C语言

//typedef int STDataType;
//struct Stack {
//	STDataType* val;//指针
//	int top;//栈顶的下一个位置
//	int capacity;//栈的容量
//};
//
//void StackInit(struct Stack* pst) {
//	assert(pst);
//	pst->val = NULL;
//	pst->top = 0;
//	pst->capacity = 0;
//}
//
//void StackPush(struct Stack* pst, int val) {
//	assert(pst);
//	if (pst->top == pst->capacity) {
//		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(pst->val, sizeof(STDataType) * newcapacity);
//		if (tmp == nullptr) {
//			perror("realloc file");
//			exit(-1);
//		}
//		pst->val = tmp;
//		pst->capacity = newcapacity;
//	}
//	pst->val[pst->top] = val;
//	++(pst->top);
//}
//
//void StackDestroy(struct Stack* pst) {
//	assert(pst);
//	free(pst->val);
//	pst->top = pst->capacity = 0;
//}
//
//void test1() {
//	struct Stack st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	
//	StackDestroy(&st);
//}
//
//class A {
//public:
//	int a;
//private :
//	int b;
//};
//
//int main() {
//	test1();
//
//	return 0;
//}

//typedef int STDataType;
//struct Stack {
//	STDataType* val;//指针
//	int top;//栈顶的下一个位置
//	int capacity;//栈的容量
//
//	void StackInit(struct Stack* pst);
//	void StackPush(struct Stack* pst, int val);
//	void StackPop(struct Stack* pst);
//	int StackTop(struct Stack* pst);
//	bool StackEmpty(struct Stack* pst);
//	void StackDestroy(struct Stack* pst);
//};

//typedef int STDataType;
//struct Stack {
//	STDataType* val;//指针
//	int top;//栈顶的下一个位置
//	int capacity;//栈的容量
//
//	void StackInit();
//	void StackPush(int val);
//	void StackPop();
//	int StackTop();
//	bool StackEmpty();
//	void StackDestroy();
//};


//struct Stack {
//private:
//	STDataType* val;//指针
//	int top;//栈顶的下一个位置
//	int capacity;//栈的容量
//
//public:
//	void StackInit();
//	void StackPush(int val);
//	void StackPop();
//	int StackTop();
//	bool StackEmpty();
//	void StackDestroy();
//};

//升级的struct，与 类 class的功能相同
//C语言用法 - 结构体
//typedef int LTDataType;
//struct ListNode {
//	LTDataType val;
//	struct ListNode* next;
//};
//
//typedef int LTDataType;
//struct ListNode {
//	LTDataType val;
//	//C++用法 - 类；C语言不能这么用（C的语法不支持）
//	ListNode* next;
//};
//
//int main() {
//
//	return 0;
//}


//class 类的引入
//class Stack {
//public:
//	void Init(size_t capacity = 4) {
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (_array == nullptr) {
//			perror("Init file");
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	void Destroy() {
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//
//	void Push(int val) {
//		if (_top == _capacity) {
//			size_t newcapacity = _capacity * 2;
//			int* tmp = (int*)realloc(_array, sizeof(int) * newcapacity);
//			if (tmp == nullptr) {
//				perror("Push flie");
//				exit(-1);
//			}
//			_array = tmp;
//			_capacity = newcapacity;
//		}
//		_array[_top] = val;
//		++_top;
//	}
//	void Pop() {
//		--_top;
//	}
//	int Top() {
//		return _array[_top - 1];
//	}
//	bool Empty() {
//		return _top == 0;
//	}
//
//private:
//	int* _array;//指向数组
//	size_t _top;//栈顶的下一个位置
//	size_t _capacity;//栈容量
//};
//
//void test1() {
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//	while (!st.Empty()) {
//		cout << st.Top() << " ";
//		st.Pop();
//	}
//	st.Destroy();
//}

//int main() {
//	test1();
//
//	return 0;
//}

//class A {
//public:
//	void Print1() {
//		_a = _b = 1;
//		cout << _a << " " << _b << endl;
//	}
//private:
//	int _a;
//	int _b;
//public:
//	void Print2() {
//		_a = _b = 2;
//		cout << _a << " " << _b << endl;
//	}
//};
//int main() {
//	A A1;
//	A1.Print1();
//	A1.Print2();
//	return 0;
//}