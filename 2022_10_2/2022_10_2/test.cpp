//#include "statement.h"
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

////////////////////////////////////////////////////////////////////////////////////////



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
//
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
//	//���캯��
//	//���󴴽�ʱ���Զ����ù��캯���Զ�����г�ʼ��  
//	//��������������ͬ
//	//û�з���ֵ�Ҳ�д��������λ��ɶҲ��д
//	Date(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
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
//	Date a3();//ʹ���޲ι��캯����ʼ��ʱ���������ţ�������� ������������
//	//Date func();// warning C4930: ��Date a3(void)��: δ����ԭ�ͺ���(�Ƿ��������ñ��������?)
//	a1.Print();
//	a2.Print();
//	//a3.Print();
//	return 0;
//}

//class Date {
//public:
//	//���캯��
//	//���󴴽�ʱ���Զ����ù��캯���Զ�����г�ʼ��  
//	//��������������ͬ
//	//û�з���ֵ�Ҳ�д��������λ��ɶҲ��д
//	Date(int year = 1970, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//ȫȱʡ���޲ι��캯������ͬʱ���ڣ�����������ʱ����������ԣ�
//	//ȫȱʡ���캯���������������޲ι��캯��
//	/*Date() {
//		_year = 1970;
//		_month = 1;
//		_day = 1;
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

//class A {
//public:
//	A() {
//		cout << "���캯�� A()" << endl;
//		_a = 10;
//	}
//	~A() {
//		cout << "�������� ~A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//
//class B {
//public:
//	~B() {
//		cout << "�������� ~B()" << endl;
//	}
//private:
//	//�������ͣ�
//	// C++��׼û�й涨Ĭ�Ϲ��캯����Ҫ�Ƿ���������ͽ��г�ʼ��
//	//�����������ʵ�ֵ�Ĭ�Ϲ��캯������ʼ����������
//	int _b1;
//	int _b2;
//	//�Զ������ͣ�
//	//Ĭ�Ϲ��캯�������ø����Ĭ�Ϲ��캯����ʼ��
//	//Ĭ�Ϲ��캯��->�Զ��幹�캯��->�Զ�����������->Ĭ����������
//	//�ȹ���ĺ�����
//	A A1;
//};
//
//int main() {
//	B B1;
//	return 0;
//}

//��A����֪�������˹��캯������������
//class A {
//public:
//	A() {
//		cout << "���캯�� A()" << endl;
//		_a = 10;
//	}
//	~A() {
//		cout << "�������� ~A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//
////��B����û�ж��幹�캯��
//class B {
//public:
//	~B() {
//		cout << "�������� ~B()" << endl;
//	}
//private:
//	//�������ͣ�
//	int _b1;
//	int _b2;
//	//�Զ������ͣ�
//	A A1;
//};
//
//int main() {
//	B B1;
//	return 0;
//}

//1.�﷨����
//........

//2.ע��ʲôʱ��д��ʲôʱ��д
//��Stack��MyQueueΪ����
//ʲôʱ����Ҫ�Լ�д���캯����
//ʲôʱ����Ҫ�Լ�д��
//Ҫ��ʵ�ʵ����󣬱�����Ĭ�����ɵĹ��þͲ���Ҫ�Լ�д�������þ��Լ�д��
//��������������Ҫд��Ĭ�Ϲ��캯����������������������Ҫ�ֶ�����
//�Զ������Ͳ���Ҫд���Զ��������ڲ��������Լ����캯����ʵ�֣�ֻ��Ҫ�������еĹ��캯������

//ʲôʱ����Ҫд����������
//ʲôʱ����Ҫд����������
//Ҫ��ʵ�����󣬱�����Ĭ�����ɵĹ��þͲ���Ҫ�Լ�д�������þ��Լ�д��

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
//class myQueue {
//public:
//	//��ʼ���β��б�
//	/*myQueue(int capacity = 8) : _stPush(8),_stPop(8){
//		size = 10;
//	}*/
//	/*void Push(int val) {
//		_stPush.Push(val);
//	}*/
//
//private:
//	/*Stack _stPush;
//	Stack _stPop;*/
//	int size;
//};
//
//int main() {
//	myQueue q;
//
//	return 0;
//}


