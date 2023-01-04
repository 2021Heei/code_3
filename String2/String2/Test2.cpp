#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cassert>
using namespace std;

//string类模板
//template <typename T>
//class basic_string {
//
//private:
//	T* _str;
//	size_t _size;
//	size_t _capacity;
//};
//
//typedef basic_string<char> string;

void test_1() {
	string s1;
	string s2("hello world!");
	string s3 = "hello world!";

	string s4(s2);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	string s5(10, '#');
	string s6("hello world!", 5);
	string s7("hello world!", 2, 3);
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;

	string s8("hello world!", 2, 100);
	cout << s8 << endl;
}

void test_2() {
	//下标
	string s1("1234");
	cout << s1 << endl;
	for (int i = 0; i < s1.size(); ++i) {
		s1[i]++;
	}
	cout << s1 << endl << endl;

	//范围for
	string s2("1234");
	cout << s2 << endl;
	for (auto& e : s2) {
		e++;
	}
	cout << s2 << endl << endl;

	//迭代器 -- 像指针一样的东西，但底层不一定是指针
	string s3("1234");
	cout << s3 << endl;
	string::iterator it = s3.begin();
	while (it != s3.end()) {
		(*it)++;
		it++;
	}
	cout << s3 << endl << endl;

	reverse(s3.begin(), s3.end());
	cout << s3 << endl;

	string::reverse_iterator rit = s3.rbegin();
	while (rit != s3.rend()) {
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

void test_3() {
	const string s1("1234");
	string::const_iterator cit = s1.begin();
	while (cit != s1.end()) {
		cout << *cit << " ";
		cit++;
	}
	cout << endl;

	string::const_reverse_iterator crit = s1.rbegin();
	while (crit != s1.rend()) {
		cout << *crit << " ";
		crit++;
	}
	cout << endl;
}

void test_4() {
	string s1("hello world!");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;

	s1.clear();
	cout << s1 << endl;
	cout << s1.capacity() << endl;
}

void TestPushBack_() {
	string s;
	s.reserve(1000);
	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << endl << endl;
	for (int i = 0; i < 1000; ++i) {
		s.push_back('1');
		if (sz != s.capacity()) {
			sz = s.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}
}

void test_5() {
	string s1("hello world!");
	s1.resize(5);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl << endl;

	string s2("hello world!");
	s2.resize(16);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	string s3("hello world!");
	s3.resize(100);
	cout << s3.size() << endl;

}
int main() {
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	TestPushBack_	();

	return 0;
}

