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

int main() {
	K::BSTree<int> bst;
	int arr[] = { 10, 6, 4, 8, 14, 12, 18 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		bst.insert(arr[i]);
	}
	bst.InOrder();
	K::BSTreeNode<int>* root = Convert(bst._root);
	while (root) {
		cout << root->_key << " ";
		root = root->_right;
	}
	cout << endl;
	return 0;
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