//class Date {
//public:
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year = 0;//ȱʡֵ�����ǳ�ʼ������Ϊ�����Ͳ���ռ�ռ�
//	int _month = 0;
//	int _day = 0;
//};
//
//int main() {
//	Date d;
//	return 0;
//}

//class Date {
//public:
//	//Ĭ�Ϲ��캯��������Ҫ���ξ��ܵ��õĹ��캯��
//	//�����޲ι��캯����ȫȱʡ���캯���ͱ������Զ����ɵ�
//	/*Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	Date() {
//		_year = 10;
//		_month = 10;
//		_day = 10;
//	}
//private:
//	int _year = 0;//ȱʡֵ�����ǳ�ʼ������Ϊ�����Ͳ���ռ�ռ�
//	int _month = 0;
//	int _day = 0;
//};
//
//int main() {
//	Date d;
//	return 0;
//}


//class Stack {
//public:
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
//	//int* _array = nullptr;
//	int* _array = (int*)malloc(sizeof(int) * 4);
//	//��Ҳ��ȱʡֵ���޹��캯��ʱ�Ż����,����û�жԷ��صĽ�����м��
//	size_t _top = 0;
//	size_t _capacity = 4;
//};
//
//class myQueue {
//public:
//
//
//private:
//	Stack _stPush;
//	Stack _stPop;
//	int size = 10;
//};
//
//int main() {
//	Stack st;
//	myQueue q;
//
//	return 0;
//}


//////////////////////////////////////////////////////////////////////////////////
//��������


//#include <iostream>
//using namespace std;
//int main() {
//	float x, y, a;
//	for (y = 1.5; y > -1.5; y -= 0.1)
//	{
//		for (x = -1.5; x < 1.5; x += 0.05) {
//			a = x * x + y * y - 1;
//			putchar(a * a * a - x * x * y * y * y <= 0.0 ? '*' : ' ');
//		}
//		system("color 0c");
//		putchar('\n');
//	}
//	return 0;
//}
//
//#include <iostream>
//#include <cassert>
//#include <cstdlib>
//using namespace std;
//
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
//	Date(Date &d) {
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
//	Date d1(2022,11,11);
//	Date d2(d1);//�������� - ������ʼ��
//	/*Func1(d1);
//	Func2(d1);*/
//	return 0;
//}


//class Date {
//public:
//	//���켴�ǳ�ʼ��
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
	////�βζ��һ��const���ƣ�ʹ����dȨ������С��д��ʱ���ڱ�������飬
	//Date(const Date& d) {
	//	cout << "�������� Date(Date &d)" << endl;
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}
//
//private:
//	int _year = 0;//ȱʡֵ�����ǳ�ʼ������Ϊ�����Ͳ���ռ�ռ�
//	int _month = 0;
//	int _day = 0;
//};
//
//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(d1);//�������� - ������ʼ��
//	return 0;
//}

//�����������������ջ������
//class Date {
//public:
//	//���켴�ǳ�ʼ��
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year = 0;//ȱʡֵ�����ǳ�ʼ������Ϊ�����Ͳ���ռ�ռ�
//	int _month = 0;
//	int _day = 0;
//};
//
//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(d1);//�������� - ������ʼ��
//	return 0;
//}


//������������
//ǳ������ֵ������ʱ��������Ĭ�����ɵĿ���������ǹ��õ�
//���ʱ����������Ҳ��Ҫ�Լ�д�������캯������������Ĭ�����ɵĲ���ȫ�ʺ�
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


