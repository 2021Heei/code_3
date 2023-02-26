namespace weihe {
	class string {
		friend istream& operator>>(istream& in, string& str);
		friend ostream& operator<<(ostream& out, const string& str);
	public:
		typedef char* iterator;
		//构造
		/*string() {
			_str = new char[1];
			_str[0] = '\0';
			_size = _capacity = 0;
		}*/
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

		//拷贝构造 - 深拷贝 - 传统写法
		/*string(const string& str) {
			if (_str != str._str) {
				_str = new char[str._capacity + 1];
				strcpy(_str, str._str);
				_size = str._size;
				_capacity = str._capacity;

			}
		}*/
		//拷贝构造 - 深拷贝 - 现代写法
		string(const string& str)
			:_str(nullptr), _size(0), _capacity(0) {
			if (_str != str._str) {
				string tmp(str._str);
				swap(tmp);
			}
		}
		void swap(string& str) {
			std::swap(_str, str._str);
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}

		//赋值运算符重载 - 传统写法
		/*string& operator=(const string& str) {
			if (this != &str) {
				char* tmp = new char[str._capacity + 1];
				strcpy(tmp, str._str);
				delete[] _str;
				_str = tmp;
				_size = str._size;
				_capacity = str._capacity;
			}
			return *this;
		}*/

		//赋值运算符重载 - 现代写法1
		/*string& operator=(const string& str) {
			if (this != &str) {
				string tmp(str);
				swap(tmp);
			}
			return *this;
		}*/
		//赋值运算符重载 - 现代写法2	
		string& operator=(string str) {
			swap(str);
			return *this;
		}

		char& operator[](int pos) {
			return _str[pos];
		}
		const char& operator[](int pos) const {
			return _str[pos];
		}
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
		//设置容量
		void reserve(int newcapacity) {
			char* tmp = new char[newcapacity + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
		}

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
		size_t find(char ch, size_t pos = 0) {
			assert(pos < _size);
			for (int i = pos; i < _size; i++) {
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
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
		const char* c_str() const {
			return _str;
		}
		const int size() const {
			return _size;
		}
		const int capacity() const {
			return _capacity;
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
}