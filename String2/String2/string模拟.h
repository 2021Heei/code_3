#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
//库函数模拟实现
#include <iostream>
#include <cassert>
using namespace std;

namespace weihe {
	
	class string {
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin() {
			return _str;
		}
		const_iterator begin() const{
			return _str;
		}
		//最后一个元素的下一个位置
		iterator end() {
			return _str + _size;
		}
		const_iterator end() const {
			return _str + size();
		}
		//拷贝构造
		string(const char* s) {
			_size = strlen(s);
			//_capacity = _size+1;
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, s);
		}
		/*void print() {
			cout << _str << endl;
		}*/
		void print()const {
			cout << _str << endl;
		}
		//大小
		size_t size() const{
			return _size;
		}
		//[]运算符重载
		char& operator[](size_t pos) {
			assert(pos < _size);
			return _str[pos];
		}
		//const []运算符重载
		const char& operator[](size_t pos)const {
			assert(pos < _size);
			return _str[pos];
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

void test1_string() {
	weihe::string s1("hello world");
	s1.print();

	//遍历
	//[]遍历
	for (int i = 0; i < s1.size(); ++i) {
		s1[i]++;
	}
	for (int i = 0; i < s1.size(); ++i) {
		cout << s1[i] << " ";
	}
	cout << endl;

	//迭代器
	weihe::string::iterator it = s1.begin();
	while (it != s1.end()) {
		(*it)--;
		it++;
	}
	it = s1.begin();
	while (it != s1.end()) {
		cout << (*it) << " ";
		it++;
	}
	cout << endl;

	//范围for - 本质会转换为迭代器，也就是依赖string类迭代器，如果迭代器没有实现或者迭代器接口不是标准的begin()或end()，那么范围for就会失效
	for (auto& ch : s1) {
		ch++;
	}
	for (auto ch : s1) {
		cout << ch << " ";
	}
	cout << endl;
}

//const成员函数
void test2_string() {
	const weihe::string s1("const hello world");
	s1.print();

	//遍历
	//[]遍历
	for (int i = 0; i < s1.size(); ++i) {
		cout << s1[i] << " ";
	}
	cout << endl;

	
	//迭代器
	weihe::string::const_iterator it = s1.begin();
	while (it != s1.end()) {
		cout << (*it) << " ";
		it++;
	}
	cout << endl;

	//范围for - 本质会转换为迭代器，也就是依赖string类迭代器，如果迭代器没有实现或者迭代器接口不是标准的begin()或end()，那么范围for就会失效
	for (auto ch : s1) {
		cout << ch << " ";
	}
	cout << endl;
}

void test3_string() {

}