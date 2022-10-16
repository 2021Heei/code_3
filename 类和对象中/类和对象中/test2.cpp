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

//class A {
//public:
//	A(int a = 1):_a(a){}
////private:
//	int _a;
//	static int _b;
//};
//
//int A::_b = 0;
//
//int main() {
//	A aa;
//	cout << A::_b << endl;
//	cout << aa._b << endl;
//	return 0;
//}

//class A {
//public:
//	A(int a = 1) :_a(a) {}
//	//静态成员函数
//	static void Function1() {
//		cout << _b << endl;
//	}
//	//非静态成员函数
//	void Function2() {
//		cout << _a << " " << _b << endl;
//	}
//private:
//	int _a;
//	static int _b;
//};
//int A::_b = 0;
//int main() {
//
//	A aa;
//	aa.Function1();
//	A::Function1();
//
//	aa.Function2();
//	//A::Function2();//error
//	return 0;
//}


//int Count = 0;
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
//private:
//	int _a;
//};
//
//int main() {
//	A a1(1);//构造
//	cout << Count << endl;//Count == 1
//	A a2 = 1;//构造+拷贝构造 --> 直接构造
//	cout << Count << endl;//Count == 2
//
//	const A& a3 = 1;//构造
//	cout << Count << endl;//Count == 3
//	return 0;
//}


//class a {
//public:
//	a(int a)
//		:_a(a) {
//		count++;
//	}
//	a(a& a) {
//		_a = a._a;
//		count++;
//	}
//	static int count;//声明
//private:
//	int _a;
//};
//
//int a::count = 0;//定义初始化
//
////传值传参
//void func1(a a) {
//	;
//}
////传值返回
//a func2() {
//	a a(1);
//	return a;
//}
////传引用传参
//void func3(a& a) {
//	;
//}
////传引用返回 - 有问题的引用
//a& func4() {
//	a a(1);
//	return a;
//}
////传引用返回
//a& func5() {
//	static a a(1);
//	return a;
//}
//int main() {
//	a a1(1);//构造
//	a a2 = 1;//构造+拷贝构造 --> 直接构造
//	cout << a::count << endl;//count == 2
//
//	const a& a3 = 1;//构造
//	cout << a::count << endl;//count == 3
//
//	func1(a1);
//	cout << a::count << endl;//count == 4
//	func2();
//	cout << a::count << endl;//count == 6
//	func3(a1);
//	cout << a::count << endl;//count == 6
//	func4();
//	cout << a::count << endl;//count == 7
//	func5();
//	cout << a::count << endl;//count == 8
//
//静态的count 不属于任何一个对象，count在静态区只有一份，任何一个对象都能访问到count
//下面的三个并不是只是说明count是在类a域中的count，起作用的是类型，而不是对象本身
//这与成员函数非常相似
//	cout << a1.count << endl;
//	a* ptr = &a1;
//	cout << ptr->count << endl;
//	ptr = nullptr;
//	cout << ptr->count << endl;
//	return 0;
//}


//class A {
//public:
//	A(int a)
//		:_a(a) {
//	}
//	static int _b;//声明
//private:
//	int _a;
//};
//int A::_b = 0;//定义初始化
//
//int main() {
//	A a1(1);//构造
//	cout << A::_b << endl;
//	cout << a1._b << endl;
//	A* ptr = &a1;
//	cout << ptr->_b << endl;
//	ptr = nullptr;
//	cout << ptr->_b << endl;
//	return 0;
//}



//class A {
//public:
//	A(int a):_a(a) {
//		Count++;
//	}
//	A(A& a) {
//		_a = a._a;
//		Count++;
//	}
//	static int Count;//声明
//private:
//	int _a;
//};
//int A::Count = 0;//定义初始化
////传值返回
//A Func2() {
//	A a(1);//构造
//	return a;//拷贝构造
//}
//int main() {
//	A a1(1);//构造
//	cout << A::Count << endl;//Count == 1
//	Func2();
//	cout << A::Count << endl;//Count == 3
//	return 0;
//}


//class A {
//public:
//	A(int a) :_a(a) {
//		Count++;
//	}
//	A(A& a) {
//		_a = a._a;
//		Count++;
//	}
//	static int Count;//声明
//private:
//	int _a;
//};
//int A::Count = 0;//定义初始化
////传引用传参
//void Func3(A& a) {
//	;
//}
//int main() {
//	A a1(1);//构造
//	cout << A::Count << endl;//Count == 1
//	Func3(a1);
//	cout << A::Count << endl;//Count == 1
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
//int A::Count = 0;//定义初始化
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
//	cout << A::Count << endl;//Count == 1
//	A a1(1);//构造
//	cout << A::Count << endl;//Count == 2
//	Func4();
//	cout << A::Count << endl;//Count == 3
//	Func5();
//	cout << A::Count << endl;//Count == 3
//	return 0;
//}


