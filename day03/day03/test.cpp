#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

bool IsDigit(char ch) {
	if (ch >= '0' && ch <= '9') {
		return true;
	}

	return false;
}

//产找pos开始的数字串的大小
long long FindIndex(string& str, long long pos) {
	int count = 0;
	for (long long i = pos; i < str.size(); ++i) {
		cout << isdigit(str[pos]) << " ";
		if (!isdigit(str[pos])) {
			break;
		}
		count++;
	}
	cout << endl;
	return count;
}

int main() {
	string str;
	cin >> str;
	long long max = 0;
	long long index = 0;
	for (long long i = 0; i < str.size(); ++i) {
		if (isdigit(str[i])) {
			long long newmax = FindIndex(str, i);
			if (max < newmax) {
				max = newmax;
				index = i;
			}
		}
		else {
			continue;
		}
	}
	cout << max << endl;
	cout << index << endl;
	for (long long i = index; i < str.size() && isdigit(str[i]); i++) {
		cout << str[i];
	}
	cout << endl;
	return 0;
}