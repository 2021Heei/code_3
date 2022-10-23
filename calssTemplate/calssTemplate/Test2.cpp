#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cassert>
#include <cassert>
using namespace std;

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

////函数模板
//template<class T>
//void Swap(T& t1, T& t2) {
//	T tmp = t1;
//	t1 = t2;
//	t2 = tmp;
//}


////函数模板
//template<typename T>
//void Swap(T& t1, T& t2) {
//	T tmp = t1;
//	t1 = t2;
//	t2 = tmp;
//}

//int main() {
//
//	/*int a = 1, b = 2;
//	cout << "前: " << a << " " << b << endl;
//	Swap(a, b);
//	cout << "后: " << a << " " << b << endl;
//	float c = 3.14, d = 9.99;
//	cout << "前: " << c << " " << d << endl;
//	Swap(c, d);
//	cout << "后: " << c << " " << d << endl;*/
//
//	int a = 1, b = 2;
//	Swap(a, b);
//
//	float c = 3.14, d = 9.99;
//	Swap(c, d);
//
//	return 0;
//}
//
//void Swap(int& t1, int& t2) {
//	int tmp = t1;
//	t1 = t2;
//	t2 = tmp;
//}
//
//void Swap(float& t1, float& t2) {
//	float tmp = t1;
//	t1 = t2;
//	t2 = tmp;
//}

//template<typename T>
//T Add(const T& t1, const T& t2) {
//	return t1 + t2;
//}
//
//int main() {
//	int a = 1, b = 2;
//	double c = 3.14, d = 9.99;
//	Add(a, b);
//	Add(c, d);
//	cout << Add(a, b) << endl;
//	cout << Add(c, d) << endl;
//
//	return 0;
//}

//template<typename T>
//T Add(const T& t1, const T& t2) {
//	return t1 + t2;
//}
//
//int main() {
//	int a = 1, b = 2;
//	double c = 3.14, d = 9.99;
//	Add<int>(a, b);
//	Add<double>(c, d);
//
//	return 0;
//}

//template<typename T>
//T Add(const T& t1, const T& t2) {
//	return t1 + t2;
//}
//
//int main() {
//
//	int a = 1;
//	double b = 3.14;
//	cout << Add(a, (int)b) << endl;
//	cout << Add((double)a, b) << endl;
//	return 0;
//}


//int main() {
//
//	int a = 1;
//	double b = 3.14;
//	cout << Add<int>(a, b) << endl;;
//	cout << Add<double>(a, b) << endl;;
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
//	int a = 1;
//	double b = 3.14;
//	Add(a, b);
//    Add(b, a);
//	cout << Add(a, b) << endl;
//	cout << Add(b, a) << endl;
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
//
//template<typename T>
//T Add(const T& t1, const T& t2) {
//	return t1 + t2;
//}

//int main() {
//	int a = 1, b = 2;
//	//调用自己实现的Add函数
//	Add(a, b);
//	cout << Add(a, b) << endl;
//	return 0;
//}

//int main() {
//	int a = 1, b = 2;
//	//指定使用函数模板推导生成的Add函数
//	Add<int>(a, b);
//	cout << Add<int>(a, b) << endl;
//	return 0;
//}

//int main() {
//	int a = 1, b = 2;
//	//调用我们实现的Add函数
//	Add(a, b);
//	//指定使用函数模板推导生成的Add函数
//	Add<int>(a, b);
//	return 0;
//}

//int Add(const int& t1, const int& t2) {
//	return t1 + t2;
//}
//
//template<typename T1, typename T2>
//T1 Add(const T1& t1, const T2& t2) {
//	return t1 + t2;
//}
//
//int main() {
//	int a = 1;
//	double b = 3.14;
//	Add(a, b);
//	cout << Add(a, b) << endl;
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

//class A1 {
//public:
//	A1(int a = 1)
//		:_a(a) {}
//	void Print() {
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//class A2 {
//public:
//	A2(float a = 1.1)
//		:_a(a) {}
//	void Print() {
//		cout << _a << endl;
//	}
//private:
//	float _a;
//};

//#define TypeDate int
//class A {
//public:
//	A(TypeDate a = 1)
//		:_a(a) {}
//	void Print() {
//		cout << _a << endl;
//	}
//private:
//	TypeDate _a;
//};
//
//int main() {
//	A a(10);
//	a.Print();
//	return 0;
//}

//typedef int TypeDate;
//class A {
//public:
//	A(TypeDate a = 1)
//		:_a(a) {}
//	void Print() {
//		cout << _a << endl;
//	}
//private:
//	TypeDate _a;
//};



//template<typename T>
//class A {
//public:
//	A(T a = 1)
//		:_a(a){}
//	void Print();
//private:
//	T _a;
//};
//
//template<typename T>
//void A<T>::Print() {
//	cout << _a << endl;
//}

//int main() {
//	A<char> a1('a');
//	A<int> a2(10);
//	A<double> a3(3.14);
//	a1.Print();
//	a2.Print();
//	a3.Print();
//}



//template<typename T>
//class A {
//public:
//	A(T a = 1)
//		:_a(a) {}
//	void Print();
//private:
//	T _a;
//};
//
//template<typename T>
//void A<T>::Print() {
//	cout << _a << endl;
//}

//定义在命名空间中，防止和库里面的类名冲突
namespace weihe {
#define N 10
	template<typename T>
	class Array {
	public:
		T& operator[](size_t i) {
			assert(i < 10);
			return _a[i];
		}
	private:
		T _a[N];
	};
}

int main() {
	weihe::Array<int> a;
	for (int i = 0; i < N; ++i) {
		a[i] = i;
	}
	for (int i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < N; ++i) {
		a[i] *= 10;
	}
	for (int i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}