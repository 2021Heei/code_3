//#include "Date.h"
//
//void TestDate1() {
//	Date d1(2022,10,11);
//	//Date d2();//与函数声明产生了混淆
//	/*Date d3(2022, 2, 2202002);
//	d3.Print();
//	Date d4(2022, 2, 220);
//	d4.Print();*/
//	/*Date d5(d1);
//	d5.Print();
//	Date d6 = d5;
//	d6.Print();*/
//	/*Date d7, d8, d9;
//	d7 = d8 = d9 = d1;
//	d7.Print();
//	d8.Print();
//	d9.Print();*/
//
//	Date d2(2022, 10, 11);
//	d2 + 40;//d2.operator(40); -> d2.operator(&d2, 40)
//	(d2 + 40).Print();
//	d2 += 40;
//	d2.Print();
//
//	//Date d3;
//	//-d3;
//}
//
//void TestDate2() {
//
//	Date d1(2022, 10, 12);
//	Date d2;
//
//	d2.Print();
//	d2 = d1;
//	d2.Print();
//
//	//Date d1(2022, 10, 11);
//	//Date d2(d1);	//拷贝构造，一个拷贝初始化另一个马上要创建的对象
//	//Date d3 = d1;	//拷贝构造
//	//Date d4;
//	//d4 = d1;		//赋值重载、复制拷贝，已存在的两个对象之间的拷贝
//	//d1.Print();
//	//d2.Print();
//	//d3.Print();
//	//d4.Print();
//	//赋值运算符重载：
//	//为什么用引用返回？ - 减少一次拷贝
//	//为什么参数用常引用？ - 减少一次拷贝，且使用方便
//	//为什么返回*this，而不是d？ 
//	//		- this是第一个参数，相当于赋值时的左值；d是第二个参数，相当于赋值时的右值；
//	//		连续赋值时一般表达式的返回值是左边的变量，
//	//为什么不用指针做第二个参数？ - 使用麻烦
//
//	/*Date d6, d7;
//	d6 = d7 = d2;
//	d6.Print();
//	d7.Print();*/
//}
//
//void TestSatck() {
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	Stack st2;
//	st2.Push(10);
//	st2.Push(20);
//	st2.Push(30);
//
//	//st1 = st2;//默认赋值运算符重载函数不能够完成栈的赋值需求，需要我们手动写
//	st1 = st2;//这里为什么不用realloc()，而是先free，再malloc()???
//	//分为三种情况：（基于栈的容量）
//	//st1小于st2
//	//st1与st2基本相当
//	//st1大于st2
//
//	//Stack st3;
//	////st3.Push(1);
//	//st3.Push(2);
//
//	//st3 = st3;//防止自己给自己赋值，进行判断即可
//
//	////myQueue和Date类operator= 满足需求，不需要再手动写了
//	//myQueue q1;
//	//q1.Push(1);
//	//q1.Push(2);
//	//myQueue q2;
//	//q2.Push(2);
//	//q2.Push(2);
//
//	//q1 = q2;
//
//}
//
//void TestDate3() {
//	/*Date d1(2022, 10, 11);
//	Date d2(2022, 10, 11);
//	int ret = d1 > d2;
//
//	(d1 + 1000).Print();
//	d2 += 10000;
//	d2.Print();
//	d1 += -20000;
//	d1.Print();*/
//
//	/*Date d1(2022, 10, 11);
//	Date d2(2022, 10, 11);
//	int ret = d1 > d2;
//
//	(d1 - 1000).Print();
//	d2 -= 10000;
//	d2.Print();
//	d1 -= -10000;
//	d1.Print();*/
//
//	//	前置和后置函数，运算符重载和函数重载，
//	//	后置多了一个int参数，目的是与前置区分，由编译器传递，构成函数重载
//	//	对于内置类型，前置与后置基本没有差别；
//	//	对于自定义类型，前置比后置少了两次拷贝构造函数的调用，所以尽量使用前置++/--
//	/*Date d1(2022, 10, 11);
//	Date d2(2022, 10, 11);
//	d1.Print();
//	(++d1).Print();
//	d1.Print();
//
//	d2.Print();
//	(d2++).Print();
//	d2.Print();*/
//
//	/*Date d1(2022, 10, 11);
//	Date d2(2022, 10, 11);
//	d1.Print();
//	(--d1).Print();
//	d1.Print();
//
//	d2.Print();
//	(d2--).Print();
//	d2.Print();*/
//	
//	Date d1(2022, 10, 12);
//	Date d2(2020, 12, 28);
//	cout << (d1 < d2) << endl;
//	cout << d1 - d2 << endl;
//}
//
//void TestDate4() {
//	Date d1;
//	//cin >> d1;
//	//d1 >> cin;//流插入运算符>> 左右操作数反了
//
//	Date d2;
//	//cin >> d2;
//	//cin >> d2;// operator>>(cin, d2);
//	//d2 << cout;
//	cout << d2;
//}
//
//void TestDate5() {
//	Date d1;
//	cout << &d1 << endl;
//
//	/*const Date d2;
//	cout << &d2 << endl;*/
//}
////int main() {
////
////	//TestDate1();
////	//TestDate2();
////	//TestSatck();
////	//TestDate3();
////	//TestDate4();
////	TestDate5();
////	return 0;
////}



