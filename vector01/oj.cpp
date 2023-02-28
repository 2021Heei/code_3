#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



	void DfsString(string& s, int start, vector<string>& result) {
		if (start == s.size() - 1) {
			//ȥ��
			if (find(result.begin(), result.end(), s) == result.end()) {
				result.push_back(s);
			}

		}
		//�����������ַ�����ÿһ��Ԫ����Ϊ��ͷ����������
		for (int i = start; i < s.size(); i++) {
			//ÿ��Ԫ���Ƚ�������λ��
			swap(s[start], s[i]);
			//�ֽ��ַ�������λ��ȷ�����ٴ��ӷ�Χ�ݹ�����
			DfsString(s, start + 1, result);
			//�ָ��ַ���ԭ��˳��Ϊ��һ��Ԫ�ؽ�����׼��
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