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
//函数可读可写，实现const+非const版本


//
void test4() {
	string s1("hello world");
	cout << s1.size() << endl;
	//关于length与size历史的解释
	//string类早于STL的出现，STL里也有一个string
	//C++标准库把STL加进来时没有要STL里的string，而是沿用的原来的string
	//原本string类实现中有表示有效字符个数的length()，
	//而STL里相同功能的是size()，所以原string类增加了size()，与STL保持一致
	//并且size()从字面意思上在STL中更加通用，比length()
	//也只有string类中有length()，STL中其他容器并没有length()，只有size(),这足够了
	//
	cout << s1.length() << endl;

	cout << s1.capacity() << endl;
	//像max_size()这样使用不多，比较鸡肋的函数设计，一般不会被删除，因为C++语法是向前兼容的，
	cout << s1.max_size() << endl;

	/*string ss;
	cout << ss.max_size() << endl;*/

	string s2("hello world");
	cout << s2 << endl;
	cout << s2.capacity() << endl;
	//clear()是否清理空间呢？
	//这是标准未定义的，可能清，也可能不清，这是没有影响的
	s2.clear();
	cout << s2 << endl;
	cout << s2.capacity() << endl;
	if (!s2.empty()) {
		cout << s2 << endl;
	}
	else {
		cout << "s2是空串" << endl;
	}
	
	string s3(100, '#');
	cout << "1: " << s3.capacity() << endl;
	//s3.clear();
	s3.resize(5);
	cout << "2: " << s3.capacity() << endl;
	s3.shrink_to_fit();
	cout << "3: " << s3.capacity() << endl;
}

void TestPushBack() {
	string s;
	//扩容是有开销的，
	//当我们直到大概需要的空间时，我们可以提前开辟reserve一个接近的大小，减少扩容次数，提高效率
	//注意与reverse区分
	//s.reserve(1000);
	size_t sz = s.capacity();
	cout << "initcapacity: " << sz << endl;
	for (int i = 0; i < 1000; ++i) {
		s.push_back('#');
		if (sz != s.capacity()) {
			sz = s.capacity();
			cout << "newcapacity: " << sz << endl;
		}
	}
}

//reserve
void test5() {
	//不同编译器的扩容实现有差别
	//g++严格2倍
	//vs大致1.5倍
	TestPushBack();

	string s1("hello world!");
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	s1.reserve(5);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}

//resize
void test6() {
	//分为3种情况
	//resize<size，删除数据
	//resize>size && resize<capacity，可以指定size之后的字符，默认时'\0'，插入数据
	//resize>capacity，扩容+插入数据
	string s1("hello world!");
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	s1.resize(5);
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl << endl;

	string s2("hello world!");
	cout << s2 << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	s2.resize(15);
	//s2.resize(15, '#');
	cout << s2 << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	string s3("hello world!");
	cout << s3 << endl;
	cout << s3.size() << endl;
	cout << s3.capacity() << endl;
	s3.resize(25);
	//s3.resize(25, '#');
	cout << s3 << endl;
	cout << s3.size() << endl;
	cout << s3.capacity() << endl << endl;
}

void test7() {
	string s1("hello world");
	for (int i = 0; i < s1.size(); ++i) {
		cout << s1[i] << " ";
		//s1[100];//断言报错
	}
	cout << endl;

	for (int i = 0; i < s1.size(); ++i) {
		cout << s1.at(i) << " ";
		//s1.at(100);//抛异常
	}
	cout << endl;
}

//modify
void test8() {
	string s1("hello world!");
	s1.push_back('1');
	s1.push_back('2');
	s1.push_back('3');
	cout << s1 << endl << endl;

	string s2("hello world!");
	s2.append("12345");
	cout << s2 << endl;
	string tmp("abcde");
	s2.append(tmp);
	cout << s2 << endl;
	s2.append("12345", 3);
	cout << s2 << endl <<endl;

	string s3("hello world");
	s3 += '#';
	cout << s3 << endl;
	s3 += "12345";
	cout << s3 << endl;
	s3 += tmp;
	cout << s3 << endl << endl;

	string s4("hello world");
	s4.assign("12345123451234512345");
	cout << s4 << endl;
	cout << s4.size() << endl;
	cout << s4.capacity() << endl;
	s4.assign(tmp);
	cout << s4 << endl;
	cout << s4.size() << endl;
	cout << s4.capacity() << endl << endl;

	//insert和erase 往往会挪动大量数据，时间复杂度高，效率低，所以使用并不多
	string s5("hello world");
	//insert的pos无效范围会抛异常
	/*cout << s5.size() << endl;
	cout << s5.capacity() << endl;*/
	/*s5.insert(5, "#####");
	cout << s5 << endl;*/
	s5.insert(5, "#####", 3);
	cout << s5 << endl;
	/*s5.insert(5, tmp);
	cout << s5 << endl;*/
	s5.insert(5, tmp, 2, 3);
	cout << s5 << endl << endl;
	/*cout << s5.size() << endl;
	cout << s5.capacity() << endl;*/

	string s6("hello world");
	cout << s4.size() << endl;
	cout << s4.capacity() << endl << endl;
	s6.erase(5, 3);
	cout << s6 << endl;
	s6.erase(2);
	cout << s6 << endl;
	cout << s4.size() << endl;
	cout << s4.capacity() << endl << endl;

	string s7("hello world");
	/*s7.replace(6, 5, "weihe");
	cout << s7 << endl;*/
	s7.replace(6, 3, "weihexxxxxxxxx", 3, 9);
	cout << s7 << endl;
	/*s7.replace(6, 5, tmp);
	cout << s7 << endl;*/
	s7.replace(6, 3, tmp, 2, 4);
	cout << s7 << endl;
	s7.replace(6, 3, 10, '#');
	cout << s7 << endl << endl;

	string s8("hello world");
	string s9("abcde");
	cout << "前" << s8 << endl;
	cout << "前" << s9 << endl;
	s8.swap(s9);
	cout << "后" << s8 << endl;
	cout << "后" << s9 << endl << endl;

	string s("weihe");
	cout << s.c_str() << endl;
}

//int main() {
//	//test1();
//	//test2();
//	//test3();
//	//test4();
//	//test5();
//	//test6();
//	//test7();
//	test8();
//	return 0;
//}