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

//����ģ��
//template<class T>
//void Swap(T& t1, T& t2) {
//	T tmp = t1;
//	t1 = t2;
//	t2 = tmp;
//}
// 
//
////����ģ��
//template<typename T>
//void Swap(T& t1, T& t2) {
//	T tmp = t1;
//	t1 = t2;
//	t2 = tmp;
//}

//���õ��Ǻ���ģ���� - �������
//���ǣ����õ���������ͬ�ĺ���

//����ģ���ʵ����
//�ú���ģ�����ɾ���ĺ���
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

//�����뺯��ģ�岻ƥ�䣬���������ɾ���ĺ�����������ģ���Ƶ�����
// ��ȥ��const֮�󱨴�����Ϊǿ������ת�������˳�����ʱ�������������������ܴ��θ��� ����������
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
//	//�Զ�����ʵ����
//	cout << Add(a, b) << endl;
//	cout << Add(c, d) << endl;
//
//	//��ʽʵ����
//	cout << Add<int>(a, b) << endl;
//	cout << Add<double>(c, d) << endl;
//
//	//��ʾʵ����+��ʽ����ת��
//	cout << Add<int>(c, d) << endl;
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
//	int a = 1, b = 2;
//	double c = 3.14, d = 9.99;
//	////�Զ�����ʵ����
//	//cout << Add(a, b) << endl;
//	//cout << Add(c, d) << endl;
//
//	cout << Add(a, c) << endl;
//	cout << Add(c, a) << endl;
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
//template<typename T>
//T Add(const T& t1, const T& t2) {
//	return t1 + t2;
//}
//
//int main() {
//	int a = 1, b = 2;
//	//��������ʵ�ֵ�Add����
//	Add(a, b);
//	//ָ��ʹ�ú���ģ���Ƶ����ɵ�Add����
//	Add<int>(a, b);
//	return 0;
//}

//��ģ��

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

//���typedef�ͺ�����������
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
////��ģ��һ��û������ʱ�������뺯��ģ��ͨ��ʵ������ģ�������ͬ
////ģ�������ͬ��ͬһ��ģ��ʵ���������Ķ��������;͸�����ͬ
//int main() {
//	Stack<int> st1;
//	st1.Push(1);
//	st1.Push(2);
//
//	Stack<double> st2;
//	st2.Push(1.1);
//	st2.Push(2.1);
//	//����ȫ��ͬ�����ͣ���������ʽ����ת��
//	//st2 = st1;//error
//	return 0;
//}

//template�з�Χ


//��ϰ
//#define N 10

//template<typename T>
//class Array {
//public:
//	T& operator[](size_t i) {
		/*�������������±�Խ��ļ���ǳ�飬������߽�д���׼�������Զ������߽��Խ��д�����׼�������������߽����Զ������߽����������������
		������������ǿ�Ƽ�飬��ֹ�����±�Խ��*/
//
//		assert(i < 10);
//		return _a[i];
//	}
//private:
//	T _a[N];
//};

//�����������ռ��У���ֹ�Ϳ������������ͻ
//namespace weihe {
//	template<typename T>
//	class Array {
//	public:
//		T& operator[](size_t i) {
//			//�������������±�Խ��ļ���ǳ�飬������߽�д���׼�������Զ������߽��Խ��д�����׼�������������߽����Զ������߽����������������
//			//������������ǿ�Ƽ�飬��ֹ�����±�Խ��
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

//���ֳ�ͻ������˼·
//�����ռ������


//ע�⣺ģ��һ�㲻������루�����Ͷ������A��

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

//��ģ��һ��û������ʱ�������뺯��ģ��ͨ��ʵ������ģ�������ͬ
//ģ�������ͬ��ͬһ��ģ��ʵ���������Ķ��������;͸�����ͬ
//int main() {
//	//Stack<int> ��Stack<double>�ǲ�ͬ������
//	Stack<int> st1;
//	st1.Push(1);
//
//	Stack<double> st2;
//	st2.Push(1.1);
//	return 0;
//}