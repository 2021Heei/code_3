//��������
#include <iostream>
using namespace std;
//
//#define ADD(x,y) ((x) + (y))
////��Ϊʲô�������ͣ� - 
////��ΪʲôҪ�Ӷ�����ţ� - ��ֹ��������ȼ��Ժ��߼���Ӱ��
////��Ϊʲô���ܼӷֺţ� - ������Ӧ�ڶ������
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
//////inline int Add(int a, int b);  Ԥ����ʱ�����滻
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

////������������
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

////������������
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



////�����������
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


////������������
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


////11�д������
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
//	const pstring p1  = &ch; // ����ɹ�����ʧ�ܣ�
//	const pstring* p2 ; // ����ɹ�����ʧ�ܣ�
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
//	int* p1 = array;//������Ԫ�صĵ�ַ
//	for (auto e : p1)//error
//		cout << e << " "
//		cout << endl;
//
//	int(*p2)[10] = &array;//��������ĵ�ַ
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