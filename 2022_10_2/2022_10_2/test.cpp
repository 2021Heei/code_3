#include "statement.h"
//�������
//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//using namespace std;

//��ϰC���Խṹ�� C++��ǰ����C����
//typedef int STDataType;
//struct Stack {
//	STDataType* val;
//	int top;
//	int capacity;
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
//void StackPop(struct Stack* pst) {
//	assert(pst);
//	--(pst->top);
//}
//
//int StackTop(struct Stack* pst) {
//	assert(pst);
//	return pst->val[pst->top - 1];
//}
//bool StackEmpty(struct Stack* pst) {
//	assert(pst);
//	return pst->top == 0;
//}
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
//	StackPush(&st, 3);
//	while (!StackEmpty(&st)) {
//		printf("%d ", StackTop(&st));
//		StackPop(&st);
//	}
//	StackDestroy(&st);
//}
//int main() {
//	test1();
//	return 0;
//}


////������struct���� �� class�Ĺ�����ͬ
//typedef int STDataType;
//struct Stack {
//	STDataType* _val;
//	int _top;
//	int _capacity;
//
//	void Init(int capacity) {
//		_val = (STDataType*)malloc(sizeof(STDataType) * capacity);
//		if (_val == nullptr) {
//			perror("Init file");
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	void Push(int val) {
//		if (_top == _capacity) {
//			int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_val, sizeof(STDataType) * newcapacity);
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
//	void Pop() {
//		--(_top);
//	}
//
//	int Top() {
//		return _val[_top - 1];
//	}
//	bool Empty() {
//		return _top == 0;
//	}
//	void Destroy() {
//		free(_val);
//		_val = nullptr;
//		_top = _capacity = 0;
//	}
//};
//
//
//void test1() {
//	//C++����÷�
//	Stack st;
//	st.Init(10);
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	while (!st.Empty()) {
//		cout << st.Top() << " ";
//		st.Pop();
//	}
//	st.Destroy();
//}
//int main() {
//	test1();
//	return 0;
//}

//������struct���� �� class�Ĺ�����ͬ
//C�����÷� - �ṹ��
//typedef int LTDataType;
//struct ListNode {
//	LTDataType val;
//	struct ListNode* next;
//};
//
//typedef int LTDataType;
//struct ListNode {
//	LTDataType val;
//	//C++�÷� - �ࣻC���Բ�����ô�ã�C���﷨��֧�֣�
//	ListNode* next;
//};
//
//int main() {
//
//	return 0;
//}

//class �������
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
//	int* _array;
//	size_t _top;
//	size_t _capacity;
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
//
//
//
//int main() {
//	//test1();
//
//	return 0;
//}

//class Ĭ��Ϊ˽��,���ⲻ�ܷ���˽�г�Ա
//�����޶�����
//public
//private
//protect
//���ݳ�Ա�����ڣ�ʹ��ʱ�ģ���Ҳ�������£���Ϊ����һ�����壬�������¡�����Ҫ��C����������������ʹ��
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
//	int* _array;
//	size_t _top;
//	size_t _capacity;
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
//
//int main() {
//	test1();
//
//	return 0;
//}


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
//	int* _array;
//	size_t _top;
//	size_t _capacity;
//};
//
//struct ListNode {
//	int val;
//	struct ListNode* next;
//};
//
//void test1() {
//	//ListNode::val;//error
//	//Stack::Init();//error
//	ListNode node;
//	node.val;//true
//	Stack st;
//	st.//
//
//}
//	
//int main() {
//	test1();
//	
//	return 0;
//}


//ΪʲôҪ�����Ͷ�����룿
//���������Ķ���Ĵ���
//����Դ��й¶
//

//������������ - ����ʱ���Ա������Ҫ��������
//��Ա�����������ڲ��ֲ�����->�ٵ����з���->�ٵ�ȫ�ַ��ʡ�


//��˽�г�Ա����ϰ��
//class Date {
//public:
//	void Init(int year, int month, int day) {
//		//������̫��������˽�г�Ա�ͺ����β�
//		//����취�ǣ�
//		//1.Ĭ����߾�����˽�г�Ա�������β����ұ�
//		//2.�����˽�г�Ա�����������Σ��磺year --> Date::year
//		//3.����˽�г�Աʱ�ֶ�����һ�£��磺year --> _year/year_/m_year/mYear��
//		year = year;
//		month = month;
//		day = day;
//	}
//
//private:
//	int year;
//	int month;
//	int day;
//};
//
//int main() {
//	Date d;
//	d.Init(2022, 10, 3);
//
//	return 0;
//}



////���Ա����ֱ�Ӷ����������棬����������Ĭ�ϵ����������������������ű�
//// �����Ͷ������֮�󣬾�����ͨ�����������ű�
//int main() {
//	Stack st;
//	st.Init();
//	st.Destroy();//����������룬������������error�����Ӵ���
//	Queue q;
//	q.Init();
//	q.Destroy();
//
//	return 0;
//}

//class A {
//public:
//	void func() {
//		;
//	}
//	int a;
//	int b;
//};
//
//int main() {
//	//A::a = 10;//�໹û��ʵ�壨ʵ��������ֻ��һ������
//	//A::func();//thisָ��
//
//	A A1;
//	A1.a = 10;
//	cout << A1.a << endl;
//	A* pA1 = &A1;
//	pA1->a = 20;
//	cout << A1.a << endl;
//
//	return 0;
//}


//class A {
//public:
//	void func() {
//		cout << a<< endl;
//	}
//	int a;
//};
////�ഢ�淽ʽ��ѡ��
////���С�ļ��㣺��C���Խṹ����ͬ
//int main() {
//	//A::a = 10;//�໹û��ʵ�壨ʵ��������ֻ��һ������
//	//A::func();//thisָ��
//
//	A A1;
//	A1.a = 10;
//	A1.func();
//	A* pA1 = &A1;
//	pA1->a = 20;
//	A1.func();
//
//	return 0;
//}

//class A {
//public:
//	void func() {
//		cout << a << endl;
//	}
//	char ch;
//	int a;
//};
//
//class A2 {
//	void func2() {
//		;
//	}
//};
////����
//class A3{
//};
////�ഢ�淽ʽ��ѡ��
////���С�ļ��㣺��C���Խṹ����ͬ
//int main() {
//
//	A a1;
//	cout << sizeof(a1) << endl;
//	A2 a2;
//	//��������Ч���ݣ�ռλ����ʶ�������
//	cout << sizeof(a2) << endl;
//	A3 a3;
//	//��������Ч���ݣ�ռλ����ʶ�������
//	cout << sizeof(a3) << endl;
//
//
//	return 0;
//}

//class A {
//public:
//	void Init(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//void Print(A* const this)//����ָ��this
//	//void Print(const A* this)//����ָ��ָ������
//	void Print() {
//		cout << "this: " << this << endl;
//		//cout << _year << "/" << _month << "/" << _day << endl;
//		cout << this->_year << "/" << this->_month << "/" << this->_day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main() {
//
//	A a, b;
//	a.Init(2122, 10, 3);
//	a.Print();
//	cout << "&a: " << & a << endl;
//	b.Init(3122, 10, 3);
//	b.Print();
//	cout << "&b: " << &b << endl;
//	return 0;
//}

//ΪʲôҪ��Ƴ�thisָ�룿
//�⻹��Ҫ��C����˵��
//C����ʵ�����ݽṹʱ������ʵ��һ��ջ��������Ҫ����һ��ջ�Ľṹ������
//typedef struct Stack{ ...}Stack;
//�ڶ���ջ�Ĺ��ܺ���ʱ������Ҫ����ջʵ���ĵ�ַ
//void StackInit(Stack* pst) { };
//void StackPush(Stack* pst) { };
//��Ȼÿ��ջ�ĺ�������Ҫ����ջʵ���ĵ�ַ��C++����ʵ�����Ա����ʱ�ͰѴ������ݽṹʵ���ĵ�ַ
//Ĭ�ϴ����ˣ��ͱ����������ˣ��Ըõ�ַ��ʹ��Ҳ���������ˡ�Ҳ����˵����˱���������ʹ������ɣ��������������������ˣ�ʹ����Ҫ�����±����ˡ�












