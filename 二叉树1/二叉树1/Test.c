////#include "BinarySearch.h"
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//
////����ڵ�
//typedef int BTDataType;
//typedef struct BTNode {
//	BTDataType val;
//	struct BTNode* left;
//	struct BTNode* right;
//}BTNode;
//
////ǰ�����,�ȷ��ʸ����ٷ��ʸ����������������ʸ���������
//void PreOrder(BTNode* root) {
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	
//	printf("%d ", root->val);
//	PreOrder(root->left);
//	PreOrder(root->right);
//}
//
////�������
//void InOrder(BTNode* root) {
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//
//	InOrder(root->left);
//	printf("%d ", root->val);
//	InOrder(root->right);
//}
//
////�������
//void PostOrder(BTNode* root) {
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//
//	PostOrder(root->left);
//	PostOrder(root->right);
//	printf("%d ", root->val);
//}
//
//
//BTNode* CreaterTree() {
//	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
//	assert(n1);
//	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
//	assert(n2);
//	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
//	assert(n3);
//	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
//	assert(n4);
//	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
//	assert(n5);
//	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
//	assert(n6);
//	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
//	assert(n7);
//
//	n1->val = 1;
//	n2->val = 2;
//	n3->val = 3;
//	n4->val = 4;
//	n5->val = 5;
//	n6->val = 6;
//	n7->val = 7;
//
//	n1->left = n2;
//	n1->right = n4;
//	n2->left = n3;
//	n2->right = NULL;
//	n4->left = n5;
//	n4->right = n6;
//	n3->left = NULL;
//	n3->right = NULL;
//	n5->left = NULL;
//	n5->right = NULL;
//	n6->left = NULL;
//	n6->right = NULL;
//
//	n3->right = n7;
//	n7->left = NULL;
//	n7->right = NULL;
//
//	return n1;
//}
//
////��ڵ���
////1. ������
////int NumNode(BTNode* root) {
////	if (root == NULL) {
////		return 0;
////	}
////	static int count = 0;//���ܶ�ε���
////	++count;
////	NumNode(root->left);
////	NumNode(root->right);
////	return count;
////}
//
////int count = 0;
////int NumNode(BTNode* root) {
////	if (root == NULL) {
////		return 0;
////	}
////	++count;
////	NumNode(root->left);
////	NumNode(root->right);
////	return count;
////}
//// 
////2. �ݹ�
////�ֶ���֮���ֳ�С���⣬��������
//int TreeNode(BTNode* root) {
//	//if (root == NULL) {
//	//	return 0;
//	//}
//	//return NumNode(root->left) + NumNode(root->right) + 1;
//	return root == NULL ? 0 : TreeNode(root->left) + TreeNode(root->right) + 1;
//}
//
////��Ҷ����
//int TreeLeafNode(BTNode* root) {
//	if (root == NULL)
//		return 0;
//
//	if (root->left == NULL && root->right == NULL)
//		return 1;
//	//������Ҷ��+������Ҷ��
//	return TreeLeafNode(root->left) + TreeLeafNode(root->right);
//}
//
////��߶Ȼ����
//int TreeHeight(BTNode* root) {
//	if (root == NULL) {
//		return 0;
//	}
//	//��ø��ĸ߶ȣ���Ϊ�������������������߶ȵĽϴ����+1
//	int leftHeight = TreeHeight(root->left);
//	int rightHeight = TreeHeight(root->right);
//	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
//}
//
////���k��Ľڵ���
//int TreeKNode(BTNode* root, int k) {
//	if (root == NULL)
//		return 0;
//	//�ýڵ���ڣ����ǵ�k��Ľڵ�ͼ�¼����
//	if (root && k == 1) {
//		return 1;
//	}
//	//�ֶ���֮
//	//���ǵ�k��ĸ������ڸø������������������ĵ�k-1��Ѱ��
//	return TreeKNode(root->left, k-1) + TreeKNode(root->right, k-1);
//}
//
////��val�����ظýڵ�
//BTNode* TreeFind(BTNode* root, BTDataType val) {
//	if (root == NULL)
//		return NULL;
//
//	if (root->val == val)
//		return root;
//	//���Σ���������
//	//�������������������ص���Ч��ַ�ĵ�һ��
//	BTNode* p1 = TreeFind(root->left, val);
//	BTNode* p2 = TreeFind(root->right, val);
//	return p1 ? p1 : p2;
//}
//
//
////
////int TreeSize(struct BTNode* root) {
////	if (root == NULL)
////		return 0;
////
////	return TreeSize(root->left) + TreeSize(root->right);
////}
////
////void preorder(int* a, struct BTNode* root, int* pi) {
////	if (root == NULL)
////		return;
////
////	preorder(a, root->left, pi);
////	a[*pi] = root->val;
////	(*pi)++;
////	preorder(a, root->right, pi);
////}
////
////int* preorderTraversal(struct BTNode* root, int* returnSize) {
////	int size = TreeSize(root);
////	int* a = (int*)malloc(sizeof(int) * size);
////	int n = 0;
////	preorder(a, root, &n);
////	*returnSize = n;
////	return a;
////}
//
// //��������������ڵ�����
//int TreeSize(struct BTNode* root) {
//	if (root == NULL)
//		return 0;
//
//	return TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
////�������
//void inorder(int* a, struct BTNode* root, int* pi) {
//	if (root == NULL)
//		return;
//
//	inorder(a, root->left, pi);
//	a[*pi] = root->val;
//	*pi++;
//	inorder(a, root->right, pi);
//}
//
//int* inorderTraversal(struct BTNode* root, int* returnSize) {
//	int size = TreeSize(root);
//	int* a = (int*)malloc(sizeof(int) * size);
//	int n = 0;
//	inorder(a, root, &n);
//	*returnSize = n;
//	return a;
//}
////int main() {
////	BTNode* root = CreaterTree();
////
////	//PreOrder(root);
////	//InOrder(root);
////	//PostOrder(root);
////
////	/*printf("TreeNode: %d\n", TreeNode(root));
////	printf("TreeNode: %d\n", TreeNode(root));
////
////	printf("TreeLeafNode: %d\n", TreeLeafNode(root));
////	printf("TreeHeight: %d\n", TreeHeight(root));
////
////	printf("TreeKNode: %d\n", TreeKNode(root, 0));
////	printf("TreeKNode: %d\n", TreeKNode(root, 1));
////	printf("TreeKNode: %d\n", TreeKNode(root, 2));
////	printf("TreeKNode: %d\n", TreeKNode(root, 3));
////	printf("TreeKNode: %d\n", TreeKNode(root, 4));
////
////	BTNode* ret = TreeFind(root, 5);
////	printf("TreeFind: %d \n", ret->val);*/
////	int num = 0;
////	int* arr = inorderTraversal(root, &num);
////	for (int i = 0; i < num; i++) {
////		printf("%d ", arr[i]);
////	}
////	return 0;
////}