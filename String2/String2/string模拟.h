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
		//缺省构造函数
		//缺省参数是空字符串，而不是'\0'或nullptr或"\0"
		string(const char* s = "") {
			_size = strlen(s);
			//_capacity = _size+1;
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, s);
		}
		//无参默认构造函数
		/*string() {
			_str = new char[1];
			_str[0] = '\0';
			_size = _capacity = 0;
		}*/

		//析构函数
		~string() {
			delete[] _str;
			_size = _capacity = 0;
		}
		
		//大小
		size_t size() const{
			return _size;
		}
		//容量
		size_t capacity() const {
			return _capacity;
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
		//C字符串
		char* c_str() const {
			return _str;
		}

		//设置大小，扩容
		void reserve(size_t n) {
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
		//插入数据
		//尾插
		void push_back(const char ch) {
			if (_size == _capacity) {
				size_t newcapacity = _capacity == 0 ? 16 : 2 * _capacity;
				reserve(newcapacity);
				_capacity = newcapacity;
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		//追加
		void append(const char* pstr) {
			size_t len = strlen(pstr);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}
			strcat(_str, pstr);
		}
		//+=运算符重载
		string& operator+=(const char ch) {
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* pstr) {
			append(pstr);
			return *this;
		}

		void insert(size_t pos, char ch) {
			if (_size == _capacity) {
				size_t newcapacity = _capacity == 0 ? 16 : 2 * _capacity;
				reserve(newcapacity);
				_capacity = newcapacity;
			}
			//牵扯到C语言的算术转换问题，需要注意
			//两种解决方法
			/*int end = _size;
			while (end >= (int)pos) {
				_str[end + 1] = _str[end];
				end--;
			}*/
			/*size_t end = _size + 1;
			while (end > pos) {
				_str[end] = _str[end - 1];
				end--;
			}*/

			memmove(_str + pos + 1, _str + pos, sizeof(char) * (_size - pos + 1));

			_str[pos] = ch;
			_size++;
		}

		void insert(size_t pos, size_t n, char ch) {
			if (_size + n > _capacity) {
				reserve(_size + n);
				_capacity = _size + n;
			}
			//牵扯到C语言的算术转换问题，需要注意
			//两种解决方法
			/*int end = _size;
			while (end >= (int)pos) {
				_str[end + n] = _str[end];
				end--;
			}*/

			size_t end = _size + n;
			while (end > pos + n - 1) {
				_str[end] = _str[end - n];
				end--;
			}

			//memmove(_str + pos + n, _str + pos, sizeof(char) * (_size - pos + 1));

			for (int i = pos; i < pos + n; ++i) {
				_str[i] = ch;
			}
			_size+=n;
		}
		//注意边界，比较麻烦
		//判断条件用>=，就需要对pos进行强转，强转为int
		//判断条件用>，就不需要强转，但需要控制好边界和元素移动
		void insert(size_t pos, const char* str) {
			size_t len = strlen(str);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}

			//hello world xxxxx
			//hello 
			/*size_t end = _size + len+1;
			while (end > pos+len) {
				_str[end-1] = _str[end - len-1];
				end--;
			}
			memcpy(_str + pos, str, len);
			_size += len;*/

			size_t end = _size + len;
			while (end > pos + len - 1) {
				_str[end] = _str[end - len];
				end--;
			}
			memcpy(_str + pos, str, len);
			_size += len;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};


	void test1_string() {
		weihe::string s1("hello world");
		cout << s1.c_str() << endl;

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
		cout << s1.c_str() << endl;

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

	//尾插，追加
	void test3_string() {
		weihe::string s1("hello world");
		s1.push_back('x');
		s1.push_back('y');
		s1.push_back('z');
		cout << s1.c_str() << endl;

		weihe::string s2("hello world");
		s2.append("!!!xxx");
		cout << s2.c_str() << endl;

		weihe::string s3("hello world");
		s3 += 'X';
		cout << s3.c_str() << endl;
		s3 += " weihe";
		cout << s3.c_str() << endl;

		weihe::string s4("helloworld");
		s4.insert(5, ' ');
		cout << s4.c_str() << endl;

		weihe::string s5("hello world");
		s5.insert(0, "");
		cout << s5.c_str() << endl;
	}

	//插入，删除
	void test4_string() {
		weihe::string s1("hello world");
		s1.insert(5, 'x');
		cout << s1.c_str() << endl;

		weihe::string s2("hello world");
		s2.insert(5, 3, 'x');
		cout << s2.c_str() << endl;

		weihe::string s3("hello world");
		s3.insert(0, 3, 'x');
		cout << s3.c_str() << endl;
	}
}