//class A {
//public:
//	A(int a):_a(a) {
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
//int A::Count = 0;//定义初始化
//
//static A a(1);
////传引用返回
//A& Func5() {
//	return a;
//}
//int main() {
//	cout << A::Count << endl;//Count == 1
//	Func5();
//	cout << A::Count << endl;//Count == 1
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
//	static int GetCount() {
//		return Count;
//	}
//private:
//	int _a;
//	static int Count;//声明
//};
//
//int A::Count = 0;//定义初始化
//int main() {
//	A a(10);
//	cout << A::GetCount() << endl;
//	return 0;
//}

//class Date {
//public:
//	friend ostream& operator<<(ostream& output, const Date& d);
//	friend istream& operator>>(istream& input, Date& d);
//	Date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day){}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream & operator<<(ostream & output, const Date & d) {
//	output << d._year << "/" << d._month << "/" << d._day << endl;
//	return output;
//}
//istream& operator>>(istream& input, Date& d) {
//	input >> d._year >> d._month >> d._day;
//	return input;
//}
//int main() {
//	Date d(2022,10,15);
//	cout << d << endl;
//	return 0;
//}


//class A {
//public:
//    friend class B;
//    friend void Function(const A& a, const B& b);
//private:
//    int _a = 1;
//};
//
//class B {
//public:
//    friend void Function(const A& a, const B& b);
//private:
//    int _b = 1;
//};
//
//void Function(const A& a, const B& b) {
//    cout << a._a << endl;
//    cout << b._b << endl;
//}
//
//int main() {
//    A a;
//    B b;
//    Function(a, b);
//    return 0;
//}

////要求对象只能在栈上创建
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
//	A a = A::GetObj(1);
//	return 0;
//}


//class A {
//public:
//    friend class B;
//private:
//    int _a = 1;
//};
//
//class B {
//public:
//    void Function(const A& a) {
//        cout << a._a << endl;
//        cout << _b << endl;
//    }
//private:
//    int _b = 2;
//};
//
//int main() {
//    A a;
//    B b;
//    b.Function(a);
//    return 0;
//}


//class A {
//public:
//
//    class B {
//    public:
//        void Function(A& aa) {
//            cout << aa._a << endl;
//            cout << _b << endl;
//        }
//    private:
//        int _b = 2;
//    };
//
//private:
//    int _a = 1;
//};
//
//int main() {
//    A a;
//    A::B b;
//    b.Function(a);
//    return 0;
//}


//class A {
//public:
//    static int count;
//    class B {
//    public:
//        void Function() {
//            cout << count << endl;
//            cout << _b << endl;
//        }
//    private:
//        int _b = 2;
//    };
//
//private:
//    int _a = 1;
//};
//int A::count = 0;
//int main() {
//
//    A::B b;
//    b.Function();
//    return 0;
//}

//class A {
//public:
//    class B {
//    public:
//        void Function(const A& aa) {
//            cout << aa._a << endl;
//            cout << _b << endl;
//        }
//    private:
//        int _b = 2;
//    };
//
//private:
//    int _a = 1;
//};
//
//int main() {
//
//    A::B b;
//    cout << sizeof(A) << endl;
//    cout << sizeof(A::B) << endl;
//    return 0;
//}


////匿名对象
//class A {
//public:
//	A(int a = 1)
//		:_a(a) {}
//	void Print() {
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//
//int main() {
//	//匿名对象
//	//生命周期只有一行，一般作用不大，但有时比较有用：
//	int();
//	int(10);
//	A();
//	A(10);
//	cout << int() << endl;
//	cout << int(10) << endl;
//	A().Print();
//	A(10).Print();
//	return 0;
//}

//int main() {
//	int ret = int();
//	//匿名对象
//	//生命周期只有一行，一般作用不大，但有时比较有用：
//	A();
//	A(10);
//
	////匿名对象用途,优化减少类成员函数调用步骤
	////原本：只为了调用类内函数而创建类A对象a
	//A a(20);
	//a.Print();
	////优化
	//A().Print();
	//A(10).Print();
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
//	A a1 = 10;//构造+拷贝构造 --> 构造
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



//class A {
//public:
//	A(int a = 1):_a(a) {
//		cout << "构造函数: A(int a)" << endl;
//	}
//	A(const A& a) {
//		cout << "拷贝构造: A(const A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//void Func1(A a) {
//	;
//}
//int main() {
//	//对 传参时 可能的优化
//	A a2(10);
//	Func1(a2);//先构造在拷贝构造
//	Func1(A(10));//先构造再拷贝构造 --> 直接构造
//}

//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "构造函数: A(int a)" << endl;
//	}
//	A(const A& a) {
//		cout << "拷贝构造: A(const A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//int main() {
//
//	//对 单参数或多参数构造函数的隐式类型转换 可能的优化
//	A a1 = 10;//构造+拷贝构造 --> 构造
//}


class A {
public:
	A(int a = 1)
		:_a(a){
		cout << "构造函数: A(int a)" << endl;
	}
	A(const A& a) {
		cout << "拷贝构造: A(const A& a)" << endl;
		_a = a._a;
	}
private:
	int _a;
};
A Func2() {
	A a(10);
	return a;
}
int main() {
	//编译器无法优化
	A _ret; //构造
	_ret = Func2();//构造+拷贝构造
}


