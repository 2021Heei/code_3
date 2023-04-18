#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cassert>
#include <initializer_list>
#include <algorithm>
#include <thread>	
using namespace std;
#include "List.h"
#include <windows.h>
#include "SmartPtr.h"

//int main() {
//	//��ʼ���б�����Ϊһ����ģ����
//	//��ʼ���б��ʼ������
//	//��ʼ���б�����Ϊ��ģ�����ͣ�������ʽ��һ�Ի������ڰ����Ŷ��ŷָ�����Ԫ��
//	//��ЩԪ����const�ģ������const�����У�
//	//������������ûɶ�ã����������ͣ���������vector��˵֧�ֶ���ʱ��ʼ����
//	//ʵ��ԭ��vector�Ĺ��캯������ʵ���˶�initializer_list���������֧�֣�Ҳ�����ڹ��캯�����Զ����ж�initializer_list����ı��������εõ��õ�ÿ��Ԫ�أ�Ȼ����뵽vector�ײ�Ľṹ��
//	auto il01 = { 1, 2, 3, 4 };
//	auto il02 = { 1.5f, 2.5f, 3.5f, 4.6f };
//	auto il03 = { "sd", "dsada", "dsasda", "dsa"};
//	cout << typeid(il01).name() << endl;
//	cout << typeid(il02).name() << endl;
//	cout << typeid(il03).name() << endl;
//	int a1 = 1;
//	int a2 = { 1 };
//	int a3{ 1 };
//
//	vector<int> v1 = { 1,2,3,4 };
//	vector<int> v2{ 1,2,3,4 };
//	map<string, int> m = { {"str1", 1}, {"str2", 1} };
//	return 0;
//}

namespace weihe
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		// ��������
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;
			string tmp(s._str);
			swap(tmp);
		}
		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}
		// �ƶ�����
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			swap(s);
		}
		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- �ƶ�����" << endl;
			swap(s);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
				_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // �������������ʶ��\0
	};
}

void func01(weihe::string& s) {

}
weihe::string func02(weihe::string& s) {
	weihe::string tmp;
	return tmp;
}

weihe::string toString(int val) {
	weihe::string ret;
	return ret;
}

//��ֵ����
//int main() {
//	/*int a = 1, b = 2;
//	int&& r1 = 10;
//	int&& r2 = a + b;
//	cout << r1 << endl;
//	cout << r2 << endl;
//
//	r1 = 20;
//	cout << r1 << endl;
//	r2 = 5;
//	cout << r2 << endl;
//
//	double x = 1.1, y = 2.2;
//	double&& r3 = x + y;
//	cout << r3 << endl;
//	r3 = 3.14;
//	cout << r3 << endl;*/
//
//	////��ֵ����������ֵ��Ҳ����������ֵ
//	//int a = 10;
//	//int& r1 = a;
//	//const int& r2 = 10;
//	////��ֵ����������ֵ��Ҳ��������move����ֵ
//	//int b = 20;
//	//int&& r3 = 10;
//	//const int&& r4 = move(b);
//	//cout << r3 << endl;
//	//cout << r4 << endl;
//	//b = 99;
//	//cout << r4 << endl;
//	//cout << b << endl;
//
//	/*weihe::string s1{ "hello, world" };
//	func01(s1);
//	weihe::string ret = func02(s1);*/
//
//	/*weihe::string r;
//	r = toString(1234);*/
//
//	weihe::string s1{ "hello world" };
//	weihe::string s2(s1);
//	weihe::string s3(move(s1));
//	return 0;
//}

//int main() {
//	weihe::test02();
//	return 0;
//}

struct Goods
{
	string _name;  // ����
	double _price; // �۸�
	int _evaluate; // ����
				   // ...

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};
struct CompareGoodsEvaluateLess {
	bool operator()(const Goods& g1, const Goods& g2) {
		return g1._evaluate < g2._evaluate;
	}
};
struct CompareGoodsEvaluateGreater {
	bool operator()(const Goods& g1, const Goods& g2) {
		return g1._evaluate > g2._evaluate;
	}
};
//int main() {
//	vector<Goods> vg = { {"ƻ��", 1, 10},{"��", 2 , 9}, {"����", 2, 8} };
//	sort(vg.begin(), vg.end(), CompareGoodsEvaluateLess());
//	sort(vg.begin(), vg.end(), CompareGoodsEvaluateGreater());
//	sort(vg.begin(), vg.end(), [](const Goods& g1, const Goods& g2) 
//		{
//			return g1._price < g2._price;
//		});
//	sort(vg.begin(), vg.end(), [](const Goods& g1, const Goods& g2)
//		{
//			return g1._price > g2._price;
//		});
//
//	auto comp = [](int x, int y)->bool {return x < y; };
//	//auto comp = [](int x, int y) {return x < y; };
//	cout << typeid(comp(10, 20)).name() << endl;
//	cout << typeid(comp).name() << endl;
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////
//�쳣

