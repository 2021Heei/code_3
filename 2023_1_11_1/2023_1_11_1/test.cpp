//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//int addAB(int A, int B) {
//    // write code here
//    /*
//    1010
//    1000
//
//
//
//    10010
//    */
//    int ret = 0;
//    int carry = 0;
//	for (int i = 0; i < 32; i++) {
//		int a = (A >> i) & 1;
//		int b = (B >> i) & 1;
//
//		int tmp = (a << 2) | (b << 1) | carry;
//		if (tmp == 0) {
//			carry = 0;
//			//结果为0，进位为0
//		}
//		else if (tmp == 1 || tmp == 2 || tmp == 4) {
//			carry = 0;//结果为1，进位为0
//			ret = ret | (1 << i);
//		}
//		else if (tmp == 3 || tmp == 5 || tmp == 6) {
//			carry = 1;//结果为0，进位为1
//		}
//		else {
//			carry = 1;//结果为1，进位为1
//			ret = ret | (1 << i);
//		}
//
//	}
//    //for (int i = 0; i < 32; i++) {
//    //    int a = (A >> i) & 1;
//    //    int b = (B >> i) & 1;
//
//
//
//    //    if (a + b + carry == 0) {
//
//    //    }
//    //    else if (a + b + carry == 1) {
//    //        carry = 0;//没有进位，余1
//    //        ret = ret | (1 << i);
//    //    }
//    //    else if (a + b + carry == 2) {
//    //        carry = 1;//有进位，且进1余0
//    //    }
//    //    else if (a + b + carry == 3) {
//    //        carry = 1;//有进位，且进1余1
//    //        ret = ret | (1 << i);
//    //    }
//
//    //}
//    return ret;
//}
//
//int main() {
//
//    cout << addAB(10, 8) << endl;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int func(int n, int m,int x, int y) {
//	if (x == n && y == m) {
//		return 0;
//	}
//	if (x == n || y == m) {
//		return 1;
//	}
//	return func(n, m, x + 1, y) + func(n, m, x, y + 1);
//}
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int ret = func(n+1, m+1, 1, 1);
//	cout << ret << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//	/*const int a = 10;
//	int* p = (int*)&a;
//	*p = 20;
//	cout << a << endl;
//	cout << *p << endl;*/
//	vector<vector<int>> board;
//	int a;
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;

int main() {
	string key;
	cin >> key;

	int score = 0;
	//length
	if (key.size() <= 4) {
		score += 5;
	}
	else if (key.size() >= 5 && key.size() <= 7) {
		score += 10;
	}
	else {
		score += 25;
	}

	int digit = 0;
	int lower = 0;
	int upper = 0;
	int symbol = 0;

	for (auto e : key) {
		if (islower(e)) {
			lower++;
		}
		else if (isupper(e)) {
			upper++;
		}
		else if (isdigit(e)) {
			digit++;
		}
		else {
			symbol++;
		}
	}
	//letter
	if (lower >= 1 && upper >= 1) {
		score += 20;
	}
	else if ((lower >= 1 && upper == 0) || (lower == 0 && upper >= 1)) {
		score += 10;
	}
	else {
		score += 0;
	}

	//digit
	if (digit == 0) {
		score += 0;
	}
	else if (digit == 1) {
		score += 10;
	}
	else {
		score += 20;
	}

	//symbol
	if (symbol == 0) {
		score += 0;
	}
	else if (symbol == 1) {
		score += 10;
	}
	else {
		score += 20;
	}

	//award
	if (lower >= 1 && upper >= 1 && digit >= 1 && symbol >= 1) {
		score += 5;
	}
	else if ((lower >= 1 || upper >= 1) && digit >= 1 && symbol >= 1) {
		score += 3;
	}
	else if ((lower >= 1 || upper >= 1) && digit >= 1) {
		score += 2;
	}

	//
	if (score >= 90) {
		cout << "VERY_SECURE" << endl;
	}
	else if (score >= 80) {
		cout << "SECURE" << endl;
	}
	else if (score >= 70) {
		cout << "VERY_STRONG" << endl;
	}
	else if (score >= 60) {
		cout << "STRONG" << endl;
	}
	else if (score >= 50) {
		cout << "AVERAGE" << endl;
	}
	else if (score >= 25) {
		cout << "WEAK" << endl;
	}
	else {
		cout << "VERY_WEAK" << endl;
	}

	return 0;
}