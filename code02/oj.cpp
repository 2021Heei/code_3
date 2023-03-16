#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

bool getNum(int val) {
	int sum = 0;
	for (int i = 1; i < val; ++i) {
		if (val % i == 0) {
			sum += i;
		}
	}
	return sum == val;
}

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		if (getNum(i)) {
			++cnt;
		}
	}

	cout << cnt << endl;
	return 0;
}