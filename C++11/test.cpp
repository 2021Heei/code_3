#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	//初始化列表，提升为一个类模板了
	auto il01 = { 1, 2, 3, 4 };
	auto il02 = { 1.5f, 2.5f, 3.5f, 4.6f };
	auto il03 = { "sd", "dsada", "dsasda", "dsa"};
	cout << typeid(il01).name() << endl;
	cout << typeid(il02).name() << endl;
	cout << typeid(il03).name() << endl;
	int a1 = 1;
	int a2 = { 1 };
	int a3{ 1 };

	vector<int> v1 = { 1,2,3,4 };
	vector<int> v2{ 1,2,3,4 };
	map<string, int> m = { {"str1", 1}, {"str2", 1} };
	return 0;
}