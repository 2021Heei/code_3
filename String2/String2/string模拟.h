#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
//�⺯��ģ��ʵ��
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
		//���һ��Ԫ�ص���һ��λ��
		iterator end() {
			return _str + _size;
		}
		const_iterator end() const {
			return _str + size();
		}
		//ȱʡ���캯��
		//ȱʡ�����ǿ��ַ�����������'\0'��nullptr��"\0"
		string(const char* s = "") {
			_size = strlen(s);
			//_capacity = _size+1;
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, s);
		}
		//�޲�Ĭ�Ϲ��캯��
		/*string() {
			_str = new char[1];
			_str[0] = '\0';
			_size = _capacity = 0;
		}*/

		//��������
		~string() {
			delete[] _str;
			_size = _capacity = 0;
		}
		
		//��С
		size_t size() const{
			return _size;
		}
		//����
		size_t capacity() const {
			return _capacity;
		}
		//[]���������
		char& operator[](size_t pos) {
			assert(pos < _size);
			return _str[pos];
		}
		//const []���������
		const char& operator[](size_t pos)const {
			assert(pos < _size);
			return _str[pos];
		}
		//C�ַ���
		char* c_str() const {
			return _str;
		}

		//���ô�С������
		void reserve(size_t n) {
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
		//��������
		//β��
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
		//׷��
		void append(const char* pstr) {
			size_t len = strlen(pstr);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}
			strcat(_str, pstr);
		}
		//+=���������
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
			//ǣ����C���Ե�����ת�����⣬��Ҫע��
			//���ֽ������
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
			//ǣ����C���Ե�����ת�����⣬��Ҫע��
			//���ֽ������
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
		//ע��߽磬�Ƚ��鷳
		//�ж�������>=������Ҫ��pos����ǿת��ǿתΪint
		//�ж�������>���Ͳ���Ҫǿת������Ҫ���ƺñ߽��Ԫ���ƶ�
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

		//����
		//[]����
		for (int i = 0; i < s1.size(); ++i) {
			s1[i]++;
		}
		for (int i = 0; i < s1.size(); ++i) {
			cout << s1[i] << " ";
		}
		cout << endl;

		//������
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

		//��Χfor - ���ʻ�ת��Ϊ��������Ҳ��������string������������������û��ʵ�ֻ��ߵ������ӿڲ��Ǳ�׼��begin()��end()����ô��Χfor�ͻ�ʧЧ
		for (auto& ch : s1) {
			ch++;
		}
		for (auto ch : s1) {
			cout << ch << " ";
		}
		cout << endl;
	}

	//const��Ա����
	void test2_string() {
		const weihe::string s1("const hello world");
		cout << s1.c_str() << endl;

		//����
		//[]����
		for (int i = 0; i < s1.size(); ++i) {
			cout << s1[i] << " ";
		}
		cout << endl;


		//������
		weihe::string::const_iterator it = s1.begin();
		while (it != s1.end()) {
			cout << (*it) << " ";
			it++;
		}
		cout << endl;

		//��Χfor - ���ʻ�ת��Ϊ��������Ҳ��������string������������������û��ʵ�ֻ��ߵ������ӿڲ��Ǳ�׼��begin()��end()����ô��Χfor�ͻ�ʧЧ
		for (auto ch : s1) {
			cout << ch << " ";
		}
		cout << endl;
	}

	//β�壬׷��
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

	//���룬ɾ��
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

