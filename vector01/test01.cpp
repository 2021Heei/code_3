#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


void prints(vector<int>& v) {
	/*for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;*/

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	/*for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;*/
}
void test01() {
	vector<int> v1;
	prints(v1);
	vector<int> v2(10, 1);
	prints(v2);
	vector<int> v3(v2.begin()+1, v2.end()-1);
	prints(v3);
	vector<int> v4(v2);
	prints(v4);

	v4 = vector<int>(10, 2);
	prints(v4);

	cout << v4.size() << endl;
	cout << v4.max_size() << endl;
	cout << vector<double>().max_size() << endl;
	cout << vector<char>().max_size() << endl;
	cout << vector<float>().max_size() << endl;
}

//容量和大小
void test02() {
	vector<int> v1(10, 2);
	prints(v1);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	v1.reserve(100);
	v1.resize(20, 3);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	prints(v1);

	//缩容,以时间换空间
	v1.shrink_to_fit();
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;

	cout << v1.front() << endl;
	cout << v1.back() << endl;
}
void test03() {
	vector<int> v1(10, 5);
	prints(v1);
	v1.assign(5, 4);
	prints(v1);

	vector<int> v2;
	v2.assign(v1.begin() + 1, v1.end() - 1);
	prints(v2);

	v2.push_back(10);
	v2.push_back(11);
	v2.push_back(12);
	prints(v2);
	v2.insert(v2.begin(), 99);
	prints(v2);
	v2.insert(v2.begin(), 5, 8);
	prints(v2);
	v2.insert(v2.begin(), v1.begin(), v1.end());
	prints(v2);
	cout << endl;
	v2.pop_back();
	v2.pop_back();
	v2.pop_back();
	prints(v2);
	v2.erase(v2.begin(), v2.begin() + 5);
	prints(v2);
	v2.erase(v2.begin());
	v2.erase(v2.begin());
	v2.erase(v2.begin());
	prints(v2);

	v2.clear();
	prints(v2);
}
void test04() {
	vector<int> v1(10, 5);
	vector<int> v2(5, 3);
	prints(v1);
	prints(v2);

	v1.swap(v2);
	prints(v1);
	prints(v2);

	v2.swap(v1);
	prints(v1);
	prints(v2);
	cout << endl;
	vector<int> v3(10, 4);
	vector<int> v4(5, 2);
	prints(v3);
	prints(v4);
	//非成员函数，优先匹配，因为参数不需要编译器推演，而是确定的，库函数中的swap需要推演，并且库函数swap是深拷贝，效率很低
	swap(v3, v4);
	prints(v3);
	prints(v4);
	//库函数
	std::swap(v3, v4);
	prints(v3);
	prints(v4);
}

#include "vector.h"

int main() {
	//test01();
	//test02();
	//test03();
	//test04();

	//weihe::test01();
	//weihe::test02();
	//weihe::test03();
	//weihe::test04();
	weihe::test05();
	return 0;
}