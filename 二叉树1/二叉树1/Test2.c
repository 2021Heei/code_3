//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//
////二叉节点
//typedef char BTDataType;
//typedef struct BTNode {
//	BTDataType val;
//	struct BTNode* left;
//	struct BTNode* right;
//}BTNode;
//
////前序遍历,先访问根，再访问根的左子树，最后访问根的右子树
//void PreOrder(BTNode* root) {
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//
//	printf("%c ", root->val);
//	PreOrder(root->left);
//	PreOrder(root->right);
//}
//
//BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi) {
//	if (*pi == n) {
//		return NULL;
//	}
//	if (a[*pi] == '#') {
//		(*pi)++;
//		return NULL;
//	}
//	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
//	if (newnode == NULL) {
//		perror("malloc file");
//		exit(-1);
//	}
//	newnode->val = a[*pi];
//	(*pi)++;
//	newnode->left = BinaryTreeCreate(a, n, pi);
//	newnode->right = BinaryTreeCreate(a, n, pi);
//
//	return newnode;
//}
//
////销毁
//void BinaryTreeDestory(BTNode** root) {
//	assert(root);
//	if (*root == NULL) {
//		return;
//	}
//	//后序
//	BinaryTreeDestory(&(*root)->left);
//	BinaryTreeDestory(&(*root)->right);
//	free(*root);
//}
//
////求高度或深度
//int TreeHeight(BTNode* root) {
//	if (root == NULL) {
//		return 0;
//	}
//	//算该根的高度，分为计算左子树与右子树高度的较大的再+1
//	int leftHeight = TreeHeight(root->left);
//	int rightHeight = TreeHeight(root->right);
//	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
//}
//
////求第k层的节点数
//int TreeKNode(BTNode* root, int k) {
//	if (root == NULL)
//		return 0;
//	//该节点存在，且是第k层的节点就记录返回
//	if (root && k == 1) {
//		return 1;
//	}
//	//分而治之
//	//不是第k层的根，就在该根的左子树和右子树的第k-1层寻找
//	return TreeKNode(root->left, k-1) + TreeKNode(root->right, k-1);
//}
////是否是完全二叉树
//int BinaryTreeComplete(BTNode* root) {
//	int heigh = TreeHeight(root);
//	for (int i = heigh - 1; i >= 1; --i) {
//		if (TreeKNode(root, i) != (int)pow(2, i - 1)) {
//			return 0;
//		}
//	}
//
//	return 1;
//}
//
//int main() {
//	//BTDataType str[20] = "ABD##E#H##CF##G##";
//	BTDataType str[20] = "124##5##36###";
//	int num = 0;
//	BTNode* root = BinaryTreeCreate(str, sizeof(str), &num);
//	PreOrder(root);
//
//	int ret = BinaryTreeComplete(root);
//	printf("%d\n", ret);
//	BinaryTreeDestory(&root);
//	root = NULL;
//	return 0;
//}