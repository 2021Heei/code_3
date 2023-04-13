#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cassert>
#include <initializer_list>
#include <algorithm>
using namespace std;
#include "List.h"

//int main() {
//	//初始化列表，提升为一个类模板了
//	//初始化列表初始化本质
//	//初始化列表被定义为了模板类型，表现形式是一对花括号内包含着逗号分隔开的元素
//	//这些元素是const的，存放在const数组中；
//	//对于内置类型没啥用，对于类类型，比如容器vector来说支持定义时初始化，
//	//实现原理vector的构造函数额外实现了对initializer_list对象参数的支持，也就是在构造函数内自动进行对initializer_list对象的遍历，依次得到得到每个元素，然后插入到vector底层的结构中
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
		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;
			string tmp(s._str);
			swap(tmp);
		}
		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}
		// 移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 移动语义" << endl;
			swap(s);
		}
		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动语义" << endl;
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
		size_t _capacity; // 不包含最后做标识的\0
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

//右值引用
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
//	////左值可以引用左值，也可以引用右值
//	//int a = 10;
//	//int& r1 = a;
//	//const int& r2 = 10;
//	////右值可以引用右值，也可以引用move的左值
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
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价
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
//	vector<Goods> vg = { {"苹果", 1, 10},{"梨", 2 , 9}, {"菠萝", 2, 8} };
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
//异常

double Div(int a, int b) {
	if (b == 0) {
		throw "division not zero";
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
	catch (const char* msgStr) {
		cout << "func:" << msgStr << endl;
		delete[] p1;
		p1 = nullptr;
		throw msgStr;
	}
	
	delete[] p1;
	p1 = nullptr;
}
int main() {
	try {
		func();
	}
	catch (const char* msgStr) {//依据throw的类型匹配
		cout << "main:" << msgStr << endl;
	}
	catch (int msgInt) {
		cout << "异常" << msgInt << endl;
	}
	return 0;
}