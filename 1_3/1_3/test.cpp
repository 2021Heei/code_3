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
//	//��������
//	//��������ֻ��һ�У�һ�����ò��󣬵���ʱ�Ƚ����ã�
//	int();//����������ͱ�����0
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
//		cout << "���캯��: A(int a)" << endl;
//	}
//	A(const A& a) {
//		cout << "��������: A(const A& a)" << endl;
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
//	//�� ����ʱ ���ܵ��Ż�
//	A a2(10);
//	Func1(a2);//�ȹ����ڿ�������
//
//	Func1(A(10));//�ȹ����ٿ������� --> ֱ�ӹ���
//	A();
//}

//class A {
//public:
//	A(int a = 1)
//		:_a(a) {
//		cout << "���캯��: A(int a)" << endl;
//	}
//	~A() {
//		cout << "��������: ~A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//
////��λnew
////Ϊ������Ŀռ���ù��캯��
//int main() {
//
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A(2);//��λnew
//	p1->~A();
//	free(p1);
//	//��delete p1;
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
		cout << "���캯��" << endl;
	}
private:
	T _a;
};

int main() {
	A<int> aa1(10);
	A<double> aa2(3.14);
	return 0;
}






