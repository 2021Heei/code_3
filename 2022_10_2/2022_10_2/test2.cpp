//�������
//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//using namespace std;

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


//class Date {
//public:
//	Date(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(int year, int month) {
//		_year = year;
//		_month = month;
//		_day = 1;
//	}
//	Date(int year) {
//		_year = year;
//		_month = 0;
//		_day = 0;
//	}
//	Date() {
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}
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
//	Date a1(2021, 1, 1);
//	Date a2(2022, 2);
//	Date a3(2023);
//	//Date a4;
//	a1.Print();
//	a2.Print();
//	a3.Print();
//	//a4.Print();
//
//	Date a4();//error
//	a4.Print();
//
//
//
//
//	//a4.Print();
//	////Date a3();//ʹ���޲ι��캯����ʼ��ʱ���������ţ�������� ������������
//	////Date func();// warning C4930: ��Date a3(void)��: δ����ԭ�ͺ���(�Ƿ��������ñ��������?)
//	//a1.Print();
//	//a2.Print();
//	////a3.Print();
//	return 0;
//}


//class Date {
//public:
//	/*Date(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date() {
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}*/
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
//	Date a1;
//	a1.Print();
//	return 0;
//}
//
//
//class Date {
//public:
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main() {
//
//	Date a1;
//	a1.Print();
//	return 0;
//}


//class Date {
//public:
//	Date(int year = 1970, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//ȫȱʡ���޲ι��캯������ͬʱ���ڣ�����������ʱ����������ԣ�
//	//ȫȱʡ���캯���������������޲ι��캯��
//	Date() {
//		_year = 1970;
//		_month = 1;
//		_day = 1;
//	}
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
//	Date a1(2020, 1, 2);
//	Date a2;
//
//	a1.Print();
//	a2.Print();
//	return 0;
//}

//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//using namespace std;
//
//class Stack {
//public:
//	//���캯��
//	Stack(int capacity = 4) {
//		cout << "���캯��: Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	void Push(int val) {
//		if (_top == _capacity) {
//			int newcapacity = _capacity * 2;
//			int* tmp = (int*)realloc(_array, sizeof(int) * newcapacity);
//			assert(tmp);
//			_array = tmp;
//			_capacity = newcapacity;
//		}
//		_array[_top++] = val;
//	}
//private:
//	int* _array;
//	int _top;
//	int _capacity;
//};
//
//class Queue {
//public:
//	void Push(int val) {
//		_stPush.Push(val);
//	}
//private:
//	Stack _stPush;
//	Stack _stPop;
//	int size;
//};
//
//int main() {
//
//	Queue q;
//	return 0;
//}
//
//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//using namespace std;

//class Stack {
//public:
//	//���캯��
//	Stack(int capacity = 4) {
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//private:
//	int* _array;
//	int _top;
//	int _capacity;
//};
//class Queue {
//public:	//...
//private:
//	Stack _stPush;
//	Stack _stPop;
//	int size = 0;//�������ͱ���size����ʱ��һȱʡֵ
//};
//int main() {
//	Queue q;
//	return 0;
//}

//class Date {
//public:
//	//Date(int year = 1, int month = 1, int day = 1) {
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year  = 1;//ȱʡֵ�����ǳ�ʼ������Ϊ�����Ͳ���ռ�ռ�
//	int _month = 1;
//	int _day   = 1;
//};
//
//int main() {
//	Date d;
//	d.Print();
//	return 0;
//}

//class Stack {
//public:
//	//ȱʡֵ����������һ������
//	Stack(int capacity = 4) {
//		cout << "Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (_array == nullptr) {
//			perror("Init file");
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//	void Push(int val) {
//		if (_top == _capacity) {
//			int newcapacity = _capacity * 2;
//			int* tmp = (int*)realloc(_array, sizeof(int) * newcapacity);
//			assert(tmp);
//			_array = tmp;
//			_capacity = newcapacity;
//		}
//		_array[_top++] = val;
//	}
//	~Stack() {
//		cout << "~Stack()" << endl;
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _array;
//	size_t _top;
//	size_t _capacity;
//};
//
//class Queue {
//public:
//	//��ʼ���β��б�
//	Queue(int capacity = 8) : _stPush(8), _stPop(8), _size(0) {
//		//_size = 10;
//	}
//
//private:
//	Stack _stPush;
//	Stack _stPop;
//	int _size;
//};
//
//int main() {
//
//	Queue q;
//	return 0;
//}

//class Stack {
//public:
//	//ȱʡֵ����������һ������
//	Stack(int capacity = 4) {
//		cout << "Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (_array == nullptr) {
//			perror("Init file");
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//private:
//	int* _array;
//	size_t _top;
//	size_t _capacity;
//};
//
//class Queue {
//public:
//	//��ʼ���β��б�
//	Queue(int capacity = 100) :
//		_stPush(capacity), 						
//		_stPop(capacity),					
//		_size(0) {
//		//_size = 10;
//	}
//private:
//	Stack _stPush;
//	Stack _stPop;
//	int _size;
//};
//int main() {
//
//	Queue q;
//	return 0;
//}


//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//using namespace std;
//
//class Stack {
//public:
//	//���캯��
//	Stack(int capacity = 4) {
//		cout << " ���캯�� " << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	void Push(int val) {
//		if (_top == _capacity) {
//			int newcapacity = _capacity * 2;
//			int* tmp = (int*)realloc(_array, sizeof(int) * newcapacity);
//			assert(tmp);
//			_array = tmp;
//			_capacity = newcapacity;
//		}
//		_array[_top++] = val;
//
//	}
//	//�������� - ������Destroy()���ܣ������Դ�������������������
//	//�ֲ���ȫ���򡢶�̬����ģ�Ӱ����������
//	~Stack() {
//		cout << " �������� " << endl;
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _array;
//	int _top;
//	int _capacity;
//};
//int main() {
//	Stack st;
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	return 0;
//}

//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//using namespace std;



//class Stack {
//public:
//	//���캯��
//	Stack(int capacity = 4) {
//		cout << "���캯��: Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	~Stack() {
//		cout << "��������: ~Stack()" << endl;
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _array;
//	int _top;
//	int _capacity;
//};
//void Function() {
//	Stack st;
//}
//int main() {
//	Function();
//	Stack st;
//	return 0;
//}


//class Stack {
//public:
//	Stack(int capacity = 4) {
//		cout << "Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (_array == nullptr) {
//			perror("Init file");
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//	~Stack() {
//		cout << "~Stack()" << endl;
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _array;
//	size_t _top;
//	size_t _capacity;
//};
//
//class myQueue {
//public:
//private:
//	Stack _stPush;
//	Stack _stPop;
//	int size = 10;
//};
//int main() {
//
//	myQueue q;
//	return 0;
//}


//class Date {
//public:
//	Date(int year = 1, int month = 1, int day = 1) {
//		cout << "���캯��: Date(int year = 1, int month = 1, int day = 1)" << endl;
//		_year = year; _month = month; _day = day;
//	}
//	//��ʽд������� ֻΪ��˵�������Ⱥ�Ĺ�ϵ
//	~Date() {
//		cout << "��������: ~Date()" << endl;
//		_year = 0; _month = 0; _day = 0;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main() {
//
//	Date d1;
//	Date d2;
//	Date d3;
//	cout << endl;
//	return 0;
//}


#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

//class Date {
//public:
//	//���켴�ǳ�ʼ��
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//���ǲ�д��������Ĭ�ϻ����ɿ������캯��
//	//�������ͱ������Զ���������
//	//�Զ������Ϳ����������������Ҫ�����ֽ�д��Ҳ���ܲ���Ҫ�����Լ�д
//	Date(Date& d) {
//		cout << "�������� Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//��ָ��Ͳ��ǿ��������ˣ�����ͨ���캯��
//	/*Date(Date* d) {
//		cout << "��ͨ���� Date(Date &d)" << endl;
//		_year = d->_year;
//		_month = d->_month;
//		_day = d->_day;
//	}*/
//private:
//	int _year = 0;//ȱʡֵ�����ǳ�ʼ������Ϊ�����Ͳ���ռ�ռ�
//	int _month = 0;
//	int _day = 0;
//};
//
////��ֵ���Σ��ȵ����˿������죬�β���ʵ�εı���
//void Func1(Date d) {
//	cout << "Func1()" << endl;
//}
////�����ô��Σ��β���ʵ�εı���
//void Func2(Date& d) {
//	cout << "Func2()" << endl;
//}
//
//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(d1);//�������� - ������ʼ��
//	/*Func1(d1);
//	Func2(d1);*/
//	return 0;
//}

//class Date {
//public:
//	//���켴�ǳ�ʼ��
//	Date(int year = 1, int month = 1, int day = 1) {
//		cout << "���캯�� Date(int year = 1," 
//				"int month = 1, int day = 1)" << endl;
//		_year = year; _month = month; _day = day;
//	}
//	//��ʽд���Ŀ������캯��
//	Date(Date& d) {
//		cout << "�������캯�� Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main() {
//	Date d1(2022, 11, 11);//�����ʼ��
//	Date d2(d1);//�������� - ��ֵ��ʼ��
//	return 0;
//}

//class Date {
//public:
//	//���켴�ǳ�ʼ��
//	Date(int year = 1, int month = 1, int day = 1) {
//		cout << "���캯�� Date(int year = 1,"
//			"int month = 1, int day = 1)" << endl;
//		_year = year; _month = month; _day = day;
//	}
//	//��ʽд���Ŀ������캯��
//	Date(const Date d) {
//		cout << "�������캯�� Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main() {
//	Date d1(2022, 11, 11);//�����ʼ��
//	Date d2(d1);//�������� - ��ֵ��ʼ��
//	return 0;
//}
//
//Date(const Date d) {
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//}


//class Date {
//public:
//	//���켴�ǳ�ʼ��
//	Date(int year = 1, int month = 1, int day = 1) {
//		cout << "���캯�� Date(int year = 1,"
//			"int month = 1, int day = 1)" << endl;
//		_year = year; _month = month; _day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main() {
//	Date d1(2022, 11, 11);//�����ʼ��
//	Date d2(d1);//�������� - ��ֵ��ʼ��
//	return 0;
//}

////������������
////ǳ������ֵ������ʱ��������Ĭ�����ɵĿ���������ǹ��õ�
////���ʱ����������Ҳ��Ҫ�Լ�д�������캯������������Ĭ�����ɵĲ���ȫ�ʺ�
//class Stack {
//public:
//	//��ͨ����
//	Stack(int capacity = 4) {
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	//��д��������
//	Stack(const Stack& st) {
//		_array = (int*)malloc(sizeof(int) * st._capacity);
//		assert(_array);
//		//memcpy(des, src, sizeByte)
//		memcpy(_array, st._array, sizeof(int) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//	void Push(int val) {
//		if (_top == _capacity) {
//			int newcapacity = _capacity * 2;
//			int* tmp = (int*)realloc(_array, sizeof(int) * newcapacity);
//			assert(tmp);
//			_array = tmp;
//			_capacity = newcapacity;
//		}
//		_array[_top++] = val;
//	}
//	~Stack() {
//		cout << "~Stack()" << endl;
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _array;
//	size_t _top;
//	size_t _capacity;
//};
//
////��Ҫд�����������࣬����Ҫд����Ŀ������죬��Ϊ����Դ��Ҫ���ⴴ���ռ䲢�������ÿռ�
////����˵��̬����Ŀռ���Դ......
////����Ҫд�����������࣬Ĭ�����ɵ�ǳ�����Ŀ���������㹻ʹ����
//int main() {
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	Stack st2(st1);
//	st2.Push(3);
//	//������ʱ��������ˣ�ͬһ��ռ�free������
//	return 0;
//}


//������������
//ǳ������ֵ������ʱ��������Ĭ�����ɵĿ���������ǹ��õ�
//���ʱ����������Ҳ��Ҫ�Լ�д�������캯������������Ĭ�����ɵĲ���ȫ�ʺ�

//class Stack {
//public:
//	Stack(int capacity = 4) {
//		cout << "Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	~Stack() {
//		cout << "~Stack()" << endl;
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _array;
//	size_t _top;
//	size_t _capacity;
//};
//int main() {
//	Stack st1;
//	Stack st2(st1);
//	//������ʱ��������ˣ�ͬһ��ռ�free������
//	return 0;
//}
//



//class Stack {
//public:
//	//��ͨ����
//	Stack(int capacity = 4) {
//		cout << "��ͨ����: Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	//��д��������
//	Stack(const Stack& st) {
//		cout << "��������: Stack(const Stack& st)" << endl;
//		_array = (int*)malloc(sizeof(int) * st._capacity);
//		assert(_array);
//		//memcpy(des, src, sizeByte)
//		memcpy(_array, st._array, sizeof(int) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//	void Push(int val) {
//		if (_top == _capacity) {
//			int newcapacity = _capacity * 2;
//			int* tmp = (int*)realloc(_array, sizeof(int) * newcapacity);
//			assert(tmp);
//			_array = tmp;
//			_capacity = newcapacity;
//		}
//		_array[_top++] = val;
//	}
//	~Stack() {
//		cout << "����: ~Stack()" << endl;
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _array;
//	size_t _top;
//	size_t _capacity;
//};
//
//class myQueue {
//	//����ûд������������ Ĭ�Ϲ��캯����������������������һ�㲻�����������ֵ(��������������Ǿ���0)
//	//���Զ������;͵����Զ������ͱ����Ĺ��캯��
//private:
//	Stack stPush;
//	Stack stPop;
//	int size;
//};
//
////myQueue�ĳ�Ա���������Զ������ͣ�����myQueue�Ͳ���Ҫд��������
////��Ϊ������������size����������Ĭ�����ɿ�������
////�����Զ�������stPush��stPop����������ֱ�ӵ��������Լ��Ŀ������캯��
////�ܵ���˵���ǿ��������������
//int main() {
//
//	myQueue q1;
//	myQueue q2(q1);
//	return 0;
//}


//class Stack {
//public:
//	//��ͨ����
//	Stack(int capacity = 4) {
//		cout << "��ͨ����: Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	//��д��������
//	Stack(const Stack& st) {
//		cout << "��������: Stack(const Stack& st)" << endl;
//		_array = (int*)malloc(sizeof(int) * st._capacity);
//		assert(_array);
//		//memcpy(des, src, sizeByte)
//		memcpy(_array, st._array, sizeof(int) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//	~Stack() {
//		cout << "����: ~Stack()" << endl;
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _array;
//	size_t _top;
//	size_t _capacity;
//};
//
//class myQueue {
//private:
//	Stack stPush;
//	Stack stPop;
//	int size;
//};
//int main() {
//
//	myQueue q1;
//	myQueue q2(q1);
//	return 0;
//}

//class A {
//public:
//	A(int a, int b) {
//		cout << "���캯��: A(int a, int b) " << this <<  endl;
//		_a = a;
//		_b = b;
//	}
//	A(const A& A1) {
//		cout << "�������캯��: A(const A& A1) " << this << endl;
//		_a = A1._a;
//		_b = A1._b;
//	}
//	~A() {
//		cout << "��������: ~A() " << this << endl;
//		_a = _b = 0;
//	}
//private:
//	int _a;
//	int _b;
//};
//
//A Copy(const A A2) {
//	A A3(A2);
//	return A3;
//}
//int main() {
//
//	A A1(1, 1);
//	Copy(A1);
//	return 0;
//}




//class Date
//{
//public:
//	Date(int year, int minute, int day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d):" << this << endl;
//	}
//	~Date()
//	{
//		cout << "~Date():" << this << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//Date Test(Date d)
//{
//	Date temp(d);
//	return temp;
//}
//int main()
//{
//	Date d1(2022, 1, 13);
//	Date d2(Test(d1));
//	return 0;
//}



class Date {
public:
	//����
	Date(int year = 1, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
//private:
	int _year;
	int _month;
	int _day;
};
//������ɹ���
bool isEqual(const Date& d1, const Date& d2) {
	return d1._year == d2._year &&
		d1._month == d2._month &&
		d1._day == d2._day;
}
//c++���룬���������ⲻ�ܷ��ʵ�˽�г�Ա�����ˣ�������Ԫ����
bool operator==(const Date& d1, const Date& d2) {
	return d1._year == d2._year &&
		d1._month == d2._month &&
		d1._day == d2._day;
}

int main() {
	Date d1(2022, 11, 11);
	Date d2(2022, 11, 11);
	int ret1 = d1 == d2;
	cout << "(d1 == d2): " << (d1 == d2) << endl;
	cout << "ret1: " << ret1 << endl;
	int ret2 = operator==(d1, d2);
	cout << "operator==(d1, d2): " << operator==(d1, d2) << endl;
	cout << "ret2: " << ret2 << endl;
	return 0;
}