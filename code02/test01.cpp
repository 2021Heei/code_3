#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

using namespace std;

bool contain(const string& s, const vector<string>& wordDict) {
	for (int i = 0; i < wordDict.size(); i++) {
		if (s == wordDict[i]) {
			return true;
		}
	}
	return false;
}

bool wordBreak(const string& s, const vector<string>& wordDict) {
	bool* canBreak = new bool[s.size() + 1];
	canBreak[0] = true;
	for (int i = 1; i < s.size() + 1; i++) {
		canBreak[i] = false;
	}
	for (int i = 1; i <= s.size(); i++) {

		for (int j = 0; j < i; j++) {
			if (canBreak[j] && contain(s.substr(j, i-j), wordDict)) {
				canBreak[i] = true;
				break;
			}
		}
	}

	return canBreak[s.size()];

}

int main() {
	
	vector<string> vs;
	vs.push_back("ap");
	vs.push_back("pe");
	cout << wordBreak("appeap", vs) << endl;

	return 0;
}