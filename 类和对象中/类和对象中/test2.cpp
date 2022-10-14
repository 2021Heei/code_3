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
//	//myQueue和Date类operator= 满足需求，不需要再手动写了
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
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
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
//	////默认 构造
//	//Date(int year = 1, int month = 1, int day = 1) {
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	//初始化列表
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
//	//默认 构造
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
//		cout << "构造函数: B(int b = 1)" << endl;
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
//	//普通构造
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

//A没有默认构造
//class A {
//public:
//	A(int a)
//		:_a(a) {}
//private:
//	int _a;
//};
////定义B类的对象时会调用B的默认构造，在B的默认构造初始化列表会调用A的默认构造，
////但A没有默认构造，所以报错，但报的是没有B的默认构造函数；
////不定义B的对象并不会报错，因为没有调用B的默认构造；
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
//		cout << "构造: A(int a)" << endl;
//	}
//	A(A& a) {
//		cout << "拷贝构造: A(A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};

//int main() {
//	//A a1(10);//构造
//	//A a2 = 10;//隐式类型转换 10 --> 匿名临时A类对象 --> a2;构造+拷贝构造
//	////等价于	const A tmp(10); A a2(tmp);
//
//	//const A& a3 = 100;//隐式类型转换 ;引用的不是整型100，引用的是临时匿名A类对象
//	////等价于	const A tmp(100); const A a2(tmp);
//
//
//	A a3(20);//构造
//	A a4 = a3;//拷贝构造
//	return 0;
//}

//int main() {
//	A a3(20);//构造
//	A a4 = a3;//拷贝构造
//	return 0;
//}

//class A {
//public:
//	A(int a)
//		:_a(a) {
//		cout << "构造: A(int a)" << endl;
//	}
//	A(A& a) {
//		cout << "拷贝构造: A(A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	A a2 = 10;//隐式类型转换 10 --> 匿名临时A类对象 --> a2;构造+拷贝构造
//	//等价于	const A tmp(10); A a2(tmp);
//	return 0;
//}


//class A {
//public:
//	A(int a)
//		:_a(a) {
//		cout << "构造: A(int a)" << endl;
//	}
//	A(A& a) {
//		cout << "拷贝构造: A(A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
////新编译器对构造相关的步骤进行可能的优化，老的编译器不支持；
//int main() {
//	A a1(10);//构造
//	A a2 = 10;//隐式类型转换 10 --> 匿名临时A类对象 --> a2;构造+拷贝构造 --->(编译器优化) 直接构造
//	//等价于	const A tmp(10); A a2(tmp);
//
//	const A& a3 = 100;//隐式类型转换 ;引用的不是整型100，引用的是临时匿名A类对象
//	//等价于	const A tmp(100); const A& a2 = tmp;
//
//
//	A a4(20);//构造
//	A a5 = a4;//拷贝构造
//	return 0;
//}

//class A {
//public:
//	A(int a)
//		:_a(a) {
//		cout << "构造: A(int a)" << endl;
//	}
//	A(A& a) {
//		cout << "拷贝构造: A(A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
////新编译器对构造相关的步骤进行可能的优化，老的编译器不支持；
//int main() {
//
//	A tmp(100);//构造函数
//	A a2(tmp);//拷贝构造
//	return 0;
//}


//class A {
//public:
//	explicit A(int a)
//		:_a(a) {
//		cout << "构造: A(int a)" << endl;
//	}
//	A(A& a) {
//		cout << "拷贝构造: A(A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
////新编译器对构造相关的步骤进行可能的优化，老的编译器不支持；
//int main() {
//	//A a2 = 10;//隐式类型转换 10 --> 匿名临时A类对象 --> a2;构造+拷贝构造 --->(编译器优化) 直接构造
//	////等价于	const A tmp(10); A a2(tmp);
//
//	//const A& a3 = 100;//隐式类型转换 ;引用的不是整型100，引用的是临时匿名A类对象
//	////等价于	const A tmp(100); const A& a2 = tmp;
//	A a(10);
//	int aa = (int)a;
//	return 0;
//}


//对单参数构造函数允许隐式类型转换的推广--
// C++11
//多参数且可以只传一个参数堆的构造函数的隐式类型转换
//
//新编译器对构造相关的步骤进行可能的优化，老的编译器不支持；

//class A {
//public:
//	A(int a = 1,int b = 1, int c = 1)
//		:_a(a)
//		,_b(b)
//		,_c(c){
//		cout << "构造: A(int a = 1,int b = 1, int c = 1)" << endl;
//	}
//	A(A& a) {
//		cout << "拷贝构造: A(A& a)" << endl;
//		_a = a._a;
//		_b = a._b;
//		_c = a._c;
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};


////explicit关键字修饰多参数构造函数，禁止隐式类型转换的发生
//class A {
//public:
//	explicit A(int a = 1, int b = 1, int c = 1)
//		:_a(a)
//		, _b(b)
//		, _c(c) {
//		cout << "构造: A(int a = 1,int b = 1, int c = 1)" << endl;
//	}
//	A(A& a) {
//		cout << "拷贝构造: A(A& a)" << endl;
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
//		cout << "构造: A(int a = 1,int b = 1, int c = 1)" << endl;
//	}
//	A(A& a) {
//		cout << "拷贝构造: A(A& a)" << endl;
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
//	A a2 = { 1,2,3 };//构造+拷贝构造 --> 优化为 构造
//	//从结果来说，可以认为A a1(10,20,30) 等价于 A a2 = {1,2,3};
//	return 0;
//}



//class A {
//public:
//	explicit A(int a = 1, int b = 1, int c = 1)
//		:_a(a)
//		, _b(b)
//		, _c(c) {
//		cout << "构造: A(int a = 1,int b = 1, int c = 1)" << endl;
//	}
//	A(A& a) {
//		cout << "拷贝构造: A(A& a)" << endl;
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
//	const A& a3 = { 1,2,3 };//构造
//	return 0;
//}

//static