///////////////////////////////////////////////////////////////////////////
//���������
//��ʲô���壿
//��������Ϊ�����
//֧��������㣬����������ʱ�ı�ʾ
//�뺯�����ز�ͬŶ

//class Date {
//public:
//	//����
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//�βζ��һ��const���ƣ�ʹ����dȨ������С��д��ʱ���ڱ�������飬
//	Date(const Date& d) {
//		//cout << "�������� Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
////private:
//	int _year;
//	int _month;
//	int _day;
//};
////������ɹ���
//bool isEqual(const Date& d1, const Date& d2) {
//	return d1._year == d2._year &&
//		d1._month == d2._month &&
//		d1._day == d2._day;
//}
////c++���룬���������ⲻ�ܷ��ʵ�˽�г�Ա�����ˣ�������Ԫ����
//bool operator==(const Date& d1, const Date& d2) {
//	return d1._year == d2._year &&
//		d1._month == d2._month &&
//		d1._day == d2._day;
//}
//
//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(2022, 11, 11);
//	int ret1 = d1 == d2;
//	cout << "(d1 == d2): " << (d1 == d2) << endl;
//	cout << "ret1: " << ret1 << endl;
//	int ret2 = operator==(d1, d2);
//	cout << "operator==(d1, d2): " << operator==(d1, d2) << endl;
//	cout << "ret2: " << ret2 << endl;
//	return 0;
//}


//class Date {
//public:
//	//����
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//�βζ��һ��const���ƣ�ʹ����dȨ������С��д��ʱ���ڱ�������飬
//	Date(const Date& d) {
//		//cout << "�������� Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	int GetYear() {
//		int year = _year;
//		return year;
//	}
//	int GetMonth() {
//		int month = _month;
//		return month;
//	}
//	int GetDay() {
//		int day = _day;
//		return day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////c++���룬���������ⲻ�ܷ��ʵ�˽�г�Ա�����ˣ�������Ԫ����
////��������
//bool operator==(Date& d1, Date& d2) {
//	return d1.GetYear() == d2.GetYear() &&
//		d1.GetMonth() == d2.GetMonth() &&
//		d1.GetDay() == d2.GetDay();
//}
//bool operator==(Date& d1, Date& d2) {
//	return d1.GetYear() == d2.GetYear() &&
//		d1.GetMonth() == d2.GetMonth() &&
//		d1.GetDay() == d2.GetDay();
//}

//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(2022, 11, 11);
//	int ret1 = d1 == d2;
//	cout << "(d1 == d2): " << (d1 == d2) << endl;
//	cout << "ret1: " << ret1 << endl;
//	int ret2 = operator==(d1, d2);
//	cout << "operator==(d1, d2): " << operator==(d1, d2) << endl;
//	cout << "ret2: " << ret2 << endl;
//	return 0;
//}


//class Date {
//public:
//	//����
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//�βζ��һ��const���ƣ�ʹ����dȨ������С��д��ʱ���ڱ�������飬
//	Date(const Date& d) {
//		//cout << "�������� Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//���󣬲������࣬==Ӧ��ֻ��������������
//	//�������ڵĺ���������һ���������β�thisָ��
//	/*bool operator==(const Date& d1, const Date& d2) {
//		return d1._year == d2._year &&
//			d1._month == d2._month &&
//			d1._day == d2._day;
//	}*/
//
//	bool operator==(const Date& d) {
//		return _year == d._year &&
//			_month == d._month &&
//			_day == d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(2022, 11, 11);
//	int ret1 = d1 == d2;
//	cout << "(d1 == d2): " << (d1 == d2) << endl;
//	cout << "ret1: " << ret1 << endl;
//	int ret2 = d1.operator==(d2);
//	cout << "d1.operator==(d2): " << d1.operator==(d2) << endl;
//	cout << "ret2: " << ret2 << endl;
//	return 0;
//}

