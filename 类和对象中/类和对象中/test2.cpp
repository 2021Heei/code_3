//#include "Date.h"



//int main() {
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	Stack st2;
//	st2.Push(10);
//	st2.Push(20);
//	st2.Push(30);
//
//	st1 = st2;
//}

//int main() {
//	//myQueue��Date��operator= �������󣬲���Ҫ���ֶ�д��
//	myQueue q1;
//	q1.Push(1);
//	q1.Push(2);
//	myQueue q2;
//	q2.Push(2);
//	q2.Push(2);
//
//	q1 = q2;
//	return 0;
//}

//int main() {
//
//	myQueue q1;
//	q1.Push(1);
//	q1.Push(2);
//	myQueue q2;
//	q2.Push(10);
//	q2.Push(20);
//
//	q1 = q2;
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << "Print()" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl;
//	}
//	void Print() const
//	{
//		cout << "Print()const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl;
//	}
//private:
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
//};
//
//int main() {
//	Date d1(2022, 1, 13);
//	d1.Print();
//	cout << endl;
//	const Date d2(1970, 1, 1);
//	d2.Print();
//	return 0;
//}

//int main() {
//	/*Date d1;
//	cout << &d1 << endl;*/
//
//	const Date d2;
//	cout << &d2 << endl;
//}

//int main() {
//
//	const Date d2;
//	cout << &d2 << endl;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//class Date {
//public:
//
//	////Ĭ�� ����
//	//Date(int year = 1, int month = 1, int day = 1) {
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	//��ʼ���б�
//	Date(int year = 1, int month = 1, int day = 1) :
//		_year(year)
//		, _month(month)
//		, _day(day) {
//
//	}
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

#include <iostream>
#include <assert.h>
using namespace std;

