#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdbool>
using namespace std;


//class Date {
//public:
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
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
//bool operator==(Date& d1, Date& d2) {
//	return d1.GetYear() == d2.GetYear() &&
//		d1.GetMonth() == d2.GetMonth() &&
//		d1.GetDay() == d2.GetDay();
//}
//
//int main() {
//	Date d1(1);
//	Date d2(2);
//	cout << (d1 == d2) << endl;
//	return 0;
//}

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


//int main() {
//	//匿名对象
//	//生命周期只有一行，一般作用不大，但有时比较有用：
//	int();//这个匿名整型变量是0
//	int(10);
//	A();
//	A(10);
//	cout << int() << endl;
//	cout << int(10) << endl;
//	A().Print();
//	A(10).Print();
//	return 0;
//}

//class A {
//public:
//	A(int a = 1)
//		:_a(a) {
//		cout << "构造函数: A(int a)" << endl;
//	}
//	A(const A& a) {
//		cout << "拷贝构造: A(const A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
//
//void Func1(A a) {
//	;
//}
//int main() {
//	//对 传参时 可能的优化
//	A a2(10);
//	Func1(a2);//先构造在拷贝构造
//
//	Func1(A(10));//先构造再拷贝构造 --> 直接构造
//	A();
//}

//class A {
//public:
//	A(int a = 1)
//		:_a(a) {
//		cout << "构造函数: A(int a)" << endl;
//	}
//	~A() {
//		cout << "析构函数: ~A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//
////定位new
////为已申请的空间调用构造函数
//int main() {
//
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A(2);//定位new
//	p1->~A();
//	free(p1);
//	//或delete p1;
//	return 0;
//}

//template <class T>
//void Swap(T& a, T& b) {
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main() {
//	int a = 1, b = 2;
//	Swap(a, b);
//	double c = 3.14, d = 1.34;
//	Swap(c, d);
//}

template<typename T>
class A {
public:
	A(T a)
		:_a(a) {
		cout << "构造函数" << endl;
	}
private:
	T _a;
};

int main() {
	A<int> aa1(10);
	A<double> aa2(3.14);
	return 0;
}






