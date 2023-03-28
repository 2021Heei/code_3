#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
#include "AVL.h"

int getMost(vector<vector<int> > board) {
	// write code here
	vector<vector<int> > dp;
	vector<int> tmp;
	for (int i = 0; i < dp.size(); ++i) {
		for (int j = 0; j < dp[i].size(); ++j) {
			tmp.push_back(0);
		}
		dp.push_back(tmp);
		tmp.clear();
	}
	dp[0][0] = board[0][0];

	//dp[n][m] = max(dp[n-1][m], dp[n, m-1])
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j) {
			if (i == 0 && j == 0) continue;
			int a = i - 1 >= 0 && i - 1 < board.size() ? dp[i - 1][j] : 0;
			int b = j - 1 >= 0 && j - 1 < board[0].size() ? dp[i][j - 1] : 0;
			dp[i][j] = board[i][j] + max(a, b);
		}
	}
	return dp[5][5];
}

int main() {
	vector<vector<int> > vv;
	vector<int> tmp;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			tmp.push_back(i + j);
		}
		vv.push_back(tmp);
		tmp.clear();
	}
	getMost(vv);

	return 0;
}
