//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//bool isPalindrome(string& str, int* start, int* end) {
//	int i = 0;
//	int j = str.size() - 1;
//	bool ret = true;
//	while (i < j) {
//		if (str[i] == str[j]) {
//			i++;
//			j--;
//		}
//		else {
//			ret = false;
//			break;
//		}
//	}
//	if (start != nullptr) *start = i;
//	if (end != nullptr) *end = j;
//	return ret;
//}
//int main() {
//	int t = 0;
//	cin >> t;
//	while (t--) {
//		string str;
//		cin >> str;
//		int start[1];
//		int end[1];
//		start[0] = end[0] = 0;
//		if (isPalindrome(str, start, end)) {
//			cout << -1 << endl;
//		}
//		else {
//			
//			str.erase(end[0], 1);
//			
//			if (isPalindrome(str, nullptr, nullptr)) {
//				cout << end[0] << endl;
//			}
//			else {
//				cout << start[0] << endl;
//			}
//		}
//	}
//	return 0;
//}