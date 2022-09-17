//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//
////����ڵ�
//typedef char BTDataType;
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
////����
//void BinaryTreeDestory(BTNode** root) {
//	assert(root);
//	if (*root == NULL) {
//		return;
//	}
//	//����
//	BinaryTreeDestory(&(*root)->left);
//	BinaryTreeDestory(&(*root)->right);
//	free(*root);
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
////�Ƿ�����ȫ������
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