//class Date {
//public:
//	//Ĭ�� ����
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day){
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	int* _p;
//};
//
//int main() {
//
//	Date d;
//	return 0;
//}


//class A {
//public:
//	A(int a = 0) 
//		:_a(a)
//		,_a(a){
//	}
//private:
//	int _a;
//};
//
//int main() {
//
//	A a1;
//	return 0;
//}

//class B {
//public:
//	B(int b = 1) :_b(b){
//		cout << "���캯��: B(int b = 1)" << endl;
//	}
//private:
//	int _b;
//	A _aa;
//};



//class A {
//public:
//	A(int a = 0, int b = 10)
//		:_a(a){
//		_b = b;
//	}
//private:
//	int _a;
//	const int _b;
//};
//
//int main() {
//
//	A a1;
//	return 0;
//}

//class A {
//public:
//	A(int a = 0, int b = 10)
//		:_a(a){
//		_b = b;
//	}
//private:
//	int _a;
//	int& _b;
//};
//
//int main() {
//
//	A a1;
//	return 0;
//}


//class A {
//public:
//	A(int a) 
//		:_a(a){
//	}
//private:
//	int _a;
//};
//
//class B {
//public:
//	B(int b = 1) :_b(b) {
//		;
//	}
//private:
//	int _b;
//	A _aa;
//};
//
//int main() {
//
//	B b1;
//	return 0;
//}

//class A {
//public:
//	A(int a = 1)
//		:_a(a) {
//	}
//private:
//	int _a;
//};
//
//
//int main() {
//
//	A a1;
//	return 0;
//}


//class Stack {
//public:
//	//��ͨ����
//	Stack(int capacity = 4) 
//		:_top(0)
//		,_capacity(capacity){
//
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (_array == nullptr) {
//			perror("Stack(int capacity = 4) malloc file");
//			exit(-1);
//		}
//	}
//	~Stack() {
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
//int main() {
//	Stack st;
//	return 0;
//}

//class A {
//public:
//	A(int a = 1)
//		:_b(a)
//		,_a(_b) {
//	}
//private:
//	int _a;
//	int _b;
//};
//
//
//int main() {
//
//	A a1;
//	return 0;
//}

//class A {
//public:
//	A(int a = 1, int b = 2, int c = 3)
//		:_a(a)
//		,_b(b)
//		,_c(c){
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};
//int main() {
//
//	A a1;
//	A a2(10);
//	A a3(10, 20);
//	A a4(10, 20, 30);
//	return 0;
//}

//Aû��Ĭ�Ϲ���
//class A {
//public:
//	A(int a)
//		:_a(a) {}
//private:
//	int _a;
//};
////����B��Ķ���ʱ�����B��Ĭ�Ϲ��죬��B��Ĭ�Ϲ����ʼ���б�����A��Ĭ�Ϲ��죬
////��Aû��Ĭ�Ϲ��죬���Ա�����������û��B��Ĭ�Ϲ��캯����
////������B�Ķ��󲢲��ᱨ����Ϊû�е���B��Ĭ�Ϲ��죻
//class B {
//private:
//	A _aa;
//};
//
//int main() {
//	//B b;
//	return 0;
//}


//class A {
//public:
//	A(int a) 
//		:_a(a){
//	}
//private:
//	int _a;
//};
//
//class B {
//public:
//	/*B(int b = 1) :_b(b) {
//		;
//	}*/
//private:
//	int _b;
//	A _aa;
//};
//
//int main() {
//
//	B b1;
//	return 0;
//}


//class A {
//public:
//	A(int a)
//		:_a(a) {
//		cout << "����: A(int a)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};

//int main() {
//	//A a1(10);//����
//	//A a2 = 10;//��ʽ����ת�� 10 --> ������ʱA����� --> a2;����+��������
//	////�ȼ���	const A tmp(10); A a2(tmp);
//
//	//const A& a3 = 100;//��ʽ����ת�� ;���õĲ�������100�����õ�����ʱ����A�����
//	////�ȼ���	const A tmp(100); const A a2(tmp);
//
//
//	A a3(20);//����
//	A a4 = a3;//��������
//	return 0;
//}

//int main() {
//	A a3(20);//����
//	A a4 = a3;//��������
//	return 0;
//}

//class A {
//public:
//	A(int a)
//		:_a(a) {
//		cout << "����: A(int a)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	A a2 = 10;//��ʽ����ת�� 10 --> ������ʱA����� --> a2;����+��������
//	//�ȼ���	const A tmp(10); A a2(tmp);
//	return 0;
//}


//class A {
//public:
//	A(int a)
//		:_a(a) {
//		cout << "����: A(int a)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
////�±������Թ�����صĲ�����п��ܵ��Ż����ϵı�������֧�֣�
//int main() {
//	A a1(10);//����
//	A a2 = 10;//��ʽ����ת�� 10 --> ������ʱA����� --> a2;����+�������� --->(�������Ż�) ֱ�ӹ���
//	//�ȼ���	const A tmp(10); A a2(tmp);
//
//	const A& a3 = 100;//��ʽ����ת�� ;���õĲ�������100�����õ�����ʱ����A�����
//	//�ȼ���	const A tmp(100); const A& a2 = tmp;
//
//
//	A a4(20);//����
//	A a5 = a4;//��������
//	return 0;
//}

//class A {
//public:
//	A(int a)
//		:_a(a) {
//		cout << "����: A(int a)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
////�±������Թ�����صĲ�����п��ܵ��Ż����ϵı�������֧�֣�
//int main() {
//
//	A tmp(100);//���캯��
//	A a2(tmp);//��������
//	return 0;
//}


//class A {
//public:
//	explicit A(int a)
//		:_a(a) {
//		cout << "����: A(int a)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
////�±������Թ�����صĲ�����п��ܵ��Ż����ϵı�������֧�֣�
//int main() {
//	//A a2 = 10;//��ʽ����ת�� 10 --> ������ʱA����� --> a2;����+�������� --->(�������Ż�) ֱ�ӹ���
//	////�ȼ���	const A tmp(10); A a2(tmp);
//
//	//const A& a3 = 100;//��ʽ����ת�� ;���õĲ�������100�����õ�����ʱ����A�����
//	////�ȼ���	const A tmp(100); const A& a2 = tmp;
//	A a(10);
//	int aa = (int)a;
//	return 0;
//}


//�Ե��������캯��������ʽ����ת�����ƹ�--
// C++11
//������ҿ���ֻ��һ�������ѵĹ��캯������ʽ����ת��
//
//�±������Թ�����صĲ�����п��ܵ��Ż����ϵı�������֧�֣�

//class A {
//public:
//	A(int a = 1,int b = 1, int c = 1)
//		:_a(a)
//		,_b(b)
//		,_c(c){
//		cout << "����: A(int a = 1,int b = 1, int c = 1)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//		_b = a._b;
//		_c = a._c;
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};


////explicit�ؼ������ζ�������캯������ֹ��ʽ����ת���ķ���
//class A {
//public:
//	explicit A(int a = 1, int b = 1, int c = 1)
//		:_a(a)
//		, _b(b)
//		, _c(c) {
//		cout << "����: A(int a = 1,int b = 1, int c = 1)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//		_b = a._b;
//		_c = a._c;
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};

//class A {
//public:
//	A(int a = 1,int b = 1, int c = 1)
//		:_a(a)
//		,_b(b)
//		,_c(c){
//		cout << "����: A(int a = 1,int b = 1, int c = 1)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//		_b = a._b;
//		_c = a._c;
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};

//int main() {
//	A a2 = { 1,2,3 };//����+�������� --> �Ż�Ϊ ����
//	//�ӽ����˵��������ΪA a1(10,20,30) �ȼ��� A a2 = {1,2,3};
//	return 0;
//}



//class A {
//public:
//	explicit A(int a = 1, int b = 1, int c = 1)
//		:_a(a)
//		, _b(b)
//		, _c(c) {
//		cout << "����: A(int a = 1,int b = 1, int c = 1)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//		_b = a._b;
//		_c = a._c;
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};
//
//int main() {
//
//	const A& a3 = { 1,2,3 };//����
//	return 0;
//}

//static