////////////////////////////////////////////////////////////////////////////////////////////////
//2022 - 10 - 13
//#include <iostream>
//#include <assert.h>
//using namespace std;



//初始化列表
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

//class Stack {
//public:
//	////函数体内初始化
//	//Stack(int capacity = 4) {
//	//	_array = (int*)malloc(sizeof(int) * capacity);
//	//	_top = 0;
//	//	_capacity = capacity;
//	//	if (_array == nullptr) {
//	//		perror("Stack(int capacity = 4)");
//	//		exit(-1);
//	//	}
//	//	memset(_array, 0, sizeof(int) * _capacity);
//	//}
//	////初始化列表 - 1
//	//Stack(int capacity = 4)
//	//	:_array((int*)malloc(sizeof(int)*capacity))
//	//	,_top(0)
//	//	,_capacity(capacity){
//	//	if (_array == nullptr) {
//	//		perror("Stack(int capacity = 4)");
//	//		exit(-1);
//	//	}
//	//	memset(_array, 0, sizeof(int) * _capacity);
//	//}
//	//初始化列表 - 2 - 与函数体内初始化联合使用（混用）
//	Stack(int capacity = 4)
//		: _top(0)
//		, _capacity(capacity) {
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (_array == nullptr) {
//			perror("Stack(int capacity = 4)");
//			exit(-1);
//		}
//		memset(_array, 0, sizeof(int) * _capacity);
//	}
//private:
//	int* _array;
//	int _top;
//	int _capacity;
//};

//int main() {
//	Stack st;
//
//	return 0;
//}


//class A {
//public:
//	A(int n) 
//	:_a(10)
//	,_b(2233)
//	,_c(n){
//	}
//private:
//	const int _a;
//	int _b = 10;//缺省值
//	int& _c;
//};

//构造函数核心--初始化列表
//构造函数完成初始化的功能可以分为两部分：
//1.初始化列表进行的 定义初始化
//2.构造函数体内的对初始化列表已定义变量的初始化，或者说赋值更好
//
//每个类成员变量默认（隐式的）都会经过初始化列表，
//我们也可以显式的在初始化列表中写，
//也就是说，不管我们在初始化列表中是否显式对类成员变量进行定义初始化，成员变量都会在初始化列表被定义初始化
//
//类对象定义时，类成员变量整体 定义初始化
//细化类成员变量的 定义初始化：
//类成员变量的 定义初始化 发生在初始化列表阶段
//即类成员变量在初始化列表进行 定义初始化
//而在构造函数内进行的是类成员变量的赋值和其他必要的操作，故在构造函数内进行的不能称之为 定义初始化 ，只能叫做初始化
// 毕竟一个类成员变量生命周期内只能定义一次
// 
//对于普通变量来说，在不在初始化列表显式定义初始化 都可以，因为普通变量 定义初始化 之后还可以在构造函数内修改
// 
//
//对于定义之后不可修改的变量（const修饰的、引用的）：
//我们必须显式在初始化列表进行定义初始化，而不能在构造函数体内进行初始化，在函数体内称为赋值也许更好理解
//因为所有变量都已经在初始化列表定义初始化过了
//
//对于自定义类型，初始化列表时会调用该类型的默认构造函数，
//如果该类没有默认构造函数我们就需要在初始化列表手动对该自定义类型进行定义初始化，不然就会报错（错误是：找不到该自定义类型的默认构造函数）

//int main() {
//	int x = 100;
//	A a1(x);
//	return 0;
//}

//class B {
//public:
//	/*B(int b=1)//强大的缺省默认构造函数
//	:_b1(b){
//
//	}*/
//	B(int b)//构造函数，需传参
//		:_b1(b) {
//
//	}
//private:
//	int _b1;
//};
//
//class A {
//public:
//	/*A(int n)
//		:_a(10)
//		, _b(2233)
//		, _c(n) {
//	}*/
//	A(int n)
//		: _a(10)
//		, _b(2233)
//		, _c(n) 
//		, _d(1000){
//	}
//private:
//	const int _a;
//	int _b = 10;//缺省值
//	int& _c;
//	B _d;//自定义类型
//};
//
//int main() {
//	int x = 233;
//	A a1(x);
//	return 0;
//}


//class A {
//public:
//	A(int a)
//	:_a1(a)
//	,_a2(_a1){}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
////初始化列表中 变量实际定义初始化 的顺序与变量的声明顺序相同，也就是说变量声明的顺序决定了变量初始化列表初始化的顺序，而与初始化列表中变量书写的顺序无关
////这可能与编译器的底层实现有关
//
//int main() {
//
//	A a(1);
//	a.Print();
//	return 0;
//}

//A没有默认构造
//class A {
//public:
//	A(int a)
//		:_a1(a) {}
//private:
//	int _a1;
//};
//定义B类的对象时会调用B的默认构造，在B的默认构造初始化列表会调用A的默认构造，但A没有默认构造，所以报错，但报的是没有B的默认构造函数；
//不定义B的对象并不会报错，因为没有调用B的默认构造；
//class B {
//public:
//
//private:
//	A _aa;
//};
//
//int main() {
//
//	//A a(1);
//	//B b;
//	return 0;
//}
//对于构造函数的建议：
//尽量使用初始化列表初始化
// 
// 
//类尽量提供默认构造，特别是全缺省的默认构造十分好用


//////////////////////////////////////////////////////////////////////////////////////////////////
//单参数构造函数的隐式类型转换
// C++98
// 
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
//	A a1(10);//构造
//	A a2 = 10;//隐式类型转换 10 --> 匿名临时A类对象 --> a2;构造+拷贝构造
//	//等价于	const A tmp(10); A a2(tmp);
//
//	const A& a3 = 100;//隐式类型转换 ;引用的不是整型100，引用的是临时匿名A类对象
//	//等价于	const A tmp(100); const A a2(tmp);
//
//
//	//A a3(20);//构造
//	//A a4 = a3;//拷贝构造
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
////explicit关键字禁止构造函数相关的隐式累型转换的发生
//int main() {
//	A a1(10);//构造
//	//A a2 = 10;//explicit修饰后禁止隐式类型转换的发生；error
//
//	//const A& a3 = 100;//explicit修饰后禁止隐式类型转换的发生；error
//
//
//	A a4(20);//构造
//	A a5 = a4;//拷贝构造
//	return 0;
//}
//


//#include <string>
//
//void push_back(const string& s) {
//	;
//}
//int main() {
//	string s1("hello");//构造
//	string s2 = "hello";//隐式类型转换，产生临时变量
//
//	push_back(s1);
//	push_back(s2);
//	push_back("hello");//先产生匿名临时string对象，这个匿名临时对象再被引用
//	return 0;
//}


//对单参数构造函数允许隐式类型转换的推广--
// C++11
//多参数且可以只传一个参数堆的构造函数的隐式类型转换

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


//explicit关键字修饰多参数构造函数，禁止隐式类型转换的发生
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

//int main() {
//	A a1(10, 20, 30);//构造
//	A a2 = { 1,2,3 };//构造+拷贝构造 --> 优化为 构造
//	//从结果来说，可以认为A a1(10,20,30) 等价于 A a2 = {1,2,3};
//
//	const A& a3 = { 1,2,3 };//构造
//	return 0;
//}


//////////////////////////////////////////////////////////////////////
//static

//int Count = 0;
//
//class A {
//public:
//	A(int a)
//		:_a(a) {
//		Count++;
//	}
//	A(A& a) {
//		Count;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	A a1(1);//构造
//	A a2 = 1;//构造+拷贝构造 --> 直接构造
//	cout << Count << endl;//Count == 2
//
//	const A& a3 = 1;//构造
//	cout << Count << endl;//Count == 3
//	return 0;
//}



//class A {
//public:
//	A(int a)
//		:_a(a) {
//		Count++;
//	}
//	A(A& a) {
//		Count++;
//		_a = a._a;
//	}
//	static int Count;//声明
//private:
//	int _a;
//};
//
//int A::Count = 0;//定义初始化
//
////传值传参
//void Func1(A a) {
//	;
//}
////传值返回
//A Func2() {
//	A a(1);
//	return a;
//}
////传引用传参
//void Func3(A& a) {
//	;
//}
////传引用返回 - 有问题的引用
//A& Func4() {
//	A a(1);
//	return a;
//}
////传引用返回
//A& Func5() {
//	static A a(1);
//	return a;
//}
//int main() {
//	A a1(1);//构造
//	A a2 = 1;//构造+拷贝构造 --> 直接构造
//	cout << A::Count << endl;//Count == 2
//
//	const A& a3 = 1;//构造
//	cout << A::Count << endl;//Count == 3
//
//	Func1(a1);
//	cout << A::Count << endl;//Count == 4
//	Func2();
//	cout << A::Count << endl;//Count == 6
//	Func3(a1);
//	cout << A::Count << endl;//Count == 6
//	Func4();
//	cout << A::Count << endl;//Count == 7
//	Func5();
//	cout << A::Count << endl;//Count == 8
//
//	//静态的Count 不属于任何一个对象，Count在静态区只有一份，任何一个对象都能访问到Count
//	//下面的三个并不是只是说明Count是在类A域中的Count，起作用的是类型，而不是对象本身
//	//这与成员函数非常相似
//	cout << a1.Count << endl;
//	A* ptr = &a1;
//	cout << ptr->Count << endl;
//	ptr = nullptr;
//	cout << ptr->Count << endl;
//	return 0;
//}

//class A {
//public:
//	A(int a)
//		:_a(a) {
//		Count++;
//	}
//	A(A& a) {
//		Count++;
//		_a = a._a;
//	}
//	int GetCount() {
//		return Count;
//	}
//private:
//	int _a;
//	static int Count;//声明
//};
//
//int A::Count = 0;//定义初始化
//
////传值传参
//void Func1(A a) {
//	;
//}
////传值返回
//A Func2() {
//	A a(1);
//	return a;
//}
////传引用传参
//void Func3(A& a) {
//	;
//}
////传引用返回 - 有问题的引用
//A& Func4() {
//	A a(1);
//	return a;
//}
////传引用返回
//A& Func5() {
//	static A a(1);
//	return a;
//}
//int main() {
//	A a1(1);//构造
//	A a2 = 1;//构造+拷贝构造 --> 直接构造
//	cout << a1.GetCount() << endl;//Count == 2
//
//	const A& a3 = 1;//构造
//	cout << a1.GetCount() << endl;//Count == 3
//
//	Func1(a1);
//	cout << a1.GetCount() << endl;//Count == 4
//	Func2();
//	cout << a1.GetCount() << endl;//Count == 6
//	Func3(a1);
//	cout << a1.GetCount() << endl;//Count == 6
//	Func4();
//	cout << a1.GetCount() << endl;//Count == 7
//	Func5();
//	cout << a1.GetCount() << endl;//Count == 8
//	return 0;
//}

//class A {
//public:
//	A(int a)
//		:_a(a) {
//		Count++;
//	}
//	A(A& a) {
//		Count++;
//		_a = a._a;
//	}
//	//静态成员函数只能调用静态 成员变量和函数，不能调用非静态 成员变量和函数
//	//静态成员函数一般和静态成员变量配合使用
//	static int GetCount() {
//		return Count;
//	}
//private:
//	int _a;
//	static int Count;//声明
//};
//
//int A::Count = 0;//定义初始化
//
////传值传参
//void Func1(A a) {
//	;
//}
////传值返回
//A Func2() {
//	A a(1);
//	return a;
//}
////传引用传参
//void Func3(A& a) {
//	;
//}
////传引用返回 - 有问题的引用
//A& Func4() {
//	A a(1);
//	return a;
//}
////传引用返回
//A& Func5() {
//	static A a(1);
//	return a;
//}
//int main() {
//	A a1(1);//构造
//	A a2 = 1;//构造+拷贝构造 --> 直接构造
//	cout << a1.GetCount() << endl;//Count == 2
//
//	const A& a3 = 1;//构造
//	cout << A::GetCount() << endl;//Count == 3
//
//	Func1(a1);
//	cout << A::GetCount() << endl;//Count == 4
//	Func2();
//	cout << A::GetCount() << endl;//Count == 6
//	Func3(a1);
//	cout << A::GetCount() << endl;//Count == 6
//	Func4();
//	cout << A::GetCount() << endl;//Count == 7
//	Func5();
//	cout << A::GetCount() << endl;//Count == 8
//	return 0;
//}

//影响生命周期的因素
/*
static修饰：在静态区
	局部变量生命周期变为程序运行期间；
	全局变量生命周期为程序运行期间，且影响全局变量的链接属性，使得全局变量只能在本文件中被找到，独属于本文件
全局域：
	在静态区，程序运行期间
局部域：
	在栈区，从进入局部域开始，到出局部域为止
动态申请的空间
	在堆上
常量：
	在常量区，字面值常量，程序运行期间

*/


//要求对象只能在栈上创建
//class A {
//public:
//	static A GetObj(int a) {
//		A aa1(a);
//		return aa1;
//	}
//private:
//	A(int a)
//		:_a(a) {
//	}
//private:
//	int _a;
//};
//
//int main() {
//	/*static A a1(1);
//	A a2(1);
//	A* a3 = new A;*/
//
//	A a4 = A::GetObj(1);
//	return 0;
//}


//友元函数 - friend
//class A {
//public:
//	friend int GetA(A& a);
//	A(int a = 1)
//		:_a(a) {}
//private:
//	int _a;
//};
//
//int GetA(A& a) {
//	return a._a;
//}
//int main() {
//	A a1(10);
//	cout << GetA(a1) << endl;
//	return 0;
//}

//友元类
//class A {
//public:
//	friend class B;
//	A(int a = 1)
//		:_a(a) {}
//private:
//	int _a;
//};
//
//class B {
//public:
//	B(int b)
//		:_b(b){}
//	int Add(A& a) {
//		return _b + a._a;
//	}
//private:
//	int _b;
//};
//
//int main() {
//	A a1(10);
//	B b1(20);
//	cout << b1.Add(a1) << endl;
//	return 0;
//}

////类中类
//class A {
//public:
//	static int x;
//	A(int a = 1)
//		:_a(a){}
//	class B {
//	public:
//		B(int b = 1)
//			:_b(b){}
//		//在B类中能够访问到A类的私有成员
//		void GetA(const A& a) {
//			cout << a._a << endl;
//			cout << x << endl;
//		}
//	private:
//		int _b;
//	};
//private:
//	int _a;
//};
//int A::x = 0;
//
////B不在A类域中，单是访问B类受到A类域和访问限定符的限制
//// 它们其实是嵌套定义，类A并未包含类B，类A与类B相互独立
////内类B天生是外类A的友元类，可以访问到A类任何成员
//
//int main() {
//	cout << sizeof(A) << endl;
//	cout << sizeof(A::B) << endl;
//	return 0;
//}


//匿名对象
//class A {
//public:
//	A(int a = 1)
//		:_a(a){}
//	void Print() {
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//
//int main() {
//	//有名对象
//	A a1;
//	A a2(10);
//	A a3 = 10;
//	//A a4();//error
//
//	//匿名对象
//	//生命周期只有一行，一般作用不大，但有时比较有用：
//	A();
//	A(10);
//
//	//匿名对象用途,优化减少类成员函数调用步骤
//	//原本：只为了调用类内函数而创建类A对象a
//	A a(20);
//	a.Print();
//	//优化
//	A().Print();
//	A(10).Print();
//	return 0;
//}


//编译器的优化 -- 需要记住
// 
//编译器对涉及类的构造和拷贝构造连续的步骤可能会进行优化，省去中间某个步骤，提高效率；
//这就要求我们在与类对象创建时尽可能以少量步骤来完成同样的功能
//这些优化当然是在不影响正确性的前提 下进行的

//class A {
//public:
//	A(int a = 1)
//		:_a(a){
//		cout << "构造函数: A(int a)" << endl;
//	}
//	A(const A& a) {
//		cout << "拷贝构造: A(const A& a)" << endl;
//		_a = a._a;
//	}
//	~A() {
//		cout << "析构函数: ~A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//
//void Func1(A a) {
//	;
//}
//A Func2() {
//	A a(10);
//	return a;
//}
////传值的极致优化
//A Func3() {
//	//A a(10);
//	return A(10);
//}
//int main() {
//	//对 单参数或多参数构造函数的隐式类型转换 可能的优化
//	//A a1 = 10;//构造+拷贝构造 --> 构造
//
//	//对 传参时 可能的优化
//	//A a2(10);
//	//Func1(a2);//先构造在拷贝构造
//
//	//Func1(A(10));//先构造再拷贝构造 --> 直接构造
//
//	//对 函数返回时 可能的优化
//	//Func2();//构造+拷贝构造
//	//A ret = Func2();//构造+拷贝构造+拷贝构造 --> 构造+拷贝构造
//	
//	////下方编译器无法优化
//	//A _ret;
//	//_ret = Func2();//构造+构造+拷贝构造
//
//	//传值返回极致优化
//	A ret = Func3();//构造+拷贝构造+拷贝构造 --> 构造
//}


// 






