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

////����ģ��
//template<class T>
//void Swap(T& t1, T& t2) {
//	T tmp = t1;
//	t1 = t2;
//	t2 = tmp;
//}


////����ģ��
//template<typename T>
//void Swap(T& t1, T& t2) {
//	T tmp = t1;
//	t1 = t2;
//	t2 = tmp;
//}

//int main() {
//
//	/*int a = 1, b = 2;
//	cout << "ǰ: " << a << " " << b << endl;
//	Swap(a, b);
//	cout << "��: " << a << " " << b << endl;
//	float c = 3.14, d = 9.99;
//	cout << "ǰ: " << c << " " << d << endl;
//	Swap(c, d);
//	cout << "��: " << c << " " << d << endl;*/
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

//��κ���ģ��
//����ģ�������������
//�����������������


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


//���庯���ͺ���ģ�嶼����ʱ�����ȵ��þ��庯�������Ǻ���ģ��
//���������ʽʹ�ú���ģ�����ɵľ��庯��Ҳ�ǿ����������еõ������
//��˵������ʵ�ֵľ��庯���ͺ���ģ���Ƶ����ɵľ��庯���ǲ�ͬ�ĺ�����������ַ��ͬ
//������д�ľ��庯���뺯��ģ���Ƶ����ɵľ��庯���ĺ��������ι����ǲ�ͬ�ģ�����ᱨ��
// ���Ա�������ԭ������������ƥ��ʱ�����ȵ�����ʽʵ�ֵģ�
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
//	//�����Լ�ʵ�ֵ�Add����
//	Add(a, b);
//	cout << Add(a, b) << endl;
//	return 0;
//}

//int main() {
//	int a = 1, b = 2;
//	//ָ��ʹ�ú���ģ���Ƶ����ɵ�Add����
//	Add<int>(a, b);
//	cout << Add<int>(a, b) << endl;
//	return 0;
//}

//int main() {
//	int a = 1, b = 2;
//	//��������ʵ�ֵ�Add����
//	Add(a, b);
//	//ָ��ʹ�ú���ģ���Ƶ����ɵ�Add����
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

//�����������ռ��У���ֹ�Ϳ������������ͻ
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