#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "Queue.h"


BTNode* CreatTree() {
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	assert(n1);
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	assert(n2);
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	assert(n3);
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	assert(n4);
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	assert(n5);
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	assert(n6);
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	assert(n7);
	BTNode* n8 = (BTNode*)malloc(sizeof(BTNode));
	assert(n8);
	BTNode* n9 = (BTNode*)malloc(sizeof(BTNode));
	assert(n9);
	BTNode* n10 = (BTNode*)malloc(sizeof(BTNode));
	assert(n10);

	n1->val = 15;
	n2->val = 18;
	n3->val = 19;
	n4->val = 25;
	n5->val = 27;
	n6->val = 28;
	n7->val = 34;
	n8->val = 37;
	n9->val = 49;
	n10->val = 65;

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	n4->left = n8;
	n4->right = n9;
	n5->left = n10;
	n5->right = NULL;
	n6->left = NULL;
	n6->right = NULL;
	n7->left = NULL;
	n7->right = NULL;
	n8->left = NULL;
	n8->right = NULL;
	n9->left = NULL;
	n9->right = NULL;
	n10->left = NULL;
	n10->right = NULL;

	//n4->right = NULL;
	return n1;
}

int TreeSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}
//
//int count = 0;
//
//void TreeSize(BTNode* root) {
//	if (root == NULL) {
//		return;
//	}
//	count++;
//	TreeSize(root->left);
//	TreeSize(root->right);
//}
//
//void TreeSize(BTNode* root) {
//	if (root == NULL) {
//		return;
//	}
//	static count = 0;
//	count++;
//	TreeSize(root->left);
//	TreeSize(root->right);
//}


int TreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeHeight(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	int heightleft = TreeHeight(root->left);
	int heightright = TreeHeight(root->right);
	return heightleft > heightright ? heightleft + 1 : heightright + 1;
}

//求第k层的节点数，递归思想
int TreeKLevel(BTNode* root, int k) {
	assert(k > 0);
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);
}

//查找val并返回
BTNode* TreeFind(BTNode* root, BTDataType val) {
	if (root == NULL) {
		return NULL;
	}
	if (root->val == val) {
		return root;
	}
	BTNode* pL = TreeFind(root->left, val);
	if (pL) {
		return pL;
	}
	BTNode* pR = TreeFind(root->right, val);
	if (pR) {
		return pR;
	}
	return NULL;
}

void BinaryTreeDestory(BTNode* root) {
	if (root = NULL) {
		return;
	}
	//后序
	//先销毁左子树，再销毁右子树
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}

//层序遍历,即非递归遍历二叉树
void TreeLevelOrder(BTNode* root) {
	Queue q;
	QueueInit(&q);
	if (root) {
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q)) {
		BTNode* head = QueueHead(&q);
		QueuePop(&q);
		printf("%d ", head->val);
		if (head->left) {
			QueuePush(&q, head->left);
		}
		if (head->right) {
			QueuePush(&q, head->right);
		}
	}
	printf("\n");
}

//判断是否是完全二叉树
int BinaryTreeComplete(BTNode* root) {
	Queue q;
	QueueInit(&q);

	if (root) {
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q)) {
		BTNode* head = QueueHead(&q);
		QueuePop(&q);
		if (head == NULL) {
			break;
		}
		QueuePush(&q, head->left);
		QueuePush(&q, head->right);
	}
	while (!QueueEmpty(&q)) {
		BTNode* head = QueueHead(&q);
		QueuePop(&q);
		if (head != NULL) {
			QueueDestroy(&q);
			return 0;
		}
	}

	QueueDestroy(&q);
	return 1;
}

int main() {
	BTNode* root = CreatTree();

	printf(" TreeSize: %d\n", TreeSize(root));
	printf(" TreeLeafSize: %d\n", TreeLeafSize(root));
	printf(" TreeHeight: %d\n", TreeHeight(root));
	printf(" TreeKLevel: %d\n", TreeKLevel(root, 4));
	BTNode* ret = TreeFind(root, 25);
	if (ret) {
		printf("ret: %d\n", ret->val);
	}

	TreeLevelOrder(root);

	printf("BinaryTreeComplete: %d ", BinaryTreeComplete(root));
	return 0;
}