#pragma once

namespace sjh {
	class string {
		friend istream& operator>>(istream& in, string& str);
		friend ostream& operator<<(ostream& out, const string& str);
	public:
		typedef char* iterator;
		string(const char* str = "") {
			int len = strlen(str);
			_size = len;
			_capacity = len;
			_str = new char[len + 1];
			strcpy(_str, str);
		}

		~string() {
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		//拷贝构造 - 深拷贝 - 现代写法
		string(const string& str)
			:_str(nullptr), _size(0), _capacity(0) {
			if (_str != str._str) {
				string tmp(str._str);
				swap(tmp);
			}
		}
		//赋值运算符重载 - 现代写法2	
		string& operator=(string str) {
			swap(str);
			return *this;
		}

		//////////////////////////////////////////
		//iterator
		iterator begin() {
			return _str;
		}
		const iterator begin()const {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
		const iterator end()const {
			return _str + _size;
		}

		//////////////////////////////////////////
		//modify
		void push_back(char ch) {
			if (_size == _capacity) {
				int newCapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newCapacity);
				_capacity = newCapacity;
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}

		void append(const char* str) {
			int len = strlen(str);
			if (_size + len > _capacity) {
				reserve(_size + len);
				_capacity = _size + len;
			}
			for (int i = _size, j = 0; j < len; i++, j++) {
				_str[i] = str[j];
			}
			_str[_size + len] = '\0';
			_size += len;
		}

		string& operator+=(char ch) {
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str) {
			append(str);
			return *this;
		}


		void swap(string& str) {
			std::swap(_str, str._str);
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}
		const char* c_str() const {
			return _str;
		}
		//////////////////////////////////////////
		//capacity

		//设置容量
		void reserve(int newcapacity) {
			char* tmp = new char[newcapacity + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
		}
		void resize(size_t n, char ch = '\0') {
			if (n > _size) {
				reserve(n);
				for (int i = _size; i < n; i++) {
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
				_capacity = n;
			}
			else {
				_str[n] = '\0';
				_size = n;
			}
		}
		void clear() {
			_size = 0;
			_str[0] = '\0';
		}

		const int size() const {
			return _size;
		}
		const int capacity() const {
			return _capacity;
		}
		//////////////////////////////////////////
		//access
		char& operator[](int pos) {
			return _str[pos];
		}
		const char& operator[](int pos) const {
			return _str[pos];
		}

		//////////////////////////////////////////
		//relational operators
		bool operator<(const string& s) {
			return strcmp(_str, s._str) < 0;
		}

		bool operator<=(const string& s) {
			return (*this == s) || (*this < s);
		}

		bool operator>(const string& s) {
			return strcmp(_str, s._str) > 0;
		}

		bool operator>=(const string& s) {
			return (*this == s) || (*this > s);
		}

		bool operator==(const string& s) {
			return strcmp(_str, s._str) == 0;
		}

		bool operator!=(const string& s) {
			return !(*this == s);
		}


		// 返回c在string中第一次出现的位置
		size_t find(char ch, size_t pos = 0) {
			assert(pos < _size);
			for (int i = pos; i < _size; i++) {
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
		}
		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const {
			assert(pos < _size);
			//abccdef   ccdd
			int i = pos;
			int j = i;
			int k = 0;
			int len = strlen(s);
			while (i < _size) {
				j = i;
				while (j < _size && k < len && _str[j] == s[k]) {
					j++;
					k++;
				}
				if (k == len) {
					return i;
				}
				k = 0;
				i++;
			}
			return npos;
		}
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char ch) {
			assert(pos <= _size);
			if (_size == _capacity) {
				int newCapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newCapacity);
				_capacity = newCapacity;
			}
			for (int i = _size + 1; i > pos; i--) {
				_str[i] = _str[i - 1];
			}
			_size++;
			_str[pos] = ch;
			return *this;
		}
		string& insert(size_t pos, const char* str) {
			assert(pos <= _size);
			int len = strlen(str);
			if (len + _size > _capacity) {
				reserve(len + _size);
				_capacity = len + _size;
			}
			for (int i = _size + len + 1; i > pos + len; i--) {
				_str[i - 1] = _str[i - len - 1];
			}

			_size = len + _size;
			for (int i = pos, j = 0; j < len; i++, j++) {
				_str[i] = str[j];
			}
			return *this;
		}
		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, int len = npos) {
			assert(pos < _size);
			if (len == npos || pos + len >= _size) {
				_str[pos] = '\0';
				_size = pos;
			}
			else {
				/*for (int i = pos; i < _size - len + 1; i++) {
					_str[i] = _str[i + len];
				}*/
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}

			return *this;
		}
	private:
		char* _str;
		int _size;//大小
		int _capacity;//容量，不包含'\0'
		const static int npos = -1;

	};

	istream& operator>>(istream& in, string& str) {
		str.clear();
		char ch = in.get();
		char buffer[128] = { '\0' };
		size_t i = 0;
		while (ch != ' ' && ch != '\n') {
			if (i == 127) {
				str += buffer;
				i = 0;
			}
			buffer[i++] = ch;
			ch = in.get();
		}
		if (i != 0) {
			buffer[i] = '\0';
			str += buffer;
		}
		return in;
	}
	ostream& operator<<(ostream& out, const string& str) {
		for (int i = 0; i < str.size(); i++) {
			out << str[i];
		}
		return out;
	}

	void test01() {
		string s1("abccccddefg");
		cout << s1.find("ccdde") << endl;
		cout << s1.find("ccdff") << endl;

		string s2("aaa");
		string s3("bbb");
		string s4("ccc");
		string s5("ddd");
		string s6("aaa");
		string s7("aaa");
		cout << (s2 == s3) << endl;
		cout << (s2 != s3) << endl;
		cout << (s2 > s3) << endl;
		cout << (s2 >= s3) << endl;
		cout << (s2 < s3) << endl;
		cout << (s2 <= s3) << endl;
	}
}