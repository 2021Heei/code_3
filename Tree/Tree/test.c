#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char BTDataType;
typedef struct BTNode {
	BTDataType val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

//先序遍历建立二叉树
BTNode* TreeCreate(BTDataType* a, int* pi) {
	//当字符为#时，说明不存在节点，下标加1以记录下一个位置，返回NULL指针
	if (a[(*pi)] == '#') {
		(*pi)++;
		return NULL;
	}
	//节点存在时，先创建根节点，初始化节点指针，并对节点赋值
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL) {
		perror("malloc fail");
		return NULL;
	}
	root->left = root->right = NULL;
	root->val = a[(*pi)];
	//节点创建完成，下标加1以记录下一个位置
	(*pi)++;
	//先链接左节点，再链接右节点
	root->left = TreeCreate(a, pi);
	root->right = TreeCreate(a, pi);

	return root;
}

//前序遍历
void PreOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->val);
	PreOrder(root->left);
	PreOrder(root->right);
}

//中序遍历
void InOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

//后序遍历
void PostOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->val);
}



int main() {
	//char str[] = "AB#CD###E#FGH##K###";
	char str[1000] = { 0 };
	printf("请输入二叉树的先序遍历构建二叉树，'#'代表NULL\n");
	scanf("%s", str);
	int i = 0;
	BTNode* root = TreeCreate(str, &i);
	if (!root) {
		return -1;
	}
	printf("二叉树的先序遍历\n");
	PreOrder(root);
	printf("\n");
	printf("二叉树的中序遍历\n");
	InOrder(root);
	printf("\n");
	printf("二叉树的后序遍历\n");
	PostOrder(root);
	printf("\n");

	return 0;
}

