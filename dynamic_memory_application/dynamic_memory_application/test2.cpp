#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//namespace weihe{
//	template<typename T>
//	void swap(T& a, T& b) {
//		T tmp = a;
//		a = b;
//		b = tmp;
//	}
//}
////template <class T1,typename T2>
//
//
//
//int main() {
//	 
//	int a = 0, b = 1;
//	weihe::swap(a, b);
//	return 0;
//}


///////////////////////////////////////////////////////////////////////////////////////////////////////
//内置类型

//int main() {
//	//new和delete是运算符
//	//内置类型，相比malloc/free，除了用法的区别，没有其他区别
//	int* p1 = new int;
//	delete p1;
//
//	int* p2 = new int(0);
//	delete p2;
//
//	int* p3 = new int[10];
//	delete[] p3;
//	int* p4 = new int[10]{ 1,2,3,4 };
//	delete[] p4;
//	return 0;
//}


//自定义类型
//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "构造函数: A(int a)" << endl;
//	}
//	~A() {
//		cout << "析构函数: ~A()" << endl;
//	}
//private:
//	int _a;
//};
//int main() {
//	//new和delete除了会开辟内存和释放空间，还会分别调用自定义类型的构造函数和析构函数
//	A* p1 = new A;
//	A* p2 = (A*)malloc(sizeof(A));
//	delete p1;
//	free(p2);
//	return 0;
//}

//struct ListNode {
//	int _val;
//	ListNode* _next;
//
//	ListNode(int val = 0) 
//		:_val(val), _next(nullptr) {
//		//cout << "构造函数: ListNode(int val = 0)" << endl;
//	}
//	~ListNode() {
//		_val = 0;
//		_next = nullptr;
//		cout << "析构函数: ~ListNode()" << endl;
//	}
//};
//
//int main() {
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//	ListNode* n4 = new ListNode(4);
//	n1->_next = n2;
//	n2->_next = n3;
//	n3->_next = n4;
//	delete n1;
//	delete n2;
//	delete n3;
//	delete n4;
//	return 0;
//}


//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "构造函数: A(int a)" << endl;
//	}
//	/*~A() {
//		cout << "析构函数: ~A()" << endl;
//	}*/
//	~A() { cout << "*"; }
//private:
//	int _a;
//};
//
////new和delete要匹配，不匹配可能报错，也可能不报错，不同的编译器的反应也不尽相同
//int main() {
//	//new了一个，delete了多个
//	//A* p1 = new A;
//
//	//delete[] p1;//析构函数显式存在就error
//	//free(p1);//不一定报错
//	//delete p1;//true
//
//	//new了多个，delete了一个
//	A* p2 = new A[10];
//	//delete[] p2;//true
//	//delete p2;//VS下析构函数不显式实现就不报错，显式实现就error；不同编译器也不相同
//	return 0;
//}

//malloc/free与new/delete的区别

//int main() {
//	////malloc失败，返回空指针
//	//while (1) {
//	//	int* p1 = (int*)malloc(sizeof(int) * 1024 * 10);
//	//	if (p1) {
//	//		cout << p1 << endl;
//	//	}
//	//	else {
//	//		cout << "malloc fail" << endl;
//	//		break;
//	//	}
//	//}
//
//	//new失败，抛异常
//	try {
//		while (1) {
//			int* p1 = new int[1024 * 10];
//			if (p1) {
//				cout << p1 << endl;
//			}
//			else {
//				cout << "malloc fail" << endl;
//				break;
//			}
//		}
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//int main() {
//	//new失败，抛异常
//	try {
//		while (1) {
//			char* p1 = new char[1024 * 1024 * 1024];
//			cout << (void*)p1 << endl;
//		}
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//new的底层 -- operator new
//operator new不是new的重载，即不是运算符重载函数，而是一个特殊的函数
//没有自定义类型形参，是库里面实现的全局函数

//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "构造函数: A(int a)" << endl;
//	}
//	~A() {
//		cout << "析构函数: ~a()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	
// 看反汇编有operator new调用
// 
//	int* p2 = new int;
//	delete p2;
//	A* p1 = new A;
//	delete p1;
//	return 0;
//}

//operator new
//int main() {
//	//new失败，抛异常
//	try {
//		while (1) {
//			//char* p1 = new char[1024 * 1024 * 1024];
//			char* p1 = (char*)operator new(1024 * 1024 * 1024);
//			cout << (void*)p1 << endl;
//		}
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}


//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "构造函数: A(int a)" << endl;
//	}
//	~A() {
//		cout << "析构函数: ~a()" << endl;
//	}
//private:
//	int _a;
//};
//
////operator new[]
//int main() {
//	A* p1 = new A;
//	delete p1;
//
//	A* p2 = new A[10];
//	delete p2;
//	return 0;
//}


//定位new
//为已申请的空间调用构造函数

//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "构造函数: A(int a)" << endl;
//	}
//	~A() {
//		cout << "析构函数: ~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	
//	A* p1 = new A;
//	delete p1;
//
//	A* p2 = (A*)malloc(sizeof(A));
//	if (p2 == nullptr) {
//		perror("malloc fail");
//		exit(-1);
//	}
//	new(p2)A(2);
//	/*p2->~A();
//	free(p2);*/
//	delete p2;
//
//	return 0;
//}


//定位new用法 -- 对从内存池申请的空间进行初始化

//面试题 - 理解记忆
//malloc和new的区别 -- 用法功能 -- 底层

//指针和引用的区别

