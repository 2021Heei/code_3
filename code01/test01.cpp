#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdbool>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode() {

	}
	
};

bool isEqual(TreeNode* A, TreeNode* B) {
	//出口条件
	if (!B) return true;
	if (!A) return false;
	//
	if (A->val != B->val) return false;
	//当前节点相等，比较子树
	return isEqual(A->left, B) && isEqual(A->right, B);
}

bool isSubStructure(TreeNode* A, TreeNode* B) {

	if (!A || !B) return false;
	bool ret = false;
	if (A->val == B->val) {
		ret = isEqual(A, B);
	}
	if (!ret) {
		ret = isSubStructure(A->left, B);
	}
	if (!ret) {
		ret = isSubStructure(A->right, B);
	}
	return ret;
}


TreeNode n1;
TreeNode n2;
TreeNode n3;
TreeNode n4;

TreeNode n;

int main() {
	n1.val = 1;
	n2.val = 2;
	n3.val = 3;
	n4.val = 4;
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = nullptr;
	n3.left = nullptr;
	n3.right = nullptr;
	n4.left = nullptr;
	n4.right = nullptr;

	n.val = 3;
	n.left = nullptr;
	n.right = nullptr;
	bool re = isSubStructure(&n1, &n);
	return 0;
}