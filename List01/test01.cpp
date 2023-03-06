#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
#include <algorithm>
#include <time.h>
#include <vector>
using namespace std;
#include "List.h"


void prints(list<int>& l) {
	for (auto& e : l) {
		cout << e << " ";
	}
	cout << endl;
}
void test01() {
	list<int> l1;
	list<int> l2(10, 5);
	list<int> l3(++l2.begin(), --l2.end());
	list<int> l4(l2);
	prints(l1);
	prints(l2);
	prints(l3);
	prints(l4);

	list<int> l5;
	l5.push_back(1);
	l5.push_back(2);
	l5.push_front(3);
	l5.push_back(4);
	prints(l5);
	cout << l5.front() << " " << l5.back() << endl;
	l5.assign(l2.begin(), l2.end());
	prints(l5);
	l5.assign(5, 10);
	prints(l5);


}

void test02() {
	list<int> l1;
	list<int> l2(2, 4);
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	list<int>::iterator it = l1.begin();
	prints(l1);
	l1.insert(it, 10);
	prints(l1);
	l1.insert(it, 3, 9);
	prints(l1);
	l1.insert(it, l2.begin(), l2.end());
	prints(l1);
	cout << endl;
	it = l1.end();
	it--;
	it--;
	it = l1.erase(it);
	prints(l1);
	l1.erase(it);
	prints(l1);

	cout << l1.size() << endl;
	l1.resize(5);
	cout << l1.size() << endl;
	prints(l1);

	cout << l1.size() << endl;
	l1.resize(10, 1);
	cout << l1.size() << endl;
	prints(l1);

	l1.push_front(1);
	prints(l1);

	/*l1.remove(1);
	prints(l1);*/

	cout << endl << endl;
	/*prints(l1);
	prints(l2);
	l1.splice(++l1.begin(), l2, l2.begin(), l2.end());
	prints(l1);
	prints(l2);*/
	prints(l1);
	l1.sort();
	
	l1.unique();
	prints(l1);

	l1.reverse();
	prints(l1);

	list<int> a = { 10, 20 ,30 };
	list<int> b = { 10, 20 ,30 };
	list<int> c = { 30, 20 ,30 };
	if (a == b) cout << "a==b" << endl;
	if (a > b) cout << "a>b" << endl;
	if (b < c) cout << "b<c" << endl;
}

void test03() {
	srand(time(0));
	const int N = 1000000;
	vector<int> v;
	v.reserve(N);
	vector<int> tmp;
	tmp.reserve(N);
	list<int> l1;
	list<int> l2;
	list<int> l3;
	for (int i = 0; i < N; i++) {
		auto e = rand();
		l1.push_back(e);
		l2.push_back(e);
		l3.push_back(e);
		v.push_back(e);
	}

	int begin1 = clock();
	sort(v.begin(), v.end());
	int end1 = clock();

	int begin2 = clock();
	for (auto e : l1) {
		tmp.push_back(e);
	}
	sort(tmp.begin(), tmp.end());
	int i = 0;
	for (auto& e : l1) {
		e = tmp[i++];
	}
	int end2 = clock();

	int begin3 = clock();
	l3.sort();
	int end3 = clock();

	int begin4 = clock();
	l2.sort();
	int end4 = clock();
	cout << end1 - begin1 << endl;
	cout << end2 - begin2 << endl;
	cout << end3 - begin3 << endl;
	cout << end4 - begin4 << endl;
	
}
int main() {
	//test01();
	//test02();
	//test03();

	weihe::test01();
	return 0;
}