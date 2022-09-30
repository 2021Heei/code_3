#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int a = 0;
//double a = 0;
//int main() {
//
//	printf("%d\n", a);
//	return 0;
//}

//#include <iostream>
//
//namespace N1 {
//	int a = 0;
//}
//namespace N2 {
//	int a = 0;
//}
//
//int main() {
//	printf("%d\n", N1::a);
//	printf("%d\n", N2::a);
//	return 0;
//}

//#include <iostream>
//namespace weihe {
//	int a = 0;
//
//	int Add(int a, int b) {
//		return a + b;
//	}
//
//	struct ListNode {
//		int data;
//		struct ListNode* next;
//	};
//}
//
//int main() {
//	int rand = 1;
//	std::cout << &weihe::a << std::endl;
//	std::cout << weihe::Add << std::endl;
//	return 0;
//}

////命名空间的嵌套
//#include <iostream>
//
//namespace N1 {
//	int a = 0;
//	int Add(int a, int b) {
//		return a + b;
//	}
//
//	namespace N2 {
//		int a = 0;
//		int Add(int x, int y) {
//			return x + y;
//		}
//	}
//}
//
//int main() {
//	int rand = 1;
//	std::cout << &N1::a << std::endl;
//	std::cout << &N1::N2::a << std::endl;
//	std::cout << N1::Add << std::endl;
//	std::cout << N1::N2::Add << std::endl;
//	return 0;
//}


//#include <iostream>
//namespace N1 {
//	int a = 0;
//	int Add(int a, int b) {
//		return a + b;
//	}
//}
//
//namespace N1 {
//	int a = 0;
//	int Sub(int a, int b) {
//		return a - b;
//	}
//}
//
//int main() {
//
//	return 0;
//}

////命名空间 - 部分展开
//#include <iostream>
//using std::cout;
//using std::endl;
//
//int main() {
//	cout << "hello!" << endl;
//	std::cout << "hello!" << std::endl;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int a;
//	double d;
//	char c;
//	cin >> a >> d >> c;
//	cout <<"int: " << a << " " << "double: " << d << 
//		" " << " char: " << c << " " << endl;
//	return 0;
//}

//#include<iostream>
//// std是C++标准库的命名空间名，C++将标准库的定义实现都放到这个命名空间中
//using std::cout;
//using std::endl;
//int main() {
//
//    cout << "Hello world!" << endl;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//void function(int val = 0) {
//	cout << val << endl;
//}
//
//int main() {
//	function();
//	function(10);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//void function(int val) {
//	cout << val << endl;
//}
//
//int main() {
//	function();//函数需要接受一个int型参数，否则报错
//	function(10);
//	return 0;
//}


//缺省形参参数 - 全缺省 - 部分缺省
//#include <iostream>
//using namespace std;
//
//void Func(int a = 10) {
//	cout << a << endl;
//}
//
//int main() {
//	Func();
//	Func(100);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//void Func(int a, int b = 0, int c = 0) {
//	cout << "a " << a << endl;
//	cout << "b " << b << endl;
//	cout << "c " << c << endl;
//}
//
//int main() {
//	Func(100);
//	Func(100, 200);
//	Func(100, 200, 300);
//	return 0;
//}


//#include <stdio.h>
//
//int Add(int a, int b) {
//	return a + b;
//}
//
//double Add(double x, double y) {
//	return x + y;
//}
//
//int main() {
//	
//	return 0;
//}


////函数重载 - 一词多义
//#include <iostream>
//using namespace std;
//
//int add(int a, int b) {
//	return a + b;
//}
//
//double add(double x, double y) {
//	return x + y;
//}
//
//
//int main() {
//	cout << add(10, 20) << endl;
//	cout << add(10.2, 20.3) << endl;
//	return 0;
//}

////函数重载 - 一词多义
//#include <iostream>
//using namespace std;
//
//int add(int a, int b) {
//	return a + b;
//}
//
//double add(double x, double y) {
//	return x + y;
//}
//
//void swap(int* pa, int* pb) {
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//
//void swap(double* pa, double* pb) {
//	double tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//
//int main() {
//	cout << add(10, 20) << endl;
//	cout << add(10.2, 20.3) << endl;
//
//	int a = 10, b = 20;
//	swap(&a, &b);
//	double x = 30.3, y = 40.4;
//	swap(&x, &y);
//	cout << a << " " << b << endl;
//	cout << x << " " << y << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//void func() {
//	cout << "func()" << endl;
//}
//
//void func(int a) {
//	cout << "func(int a)" << endl;
//}
//
//int main() {
//	func();
//	func(10);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//void func(int a) {
//	cout << "func(int a)" << endl;
//}
//
//void func(double a) {
//	cout << "func(doublea)" << endl;
//}
//
//int main() {
//
//	func(10);
//	func(3.14);
//	return 0;
//}

//#include <stdio.h>
//
//int Add(int x, int y) {
//	return x + y;
//}
//
//
//int main() {
//
//	return 0;
//}

int Add(int a, int b) {
	return a + b;
}

void fun(int a, double b) {
	printf("%d %.2ld\n", a, b);
}

