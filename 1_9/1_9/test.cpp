//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class A {
//public:
//	A(int val = 0) {
//		_val = val;
//	}
//	A(const A& a) {
//		cout << "**" << endl;
//		_val = a._val;
//	}
//	A& operator=(A a) {
//		cout << "##" << endl;
//		_val = a._val;
//		return *this;
//	}
//private:
//	int _val;
//};
//
//A test(A a) {
//	A b(a);
//	A c = b;
//	return c;
//}
//
//int main() {
//	A aa;
//	A ret = test(test(aa));
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <cstdbool>
//using namespace std;
//
//bool isLength(vector<string>& vs, int n) {
//	
//	for (int i = 0; i < n-1; ++i) {
//		if (vs[i].size() > vs[i + 1].size()) {
//			return false;
//		}
//	}
//	return true;
//}
//
//bool isOrder(const string& s1, const string& s2) {
//	int len1 = s1.size();
//	int len2 = s2.size();
//	int i = 0;
//	while (len1 && len2) {
//		if (s1[i] > s2[i]) {
//			return false;
//		}
//		len1--;
//		len2--;
//		i++;
//	}
//	
//	return len1 == 0;
//}
//
//bool isLexicographically(vector<string>& vs, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		if (!isOrder(vs[i], vs[i+1])) {
//			return false;
//		}
//	}
//	return true;
//}
//
//int main() {
//	vector<string> vs;
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		string tmp;
//		cin >> tmp;
//		vs.push_back(tmp);
//	}
//
//	bool lex = isLexicographically(vs, n);
//	bool len = isLength(vs, n);
//	if (lex && len) {
//		cout << "both" << endl;
//	}
//	else if (lex && !len) {
//		cout << "lexicographically" << endl;
//	}
//	else if (!lex && len) {
//		cout << "lengths" << endl;
//	}
//	else {
//		cout << "none" << endl;
//	}
//
//	return 0;
//}

#include <iostream>
using namespace std;
/*

10	16
16	10
10	6
6	4
4	2
2	0

*/
int function(int a, int b) {

	while (b) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {
	int a, b;
	cin >> a >> b;
	//辗转相除法求最大公因数
	int ret = function(a, b);
	//cout << ret << endl;
	//最小公倍数
	cout << (a * b) / ret << endl;
	return 0;
}