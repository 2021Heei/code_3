//内联函数
#include <iostream>
using namespace std;
//
//#define ADD(x,y) ((x) + (y))
////宏为什么不加类型？ - 
////宏为什么要加多个括号？ - 防止运算符优先级对宏逻辑的影响
////宏为什么不能加分号？ - 便于适应于多个场景
//
//inline int Add(int a, int b) {
//	return a + b;
//}
//
//int main() {
//
//	return 0;
//}

//#include "Add.h"
//////inline int Add(int a, int b);  预处理时进行替换
////#include <iostream>
////inline int Add(int a, int b) {
////	return a + b;
////}
//
//int main() {
//	int a = 10;
//	int ret = Add(4, 5);
//	return 0;
//}

////交换两个整数
//void Swap(int* x, int* y) {
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//#define SWAP(x, y) int tmp = x;\
//					x = y;\
//					y = tmp
//
//
//#define ADD(x, y) ((x) + (y))
//
//int main() {
//	int a = 10;
//	int b = 20;
//	//SWAP(a, b);
//	SWAP(a, 10);
//
//	return 0;
//}

////交换两个整数
//void Swap(int* x, int* y) {
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//
//
//int main() {
//	int a = 10;
//	int b = 20;
//	Swap(&a, &b);
//
//	return 0;
//}



////两个整数相加
//int Add(int a, int b) {
//	return a + b;
//}

//#define ADD(x, y) ((x) + (y))


//int main() {
//
//	int a = 10;
//	int b = 20;
//	int ret = ADD(a, b);
//	return 0;
//}

//#define SWAP(x, y) int tmp = x;\
//					x = y;\
//					y = tmp
//
//
//int main() {
//
//	int a = 10;
//	int b = 20;
//	SWAP(a, b);
//	return 0;
//}


////交换两个整数
//inline void Swap(int* x, int* y) {
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//int main() {
//
//	int a = 10;
//	int b = 20;
//	Swap(&a, &b);
//	return 0;
//}


////11行代码输出
//inline void function() {
//	cout << "hello C++!\n" << endl;
//	cout << "hello C++!\n" << endl;
//	cout << "hello C++!\n" << endl;
//	cout << "hello C++!\n" << endl;
//	cout << "hello C++!\n" << endl;
//	cout << "hello C++!\n" << endl;
//	cout << "hello C++!\n" << endl;
//	cout << "hello C++!\n" << endl;
//	cout << "hello C++!\n" << endl;
//	cout << "hello C++!\n" << endl;
//	cout << "hello C++!\n" << endl;
//}
//
//int main() {
//
//	function();
//	return 0;
//}

//#include "Add.h"
//#include <iostream>
//using namespace std;
//
//int Add(int a, int b);
//int main() {
//
//	int ret = Add(10, 20);
//	return 0;
//}

//typedef char* pstring;
//int main()
//{	
//	char ch = 'a';
//	const pstring p1  = &ch; // 编译成功还是失败？
//	const pstring* p2 ; // 编译成功还是失败？
//	return 0;
//}

//int main() {
//	int a = 10;
//	auto b = a;
//	auto c = &a;
//	auto* d = &a;
//	auto& e = a;
//	//auto f;
//	cout << "a: " << a << endl;
//	cout << "b: " << b << endl;
//	cout << "c: " << c << endl;
//	cout << "d: " << d << endl;
//	cout << "e: " << e << endl;
//	return 0;
//}

//int main() {
//	int a = 10;
//	auto b = a;
//	auto c = &a;
//	auto* d = &a;
//	auto& e = a;
//	//auto f;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//	return 0;
//}

//int main() {
//	int a = 10;
//	auto b = 1, * c = &a, & e = a;
//	//auto d = 10, f = 3.14;//error
//
//	cout << "a: " << a << endl;
//	cout << "b: " << b << endl;
//	cout << "c:  " << c << endl;
//	cout << "&a: " << &a << endl;
//	cout << "e: " << e << endl;
//	return 0;
//}


//int main() {
//
//	int array[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
//		cout << array[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}
//
//int main() {
//
//	int array[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (auto e : array) {
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//
//int main() {
//
//	int array[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (auto& e : array) {
//		if (e == 8)
//			continue;
//		e *= 2;
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


//int main() {
//
//	int array[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p1 = array;//数组首元素的地址
//	for (auto e : p1)//error
//		cout << e << " "
//		cout << endl;
//
//	int(*p2)[10] = &array;//整个数组的地址
//	for (auto e : p2)//error
//		cout << e << " "
//		cout << endl;
//	return 0;
//}

//void func(int)
//{
//	cout << "f(int)" << endl;
//}
//void func(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	func(0);
//	func(NULL);
//	func((int*)NULL);
//	return 0;
//}

void func(int)
{
	cout << "f(int)" << endl;
}
void func(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	func(0);
	func(nullptr);
	func((int*)NULL);
	return 0;
}