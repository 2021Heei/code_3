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
		//��������
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
		//��С
		size_t size() const{
			return _size;
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
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

void test1_string() {
	weihe::string s1("hello world");
	s1.print();

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
	s1.print();

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

void test3_string() {

}