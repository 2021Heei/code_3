#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <list>//双向循环链表
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <array>

using namespace std;
#include "BSTree.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		:val(x)
		,left(nullptr)
		,right(nullptr){ }
};

//prev的延迟赋值，需要使用引用类型
void InOrder(K::BSTreeNode<int> * cur, K::BSTreeNode<int>*& prev) {
	if (!cur) return;
	InOrder(cur->_left, prev);

	cur->_left = prev;
	if (prev)
		prev->_right = cur;
	prev = cur;

	InOrder(cur->_right, prev);
}
K::BSTreeNode<int>* Convert(K::BSTreeNode<int>* pRootOfTree) {
	K::BSTreeNode<int>* prev = nullptr;
	InOrder(pRootOfTree, prev);
	K::BSTreeNode<int>* head = pRootOfTree;
	while (head && head->_left) {
		head = head->_left;
	}
	return head;
}

int evalRPN(vector<string>& tokens) {
	stack<int> st;
	int i = 0;
	while (i < tokens.size()) {
		if (isdigit(tokens[i][0])) {
			st.push(stoi(tokens[i]));
		}
		else {
			int next = st.top();
			st.pop();
			int front = st.top();
			st.pop();
			switch (tokens[i][0]) {
			case '+':
				st.push(front + next);
				break;
			case '-':
				st.push(front - next);
				break;
			case '*':
				st.push(front * next);
				break;
			case '/':
				st.push(front / next);
				break;
			}
		}

		++i;
	}
	return st.top();
}

//int main() {
//	/*K::BSTree<int> bst;
//	int arr[] = { 10, 6, 4, 8, 14, 12, 18 };
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
//		bst.insert(arr[i]);
//	}
//	bst.InOrder();
//	K::BSTreeNode<int>* root = Convert(bst._root);
//	while (root) {
//		cout << root->_key << " ";
//		root = root->_right;
//	}
//	cout << endl;*/
//
//	vector<string> vs{ "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
//	int ret = evalRPN(vs);
//
//	return 0;
//}

TreeNode* _buildTree(vector<int>& preorder, int& i, vector<int>& inorder, int left, int right) {
	int j = left;
	for (; j <= right; ++j) {
		if (preorder[i] == inorder[j]) {
			break;
		}
	}
	TreeNode* root = new TreeNode(preorder[i]);
	++i;
	root->left = _buildTree(preorder, i, inorder, left, j);
	root->right = _buildTree(preorder, i, inorder, j + 1, right);
	return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int i = 0;
	TreeNode* root = _buildTree(preorder, i, inorder, 0, inorder.size() - 1);
	return root;
}

int main()

{

	deque<int> cont = { 1, 2, 3, 4, 5 };

	deque<int>::iterator iter, tempIt;

	for (iter = cont.begin(); iter != cont.end();)

	{



		tempIt = iter;



		++iter;



		cont.erase(tempIt);

	}

}
////二叉树前序迭代遍历
//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//		//左节点和左节点的右子树
//		vector<int> ret;
//		if (!root) return ret;
//		stack<TreeNode*> st;
//
//		TreeNode* cur = root;
//		while (cur || !st.empty()) {
//			while (cur) {
//				ret.push_back(cur->val);
//				st.push(cur);
//				cur = cur->left;
//			}
//
//			TreeNode* top = st.top();
//			st.pop();
//			cur = top->right;
//		}
//		return ret;
//	}
//};
//
////二叉树中序迭代遍历
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {
//		//左节点和左节点的右子树
//		vector<int> ret;
//		if (!root) return ret;
//		stack<TreeNode*> st;
//		TreeNode* cur = root;
//		while (cur || !st.empty()) {
//
//			while (cur) {
//				st.push(cur);
//				cur = cur->left;
//			}
//
//			TreeNode* top = st.top();
//			st.pop();
//			ret.push_back(top->val);
//			cur = top->right;
//		}
//		return ret;
//	}
//};