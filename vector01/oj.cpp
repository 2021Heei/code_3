#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



	void DfsString(string& s, int start, vector<string>& result) {
		if (start == s.size() - 1) {
			//去重
			if (find(result.begin(), result.end(), s) == result.end()) {
				result.push_back(s);
			}

		}
		//依次以所给字符串的每一个元素作为开头，进行排列
		for (int i = start; i < s.size(); i++) {
			//每个元素先交换到首位置
			swap(s[start], s[i]);
			//分解字符串，首位置确定，再从子范围递归排列
			DfsString(s, start + 1, result);
			//恢复字符串原先顺序，为下一次元素交换做准备
			swap(s[start], s[i]);
		}
	}

	vector<string> Permutation(string s) {
		vector<string> result;
		if (s.size() == 0) return result;
		DfsString(s, 0, result);
		sort(result.begin(), result.end());
		return result;
	}


//int main() {
//	string s1 = "abcdefgi";
//	//string s1 = "qwertyuio";
//	vector<string> vs = Permutation(s1);
//	for (auto& e : vs) {
//		cout << e << endl;
//	}
//	return 0;
//}