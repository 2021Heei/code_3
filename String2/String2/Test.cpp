#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str("hello world!");
	//operator[]
	for (int i = 0; i < str.size(); ++i) {
		cout << str[i] << " ";
	}
	cout << endl;
	//��Χfor
	for (auto ch : str) {
		cout << ch << " ";
	}
	cout << endl;
	//������
	string::iterator it = str.begin();
	while (it != str.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	return 0;
}
