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
//�������ɶ���д��ʵ��const+��const�汾

int main() {
	//test1();
	//test2();
	test3();
	return 0;
}