//class Date {
//public:
//	//����
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//�βζ��һ��const���ƣ�ʹ����dȨ������С��д��ʱ���ڱ�������飬
//	Date(const Date& d) {
//		//cout << "�������� Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//	int DateTransDay() {
//		 Date cur(*this);
//		 
//		 while (cur._year > 0 || cur._month > 0) {
//			 cur._month--;
//			 if (cur._month == 0 && cur._year > 0) {
//				 cur._month = 12;
//				 cur._year--;
//			 }
//			 cur._day += GetDay(cur._year, cur._month);
//			 //cout << cur._year << "    " << cur._month << "    " << cur._day << endl;
//		}
//		 return cur._day;
//	}
//	//����
//	bool operator==(const Date& d) {
//		return _year == d._year &&
//			_month == d._month &&
//			_day == d._day;
//	}
//	//����
//	bool operator>(const Date& d) {
//		if (_year > d._year) {
//			return true;
//		}
//		else if (_year == d._year && _month > d._month) {
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day > d._day) {
//			return true;
//		}
//		return false;
//	}
//	//С��
//	bool operator<(const Date& d) {
//		//return !((this->operator==(d)) || (this->operator>(d)));
//		if (_year < d._year) {
//			return true;
//		}
//		else if (_year == d._year && _month < d._month) {
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day < d._day) {
//			return true;
//		}
//		return false;
//	}
//	//С�ڵ���
//	bool operator<=(const Date& d) {
//		return this->operator<(d) || this->operator==(d);
//	}
//	//���ڵ���
//	bool operator>=(const Date& d) {
//		return this->operator>(d) || this->operator==(d);
//	}
//	//�õ�ĳһ������
//	static int GetDay(int year, int month) {
//		//ƽ��
//		int array[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		//���⴦������2��
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) && month == 2) {
//			return 29;
//		}
//		return array[month];
//	}
//	//d1+d2
//	Date operator+(int day) {
//		Date cur(*this);
//		cur._day = cur._day + day;
//		while (cur._day > GetDay(cur._year, cur._month)) {
//			cur._day -= GetDay(cur._year, cur._month);
//			cur._month++;
//			if (cur._month > 12) {
//				cur._year++;
//				cur._month = 1;
//			}
//		}
//		return cur;
//	}
//	//+=
//	Date& operator+=(int day) {
//		_day = _day + day;
//		while (_day > GetDay(_year, _month)) {
//			_day -= GetDay(_year, _month);
//			_month++;
//			if (_month > 12) {
//				_year++;
//				_month = 1;
//			}
//		}
//		return *this;
//	}
//	//-
//	int operator-(Date& d) {
//		Date cur(*this);
//		return this->DateTransDay() - d.DateTransDay();
//
//		/*cur._day -= d._day;
//		if (cur._day < 0) {
//			cur._day += GetDay(cur._year, cur._month);
//			cur._month--;
//		}
//		cur._month -= d._month;
//		if (cur._month < 0) {
//			cur._month += 12;
//			cur._year--;
//		}
//		cur._year -= d._year;
//		return cur;*/
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(2022, 12, 12);
//	//cout << (d1 > d2) << endl;
//
//	/*cout << (d1 < d2) << endl;
//	cout << (d2 < d1) << endl;*/
//
//	/*cout << (d1 <= d2) << endl;
//	cout << (d2 <= d1) << endl;*/
//
//	//cout << (d1 >= d2) << endl;
//	//cout << (d2 >= d1) << endl;
//
//	/*d1.Print();
//	(d1 + 50).Print();
//	d2.Print();
//	(d2 + 60).Print();*/
//
//	d1.Print();
//	d1 += 50;
//	d1.Print();
//
//	d2.Print();
//	d2 += 60;
//	d2.Print();
//
//	//cout << d1.DateTransDay() << endl;
//	/*cout << (d1 - d2) << endl;
//	cout << (d2 - d1) << endl;*/
//
//	return 0;
//}




























