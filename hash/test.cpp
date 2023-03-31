#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

void test() {
	int arr[] = { 1,3,2,5,4,1,2,3,4 };
	unordered_set<int> uns;
	for (auto& e : arr) {
		uns.insert(e);
	}
	for (auto& e : uns) {
		cout << e << " ";
	}
	cout << endl;
	unordered_set<int>::iterator it = uns.begin();
	while (it != uns.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	unordered_map<int, int> unm;
	for (auto& e : arr) {
		unm[e]++;
	}
	for (auto& e : unm) {
		cout << e.first << ":" << e.second << endl;
	}
}
#include "hash.h"
int main() {
	
	closehash::test01();
	return 0;
}