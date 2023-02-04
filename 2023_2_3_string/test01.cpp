#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
void test01() {
	string s1;
	string s2("hello");
	string s3 = "hello";
	string s4(10, '#');
	string s5(s4);
	string s6("hello", 3);
	string s7(s2, 2, 4);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;

	string s8 = "hello";
	s8 += " world";
	cout << s8 << endl;
}

//±éÀú×Ö·û´®
void test02() {
	string s1 = "1234";
	for (int i = 0; i < s1.size(); i++) {
		s1[i] += 1;
	}
	cout << s1 << endl;

	for (auto& e :  s1) {
		e--;
	}
	cout << s1 << endl;

	string::iterator it = s1.begin();
	while (it != s1.end()) {
		*it += 1;
		it++;
	}
	cout << s1 << endl;
}

//µü´úÆ÷
void test03() {
	string s1 = "1234";
	string::iterator it = s1.begin();
	while (it != s1.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;

	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend()) {
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	const string s2 = "6789";
	string::const_iterator cit = s2.begin();
	while (cit != s2.end()) {
		cout << *cit << " ";
		cit++;
	}
	cout << endl;

	string::const_reverse_iterator crt = s1.rbegin();
	while (crt != s1.rend()) {
		cout << *crt << " ";
		crt++;
	}
	cout << endl;
}

void test04() {
	string s1("hello world");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;

	s1.clear();
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl << endl;

	string s;
	s.reserve(1000);
	int capacity = s.capacity();

	cout << "StartCapacity: " << capacity << endl;

	for (int i = 0; i < 1000; i++) {
		s.push_back('*');
		if (capacity != s.capacity()) {
			capacity = s.capacity();
			cout << "ChangeCapacity: " << capacity << endl;
		}
	}

	string s2("hello world!");
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	string s3("hello world!");
	s3.resize(5);
	cout << s3.size() << endl;
	cout << s3.capacity() << endl << endl;

	string s4("hello world!");
	s4.resize(15, '*');
	cout << s4.size() << endl;
	cout << s4.capacity() << endl << endl;

	string s5("hello world!");
	s5.resize(50);
	cout << s5.size() << endl;
	cout << s5.capacity() << endl << endl;
}

void test05() {
	string s("asda");
	for (int i = 0; i < s.size(); i++) {
		//s.at(10);
		//s[10];
		cout << s.at(i) << " ";
	}
	cout << endl << endl;
	string s1("hello ");
	cout << s1 << endl << endl;
	s1.append("world!");
	cout << s1 << endl << endl;
	s1.append(1, '#');
	cout << s1 << endl << endl;
	s1.append(s);
	cout << s1 << endl << endl;
	s1.append(s, 2);
	cout << s1 << endl << endl;
	s1.append("sadsadsa", 5);
	cout << s1 << endl << endl;


	string s2("hello");
	s2.insert(2, s);
	cout << s2 << endl;
	s2.insert(2, "#####");
	cout << s2 << endl;
	s2.insert(2, "*****", 3);
	cout << s2 << endl;
	s2.insert(0, 6, '@');
	cout << s2 << endl;
	s2.insert(s2.begin(), 6, '!');
	cout << s2 << endl;
	s2.insert(s2.begin(), '&');
	cout << s2 << endl << endl;

	string s3;
	s3 += s;
	cout << s3 << endl;
	s3 += "%%%%";
	cout << s3 << endl;
	s3 += '&';
	cout << s3 << endl;

}

void test06() {
	string s1("hello world!");
	string str("abcdefghijklmn");
	cout << s1 << endl;
	s1.assign(str);
	cout << s1 << endl;
	s1.assign(str, 2, 3);
	cout << s1 << endl;

	s1.assign("hello");
	cout << s1 << endl;
	s1.assign("hello", 3);
	cout << s1 << endl;
	s1.assign(10, '#');
	cout << s1 << endl <<endl;
	
	string s3("hello world!");
	s3.replace(2, 3, "###");
	cout << s3 << endl;
	s3.replace(s3.begin(), s3.end(), "^^^^^^^^^^^^^^^");
	cout << s3 << endl;
	s3.replace(2, 3, "abcdefg", 2, 3);
	cout << s3 << endl;
	s3.replace(0, 5, "alsdk");
	cout << s3 << endl;
	s3.replace(3, 5, "asdkj", 4);
	cout << s3 << endl;
	s3.replace(2, 4, 10, '&');
	cout << s3 << endl;

	s3.erase(5, 4);
	cout << s3 << endl;
	s3.erase(5);
	cout << s3 << endl;
}

void test07() {
	string file("test01.cpp");
	FILE* pf = fopen(file.c_str(), "r");
	assert(pf);
	char ch=fgetc(pf);
	while (ch != EOF) {
		cout << ch;
		ch = fgetc(pf);
	}
	fclose(pf);
	pf = nullptr;
}

void test08() {
	string s1("hello world!");
	cout << s1.substr(3, 6) << endl;
}

class A {
public:
	friend A& operator+(int val, A& a);
private:
	int _a = 0;
};

A& operator+(int val, A& a) {
	a._a += val;
	return a;
}
int main() {
	//test06();
	//test07();
	//test08();
	A aa;
	//aa + 10;
	10 + aa;
	return 0;
}