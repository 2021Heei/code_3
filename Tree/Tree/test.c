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

//�����������������
BTNode* TreeCreate(BTDataType* a, int* pi) {
	//���ַ�Ϊ#ʱ��˵�������ڽڵ㣬�±��1�Լ�¼��һ��λ�ã�����NULLָ��
	if (a[(*pi)] == '#') {
		(*pi)++;
		return NULL;
	}
	//�ڵ����ʱ���ȴ������ڵ㣬��ʼ���ڵ�ָ�룬���Խڵ㸳ֵ
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL) {
		perror("malloc fail");
		return NULL;
	}
	root->left = root->right = NULL;
	root->val = a[(*pi)];
	//�ڵ㴴����ɣ��±��1�Լ�¼��һ��λ��
	(*pi)++;
	//��������ڵ㣬�������ҽڵ�
	root->left = TreeCreate(a, pi);
	root->right = TreeCreate(a, pi);

	return root;
}

//ǰ�����
void PreOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->val);
	PreOrder(root->left);
	PreOrder(root->right);
}

//�������
void InOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

//�������
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
	printf("��������������������������������'#'����NULL\n");
	scanf("%s", str);
	int i = 0;
	BTNode* root = TreeCreate(str, &i);
	if (!root) {
		return -1;
	}
	printf("���������������\n");
	PreOrder(root);
	printf("\n");
	printf("���������������\n");
	InOrder(root);
	printf("\n");
	printf("�������ĺ������\n");
	PostOrder(root);
	printf("\n");

	return 0;
}

