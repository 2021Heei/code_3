//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//
//using namespace std;
//
//bool getNum(int val) {
//	int sum = 0;
//	for (int i = 1; i < val; ++i) {
//		if (val % i == 0) {
//			sum += i;
//		}
//	}
//	return sum == val;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	int cnt = 0;
//	for (int i = 2; i <= n; ++i) {
//		if (getNum(i)) {
//			++cnt;
//		}
//	}
//
//	cout << cnt << endl;
//	string str("hello");
//	cout << str << endl;
//	return 0;
//}


/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool isKing(vector<string>& vs) {
	if (vs.size() == 2 && vs[0] == "joker" && vs[1] == "JOKER") {
		return true;
	}
	return false;
}
bool isSeq(vector<string>& vs) {

	for (int i = 0; i < vs.size() - 1; ++i) {
		if (vs[i][0] + 1 != vs[i + 1][0]) {
			return false;
		}
	}
	return true;
}
int main() {
	string str;
	getline(cin, str);
	vector<string> l;
	vector<string> r;

	bool flag = false;
	int i = 0, j = 0;
	for (; i < str.size(); ++i) {
		if (str[i] == '-') {
			string tmp;
			while (j < i) {
				tmp += str[j++];
			}
			l.push_back(tmp);
			j++;
			flag = true;
		}
		else if (str[i] == ' ' && !flag) {
			//fuzhi
			string tmp;
			while (j < i) {
				tmp += str[j++];
			}
			l.push_back(tmp);
			j++;
		}
		else if (str[i] == ' ' && flag) {
			string tmp;
			while (j < i) {
				tmp += str[j++];
			}
			r.push_back(tmp);
			j++;
		}
	}

	string tmp;
	while (j < i) {
		tmp += str[j++];
	}
	r.push_back(tmp);

	//Âß¼­²¿·Ö
	if (l.size() == 1 && r.size() == 1) {
		if (l[0][0] > r[0][0]) cout << l[0] << endl;
		else cout << r[0] << endl;
	}
	else if (l.size() == 2 && r.size() == 2) {
		if (l[0] == l[1] && r[0] == r[1]) {
			if (l[0][0] > r[0][0]) {
				for (int i = 0; i < 2; ++i) {
					cout << l[i][0];
					if (i < 1) cout << " ";
				}
			}
			else {
				for (int i = 0; i < 2; ++i) {
					cout << r[i][0];
					if (i < 1) cout << " ";
				}
			}
			cout << endl;
		}
		else {
			cout << "ERROR" << endl;
		}

	}
	else if (l.size() == 3 && r.size() == 3) {
		if (l[0] == l[1] && l[0] == l[2] && r[0] == r[1] && r[0] == r[2]) {
			if (l[0][0] > r[0][0]) {
				for (int i = 0; i < 3; ++i) {
					cout << l[i][0];
					if (i < 2) cout << " ";
				}
			}
			else {
				for (int i = 0; i < 3; ++i) {
					cout << r[i][0];
					if (i < 2) cout << " ";
				}
			}
			cout << endl;
		}
		else {
			cout << "ERROR" << endl;
		}
	}
	else if (l.size() == 4 && r.size() == 4) {
		if (l[0] == l[1] && l[0] == l[2] && l[0] == l[3] && r[0] == r[1] && r[0] == r[2] && r[0] == r[3]) {
			if (l[0][0] > r[0][0]) {
				for (int i = 0; i < 4; ++i) {
					cout << l[i][0];
					if (i < 3) cout << " ";
				}
			}
			else {
				for (int i = 0; i < 4; ++i) {
					cout << r[i][0];
					if (i < 3) cout << " ";
				}
			}
			cout << endl;
		}
		else {
			cout << "ERROR" << endl;
		}


	}
	else if (l.size() == 5 && r.size() == 5) {
		if (isSeq(l) && isSeq(r)) {
			if (l[0][0] > r[0][0]) {
				for (int i = 0; i < 5; ++i) {
					cout << l[i][0];
					if (i < 4) cout << " ";
				}
			}
			else {
				for (int i = 0; i < 5; ++i) {
					cout << r[i][0];
					if (i < 4) cout << " ";
				}
			}
			cout << endl;
		}
		else {
			cout << "ERROR" << endl;
		}

	}
	else if (isKing(l) || isKing(r)) {
		//joker
		cout << "joker JOKER" << endl;
	}
	else if (l.size() == 4 && r.size() != 4 && l[0] == l[1] && l[0] == l[2] && l[0] == l[3]) {
		for (int i = 0; i < 4; ++i) {
			cout << l[i][0];
			if (i < 3) cout << " ";
		}
	}
	else if (r.size() == 4 && l.size() != 4 && r[0] == r[1] && r[0] == r[2] && r[0] == r[3]) {
		for (int i = 0; i < 4; ++i) {
			cout << r[i][0];
			if (i < 3) cout << " ";
		}
	}
	else {
		cout << "ERROR" << endl;
	}

	return 0;
}

*/

#include <iostream>
#include <vector>

using namespace std;

void prints(vector < vector<int>>& v) {
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int n;
	cin >> n;
	vector<vector<int>> v;
	//2*(n-1)+1
	vector<int> tmp;
	for (int i = 0; i < n; ++i) {
		tmp.clear();
		int size = 2 * (i + 1 - 1) + 1;
		for (int j = 0; j < size; ++j) {
			if (i == 0 || j == 0 || j == size - 1) {
				tmp.push_back(1);
			}
			else {
				int a = j - 2 >= 0 && j-2 < v[i-1].size() ? v[i - 1][j - 2] : 0;
				int b = j - 1 >= 0 && j-1 < v[i-1].size() ? v[i - 1][j - 1] : 0;
				int c = j >= 0 && j < v[i-1].size() ? v[i - 1][j] : 0;
				//v[i][j] = a + b + c;
				tmp.push_back(a + b + c);
			}
		}
		v.push_back(tmp);
	}
	prints(v);
	int index = -1;
	for (int i = 0; i < v[n - 1].size(); ++i) {
		if (v[n - 1][i] % 2 == 0) {
			index = i + 1;
			break;
		}
	}
	cout << index << endl;
	return 0;
}

