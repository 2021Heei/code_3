#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
//#include <iostream>
//#include <cassert>
//#include <cassert>
//using namespace std;
//
//void Swap(int& a, int& b) {
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void Swap(float& a, float& b) {
//	float tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void Swap(char& a, char& b) {
//	char tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main() {
//
//	int a = 1, b = 2;
//	Swap(a, b);
//	float c = 3.14, d = 9.99;
//	Swap(c, d);
//	char e = 'a', f = 'b';
//	Swap(e, f);
//	return 0;
//}

//函数模板
//template<class T>
//void Swap(T& t1, T& t2) {
//	T tmp = t1;
//	t1 = t2;
//	t2 = tmp;
//}
// 
//
////函数模板
//template<typename T>
//void Swap(T& t1, T& t2) {
//	T tmp = t1;
//	t1 = t2;
//	t2 = tmp;
//}

//调用的是函数模板吗？ - 看反汇编
//不是，调用的是三个不同的函数

//函数模板的实例化
//用函数模板生成具体的函数
//int main() {
//
//	int a = 1, b = 2;
//	//Swap<int>(a, b);
//	Swap(a, b);
//	float c = 3.14, d = 9.99;
//	//Swap<float>(c, d);
//	Swap(c, d);
//	char e = 'a', f = 'b';
//	//Swap<char>(e, f);
//	Swap(e, f);
//	return 0;
//}

//int main() {
//
//	int a = 1, b = 2;
//	Swap(a, b);
//	int c = 3, d = 4;
//	Swap(c, d);
//	return 0;
//}

//int main() {
//
//	int a = 1, b = 2;
//	Swap(a, b);
//	int c = 3;
//	char d = 'a';
//	Swap(c, d);
//	return 0;
//}

//template<typename T>
//T Add(const T& t1, const T& t2) {
//	return t1 + t2;
//}
//
//T Add(T& t1, T& t2) {
//	return t1 + t2;
//}
//
//int main() {
//	int a = 1, b = 2;
//	double c = 3.14, d = 9.99;
//	cout << Add(a, b) << endl;
//	cout << Add(c, d) << endl;
//
//	return 0;
//}

//类型与函数模板不匹配，将不会生成具体的函数，即函数模板推导错误
// 而去掉const之后报错，是因为强制类型转换产生了常性临时匿名变量，常变量不能传参给非 常引用类型
//int main() {
//	int a = 1;
//	double b = 3.14;
//	//cout << Add(a, b) << endl;//error
//	cout << Add((double)a, b) << endl;
//	cout << Add(a, (int)b) << endl;
//	return 0;
//}


//int main() {
//	int a = 1, b = 2;
//	double c = 3.14, d = 9.99;
//	//自动推演实例化
//	cout << Add(a, b) << endl;
//	cout << Add(c, d) << endl;
//
//	//显式实例化
//	cout << Add<int>(a, b) << endl;
//	cout << Add<double>(c, d) << endl;
//
//	//显示实例化+隐式类型转换
//	cout << Add<int>(c, d) << endl;
//	return 0;
//}

//多参函数模板
//函数模板参数定义类型
//函数参数定义变量名
//template<typename T1, typename T2>
//T1 Add(const T1& t1, const T2& t2) {
//	return t1 + t2;
//}
//
//int main() {
//	int a = 1, b = 2;
//	double c = 3.14, d = 9.99;
//	////自动推演实例化
//	//cout << Add(a, b) << endl;
//	//cout << Add(c, d) << endl;
//
//	cout << Add(a, c) << endl;
//	cout << Add(c, a) << endl;
//	return 0;
//}

//具体函数和函数模板都存在时，优先调用具体函数而不是函数模板
//如果我们显式使用函数模板生成的具体函数也是可以正常运行得到结果的
//这说明我们实现的具体函数和函数模板推导生成的具体函数是不同的函数，函数地址不同
//即我们写的具体函数与函数模板推导生成的具体函数的函数名修饰规则是不同的，否则会报错
// 所以编译器的原则是在最满足匹配时，优先调用显式实现的，
// 
//int Add(const int& t1, const int& t2) {
//	return t1 + t2;
//}
//template<typename T>
//T Add(const T& t1, const T& t2) {
//	return t1 + t2;
//}
//
//int main() {
//	int a = 1, b = 2;
//	//调用我们实现的Add函数
//	Add(a, b);
//	//指定使用函数模板推导生成的Add函数
//	Add<int>(a, b);
//	return 0;
//}

//类模板

//typedef int STDataType;
//class Stack {
//public:
//	Stack(int capacity = 4)
//		:_size(0)
//		, _capacity(capacity) {
//		_a = (STDataType*)malloc(sizeof(STDataType)*_capacity);
//		assert(_a);
//	}
//
//	~Stack() {
//		delete[] _a;
//		_size = _capacity = 0;
//	}
//
//	void Push(int val) {
//		if (_size == _capacity) {
//			_capacity = _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_a, sizeof(STDataType) * _capacity);
//			assert(tmp);
//			_a = tmp;
//		}
//		_a[_size++] = val;
//
//	}
//private:
//	STDataType* _a;
//	int _size;
//	int _capacity;
//};
//
//int main() {
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//
//	Stack st2;
//	st2.Push(1.1);
//	st2.Push(2.1);
//	st2.Push(3.1);
//	return 0;
//}
// 

//解决typedef和宏遇到的问题
//template<typename T>
//class Stack {
//public:
//	Stack(int capacity = 4)
//		:_size(0)
//		, _capacity(capacity) {
//		_a = (T*)malloc(sizeof(T) * _capacity);
//		assert(_a);
//	}
//
//	~Stack() {
//		delete[] _a;
//		_size = _capacity = 0;
//	}
//
//	void Push(const T& val) {
//		if (_size == _capacity) {
//			_capacity = _capacity * 2;
//			T* tmp = (T*)realloc(_a, sizeof(T) * _capacity);
//			assert(tmp);
//			_a = tmp;
//		}
//		_a[_size++] = val;
//
//	}
//private:
//	T* _a;
//	int _size;
//	int _capacity;
//};
//
////类模板一般没有推演时机，这与函数模板通过实参推演模板参数不同
////模板参数不同，同一类模板实例化出来的多个类的类型就各不相同
//int main() {
//	Stack<int> st1;
//	st1.Push(1);
//	st1.Push(2);
//
//	Stack<double> st2;
//	st2.Push(1.1);
//	st2.Push(2.1);
//	//是完全不同的类型，不存在隐式类型转换
//	//st2 = st1;//error
//	return 0;
//}

//template有范围


//练习
//#define N 10

//template<typename T>
//class Array {
//public:
//	T& operator[](size_t i) {
		/*编译器对数组下标越界的检查是抽查，在数组边界写容易检查出来，远离数组边界的越界写不容易检查出来；在数组边界读和远离数组边界读基本不被检查出来
		可以主动进行强制检查，防止数组下边越界*/
//
//		assert(i < 10);
//		return _a[i];
//	}
//private:
//	T _a[N];
//};

//定义在命名空间中，防止和库里面的类名冲突
//namespace weihe {
//	template<typename T>
//	class Array {
//	public:
//		T& operator[](size_t i) {
//			//编译器对数组下标越界的检查是抽查，在数组边界写容易检查出来，远离数组边界的越界写不容易检查出来；在数组边界读和远离数组边界读基本不被检查出来
//			//可以主动进行强制检查，防止数组下边越界
//
//			assert(i < 10);
//			return _a[i];
//		}
//	private:
//		T _a[N];
//	};
//}

//int main() {
//	weihe::Array<int> a;
//	for (int i = 0; i < 10; ++i) {
//		a[i] = i;
//	}
//	for (int i = 0; i < 10; ++i) {
//		cout << a[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < 10; ++i) {
//		a[i] *= 10;
//	}
//	for (int i = 0; i < 10; ++i) {
//		cout << a[i] << " ";
//	}
//	cout << endl;
//
//	//a[10];
//	//a[20] = 1;
//	return 0;
//}

//名字冲突问题解决思路
//命名空间的作用


//注意：模板一般不分离编译（声明和定义分离A）

//template<typename T>
//class Stack {
//public:
//	Stack(int capacity = 4)
//		:_size(0)
//		, _capacity(capacity) {
//		_a = (T*)malloc(sizeof(T) * _capacity);
//		assert(_a);
//	}
//
//	~Stack() {
//		delete[] _a;
//		_size = _capacity = 0;
//	}
//
//	void Push(const T& val) {
//		if (_size == _capacity) {
//			_capacity = _capacity * 2;
//			T* tmp = (T*)realloc(_a, sizeof(T) * _capacity);
//			assert(tmp);
//			_a = tmp;
//		}
//		_a[_size++] = val;
//
//	}
//private:
//	T* _a;
//	int _size;
//	int _capacity;
//};

//类模板一般没有推演时机，这与函数模板通过实参推演模板参数不同
//模板参数不同，同一类模板实例化出来的多个类的类型就各不相同
//int main() {
//	//Stack<int> 与Stack<double>是不同的类型
//	Stack<int> st1;
//	st1.Push(1);
//
//	Stack<double> st2;
//	st2.Push(1.1);
//	return 0;
//}