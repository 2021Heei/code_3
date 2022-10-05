//�������
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

//��ϰC���Խṹ�� C++��ǰ����C����

//typedef int STDataType;
//struct Stack {
//	STDataType* val;//ָ��
//	int top;//ջ������һ��λ��
//	int capacity;//ջ������
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
//	STDataType* val;//ָ��
//	int top;//ջ������һ��λ��
//	int capacity;//ջ������
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
//	STDataType* val;//ָ��
//	int top;//ջ������һ��λ��
//	int capacity;//ջ������
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
//	STDataType* val;//ָ��
//	int top;//ջ������һ��λ��
//	int capacity;//ջ������
//
//public:
//	void StackInit();
//	void StackPush(int val);
//	void StackPop();
//	int StackTop();
//	bool StackEmpty();
//	void StackDestroy();
//};

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
//	int* _array;//ָ������
//	size_t _top;//ջ������һ��λ��
//	size_t _capacity;//ջ����
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

//class Date {
//public:
//	void Init(int year, int month, int day) {
//		Date::year = year;
//		Date::month = month;
//		Date::day = day;
//	}
//	void Print() {
//		cout << year << "/" << month << "/" << day << endl;
//	}
//private:
//	int year;
//	int month;
//	int day;
//};
//int main() {
//	Date d;
//	d.Init(2122, 10, 10);
//	d.Print();
//}

//class Date {
//public:
//	void Init(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	//_day �� day_ �� m_day �� mDay��
//};
//int main() {
//	Date d;
//	d.Init(2122, 10, 10);
//	d.Print();
//}

//namespace B {
//	void function() {
//		cout << "namespace B\n" << endl;
//	}
//	int c = 20;
//}
//int c = 10;
//int main() {
//	cout << B::c << endl;
//	B::function();
//	return 0;
//}
//class A {
//public:
//	void func() {
//		cout << "hello world!\n" << endl;
//	}
//	int _a;
//private:
//	int _b;
//};
//
//int main() {
//	A::_a = 10;
//	A::func();
//	
//	return 0;
//}

//class A {
//public:
//	//�ڹ�������������ռ��Ĵ���ռ䣬
//	//����ʱ��������ֱ�ӵ���������������Ӧ�ĺ���
//	void func() {
//		cout << "hello world!\n" << endl;
//	}
//private:
//	char _a;//0
//			//1 -> 3
//	int _b;//4 -> 7  ��8byte
//};
//
//int main() {
//	sizeof(A);
//	A A1;
//	sizeof(A1);
//	return 0;
//}


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
//	void func2() {
//		;
//	}
//};
////����
//class B{
//};
////�ഢ�淽ʽ��ѡ��
////���С�ļ��㣺��C���Խṹ����ͬ
//int main() {
//
//	A A1;
//	//��������Ч���ݣ�ռλ����ʶ�������
//	cout << sizeof(A1) << endl;
//	B B1;
//	//��������Ч���ݣ�ռλ����ʶ�������
//	cout << sizeof(B1) << endl;
//	return 0;
//}

//class A {
//public:
//	void Init(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//void Print(A* const this)//����ָ��this        ����ָ��
//	  void Print(const A* this)//����ָ��ָ������    ָ�볣��
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

//class A {
//public:
//	void Init(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
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
//	A a;
//	a.Init(2122, 10, 3);
//	a.Print();
//
//	A b;
//	b.Init(3122, 10, 3);
//	b.Print();
//	return 0;
//}

//class A {
//public:
//	void Init(int year, int month, int day) {
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print() {
//		cout << "this: " << this << endl;
//		//cout << _year << "/" << _month << "/" << _day << endl;
//		cout << this->_year << "/" 
//			<< this->_month << "/" << this->_day << endl;
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
//	A a;
//	a.Init(2122, 10, 3);
//	a.Print();
//	cout << "&a: " << &a << endl;
//
//	A b;
//	b.Init(3122, 10, 3);
//	b.Print();
//	cout << "&b: " << &b << endl;
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////////////

//class Date {
//public:
//	/*void Init(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	//���캯��
//	//���󴴽�ʱ���Զ����ù��캯���Զ�����г�ʼ��  
//	//��������������ͬ
//	//û�з���ֵ�Ҳ�д��������λ��ɶҲ��д
//	Date(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main() {
//
//	Date a(2020, 1, 2);
//	a.Print();
//
//	Date b(2010, 10, 10);
//	b.Print();
//	return 0;
//}

//class Date {
//public:
//	Date(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main() {
//
//	Date a(2022, 10, 10);
//	a.Print();
//	return 0;
//}


class Date {
public:
	Date(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
	}
	Date(int year, int month) {
		_year = year;
		_month = month;
		_day = 1;
	}
	Date(int year) {
		_year = year;
		_month = 1;
		_day = 1;
	}
	Date() {
		_year = 1970;
		_month = 1;
		_day = 1;
	}
	void Print() {
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main() {

	Date a1(2020, 1, 2);
	Date a2;
	Date a3();//ʹ���޲ι��캯����ʼ��ʱ���������ţ�������� ������������
	//Date func();// warning C4930: ��Date a3(void)��: δ����ԭ�ͺ���(�Ƿ��������ñ��������?)
	a1.Print();
	a2.Print();
	//a3.Print();
	return 0;
}