double Div(int a, int b) {
	if (b == 0) {
		string s = "division not zero";
		throw s;
	}
	else {
		return a / b;
	}
}
void func() {
	int* p1 = new int[10]{ 0 };
	try {
		int len, time;
		cin >> len >> time;
		cout << Div(len, time) << endl;
	}
	catch (string msgStr) {
		cout << "func:" << msgStr << endl;
		delete[] p1;
		p1 = nullptr;
		//throw msgStr;
		throw;
	}
	
	delete[] p1;
	p1 = nullptr;
}
//int main() {
//	try {
//		func();
//	}
//	//catch (const char* msgStr) {//����throw������ƥ��
//	//	cout << "main:" << msgStr << endl;
//	//}
//	catch (...) {
//		cout << "δ֪�쳣`" << endl;
//	}
//	/*catch (int msgInt) {
//		cout << "�쳣" << msgInt << endl;
//	}*/
//	return 0;
//}

//int main() {
//	vector<int> v;
//	//v.reserve(1000000000);//40���ֽ�
//	v.push_back(10);
//	//cout << v[1] << endl;
//	return 0;
//}
class Exception {
public:
	Exception(const string errmsg, int id)
		:_errmsg(errmsg)
		,_id(id) { }
	virtual string what() const {
		return "";
	}
private:
	string _errmsg;
	int _id;
};
class f01 : public Exception {
public:
	f01(const string errmsg, int id, string type)
		:Exception(errmsg, id),
		_type(type){ }
	virtual string what() const {
		string str = "f01";
		str += _type;
		return str;
	}
private:
	string _type;
};
class f02 : public Exception {
public:
	f02(const string errmsg, int id, string type)
		:Exception(errmsg, id),
		_type(type) { }
	virtual string what() const {
		string str = "f02";
		str += _type;
		return str;
	}
private:
	string _type;
};
class f03 : public Exception {
public:
	f03(const string errmsg, int id, string type)
		:Exception(errmsg, id),
		_type(type) { }
	virtual string what() const {
		string str = "f03";
		str += _type;
		return str;
	}
private:
	string _type;
};
void f3() {
	int t = rand();
	if (t % 5 == 0) {
		throw f03("Exception", 2, "333").what();
	}
	else {
		cout << "f03 success" << endl;
	}
}
void f2() {
	int t = rand();
	if (t % 3 == 0) {
		throw f02("Exception", 2, "222").what();
	}
	else {
		cout << "f02 success" << endl;

	}
	f3();
}

void f1() {
	int t = rand();
	if (t % 2 == 0) {
		throw f01("Exception", 1, "111").what();
	}
	else {
		cout << "f01 success" << endl;
	}
	f2();
}

//int main() {
//	srand(time(0));
//	while (1) {
//		try {
//			f1();
//		}
//		catch (const Exception& e) {
//			cout << e.what() << endl;
//		}
//		catch (...) {
//			cout << "unknow exception" << endl;
//		}
//		Sleep(1000);
//	}
//	return 0;
//}


//////////////////////////////////////////////////////////
//����ָ��

void func01() {
	int* p1 = new int[10];
	int* p2 = new int[10];
	weihe::auto_ptr<int> ap1(p1);
	weihe::auto_ptr<int> ap2(p2);
	*ap1 = 10;
	ap1[0]--;
	cout << *ap1 << endl;

	int len, time;
	cin >> len >> time;
	cout << Div(len, time) << endl;
}

//int main() {
//	try {
//		func01();
//	}
//	catch (...) {
//		cout << "δ֪�쳣" << endl;
//	}
//	return 0;
//}

//unique_ptr ��ֹ����֮����и�ֵ���Ӹ�Դ�Ͻ���˸�ֵ������
//int main() {
//	weihe::unique_ptr<int> up1(new int);
//	//weihe::unique_ptr<int> up2(up1);
//	weihe::unique_ptr<int> up = up1;
//	*up1 = 10;
//	cout << *up1 << endl;
//	return 0;
//}

