#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "Queue.h"

BTNode* TreeCreate(BTDataType * a, int* pi) {
	if (a[(*pi)] == '#') {
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL) {
		perror("malloc fail");
		return NULL;
	}
	root->left = root->right = NULL;
	root->val = a[(*pi)];
	(*pi)++;
	root->left = TreeCreate(a, pi);
	root->right = TreeCreate(a, pi);

	return root;
}

BTNode* TreeCreateIn(BTDataType* a, int* pi) {
	if (a[(*pi)] == '#') {
		(*pi)++;
		return NULL;
	}
	BTNode* left = TreeCreate(a, pi);

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL) {
		perror("malloc fail");
		return NULL;
	}
	root->left = root->right = NULL;
	root->val = a[(*pi)];
	(*pi)++;
	root->left = left;

	BTNode* right = TreeCreate(a, pi);
	root->right = right;
	
	return root;
}

BTNode* CreateTree() {
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

	//初始化左右指针为NULL
	n1->left = n1->right = NULL;
	n2->left = n2->right = NULL;
	n3->left = n3->right = NULL;
	n4->left = n4->right = NULL;
	n5->left = n5->right = NULL;
	n6->left = n6->right = NULL;
	n7->left = n7->right = NULL;

	//手动赋值
	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 4;
	n5->val = 5;
	n6->val = 6;
	n7->val = 7;

	//手动控制节点左右指针指向
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = NULL;
	n3->left = n5;
	n3->right = n6;
	n4->left = n7;
	n4->right = NULL;
	n5->left = NULL;
	n5->right = NULL;
	n6->left = NULL;
	n6->right = NULL;
	n7->left = NULL;
	n7->right = NULL;
	return n1;
}

//递归遍历
//前序遍历
void PreOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	printf("%d ", root->val);
	PreOrder(root->left);
	PreOrder(root->right);
}
//中序遍历
//void InOrder(BTNode* root){
//	if (root == NULL) {
//		printf("NULL ");
//		return;
//	}
//
//	InOrder(root->left);
//	printf("%d ", root->val);
//	InOrder(root->right);
//}

//后序遍历
void PostOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
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

//int main() {
//	BTNode* root = CreateTree();
//	PreOrder(root);
//	printf("\n");
//	InOrder(root);
//	printf("\n");
//	PostOrder(root);
//	printf("\n");
//	printf(" TreeSize: %d\n", TreeSize(root));
//	printf(" TreeLeafSize: %d\n", TreeLeafSize(root));
//	printf(" TreeHeight: %d\n", TreeHeight(root));
//	printf(" TreeKLevel: %d\n", TreeKLevel(root, 4));
//	BTNode* ret = TreeFind(root, 25);
//	if (ret) {
//		printf("ret: %d\n", ret->val);
//	}
//
//	TreeLevelOrder(root);
//
//	printf("BinaryTreeComplete: %d \n", BinaryTreeComplete(root));
//	
//	//char str[] = "1247####35##6##";
//	char str[] = "#7#4#2#1#5#3#6#";
//	int i = 0;
//	/*BTNode* roots = TreeCreate(str, &i);
//	if (roots)
//		PreOrder(roots);*/
//
//	i = 0;
//	BTNode* rootin = TreeCreateIn(str, &i);
//	if (rootin) {
//		InOrder(rootin);
//	}
//	return 0;
//}
int TreeSize2(struct BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}

void PreOrder2(struct BTNode* root, int* a, int* pi) {
	if (root == NULL) {
		return;
	}
	a[*pi] = root->val;
	(*pi)++;
	PreOrder2(root->left, a, pi);
	PreOrder2(root->right, a, pi);
}
int* preorderTraversal(struct BTNode* root, int* returnSize) {
	if (root == NULL) {
		return NULL;
	}
	int num = TreeSize2(root);
	int* tmp = (int*)malloc(sizeof(int) * num);
	if (tmp == NULL) {
		perror("malloc fail");
		return NULL;
	}
	int* a = tmp;
	*returnSize = num;

	int i = 0;
	PreOrder2(root, a, &i);
	return a;
}
int main() {
	int size = 0;
	//BTNode* root = CreateTree();
	BTNode* root = NULL;
	int* a = preorderTraversal(root, &size);
	for (int i = 0; i < size; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
	//PreOrder(root);
	return 0;
}