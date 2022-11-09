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
//	//��Χfor
//	for (auto ch : str) {
//		cout << ch << " ";
//	}
//	cout << endl;
//	//������
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
//	char str3[] = "δ��";
//	str3[3]++;
//	str3[3]++;
//	str3[3]++;
//	str3[3]--;
//	str3[3]--;
//	str3[3]--;
//	return 0;
//}
//��string�Ƚ����룬�ֽ׶��˽⼴�ɣ��Ժ����̽��һ��
//unicode ͳһ��
//GBK ����


//template<class T>
//class basic_string {
//	T* _str;
//	size_t _size;
//	size_t _capacity;
//};
//typedef basic_string<char> string;

void test1() {
	//����Ϳ�������
	string s1;
	string s2("hello");
	string s3 = "world";//��ʽ����ת��
	string s4(10, '#');
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	s2 += "world";
	cout << s2 << endl;

	string s5(s2);//��������
	string s6 = s2;
	cout << s5 << endl;
	cout << s6 << endl;

	string s7("hello world!", 8);
	cout << s7 << endl;
	//string s8("hello world!", 2, 5);
	string s8("hello world!", 2, 30);
	cout << s8 << endl;
	//�������ַ������ȣ���ֻ�������ַ�������
	string s9("hello world!", 2);
	cout << s9 << endl;
}

void test2() {
	//����
	string s1("12345");
	//�±�
	//ֻ֧��string��vector����ͨ��
	for (size_t i = 0; i < s1.size(); ++i) {
		//s1.operator[](i)++;
		s1[i]++;
	}
	cout << s1 << endl;

	//��Χfor
	//�ײ��ǵ�����������������ת��Ϊ�������ڱ���
	for (auto& ch : s1) {
		ch--;
	}
	cout << s1 << endl;

	//����
	size_t begin = 0;
	size_t end = s1.size() - 1;
	while (begin < end) {
		swap(s1[begin++], s1[end--]);
	}
	cout << s1 << endl;

	reverse(s1.begin(), s1.end());
	cout << s1 << endl;

	//������
	//�ײ������ָ�룬Ҳ���ܲ��ǣ���������ָ��
	//����STL������ͨ�ñ�����ʽ
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

//����	����			�ܱ�������д
//const����	const����	ֻ�ܱ������������޸���������
void test3() {
	//������
	string s1("12345");
	//��ͨ������
	string::iterator it = s1.begin();
	while (it != s1.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//���������
	//string::reverse_iterator rit = s1.rbegin();
	auto rit = s1.rbegin();
	while (rit != s1.rend()) {
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	//const���������
	const string s2("12345");
	//const���ε���������citָ������
	string::const_iterator cit = s2.begin();
	//auto cit = s2.begin();//auto
	//const���ε���������cit����
	//const string::const_iterator cit = s2.begin();
	while (cit != s2.end()) {
		cout << *cit << " ";
		cit++;
	}
	cout << endl;

	//const���������
	//string::const_reverse_iterator rcit = s2.rbegin();
	auto crit = s2.rbegin();
	while (crit != s2.rend()) {
		cout << *crit << " ";
		crit++;
	}
	cout << endl;
}

//����ʲôʱ��ʵ�ַ�const�汾��ʲôʱ��ʵ��const�汾�أ�
//������
//����ֻ����ʵ��const�汾
//����ֻд��ʵ�ַ�const�汾
//�����ɶ���д��ʵ��const+��const�汾


//
void test4() {
	string s1("hello world");
	cout << s1.size() << endl;
	//����length��size��ʷ�Ľ���
	//string������STL�ĳ��֣�STL��Ҳ��һ��string
	//C++��׼���STL�ӽ���ʱû��ҪSTL���string���������õ�ԭ����string
	//ԭ��string��ʵ�����б�ʾ��Ч�ַ�������length()��
	//��STL����ͬ���ܵ���size()������ԭstring��������size()����STL����һ��
	//����size()��������˼����STL�и���ͨ�ã���length()
	//Ҳֻ��string������length()��STL������������û��length()��ֻ��size(),���㹻��
	//
	cout << s1.length() << endl;

	cout << s1.capacity() << endl;
	//��max_size()����ʹ�ò��࣬�Ƚϼ��ߵĺ�����ƣ�һ�㲻�ᱻɾ������ΪC++�﷨����ǰ���ݵģ�
	cout << s1.max_size() << endl;

	/*string ss;
	cout << ss.max_size() << endl;*/

	string s2("hello world");
	cout << s2 << endl;
	cout << s2.capacity() << endl;
	//clear()�Ƿ�����ռ��أ�
	//���Ǳ�׼δ����ģ������壬Ҳ���ܲ��壬����û��Ӱ���
	s2.clear();
	cout << s2 << endl;
	cout << s2.capacity() << endl;
	if (!s2.empty()) {
		cout << s2 << endl;
	}
	else {
		cout << "s2�ǿմ�" << endl;
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
	//�������п����ģ�
	//������ֱ�������Ҫ�Ŀռ�ʱ�����ǿ�����ǰ����reserveһ���ӽ��Ĵ�С���������ݴ��������Ч��
	//ע����reverse����
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
	//��ͬ������������ʵ���в��
	//g++�ϸ�2��
	//vs����1.5��
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
	//��Ϊ3�����
	//resize<size��ɾ������
	//resize>size && resize<capacity������ָ��size֮����ַ���Ĭ��ʱ'\0'����������
	//resize>capacity������+��������
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
		//s1[100];//���Ա���
	}
	cout << endl;

	for (int i = 0; i < s1.size(); ++i) {
		cout << s1.at(i) << " ";
		//s1.at(100);//���쳣
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

	//insert��erase ������Ų���������ݣ�ʱ�临�Ӷȸߣ�Ч�ʵͣ�����ʹ�ò�����
	string s5("hello world");
	//insert��pos��Ч��Χ�����쳣
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
	cout << "ǰ" << s8 << endl;
	cout << "ǰ" << s9 << endl;
	s8.swap(s9);
	cout << "��" << s8 << endl;
	cout << "��" << s9 << endl << endl;

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