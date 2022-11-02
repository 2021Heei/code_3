#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

//int main() {
//	string str("hello world!");
//	//operator[]
//	for (int i = 0; i < str.size(); ++i) {
//		cout << str[i] << " ";
//	}
//	cout << endl;
//	//范围for
//	for (auto ch : str) {
//		cout << ch << " ";
//	}
//	cout << endl;
//	//迭代器
//	string::iterator it = str.begin();
//	while (it != str.end()) {
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	return 0;
//}

//int main() {
//	char str1[] = "abcd";
//	char str2[] = "apple";
//
//	char str3[] = "未禾";
//	str3[3]++;
//	str3[3]++;
//	str3[3]++;
//	str3[3]--;
//	str3[3]--;
//	str3[3]--;
//	return 0;
//}
//讲string先讲编码，现阶段了解即可，以后可以探索一下
//unicode 统一码
//GBK 国标


//template<class T>
//class basic_string {
//	T* _str;
//	size_t _size;
//	size_t _capacity;
//};
//typedef basic_string<char> string;

void test1() {
	//构造和拷贝构造
	string s1;
	string s2("hello");
	string s3 = "world";//隐式类型转换
	string s4(10, '#');
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	s2 += "world";
	cout << s2 << endl;

	string s5(s2);//拷贝构造
	string s6 = s2;
	cout << s5 << endl;
	cout << s6 << endl;

	string s7("hello world!", 8);
	cout << s7 << endl;
	//string s8("hello world!", 2, 5);
	string s8("hello world!", 2, 30);
	cout << s8 << endl;
	//超过了字符串长度，则只拷贝到字符串结束
	string s9("hello world!", 2);
	cout << s9 << endl;
}

void test2() {
	//遍历
	string s1("12345");
	//下标
	//只支持string和vector，不通用
	for (size_t i = 0; i < s1.size(); ++i) {
		//s1.operator[](i)++;
		s1[i]++;
	}
	cout << s1 << endl;

	//范围for
	//底层是迭代器，编译器会先转换为迭代器在编译
	for (auto& ch : s1) {
		ch--;
	}
	cout << s1 << endl;

	//逆置
	size_t begin = 0;
	size_t end = s1.size() - 1;
	while (begin < end) {
		swap(s1[begin++], s1[end--]);
	}
	cout << s1 << endl;

	reverse(s1.begin(), s1.end());
	cout << s1 << endl;

	//迭代器
	//底层可能是指针，也可能不是，表现上像指针
	//对于STL容器的通用遍历方式
	string::iterator it = s1.begin();
	while (it != s1.end()) {
		(*it)++;
		it++;
	}
	cout << s1 << endl;

	it = s1.begin();
	while (it != s1.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;

	vector<int> v;
	vector<int>::iterator vit = v.begin();
	while (vit != v.end()) {
		cout << *vit << " ";
		vit++;
	}
	cout << endl;
	list<int> l;
	list<int>::iterator lit = l.begin();
	while (lit != l.end()) {
		cout << *lit << " ";
		lit++;
	}
	cout << endl;
}

//正向	反向			能遍历读和写
//const正向	const反向	只能遍历读，不能修改容器数据
void test3() {
	//迭代器
	string s1("12345");
	//普通迭代器
	string::iterator it = s1.begin();
	while (it != s1.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//反向迭代器
	//string::reverse_iterator rit = s1.rbegin();
	auto rit = s1.rbegin();
	while (rit != s1.rend()) {
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	//const正向迭代器
	const string s2("12345");
	//const修饰迭代器对象cit指向内容
	string::const_iterator cit = s2.begin();
	//auto cit = s2.begin();//auto
	//const修饰迭代器对象cit本身
	//const string::const_iterator cit = s2.begin();
	while (cit != s2.end()) {
		cout << *cit << " ";
		cit++;
	}
	cout << endl;

	//const反向迭代器
	//string::const_reverse_iterator rcit = s2.rbegin();
	auto crit = s2.rbegin();
	while (crit != s2.rend()) {
		cout << *crit << " ";
		crit++;
	}
	cout << endl;
}

//函数什么时候实现非const版本，什么时候实现const版本呢？
//看功能
//函数只读，实现const版本
//函数只写，实现非const版本
//汉纳树可读可写，实现const+非const版本

int main() {
	//test1();
	//test2();
	test3();
	return 0;
}