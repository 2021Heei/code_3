#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
//库函数模拟实现
#include <iostream>
#include <cassert>
using namespace std;

namespace weihe {
	
	const char* mystrstr(const char* str, const char* substr) {
		assert(str && substr);
		const char* pstr = str;
		const char* flag = str;
		const char* psubstr = substr;
		while (*flag != '\0') {
			pstr = flag;
			while (*pstr != '\0' && *psubstr != '\0' && *pstr == *psubstr) {
				pstr++;
				psubstr++;
			}
			if (*psubstr == '\0') {
				return flag;
			}
			psubstr = substr;
			flag++;
		}
		return nullptr;
	}

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

		//扩容
		void reserve(size_t n) {
			//控制条件，只扩容，不缩容
			//一般不缩容
			if (n > _capacity) {
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		//设置大小
		//hello world\0
		void resize(size_t n, char ch = '\0') {
			if (n > _size) {
				reserve(n);
				for (int i = _size; i <= n; ++i) {
					_str[i] = ch;
				}
			}
			_str[n] = '\0';
			_size = n;
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
			_size += len;
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
			/*int end = _size;
			while (end >= (int)pos) {
				_str[end + len] = _str[end];
				end--;
			}*/
			/*size_t end = _size + len+1;
			while (end > pos+len) {
				_str[end-1] = _str[end - len-1];
				end--;
			}*/
			/*memcpy(_str + pos, str, len);
			_size += len;*/

			size_t end = _size + len;
			while (end > pos + len - 1) {
				_str[end] = _str[end - len];
				end--;
			}
			memcpy(_str + pos, str, len);
			_size += len;
		}
		//删除
		//hello world\0
		string& erase(size_t pos, size_t len = npos) {
			assert(pos < _size);
			if (pos + len >= _size || len == npos) {
				_str[pos] = '\0';
				_size = pos;
			}
			else {
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
		//查找
		// hello world
		//查找字符
		size_t find(const char ch, size_t pos) const{
			assert(pos < _size);
			for (int i = pos; i < _size; ++i) {
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
		}
		//查找字符串
		size_t find(const char* str, size_t pos) const {
			assert(pos < _size);
			const char* p = strstr(_str + pos, str);
			if (p == nullptr) {
				return npos;
			}
			else {
				return p - _str;
			}
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		//const修饰静态成员一般来说需要在类内声明，然后在类外进行初始化
		//不过这里有一个特例，针对整型家族（char,short,int,long,long long），可以对静态整型成员直接在类内进行初始化，这样支持的其中一个用法是定义固定大小的数组成员
		// 对于非const静态成员变量，必须在类外进行定义，包括整型；
		//const static int N = 100;
		//int arr[N];

		const static int npos = -1;
		
		/*const static char n = -1;
		const static short n = -1;
		const static long n = -1;
		const static long long n = -1;*/
		//const static double d = 3.14;//error
	};
	//const static string::d = 3.14;

	//输出运算符重载
	ostream& operator<<(ostream& out, const string& str) {
		for (int i = 0; i < str.size(); ++i) {
			out << str[i];
		}
		
		return out;
	}
	//输入运算符重载
	//读取字符到string对象，遇到空格或换行结束
	istream& operator>>(istream& in, string& str) {
		char ch;
		in.get(ch);
		//scanf,cin默认以空格字符作为读取间隔，默认略过空格字符和换行字符的读取
		// 或者说遇到空格字符或换行字符就直接丢弃，并读取下一个字符
		// 在C语言中我们使用getchar()函数来读取避免空格字符和换行字符被丢弃
		// 在C++中我们使用cin的成员函数get()来读取避免空格字符和换行字符被丢弃
		//in >> ch;
		char buf[128] = { 0 };
		size_t i = 0;
		while (ch != ' ' && ch != '\n') {
			if (i == 127) {
				str += buf;
				i = 0;
			}
			buf[i++] = ch;
			//in >> ch;
			in.get(ch);
		}
		if (i > 0) {
			buf[i] = '\0';
			str += buf;
		}
		return in;
	}

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

		weihe::string s4("hello world");
		s4.insert(0, "xxxxx ");
		cout << s4.c_str() << endl;


		//删除erase
		string s5("hello world");
		s5.erase(5, 4);
		cout << s5.c_str() <<endl;

		string s6("hello world");
		s6.erase(0, 6);
		cout << s6.c_str() << endl;

		string s7("hello world");
		s7.erase(5);
		cout << s7.c_str() << endl;
	}
	//查找
	void test5_string() {
		string s1("hello world");
		size_t ret1 = s1.find('w', 0);
		cout << ret1 << endl;

		string s2("hello worldd");
		size_t ret2 = s2.find("world", 0);
		cout << ret2 << endl;
	}
	//resize
	void test6_string() {

		string s1("hello world");
		s1.resize(5, 'x');
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;
		cout << s1.c_str() << endl << endl;

		string s2("hello world");
		s2 += '!';
		s2.resize(18, 'x');
		cout << s2.size() << endl;
		cout << s2.capacity() << endl;
		cout << s2.c_str() << endl << endl;

		string s3("hello world");
		s3.resize(50, 'x');
		cout << s3.size() << endl;
		cout << s3.capacity() << endl;
		cout << s3.c_str() << endl;
	}

	void test7_string() {
		string s1;
		cin >> s1;
		cout << s1;
	}
}