//shared_ptr
//int main() {
//	weihe::shared_ptr<int> sp1(new int);
//	weihe::shared_ptr<int> sp2(sp1);
//	*sp1 = 10;
//	cout << *sp1 << " " << *sp2 << endl;
//	//cout << *sp1 << endl;
//	weihe::shared_ptr<int> sp3(sp1);
//
//	weihe::shared_ptr<int> sp4(new int);
//	weihe::shared_ptr<int> sp5(sp4);
//
//	sp1 = sp1;
//	sp2 = sp1;
//	sp4 = sp1;
//	return 0;
//}

//int main() {
//	int* p1 = new int;
//	unique_ptr<int> up1(p1);
//	int* p2 = p1;
//	unique_ptr<int> up2(p2);
//	return 0;
//}

//int main() {
//	int* p1 = new int;
//	weihe::shared_ptr<int> sp1(p1);
//	int* p2 = p1;
//	weihe::shared_ptr<int> sp2(p2);
//	return 0;
//}

//int main() {
//	weihe::SmartPtrTest01();
//	return 0;
//}

///////////////////////////////////////////////
//����������ת��
//inttend : �滻C�����е���ʽ����ת����ǿ������ת��(��ʽ����ת��)
//static_cast/reinterpret_cast/const_cast/dynamic_cast;

//static_cast
//ת��ǰ��ĵ����ͱ�ʾ��������壬����int��double��int��char����ʾ�Ķ�����
//int main() {
//	int a = 10;
//	double b = static_cast<double>(a);
//	return 0;
//}

//reinterpret_cast
//ת��ǰ������ͱ�ʾ���������ϴ󣬱���int��int*
//int main() {
//	int a = 10;
//	//int* p = static_cast<int*>(a);
//	int* p = reinterpret_cast<int*>(a);
//	cout << p << endl;
//	cout << *p << endl;
//	return 0;
//}

//const_cast
//����const���εı���������ͨ��const_castת��Ϊ��const���ε�ָ�������
//�޸ĵ����޶���const
//����valatile�ؼ��ֵ��������ñ�������Ҫ��const���ε�a����Ĵ�����10��������ÿ��ʹ��aʱ��Ҫȥ�ڴ浥Ԫȡ���������Ա���a��ת��������ͱ�����ȥ��ͬ���ڴ浥Ԫȡ���ݣ�20 or 30����
//int main() {
//	volatile const int a = 10;
//	//const int a = 10;
//	int* p = const_cast<int*>(&a);
//	
//	*p = 20;
//	cout << a << endl;
//	cout << *p << endl;
//	printf("%p\n", &a);
//	printf("%p\n", p);
//	cout << endl;
//	int& r = const_cast<int&>(a);
//	r = 30;
//	cout << a << endl;
//	cout << *p << endl;
//	cout << r << endl;
//	printf("%p\n", &a);
//	printf("%p\n", p);
//	printf("%p\n", &r);
//	cout << &a << endl;
//	cout << p << endl;
//	cout << &r << endl;
//	return 0;
//}

//dynamic_cast
//������������˵������ָ���������תΪ����ָ�룬������ָ�벻��ֱ��ת��Ϊ����ָ�룬����Ҳ����ˡ�
//dynamic_cast�Դ�ת�����м�飬
//��������ָ��ת����ָ�룬����ת��������ת������Ǹ�ָ��
//���ڸ���ָ��ת����ָ�룬����ת�������ؿ�

class A {
public:
	virtual void test() {

	}
	int _a;
};

class AB : public A {
public:
	int _b;
};

void func03(A* _ptr) {
	//ֱ��ǿ������ת�������ܵ��³����������ʹ�õ��������и��಻���ڵĶ���
	AB* _bptr = (AB*)_ptr;
	_bptr->_a = 10;
	_bptr->_b = 20;
	cout << _bptr->_a << ":" << _bptr->_b << endl;
}
void func04(A* _ptr) {
	AB* _bptr = dynamic_cast<AB*>(_ptr);
	if(_bptr){
		_bptr->_a = 10;
		_bptr->_b = 20;
		cout << _bptr->_a << ":" << _bptr->_b << endl;
	}
	else {
		cout << "error change" << endl;
	}
	cout << _bptr << endl;
}
void func05(AB& _ptr) {
	A& _bptr = dynamic_cast<A&>(_ptr);
	/*if () {
		_bptr._a = 10;
		_bptr._b = 20;
		cout << _bptr._a << ":" << _bptr._b << endl;
	}
	else {
		cout << "error change" << endl;
	}*/
	cout << typeid(_bptr).name() << endl;
}
//int main() {
//	A aa;
//	AB bb;
//	//func03(&aa);
//	//func04(&aa);
//	func05(bb);
//	return 0;
//}


